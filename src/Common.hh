#ifndef COMMON_H_
#define COMMON_H_

// Standard C++ Includes
#include <iostream>      // Standard IO
#include <fstream>       // File IO
#include <string>        // Everything strings
#include <unordered_map> // Unordered maps
#include <vector>        // Lists
#include <exception>     // Exception
#include <stdexcept>     // Standard Exceptions, such as std::runtime_error

// Standard C Includes
#include <cstdio>  // Standard IO
#include <cstdlib> // Standard Library
#include <cstdint> // Integer types
#include <cstdarg> // Argument lists

// Other includes
#include <json/json.h> // For everything Json

// Integer types
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;

typedef signed char  s8;
typedef signed short s16;
typedef signed int   s32;
typedef signed long  s64;

// Project definitions
#define DISPLAY_NAME "NR Text Adventure"

#endif // COMMON_H_
