// utility.h
//	Miscellaneous useful definitions.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#ifndef UTILITY_H
#define UTILITY_H

#include "copyright.h"

// Miscellaneous useful routines

#define NULL 0
#define TRUE true
#define FALSE false
// #define bool int		// necessary on the Mac?

// NOTE: 原本這裡有 min/max 巨集，會污染現代 libstdc++ 的 <string_view>：
//   std::min(...) 被展開成 std::(((a) < (b)) ? ...) → expected unqualified-id
// 這兩個巨集在 NachOS 程式碼中沒有被使用，因此移除；
// 若之後需要，請用 std::min / std::max。

// Divide and either round up or down
#define divRoundDown(n, s) ((n) / (s))
#define divRoundUp(n, s) (((n) / (s)) + ((((n) % (s)) > 0) ? 1 : 0))

// This declares the type "VoidFunctionPtr" to be a "pointer to a
// function taking an arbitrary pointer argument and returning nothing".  With
// such a function pointer (say it is "func"), we can call it like this:
//
//	(*func) ("help!");
//
// This is used by Thread::Fork as well as a couple of other places.

typedef void (*VoidFunctionPtr)(void *arg);
typedef void (*VoidNoArgFunctionPtr)();

#endif  // UTILITY_H
