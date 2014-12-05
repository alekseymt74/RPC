/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastrpc_LICENSE file included in this fastrpc distribution.
 *
 *************************************************************************
 * 
 * @file LatencyClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "LatencyProxy.h"
#include "Latency.h"
#include "LatencyCDRProtocol.h"
#include "fastrpc/transports/TCPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>
#include <sstream>

#ifdef _WIN32
#include "boost/date_time/posix_time/posix_time.hpp"
#else
#include <chrono>
#endif

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport;
using namespace ::protocol::fastcdr;
using namespace std;

void printResultTile()
{
	printf("Samples   ,     Bytes,  Time(us)\n");
	printf("----------,----------,----------\n");
}

void printResult(int samples,int bytes,double res )
{
	printf("%10d,%10d,%10.3f\n",samples, bytes,res);
}

int main(int argc, char **argv)
{
    LatencyProtocol *protocol = NULL;
    TCPProxyTransport *transport = NULL;
    LatencyProxy *proxy = NULL;

	int samples = 10000;
	int bytes = 0;
	string ip = "127.0.0.1";

	if(argc <= 4)
	{

		if(argc > 1) {
			ip = argv[1];
		}

		if(argc > 2) {
			std::istringstream iss1( argv[2] );
			if (!(iss1 >> samples))
			{
				cout << "Problem reading samples number, using default (10000) "<< endl;
				samples = 10000;
			}
		}

		if(argc > 3) {
			std::istringstream iss2( argv[3] );
			if (!(iss2 >> bytes))
			{
				cout << "Problem reading bytes number, using default (1024) "<< endl;
				bytes = 0;
			}
		}
	}
	else
	{
		cout << "usage: " << argv[0] << " [server IP] [samples] [bytes] "<<endl;
		return 0;
	}

#ifdef _WIN32
	// Para calcular el tiempo
	boost::posix_time::ptime m_t1;
	boost::posix_time::ptime m_t2;

	m_t1 = boost::posix_time::microsec_clock::local_time();
	for(int i=0;i<1000;i++)
		m_t2 = boost::posix_time::microsec_clock::local_time();
	double m_overhead = (m_t2 - m_t1).total_microseconds() / 1001;
#else
	// Para calcular el tiempo
	typedef std::chrono::steady_clock Clock;
	typedef std::chrono::microseconds microseconds;

	Clock::time_point m_t1;
	Clock::time_point m_t2;

	m_t1 = Clock::now();
	for(int i=0;i<1000;i++)
		m_t2 = Clock::now();
	double m_overhead = std::chrono::duration_cast<microseconds>(m_t2 - m_t1).count()/1001;

#endif
    
    // Creation of the proxy for interface "Latency".
    try
    {
        protocol = new LatencyProtocol();
		std::string ip_dir(ip + ":8080");
		transport = new TCPProxyTransport(ip_dir.c_str());
        proxy = new LatencyProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

	printResultTile();

    element elm;
    elm.att1(true);
    elm.att2("ABCDEFG");
    elm.att3(65000);
    elm.att4(564);
    elm.att5(false);
    
	if(bytes == 0) {
		//int bytessizes[] = {16,32,64,128,256,512,1024,2048,4096,8192};
		int bytessizes[] = {1,2,4,8,16,32,64,128,256,512};
		std::vector<int> v_bytes (bytessizes, bytessizes + sizeof(bytessizes) / sizeof(uint32_t) );
		for(std::vector<int>::iterator it = v_bytes.begin();it!=v_bytes.end();++it) {

            st payload;
			for(int i = 0; i < *it; ++i) 
            {
                payload.push_back(elm);
			}

#ifdef _WIN32
			m_t1 = boost::posix_time::microsec_clock::local_time();
#else
			m_t1 = Clock::now();
#endif
			int isam = 0;
			for(isam = 0; isam<samples; ++isam) {
			    // Call to remote procedure "latency".
			    try {
				proxy->latency(payload);
			    } catch(SystemException &ex) {
				std::cout << ex.what() << std::endl;
			    }
			}

#ifdef _WIN32
			m_t2 = boost::posix_time::microsec_clock::local_time();
#else
			m_t2 = Clock::now();
#endif

			double result = -1;
			if(isam == samples)
			{
#ifdef _WIN32
				result = ( (m_t2 - m_t1).total_microseconds() - m_overhead) / samples;
#else
				result = (std::chrono::duration_cast<microseconds>(m_t2 - m_t1).count() - m_overhead) / samples;
#endif
			}
			printResult(samples, *it, result);
		}
	} else {

        st payload;
		for(int i = 0; i < bytes; ++i) {
            payload.push_back(elm);
		}

#ifdef _WIN32
		m_t1 = boost::posix_time::microsec_clock::local_time();
#else
		m_t1 = Clock::now();
#endif

		int isam = 0;
		for(isam = 0; isam<samples; ++isam) {
		    // Call to remote procedure "latency".
		    try {
			proxy->latency(payload);
			} catch(SystemException &ex) {
			std::cout << ex.what() << std::endl;
		    }
		}

#ifdef _WIN32
		m_t2 = boost::posix_time::microsec_clock::local_time();
#else
		m_t2 = Clock::now();
#endif

		double result = -1;
		if(isam == samples) {
#ifdef _WIN32
			result = ( (m_t2 - m_t1).total_microseconds() - m_overhead) / samples;
#else
			result = (std::chrono::duration_cast<microseconds>(m_t2 - m_t1).count() - m_overhead) / samples;
#endif
		}
		printResult(samples, bytes, result);
	}
         
    delete proxy;
    delete transport;
    delete protocol;
   
    return 0;
}


