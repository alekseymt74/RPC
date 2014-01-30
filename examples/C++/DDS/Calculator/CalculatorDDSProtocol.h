/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorDDSProtocol.h
 * This header file contains the declaration of the protocol used to create DDS messages.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_DDS_PROTOCOL_H_
#define _Calculator_DDS_PROTOCOL_H_

#include "CalculatorProtocol.h"
#include "rpcdds/utils/Messages.h"
namespace eprosima
{
    namespace rpcdds
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
                 *  It uses DDS.
                 */
                class RPCDDSUSERDllExport  CalculatorProtocol : public eprosima::rpcdds::protocol::CalculatorProtocol
                {
                    public:
                    
                       /*!
                        * @brief Default constructor
                        */
                        CalculatorProtocol();
                        
                       /*!
                        * @brief Default destructor
                        */
                        virtual ~CalculatorProtocol();
                    
                       /*!
                        * @brief This method sets the transport for the communications.
                        * @param transport Transport to use
                        * @return True if the assignment is successful, false otherwise
                        */
                        virtual bool setTransport(eprosima::rpcdds::transport::Transport &transport);
                        
                        bool activateInterface(const char* interfaceName);
                        
                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation addition
                         */
                        DDS_Long Calculator_addition(/*in*/ DDS_Long value1, /*in*/ DDS_Long value2);

                        void Calculator_addition_async(Calculator_additionCallbackHandler &obj, /*in*/ DDS_Long value1, /*in*/ DDS_Long value2);

                        /*!
                         * @brief This method implements the server part of the protocol for the operation addition
                         */
                        static void Calculator_addition_serve(eprosima::rpcdds::protocol::Protocol &protocol,
                            void *data , eprosima::rpcdds::transport::Endpoint *endpoint);
                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation subtraction
                         */
                        DDS_Long Calculator_subtraction(/*in*/ DDS_Long value1, /*in*/ DDS_Long value2);

                        void Calculator_subtraction_async(Calculator_subtractionCallbackHandler &obj, /*in*/ DDS_Long value1, /*in*/ DDS_Long value2);

                        /*!
                         * @brief This method implements the server part of the protocol for the operation subtraction
                         */
                        static void Calculator_subtraction_serve(eprosima::rpcdds::protocol::Protocol &protocol,
                            void *data , eprosima::rpcdds::transport::Endpoint *endpoint);

                        
                    private:
                    
                        eprosima::rpcdds::transport::dds::Transport *m_ddsTransport;
                    
                                                                        const char* const Calculator_addition_str;
                                                                        
                                                                        eprosima::rpcdds::transport::dds::ProxyProcedureEndpoint *Calculator_addition_pe;
                                                                        
                                                                        eprosima::rpcdds::transport::dds::ServerProcedureEndpoint *Calculator_addition_se;
                                                                        
                                                                        
                                                                        const char* const Calculator_subtraction_str;
                                                                        
                                                                        eprosima::rpcdds::transport::dds::ProxyProcedureEndpoint *Calculator_subtraction_pe;
                                                                        
                                                                        eprosima::rpcdds::transport::dds::ServerProcedureEndpoint *Calculator_subtraction_se;
                                                                        
                                                                        
                                                
                };
            } // namespace dds
        } // namespace protocol
    } // namespace rpcdds
} // namespace eprosima

#endif // _Calculator_DDS_PROTOCOL_H_