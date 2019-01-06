// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef BASETYPES_H
#define BASETYPES_H

#include <cstdint>

typedef float vec_t;

typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef uint32_t uint;

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef unsigned char byte;

#define CHECK_VALID( _v)	(_v).IsValid()

#endif