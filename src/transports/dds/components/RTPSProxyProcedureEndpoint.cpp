/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************/

#include <fastrpc/transports/dds/components/RTPSProxyProcedureEndpoint.h>
#include <fastrpc/transports/dds/RTPSAsyncTask.h>
#include <fastrpc/protocols/dds/MessageHeader.h>
#include <fastrpc/utils/macros/snprintf.h>
#include <fastrpc/utils/macros/strdup.h>
#include <fastrpc/utils/Typedefs.h>

#include <fastrtps/Domain.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/SampleInfo.h>

#include <boost/config/user.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/chrono.hpp>

#ifdef __linux
#include <cinttypes>
#endif

static const char* const CLASS_NAME = "eprosima::rpc::transport::dds::RTPSProxyProcedureEndpoint";

namespace eprosima { namespace rpc {
namespace transport { namespace dds {
class RecvPoint
{
public:

	RecvPoint(void *reply) : reply_(reply), task_(NULL) {}

	explicit RecvPoint(RTPSAsyncTask *task) : reply_(NULL), task_(task)
	{
		if(task_ != NULL) reply_ = task_->getReplyInstance();
	}

	void* getReply() { return reply_;}

	RTPSAsyncTask* getTask() { return task_;}

	boost::condition_variable cond_;

private:

	void *reply_;

	RTPSAsyncTask *task_;
};
}}
}}

using namespace eprosima::rpc;
using namespace ::transport::dds;

RTPSProxyProcedureEndpoint::RTPSProxyProcedureEndpoint(RTPSProxyTransport &transport) : m_mutex(NULL), recv_mutex_(NULL),
		matched_mutex_(NULL), matched_sub_cond_(NULL), matched_pub_cond_(NULL), num_matched_sub_(0), num_matched_pub_(0),
		m_transport(transport), m_writer(NULL), m_reader(NULL), m_numSec(0),
		m_create_data(NULL), m_copy_data(NULL), m_destroy_data(NULL), data_(NULL)
{
}

RTPSProxyProcedureEndpoint::~RTPSProxyProcedureEndpoint()
{
	// Remove asynchronous tasks.
	//TODO
	//m_transport.deleteAssociatedAsyncTasks(this);

	finalize();
}

int RTPSProxyProcedureEndpoint::initialize(const char *name, const char *writertypename,
		const char *writertopicname, const char *readertypename, const char *readertopicname,
		RTPSTransport::Create_data create_data, RTPSTransport::Copy_data copy_data,
		RTPSTransport::Destroy_data destroy_data)
{
	const char* const METHOD_NAME = "initialize";
	m_create_data = create_data;
	m_copy_data = copy_data;
	m_destroy_data = destroy_data;
	m_mutex =  new boost::mutex();
	recv_mutex_ = new boost::mutex();
	matched_mutex_ = new boost::shared_mutex();
	matched_sub_cond_ = new boost::condition_variable_any();
	matched_pub_cond_ = new boost::condition_variable_any();

	if(m_mutex != NULL && recv_mutex_ != NULL && matched_mutex_ != NULL &&
			matched_sub_cond_ != NULL && matched_pub_cond_ != NULL)
	{
		if(createEntities(name, writertypename, writertopicname,
				readertypename, readertopicname) == 0)
		{
			// Not oneway
			if(m_reader != NULL)
			{
				data_ = m_create_data();

				if(data_ != NULL)
					return 0;
				else
					printf("ERROR<%s::%s>: Cannot create data\n", CLASS_NAME, METHOD_NAME);
			}
			else
				return 0;
		}
		else
		{
			printf("ERROR<%s::%s>: Cannot create the DDS entities\n", CLASS_NAME, METHOD_NAME);
		}
	}
	else
	{
		printf("ERROR<%s::%s>: Cannot create the mutex\n", CLASS_NAME, METHOD_NAME);
	}

	return -1;
}

void RTPSProxyProcedureEndpoint::finalize()
{
	if(data_ != NULL)
		m_destroy_data(data_);

	// if not operation oneway.
	if(m_reader != nullptr)
	{
		eprosima::fastrtps::Domain::removeSubscriber(m_reader);
	}

	if(m_writer != nullptr)
		eprosima::fastrtps::Domain::removePublisher(m_writer);

	if(matched_pub_cond_ != NULL)
	{
		delete matched_pub_cond_;
		matched_pub_cond_ = NULL;
	}

	if(matched_sub_cond_ != NULL)
	{
		delete matched_sub_cond_;
		matched_sub_cond_ = NULL;
	}

	if(matched_mutex_ != NULL)
	{
		delete matched_mutex_;
		matched_mutex_ = NULL;
	}

	if(recv_mutex_ != NULL)
	{
		delete recv_mutex_;
		recv_mutex_ = NULL;
	}

	if(m_mutex != NULL)
	{
		delete m_mutex;
		m_mutex = NULL;
	}
}

