/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "MultithreadTestServer.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "MultithreadTestRequestReplyPlugin.h"

#include "MultithreadTestServerRPCSupport.h"

MultithreadTestServerH::MultithreadTestServerH(eProsima::DDSRPC::ServerStrategy *strategy,
    eProsima::DDSRPC::Transport *transport, int domainId) :
    Server(strategy, transport, domainId)
{
    _impl = new MultithreadTestServerImpl();
    
    this->setRPC(new testServerRPC("test", this,
                testRequestUtils::registerType(getParticipant()),
                testReplyUtils::registerType(getParticipant()),
                &MultithreadTestServerH::test, getParticipant()));

}
MultithreadTestServerH::~MultithreadTestServerH()
{
    delete _impl;    
}

void MultithreadTestServerH::test(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    MultithreadTestServerH *srv = dynamic_cast<MultithreadTestServerH*>(server);
    Dato *dato1 = NULL;    
    Dato *dato2 = DatoPluginSupport_create_data();    
    DDS_Long  test_ret = 0;      
    eProsima::DDSRPC::ReturnMessage  returnedValue = eProsima::DDSRPC::OPERATION_SUCCESSFUL;        
    testReply *replyData = NULL;

    testRequestUtils::extractTypeData((testRequest*)requestData, dato1  );

returnedValue = srv->_impl->test(dato1  , dato2  , test_ret  );

    replyData = testReplyUtils::createTypeData(dato2  , test_ret  );

    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);

    testReplyTypeSupport::delete_data(replyData);
    
    testRequestTypeSupport::delete_data((testRequest*)requestData);
    
    DatoPluginSupport_destroy_data(dato2);    
        
}

MultithreadTestServer::MultithreadTestServer(eProsima::DDSRPC::ServerStrategy *strategy,
    int domainId) :
    MultithreadTestServerH(strategy, new eProsima::DDSRPC::UDPTransport(), domainId)
{
}
MultithreadTestServer::~MultithreadTestServer()
{   
}

MultithreadTestWANServer::MultithreadTestWANServer(eProsima::DDSRPC::ServerStrategy *strategy,
    const char *public_address, const char *server_bind_port,
    int domainId) :
    MultithreadTestServerH(strategy, new eProsima::DDSRPC::TCPTransport(public_address, server_bind_port), domainId)
{
}
MultithreadTestWANServer::~MultithreadTestWANServer()
{   
}