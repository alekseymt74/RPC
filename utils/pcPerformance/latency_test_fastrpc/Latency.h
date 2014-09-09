/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * _LICENSE file included in this  distribution.
 *
 *************************************************************************
 * 
 * @file Latency.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _Latency_H_
#define _Latency_H_

// TODO Poner en el contexto.
#include "fastrpc/exceptions/UserException.h"

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

namespace eprosima
{
    namespace fastcdr
    {
        class FastCdr;
    }
}
typedef std::string cadena;
/*!
 * @brief This class represents the interface Latency defined by the user in the IDL file.
 * @ingroup LATENCY
 */
namespace Latency
{
}

#endif // _Latency_H_