int RTPSProxyProcedureEndpoint::createEntities(const char *name, const char *writertypename, const char *writertopicname,
		const char *readertypename, const char *readertopicname)
{
	const char* const METHOD_NAME = "createEntities";

	if(name != NULL)
	{
		if(writertypename != NULL)
		{
			eprosima::fastrtps::PublisherAttributes wQos;

			wQos.topic.topicName = writertopicname;
			wQos.topic.topicDataType = writertypename;
			wQos.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;
			wQos.topic.historyQos.depth = 100;

			m_writer = eprosima::fastrtps::Domain::createPublisher(m_transport.getParticipant(), wQos, this);

			if(m_writer != nullptr)
			{
				// Is not oneway operation
				if(readertypename != NULL)
				{
					eprosima::fastrtps::SubscriberAttributes rQos;

					rQos.topic.topicName = readertopicname;
					rQos.topic.topicDataType = readertypename;
					rQos.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;
					rQos.topic.historyQos.depth = 100;

					m_reader = eprosima::fastrtps::Domain::createSubscriber(m_transport.getParticipant(), rQos, this);

					if(m_reader != nullptr)
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}

				eprosima::fastrtps::Domain::removePublisher(m_writer);
			}
			else
			{
				printf("ERROR<%s::%s>: Cannot create the data writer\n", CLASS_NAME, METHOD_NAME);
			}
		}
		else
		{
			printf("ERROR<%s::%s>: Bad parameter (writertypename)\n", CLASS_NAME, METHOD_NAME);
		}
	}
	else
	{
		printf("ERROR<%s::%s>: Bad parameter (name)\n", CLASS_NAME, METHOD_NAME);
	}

	return -1;
}

ReturnMessage RTPSProxyProcedureEndpoint::checkServerConnection(long timeout)
{
	boost::shared_lock<boost::shared_mutex> lock(*matched_mutex_);

	if(num_matched_sub_ == 0)
	{
		if(matched_sub_cond_->wait_for(lock, boost::chrono::milliseconds(timeout)) != boost::cv_status::timeout)
		{
			if(num_matched_sub_ == 0)
				return SERVER_NOT_FOUND;
		}
	}

	if(num_matched_pub_ == 0)
	{
		if(matched_pub_cond_->wait_for(lock, boost::chrono::milliseconds(timeout)) != boost::cv_status::timeout)
		{
			if(num_matched_pub_ == 0)
				return SERVER_NOT_FOUND;
		}
	}

	return OK;
}

ReturnMessage RTPSProxyProcedureEndpoint::send(void *request, void *reply)
{
	const char* const METHOD_NAME = "send";
	ReturnMessage returnedValue = CLIENT_INTERNAL_ERROR;
	eprosima::rpc::protocol::dds::rpc::RequestHeader *requestHeader = NULL;
	int64_t numSec = 0;

	if(request != NULL)
	{
		requestHeader = reinterpret_cast<eprosima::rpc::protocol::dds::rpc::RequestHeader*>(request);
		memcpy(requestHeader->requestId().writer_guid().guidPrefix(), m_proxyId.guidPrefix(), 12);
		memcpy(requestHeader->requestId().writer_guid().entityId().entityKey(), m_proxyId.entityId().entityKey(), 3);
		requestHeader->requestId().writer_guid().entityId().entityKind() = m_proxyId.entityId().entityKind();
		requestHeader->instanceName(m_transport.getInstanceName());

		std::cout << "Blocking before sending"<<std::endl;
		m_mutex->lock();
		numSec = m_numSec;
		// Thread safe num_Sec handling
		int32_t high = (numSec >> 32) & 0xFFFFFFFF;
		uint32_t low = (numSec & 0xFFFFFFFF);
		requestHeader->requestId().sequence_number().high(high);
		requestHeader->requestId().sequence_number().low(low);
		std::cout << "Sending: "<< numSec << std::endl;
		++m_numSec;
		m_mutex->unlock();
		std::cout << "Unlocking: "<< numSec << std::endl;
		// TODO Chech for server connection.

		if(checkServerConnection(m_transport.getTimeout()) == OK)
		{
			std::cout << "Checking connection for "<<numSec<<std::endl;
			if(m_writer->write(request))
			{
				// Its not a oneway function.
				std::cout << "Write numSec" <<numSec << " sended"<<std::endl;
				if(m_reader != nullptr && reply != NULL)
				{
					returnedValue = takeReply(reply, numSec);
				}
				else
				{
					returnedValue = OK;
				}
			}
			else
			{
				printf("ERROR <%s::%s>: Some error occurs\n", CLASS_NAME, METHOD_NAME);
			}
		}
		else
		{
			printf("WARNING<%s::%s>: No server discovered.\n", CLASS_NAME, METHOD_NAME);
			returnedValue = SERVER_NOT_FOUND;
		}
	}
	else
	{
		printf("ERROR<%s::%s>: Bad parameter(data)\n", CLASS_NAME, METHOD_NAME);
	}

	return returnedValue;
}

