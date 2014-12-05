/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file LatencyDDSProtocol.h
 * This header file contains the declaration of the protocol used to create DDS messages.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Latency_DDS_PROTOCOL_H_
#define _Latency_DDS_PROTOCOL_H_

#include "LatencyProtocol.h"
#include "rpcdds/utils/Messages.h"

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            namespace dds
            {
                class ProxyProcedureEndpoint;
                class ServerProcedureEndpoint;
                class Transport;
            }
        }
        
        namespace protocol
        {
            namespace dds
            {
                /*!
                 * @brief This class is responsible for serializing and deserializing the requests and responses of this application.
                 * It uses DDS.
		         * @ingroup LATENCY
                 */
                class FASTRPCUSERDllExport  LatencyProtocol : public eprosima::rpc::protocol::LatencyProtocol
                {
                    public:
                    
                       /*!
                        * @brief Default constructor
                        */
                        LatencyProtocol();
                        
                       /*!
                        * @brief Destructor
                        */
                        virtual ~LatencyProtocol();
                    
                       /*!
                        * @brief This method sets the transport for the communications.
                        * @param transport Transport to use
                        * @return True if the assignment is successful, false otherwise
                        */
                        virtual bool setTransport(eprosima::rpc::transport::Transport &transport);
                        
                        /*!
                         * @brief This function activates needed DDS entities to use an interface.
                         * @param interfaceName Interface name.
                         * @return Whether the activation works successfully.
                         */
                        bool activateInterface(const char* interfaceName);
                        


                        /*!
                         * @brief This method implements the server part of the protocol for the interface Latency.
                         * It is called when a request sample is received.
                         * @param protocol DDS protocol object that is in used.
                         * @param data Pointer to the received request sample. Cannot be NULL.
                         * @param endpoint Pointer to the endpoint that sent the request reply. Cannot be NULL.
                         */
                        static void Latency_serve(eprosima::rpc::protocol::Protocol &protocol,
                            void *data , eprosima::rpc::transport::Endpoint *endpoint);
                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation latency.
                         * It is called from the Proxy interface.
                         */
                        st Latency_latency(/*in*/ const st& param);

                        /*!
                         * @brief This asynchronous method implements the proxy part of the protocol for the operation latency.
                         * It is called from the Proxy interface.
                         */
                        void Latency_latency_async(Latency_latencyCallbackHandler &obj, /*in*/ const st& param);



                        
                    private:
                    
                        eprosima::rpc::transport::dds::Transport *m_ddsTransport;
                    
                                                const char* const Latency_str;
                                                
                                                eprosima::rpc::transport::dds::ProxyProcedureEndpoint *Latency_pe;
                                                
                                                eprosima::rpc::transport::dds::ServerProcedureEndpoint *Latency_se;
                                                
                                                
                };
            } // namespace dds
        } // namespace protocol
    } // namespace rpc
} // namespace eprosima

#endif // _Latency_DDS_PROTOCOL_H_