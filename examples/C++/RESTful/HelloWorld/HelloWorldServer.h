/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldServer.h
 * This header file contains the declaration of the server for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _HelloWorldSERVER_H_
#define _HelloWorldSERVER_H_

#include "server/Server.h"
#include "HelloWorldServerImpl.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            class HelloWorldProtocol;
        }
    }
}

/**
 * \brief This class implements a specific server for the defined interface HelloWorldResource by user.
 */
class HelloWorldResourceServer : public eprosima::rpcdds::server::Server
{
    public:

        /**
         * \brief This constructor sets the transport that will be used by the server.
         *
         * \param serviceName The service's name that proxies will use to connect with the server.
         * \param strategy Strategy used by server to work with new requests.
         *        This class doesn't delete this object in its destructor. Cannot be NULL.
         * \param transport The network transport that server has to use.
         *        This transport's object is not deleted by this class in its destrcutor. Cannot be NULL.
         * \param servant Servant that server will use to invoke user's functions.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0.
         * \exception eProsima::RPCDDS::InitializeException This exception is thrown when the initialization was wrong.
         */
        HelloWorldResourceServer(eprosima::rpcdds::strategy::ServerStrategy &strategy, eprosima::rpcdds::transport::ServerTransport &transport,
            eprosima::rpcdds::protocol::HelloWorldProtocol &protocol, HelloWorldResourceServerImpl &servant);

        /// \brief The default destructor.
        virtual ~HelloWorldResourceServer();




        
     private:
        
        /// \brief Pointer to the server's servant implemented by the user.
        HelloWorldResourceServerImpl &_impl;
};


#endif // _HelloWorldSERVER_H_