ReturnMessage RTPSProxyProcedureEndpoint::send_async(void *request, RTPSAsyncTask *task)
{
	const char* const METHOD_NAME = "send_async";
	ReturnMessage returnedValue = CLIENT_INTERNAL_ERROR;
	eprosima::rpc::protocol::dds::rpc::RequestHeader *requestHeader = NULL;
	int64_t numSec = 0;

	if(request != NULL)
	{
		requestHeader = reinterpret_cast<eprosima::rpc::protocol::dds::rpc::RequestHeader*>(request);
		memcpy(requestHeader->requestId().writer_guid().guidPrefix(), m_proxyId.guidPrefix(), 12);
		memcpy(requestHeader->requestId().writer_guid().entityId().entityKey(), m_proxyId.entityId().entityKey(), 3);
		requestHeader->requestId().writer_guid().entityId().entityKind() = m_proxyId.entityId().entityKind();
		requestHeader->instanceName(m_transport.getInstanceName());


		m_mutex->lock();
		numSec = m_numSec;
		// Thread safe num_Sec handling
		int32_t high = (numSec >> 32) & 0xFFFFFFFF;
		uint32_t low = (numSec & 0xFFFFFFFF);
		requestHeader->requestId().sequence_number().high(high);
		requestHeader->requestId().sequence_number().low(low);
		++m_numSec;
		m_mutex->unlock();

		// TODO Chech for server connection.

		if(checkServerConnection(m_transport.getTimeout()) == OK)
		{
			if(m_writer->write(request))
			{
				addAsyncTask(task, numSec);
				returnedValue = OK;
			}
			else
			{
				printf("ERROR <%s::%s>: Some error occurs\n", CLASS_NAME, METHOD_NAME);
			}
		}
		else
		{
			printf("WARNING<%s::%s>: No server discovered.\n", CLASS_NAME, METHOD_NAME);
			returnedValue = SERVER_NOT_FOUND;
		}
	}
	else
	{
		printf("ERROR<%s::%s>: Bad parameter(data)\n", CLASS_NAME, METHOD_NAME);
	}

	return returnedValue;
}

ReturnMessage RTPSProxyProcedureEndpoint::takeReply(void *reply, int64_t numSec)
{
	ReturnMessage returnedValue = CLIENT_INTERNAL_ERROR;
	eprosima::fastrtps::SampleInfo_t info;

	if(reply != NULL)
	{
		cout << "Blocking to take reply "<<numSec << std::endl;
		boost::unique_lock<boost::mutex> lock(*recv_mutex_);
		RecvPoint recvpoint(reply);
		recv_threads.insert(std::pair<int64_t, RecvPoint&>(numSec, recvpoint));
		std::cout << "WAITING for sample: "<<numSec<<std::endl;
		if(recvpoint.cond_.wait_for(lock, boost::chrono::milliseconds(m_transport.getTimeout())) != boost::cv_status::timeout)
		{
			returnedValue = OK;

		}
		else
		{
			returnedValue = TIMEOUT;
			std::cout << "SAMPLE: "<< numSec << "TIMEOUT"<< std::endl;
		}

		std::map<int64_t, RecvPoint&>::iterator it = recv_threads.find(numSec);

		if(it != recv_threads.end())
		{
			recv_threads.erase(it);
		}
	}

	return returnedValue;
}

void RTPSProxyProcedureEndpoint::addAsyncTask(RTPSAsyncTask *task, int64_t numSec)
{
	boost::unique_lock<boost::mutex> lock(*recv_mutex_);
	RecvPoint *recvpoint = new RecvPoint(task);
	recv_threads.insert(std::pair<int64_t, RecvPoint&>(numSec, *recvpoint));
}

