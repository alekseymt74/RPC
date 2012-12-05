/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file Client.cxx
 * This source file shows a simple example of how to create a proxy for interface SimpleDelay.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "SimpleDelayProxy.h"
#include "SimpleDelayRequestReplyPlugin.h"
#include "transports/UDPTransport.h"
#include "exceptions/Exceptions.h"

#include <iostream>
#include <boost/chrono.hpp>

int main(int argc, char **argv)
{
    boost::chrono::duration<double> suma_call_seconds[10000];
    boost::chrono::duration<double> duplicate_call_seconds[10000];
    boost::chrono::duration<double> suma_procedure_seconds;
    boost::chrono::duration<double> duplicate_procedure_seconds;
    boost::chrono::duration<double> program_seconds;

    if(argc == 2)
    {
        uint8_t ip[4];

        // Check that the parameter is a IP address.
        if(sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]) == 4)
        {
            eProsima::RPCDDS::UDPTransport *udpt = NULL;
            SimpleDelayProxy *proxy = NULL;

            // Creation of the proxy for interface "SimpleDelay".
            try
            {
                udpt = new eProsima::RPCDDS::UDPTransport(argv[1]);
                proxy = new SimpleDelayProxy("SimpleDelayService", udpt);
            }
            catch(eProsima::RPCDDS::InitializeException &ex)
            {
                std::cout << ex.what() << std::endl;
                return -1;
            }

            sleep(10);

            boost::chrono::system_clock::time_point program_start = boost::chrono::system_clock::now();

            boost::chrono::system_clock::time_point procedure_start = boost::chrono::system_clock::now();
            // Testing suma procedure.
            /*for(int i = 0; i < 10000; ++i)
            {
                boost::chrono::system_clock::time_point call_start = boost::chrono::system_clock::now();
                int32_t result = proxy->suma(10, i);
                suma_call_seconds[i] = boost::chrono::system_clock::now() - call_start;
            }*/

            suma_procedure_seconds = boost::chrono::system_clock::now() - procedure_start;

            procedure_start = boost::chrono::system_clock::now();
            // Testing ducplicate procedure.
            for(int i = 0; i < 10000; ++i)
            {
                Estructura es, ret;
                Estructura_initialize(&es);
                es.valor1 = i;
                es.valor2 = i*2;
                es.valor3 = "Esto es una prueba para el test de performance rpcdds vs thrift vs rpcdds";
                es.seq.ensure_length(500, 500);
                for(int i = 0; i < 500; ++i)
                    es.seq[i] = i;

                boost::chrono::system_clock::time_point call_start = boost::chrono::system_clock::now();
                ret = proxy->duplicate(es);
                duplicate_call_seconds[i] = boost::chrono::system_clock::now() - call_start;
                es.valor3 = NULL;
                Estructura_finalize(&es);
            }

            duplicate_procedure_seconds = boost::chrono::system_clock::now() - procedure_start;

            program_seconds = boost::chrono::system_clock::now() - program_start;

            // Print the suma call times.
            //for(int i = 0; i < 10000; ++i)
            //    std::cout << i << " > suma in " << suma_call_seconds[i].count() << " seconds." << std::endl;
            // Print the all suma procedure time.
            std::cout << "Executed 10000 suma procedures in " << suma_procedure_seconds.count() << " seconds." << std::endl;

            // Print the duplicate call times.
            //for(int i = 0; i < 10000; ++i)
            //    std::cout << i << " > duplicate in " << duplicate_call_seconds[i].count() << " seconds." << std::endl;
            // Print the all duplicate procedure time.
            std::cout << "Executed 10000 duplicate procedures in " << duplicate_procedure_seconds.count() << " seconds." << std::endl;

            // Print total execution time.
            std::cout << "Program execution in " << program_seconds.count() << " seconds." << std::endl;

            delete(proxy);
        }
        else
        {
            std::cout << "Parameter is not a valid IPv4 address." << std::endl;
        }
    }
    else
    {
        std::cout << "The server IP address is expected." << std::endl;
    }

    return 0;
}
