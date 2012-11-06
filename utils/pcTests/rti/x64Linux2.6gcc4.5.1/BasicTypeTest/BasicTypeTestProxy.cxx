/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */


#include "BasicTypeTestProxy.h"
#include "client/ClientRPC.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "BasicTypeTestRequestReplyPlugin.h"
#include "BasicTypeTestAsyncSupport.h"
#include "exceptions/Exceptions.h"

BasicTypeTestProxy::BasicTypeTestProxy(int domainId, long timeout) :
    Client(NULL, domainId, timeout)
{
    createRPCs();
}

BasicTypeTestProxy::BasicTypeTestProxy(eProsima::DDSRPC::Transport *transport, int domainId, long timeout) :
    Client(transport, domainId, timeout)
{
    createRPCs();
}

BasicTypeTestProxy::~BasicTypeTestProxy()
{
    delete getOctet_Service;
    delete getChar_Service;
    delete getWChar_Service;
    delete getShort_Service;
    delete getUShort_Service;
    delete getLong_Service;
    delete getULong_Service;
    delete getLLong_Service;
    delete getULLong_Service;
    delete getFloat_Service;
    delete getDouble_Service;
    delete getBoolean_Service;
}

void BasicTypeTestProxy::createRPCs()
{
    this->getOctet_Service = new getOctetClientRPC("getOctet",
                                  getOctetRequestUtils::registerType(getParticipant()),
                                  getOctetReplyUtils::registerType(getParticipant()),
                                  this);
    this->getChar_Service = new getCharClientRPC("getChar",
                                  getCharRequestUtils::registerType(getParticipant()),
                                  getCharReplyUtils::registerType(getParticipant()),
                                  this);
    this->getWChar_Service = new getWCharClientRPC("getWChar",
                                  getWCharRequestUtils::registerType(getParticipant()),
                                  getWCharReplyUtils::registerType(getParticipant()),
                                  this);
    this->getShort_Service = new getShortClientRPC("getShort",
                                  getShortRequestUtils::registerType(getParticipant()),
                                  getShortReplyUtils::registerType(getParticipant()),
                                  this);
    this->getUShort_Service = new getUShortClientRPC("getUShort",
                                  getUShortRequestUtils::registerType(getParticipant()),
                                  getUShortReplyUtils::registerType(getParticipant()),
                                  this);
    this->getLong_Service = new getLongClientRPC("getLong",
                                  getLongRequestUtils::registerType(getParticipant()),
                                  getLongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getULong_Service = new getULongClientRPC("getULong",
                                  getULongRequestUtils::registerType(getParticipant()),
                                  getULongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getLLong_Service = new getLLongClientRPC("getLLong",
                                  getLLongRequestUtils::registerType(getParticipant()),
                                  getLLongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getULLong_Service = new getULLongClientRPC("getULLong",
                                  getULLongRequestUtils::registerType(getParticipant()),
                                  getULLongReplyUtils::registerType(getParticipant()),
                                  this);
    this->getFloat_Service = new getFloatClientRPC("getFloat",
                                  getFloatRequestUtils::registerType(getParticipant()),
                                  getFloatReplyUtils::registerType(getParticipant()),
                                  this);
    this->getDouble_Service = new getDoubleClientRPC("getDouble",
                                  getDoubleRequestUtils::registerType(getParticipant()),
                                  getDoubleReplyUtils::registerType(getParticipant()),
                                  this);
    this->getBoolean_Service = new getBooleanClientRPC("getBoolean",
                                  getBooleanRequestUtils::registerType(getParticipant()),
                                  getBooleanReplyUtils::registerType(getParticipant()),
                                  this);

}

 
DDS_Octet BasicTypeTestProxy::getOctet(/*in*/ DDS_Octet oc1, /*inout*/ DDS_Octet& oc2, /*out*/ DDS_Octet& oc3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Octet  getOctet_ret = 0;    
    getOctetRequest instance;
    getOctetReply retInstance;

    getOctetReply_initialize(&retInstance);    
    getOctetRequestUtils::setTypeData(instance, oc1, oc2);
    retcode = getOctet_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getOctetReplyUtils::extractTypeData(retInstance, retcode, oc2, oc3, getOctet_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getOctet_ret;
}
 
DDS_Char BasicTypeTestProxy::getChar(/*in*/ DDS_Char ch1, /*inout*/ DDS_Char& ch2, /*out*/ DDS_Char& ch3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Char  getChar_ret = 0;    
    getCharRequest instance;
    getCharReply retInstance;

    getCharReply_initialize(&retInstance);    
    getCharRequestUtils::setTypeData(instance, ch1, ch2);
    retcode = getChar_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getCharReplyUtils::extractTypeData(retInstance, retcode, ch2, ch3, getChar_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getChar_ret;
}
 
DDS_Wchar BasicTypeTestProxy::getWChar(/*in*/ DDS_Wchar wch1, /*inout*/ DDS_Wchar& wch2, /*out*/ DDS_Wchar& wch3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Wchar  getWChar_ret = 0;    
    getWCharRequest instance;
    getWCharReply retInstance;

    getWCharReply_initialize(&retInstance);    
    getWCharRequestUtils::setTypeData(instance, wch1, wch2);
    retcode = getWChar_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getWCharReplyUtils::extractTypeData(retInstance, retcode, wch2, wch3, getWChar_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getWChar_ret;
}
 
DDS_Short BasicTypeTestProxy::getShort(/*in*/ DDS_Short sh1, /*inout*/ DDS_Short& sh2, /*out*/ DDS_Short& sh3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Short  getShort_ret = 0;    
    getShortRequest instance;
    getShortReply retInstance;

    getShortReply_initialize(&retInstance);    
    getShortRequestUtils::setTypeData(instance, sh1, sh2);
    retcode = getShort_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getShortReplyUtils::extractTypeData(retInstance, retcode, sh2, sh3, getShort_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getShort_ret;
}
 
DDS_UnsignedShort BasicTypeTestProxy::getUShort(/*in*/ DDS_UnsignedShort ush1, /*inout*/ DDS_UnsignedShort& ush2, /*out*/ DDS_UnsignedShort& ush3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_UnsignedShort  getUShort_ret = 0;    
    getUShortRequest instance;
    getUShortReply retInstance;

    getUShortReply_initialize(&retInstance);    
    getUShortRequestUtils::setTypeData(instance, ush1, ush2);
    retcode = getUShort_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getUShortReplyUtils::extractTypeData(retInstance, retcode, ush2, ush3, getUShort_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getUShort_ret;
}
 
DDS_Long BasicTypeTestProxy::getLong(/*in*/ DDS_Long lo1, /*inout*/ DDS_Long& lo2, /*out*/ DDS_Long& lo3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Long  getLong_ret = 0;    
    getLongRequest instance;
    getLongReply retInstance;

    getLongReply_initialize(&retInstance);    
    getLongRequestUtils::setTypeData(instance, lo1, lo2);
    retcode = getLong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getLongReplyUtils::extractTypeData(retInstance, retcode, lo2, lo3, getLong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getLong_ret;
}
 
DDS_UnsignedLong BasicTypeTestProxy::getULong(/*in*/ DDS_UnsignedLong ulo1, /*inout*/ DDS_UnsignedLong& ulo2, /*out*/ DDS_UnsignedLong& ulo3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_UnsignedLong  getULong_ret = 0;    
    getULongRequest instance;
    getULongReply retInstance;

    getULongReply_initialize(&retInstance);    
    getULongRequestUtils::setTypeData(instance, ulo1, ulo2);
    retcode = getULong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getULongReplyUtils::extractTypeData(retInstance, retcode, ulo2, ulo3, getULong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getULong_ret;
}
 
DDS_LongLong BasicTypeTestProxy::getLLong(/*in*/ DDS_LongLong llo1, /*inout*/ DDS_LongLong& llo2, /*out*/ DDS_LongLong& llo3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_LongLong  getLLong_ret = 0;    
    getLLongRequest instance;
    getLLongReply retInstance;

    getLLongReply_initialize(&retInstance);    
    getLLongRequestUtils::setTypeData(instance, llo1, llo2);
    retcode = getLLong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getLLongReplyUtils::extractTypeData(retInstance, retcode, llo2, llo3, getLLong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getLLong_ret;
}
 
DDS_UnsignedLongLong BasicTypeTestProxy::getULLong(/*in*/ DDS_UnsignedLongLong ullo1, /*inout*/ DDS_UnsignedLongLong& ullo2, /*out*/ DDS_UnsignedLongLong& ullo3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_UnsignedLongLong  getULLong_ret = 0;    
    getULLongRequest instance;
    getULLongReply retInstance;

    getULLongReply_initialize(&retInstance);    
    getULLongRequestUtils::setTypeData(instance, ullo1, ullo2);
    retcode = getULLong_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getULLongReplyUtils::extractTypeData(retInstance, retcode, ullo2, ullo3, getULLong_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getULLong_ret;
}
 
DDS_Float BasicTypeTestProxy::getFloat(/*in*/ DDS_Float fl1, /*inout*/ DDS_Float& fl2, /*out*/ DDS_Float& fl3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Float  getFloat_ret = 0;    
    getFloatRequest instance;
    getFloatReply retInstance;

    getFloatReply_initialize(&retInstance);    
    getFloatRequestUtils::setTypeData(instance, fl1, fl2);
    retcode = getFloat_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getFloatReplyUtils::extractTypeData(retInstance, retcode, fl2, fl3, getFloat_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getFloat_ret;
}
 
DDS_Double BasicTypeTestProxy::getDouble(/*in*/ DDS_Double do1, /*inout*/ DDS_Double& do2, /*out*/ DDS_Double& do3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Double  getDouble_ret = 0;    
    getDoubleRequest instance;
    getDoubleReply retInstance;

    getDoubleReply_initialize(&retInstance);    
    getDoubleRequestUtils::setTypeData(instance, do1, do2);
    retcode = getDouble_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getDoubleReplyUtils::extractTypeData(retInstance, retcode, do2, do3, getDouble_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getDouble_ret;
}
 
DDS_Boolean BasicTypeTestProxy::getBoolean(/*in*/ DDS_Boolean bo1, /*inout*/ DDS_Boolean& bo2, /*out*/ DDS_Boolean& bo3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    DDS_Boolean  getBoolean_ret = RTI_FALSE;    
    getBooleanRequest instance;
    getBooleanReply retInstance;

    getBooleanReply_initialize(&retInstance);    
    getBooleanRequestUtils::setTypeData(instance, bo1, bo2);
    retcode = getBoolean_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        getBooleanReplyUtils::extractTypeData(retInstance, retcode, bo2, bo3, getBoolean_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_ERROR:
            throw eProsima::DDSRPC::ServerException("Error in server side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
    };
    

    return getBoolean_ret;
}

 
void BasicTypeTestProxy::getOctet_async(BasicTypeTest_getOctet &obj, /*in*/ DDS_Octet oc1, /*inout*/ DDS_Octet oc2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getOctetRequest instance;
    BasicTypeTest_getOctetTask *task = NULL;
    getOctetRequestUtils::setTypeData(instance, oc1, oc2);
    task = new BasicTypeTest_getOctetTask(obj, this);
    retcode = getOctet_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getChar_async(BasicTypeTest_getChar &obj, /*in*/ DDS_Char ch1, /*inout*/ DDS_Char ch2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getCharRequest instance;
    BasicTypeTest_getCharTask *task = NULL;
    getCharRequestUtils::setTypeData(instance, ch1, ch2);
    task = new BasicTypeTest_getCharTask(obj, this);
    retcode = getChar_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getWChar_async(BasicTypeTest_getWChar &obj, /*in*/ DDS_Wchar wch1, /*inout*/ DDS_Wchar wch2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getWCharRequest instance;
    BasicTypeTest_getWCharTask *task = NULL;
    getWCharRequestUtils::setTypeData(instance, wch1, wch2);
    task = new BasicTypeTest_getWCharTask(obj, this);
    retcode = getWChar_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getShort_async(BasicTypeTest_getShort &obj, /*in*/ DDS_Short sh1, /*inout*/ DDS_Short sh2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getShortRequest instance;
    BasicTypeTest_getShortTask *task = NULL;
    getShortRequestUtils::setTypeData(instance, sh1, sh2);
    task = new BasicTypeTest_getShortTask(obj, this);
    retcode = getShort_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getUShort_async(BasicTypeTest_getUShort &obj, /*in*/ DDS_UnsignedShort ush1, /*inout*/ DDS_UnsignedShort ush2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getUShortRequest instance;
    BasicTypeTest_getUShortTask *task = NULL;
    getUShortRequestUtils::setTypeData(instance, ush1, ush2);
    task = new BasicTypeTest_getUShortTask(obj, this);
    retcode = getUShort_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getLong_async(BasicTypeTest_getLong &obj, /*in*/ DDS_Long lo1, /*inout*/ DDS_Long lo2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getLongRequest instance;
    BasicTypeTest_getLongTask *task = NULL;
    getLongRequestUtils::setTypeData(instance, lo1, lo2);
    task = new BasicTypeTest_getLongTask(obj, this);
    retcode = getLong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getULong_async(BasicTypeTest_getULong &obj, /*in*/ DDS_UnsignedLong ulo1, /*inout*/ DDS_UnsignedLong ulo2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getULongRequest instance;
    BasicTypeTest_getULongTask *task = NULL;
    getULongRequestUtils::setTypeData(instance, ulo1, ulo2);
    task = new BasicTypeTest_getULongTask(obj, this);
    retcode = getULong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getLLong_async(BasicTypeTest_getLLong &obj, /*in*/ DDS_LongLong llo1, /*inout*/ DDS_LongLong llo2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getLLongRequest instance;
    BasicTypeTest_getLLongTask *task = NULL;
    getLLongRequestUtils::setTypeData(instance, llo1, llo2);
    task = new BasicTypeTest_getLLongTask(obj, this);
    retcode = getLLong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getULLong_async(BasicTypeTest_getULLong &obj, /*in*/ DDS_UnsignedLongLong ullo1, /*inout*/ DDS_UnsignedLongLong ullo2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getULLongRequest instance;
    BasicTypeTest_getULLongTask *task = NULL;
    getULLongRequestUtils::setTypeData(instance, ullo1, ullo2);
    task = new BasicTypeTest_getULLongTask(obj, this);
    retcode = getULLong_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getFloat_async(BasicTypeTest_getFloat &obj, /*in*/ DDS_Float fl1, /*inout*/ DDS_Float fl2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getFloatRequest instance;
    BasicTypeTest_getFloatTask *task = NULL;
    getFloatRequestUtils::setTypeData(instance, fl1, fl2);
    task = new BasicTypeTest_getFloatTask(obj, this);
    retcode = getFloat_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getDouble_async(BasicTypeTest_getDouble &obj, /*in*/ DDS_Double do1, /*inout*/ DDS_Double do2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getDoubleRequest instance;
    BasicTypeTest_getDoubleTask *task = NULL;
    getDoubleRequestUtils::setTypeData(instance, do1, do2);
    task = new BasicTypeTest_getDoubleTask(obj, this);
    retcode = getDouble_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void BasicTypeTestProxy::getBoolean_async(BasicTypeTest_getBoolean &obj, /*in*/ DDS_Boolean bo1, /*inout*/ DDS_Boolean bo2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_ERROR;
    getBooleanRequest instance;
    BasicTypeTest_getBooleanTask *task = NULL;
    getBooleanRequestUtils::setTypeData(instance, bo1, bo2);
    task = new BasicTypeTest_getBooleanTask(obj, this);
    retcode = getBoolean_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_ERROR:
            throw eProsima::DDSRPC::ClientException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}