void RTPSProxyProcedureEndpoint::onNewDataMessage(eprosima::fastrtps::Subscriber *sub)
{
	eprosima::fastrtps::SampleInfo_t info;

	boost::unique_lock<boost::mutex> lock(*recv_mutex_);

	if(sub->takeNextData(data_, &info))
	{
		if(info.sampleKind == eprosima::fastrtps::ALIVE)
		{

			eprosima::rpc::protocol::dds::rpc::ReplyHeader *replyHeader = reinterpret_cast<eprosima::rpc::protocol::dds::rpc::ReplyHeader*>(data_);

			if(replyHeader->relatedRequestId().writer_guid().guidPrefix()[0] == m_proxyId.guidPrefix()[0] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[1] == m_proxyId.guidPrefix()[1] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[2] == m_proxyId.guidPrefix()[2] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[3] == m_proxyId.guidPrefix()[3] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[4] == m_proxyId.guidPrefix()[4] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[5] == m_proxyId.guidPrefix()[5] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[6] == m_proxyId.guidPrefix()[6] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[7] == m_proxyId.guidPrefix()[7] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[8] == m_proxyId.guidPrefix()[8] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[9] == m_proxyId.guidPrefix()[9] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[10] == m_proxyId.guidPrefix()[10] &&
					replyHeader->relatedRequestId().writer_guid().guidPrefix()[11] == m_proxyId.guidPrefix()[11] &&
					replyHeader->relatedRequestId().writer_guid().entityId().entityKey()[0] == m_proxyId.entityId().entityKey()[0] &&
					replyHeader->relatedRequestId().writer_guid().entityId().entityKey()[1] == m_proxyId.entityId().entityKey()[1] &&
					replyHeader->relatedRequestId().writer_guid().entityId().entityKey()[2] == m_proxyId.entityId().entityKey()[2] &&
					replyHeader->relatedRequestId().writer_guid().entityId().entityKind() == m_proxyId.entityId().entityKind())
			{
				int64_t numSec = replyHeader->relatedRequestId().sequence_number().high();

				numSec <<= 32;
				numSec &= 0xFFFFFFFF00000000;
				numSec += replyHeader->relatedRequestId().sequence_number().low();
				std::cout << "Received: "<< numSec << std::endl;

				std::map<int64_t, RecvPoint&>::iterator it = recv_threads.find(numSec);
				bool aux = false;
				while(it == recv_threads.end())
				{
					std::cout << "Unlocking for sample"<<numSec << std::endl;
					if(!aux)
						recv_mutex_->unlock();
					std::cout << "Sleeping "<<numSec <<std::endl;
					boost::this_thread::sleep(boost::posix_time::milliseconds(1));
					it= recv_threads.find(numSec);
					aux = true;
				}
				if(aux)
					recv_mutex_->lock();

				if(it != recv_threads.end())
				{
					m_copy_data(it->second.getReply(), data_);

					if(it->second.getTask() == NULL)
					{
						it->second.cond_.notify_one();
					}
					else
					{
						RecvPoint *rp = &it->second;
						recv_threads.erase(it);
						RTPSAsyncTask *task = rp->getTask();
						delete rp;
						lock.unlock();
						task->execute();
					}
				}
			}
		}
	}
}

void RTPSProxyProcedureEndpoint::onSubscriptionMatched(eprosima::fastrtps::Subscriber* /*sub*/, eprosima::fastrtps::rtps::MatchingInfo& info)
{
	boost::upgrade_lock<boost::shared_mutex> lock(*matched_mutex_);
	boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);

	if(info.status == MatchingStatus::MATCHED_MATCHING)
	{
		++num_matched_sub_;
		if(num_matched_sub_ == 1)
			matched_sub_cond_->notify_all();
	}
	else
	{
		--num_matched_sub_;
	}
}

void RTPSProxyProcedureEndpoint::onPublicationMatched(eprosima::fastrtps::Publisher* /*pub*/, eprosima::fastrtps::rtps::MatchingInfo& info)
{
	boost::upgrade_lock<boost::shared_mutex> lock(*matched_mutex_);
	boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);

	if(info.status == MatchingStatus::MATCHED_MATCHING)
	{
		++num_matched_pub_;
		if(num_matched_pub_ == 1)
			matched_pub_cond_->notify_all();
	}
	else
	{
		--num_matched_pub_;
	}
}
