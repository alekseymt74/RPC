/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcrest_LICENSE file included in this rpcrest distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcrestgen.
 */

#include "HelloWorldProxy.h"
#include "HelloWorld.h"
#include "HelloWorldRESTProtocol.h"
#include "rpcrest/transports/HttpProxyTransport.h"
#include "rpcrest/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace eprosima::rpc::exception;
using namespace eprosima::rpc::transport;
using namespace eprosima::rpc::protocol::rest;

int main(int argc, char **argv)
{
    HelloWorldProtocol *protocol = NULL;
    ProxyTransport *transport = NULL;
    HelloWorld::HelloWorldResourceProxy *proxy = NULL;
    
    // Creation of the proxy for interface "HelloWorld::HelloWorldResource".
    try
    {
        protocol = new HelloWorldProtocol();
        transport = new HttpProxyTransport("127.0.0.1:8080");
        proxy = new HelloWorld::HelloWorldResourceProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    // Create and initialize parameters.
    std::string  name = "Richard";

    // Create and initialize return value.
    HelloWorld::HelloWorldResource::HelloResponse  hello_ret;


    // Call to remote procedure "hello".
    try
    {
        hello_ret = proxy->hello(name);

		if(hello_ret._d() == 1)
        {
			std::cout << hello_ret.xmlHelloResponse().xmlRepresentation() << std::endl;
		}
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    



    
    delete(proxy);
    delete(transport);
    delete(protocol);
   
    return 0;
}



