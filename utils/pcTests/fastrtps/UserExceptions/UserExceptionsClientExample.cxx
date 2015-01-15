/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file UserExceptionsClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "UserExceptionsProxy.h"
#include "UserExceptions.h"
#include "UserExceptionsDDSProtocol.h"
#include "fastrpc/transports/dds/RTPSProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>
#ifdef __linux
#include <unistd.h>
#endif

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    UserExceptionsProtocol *protocol = NULL;
    RTPSProxyTransport *transport = NULL;
    Beta::IfcProxy *proxy = NULL;
    
    // Creation of the proxy for interface "Beta::Ifc".
    try
    {
        protocol = new UserExceptionsProtocol();
        transport = new RTPSProxyTransport("UserExceptionsService", "Instance");
        proxy = new Beta::IfcProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        _exit(-1);
    }
    
    // Create and initialize parameters.
    int32_t  l1 = 10;
    int32_t  l2 = 2;
    int32_t  l3 = 120;
    int32_t  ret = 0;


    // Call to remote procedure "sendLevel1".
    try
    {
        proxy->sendLevel1(l1, l2, l3);
        std::cout << "TEST FAILED<sendLevel1>: Not catch user exception" << std::endl;
        _exit(-1);
    }
    catch(Level1 &ex)
    {
        if((ex.count() != l1) || (ex.msg().compare("sendLevel1") != 0))
        {
            std::cout << "TEST FAILED<sendLevel1>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendLevel1>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendLevel1>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }
    
    // Call to remote procedure "sendLevel2".
    try
    {
        ret = proxy->sendLevel2();
        std::cout << "TEST FAILED<sendLevel2>: Not catch user exception" << std::endl;
        _exit(-1);
    }
    catch(Alfa::Level2 &ex)
    {
        if((ex.count() != 101) || (ex.ana().count() != 102) || (ex.ana().comment().compare("sendLevel2") != 0))
        {
            std::cout << "TEST FAILED<sendLevel2>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendLevel2>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendLevel2>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }

    // Call to remote procedure "sendExcep".
    try
    {
        ret = proxy->sendExcep(l1);
        std::cout << "TEST FAILED<sendExcep>: Not catch user exception" << std::endl;
        _exit(-1);
    }
    catch(Beta::Excep &ex)
    {
        if((ex.count() != l1) || (ex.msg().compare("sendExcep") != 0))
        {
            std::cout << "TEST FAILED<sendExcep>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendExcep>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendExcep>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }

    // Call to remote procedure "sendExcepIntern".
    try
    {
        ret = proxy->sendExcepIntern(l1);
        std::cout << "TEST FAILED<sendExcepIntern>: Not catch user exception" << std::endl;
        _exit(-1);
    }
    catch(Beta::Ifc::ExcepIntern &ex)
    {
        if((ex.count() != l1) || (ex.msg().compare("sendExcepIntern") != 0))
        {
            std::cout << "TEST FAILED<sendExcepIntern>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendExcepIntern>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendExcepIntern>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }

    // Call to remote procedure "sendOnlyExcep".
    try
    {
        proxy->sendOnlyExcep();
        std::cout << "TEST FAILED<sendOnlyExcep>: Not catch user exception" << std::endl;
        _exit(-1);
    }
    catch(Beta::Excep &ex)
    {
        if((ex.count() != 1) || (ex.msg().compare("sendOnlyExcep") != 0))
        {
            std::cout << "TEST FAILED<sendOnlyExcep>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendOnlyExcep>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendOnlyExcep>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }
    
	printf("TEST SUCCESFULLY\n");

    delete proxy;
    delete transport;
    delete protocol;

	_exit(0);
    return 0;
}









