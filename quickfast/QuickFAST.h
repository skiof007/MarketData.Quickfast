// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.

// This file is intended to be used by external projects that are using the QuickFAST library.
// It is most likely that this file should be included from a precompilable header file in the
// QuickFAST-based application.

#ifdef _MSC_VER
# pragma once
#endif
#ifndef QUICKFAST_H
#define QUICKFAST_H
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Common/Version.h>
#include <quickfast/Common/Decimal.h>
#include <quickfast/Common/StringBuffer.h>
#include <quickfast/Application/DecoderConnection.h>
#include <quickfast/Codecs/XMLTemplateParser.h>
#include <quickfast/Codecs/TemplateRegistry.h>
#include <quickfast/Messages/FieldIdentity.h>
#endif // QUICKFAST_H

#if !defined(QUICKFAST_BUILD_LIB)

	#define QUICKFAST_LIB_NAME "QUICKFAST"

	#if !defined(_MSC_VER)
		#error "Invalid compiler!"
	#else
		#if _MSC_VER >= 1900
			#define QUICKFAST_COMPILER_VERSION "_VC140"
		#elif _MSC_VER >= 1800
			#define QUICKFAST_COMPILER_VERSION "_VC120"
		#elif _MSC_VER >= 1700
			#define QUICKFAST_COMPILER_VERSION "_VC110"
		#elif _MSC_VER >= 1600
			#define QUICKFAST_COMPILER_VERSION "_VC100"
		#elif _MSC_VER >= 1500
			#define QUICKFAST_COMPILER_VERSION "_VC90"
		#else
			#error "Invalid compiler!"
		#endif
	#endif

	#if defined(_M_X64)
		#define QUICKFAST_ARCH_SUFIX "_64"
	#elif defined(_M_IX86)
		#define QUICKFAST_ARCH_SUFIX "_32"
	#else
		#error "Invalid architecture!"
	#endif

	#if defined(_DEBUG)
		#define QUICKFAST_DEBUG_SUFFIX "_d"
	#else
		#define QUICKFAST_DEBUG_SUFFIX "_r"
	#endif

	#if defined(_DLL)
		#define QUICKFAST_RT_SUFIX "_mt_dll"
	#else
		#define QUICKFAST_RT_SUFIX "_mt_static"
	#endif

	#pragma comment(lib, QUICKFAST_LIB_NAME QUICKFAST_COMPILER_VERSION QUICKFAST_ARCH_SUFIX QUICKFAST_DEBUG_SUFFIX QUICKFAST_RT_SUFIX ".lib") 

#endif