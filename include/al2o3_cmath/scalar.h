// MIT Licensed (for full license see LICENSE file)

/// CMath has no designs on being the fastest, most comprehensive or even most
/// correct maths library.
/// Its one purpose is to be portable, tested and available everywhere.
/// Its for the 'normal' everyday math usage that probably won't need
/// perfect alignment, SIMD or exact precision ulp guarentees. There are plenty
/// of those for those tasks that need that. This however is small, portable
/// and perfect for API interfaces and little bits of portable maths.
///
/// Current scalar.h supports function split into 5 groups
/// * Unsigned
/// * Signed
/// * Real
/// * Unsigned integers
/// * Signed integers
/// | Type | Postfix | Group |
/// | float | F | Real |
/// | double | D | Real |
/// | int8_t | I8 | Signed |
/// | uint8_t | U8 | Unsigned |
/// | int16_t | I16 | Signed |
/// | uint16_t | UI16 | Unsigned |
/// | int32_t | I32 | Signed |
/// | uint32_t | U32 | Unsigned |
/// | int64_t | I64 | Signed |
/// | uint64_t | U64 | Unsigned |
/// | size_t  | SizeT | Unsigned |
/// SizeT is included as some platforms define it different from other types

// Functions supported for unsigned scalar types (float used as exampler)
// ---------
// Math_LerpF(float const a, float const b, float t) = a + (b - a) * t
// Math_MinF(float const v, float const a) = v < a ? v : a
// Math_MaxF(float const v, float const a) = v > a ? v : a
// Math_ClampF(float const v, float const a, float const b) = min(max(v, a), b)
// Math_EqualF(float const a, float const b) = a == b
// Math_RoundUpToF(float const a, float const multiple) = a rounded up to a multiple
//
// Functions supported for signed scale types (float used as exampler), all unsigned plus
// ---------
// Math_AbsF(float const a) = a < 0 ? -a : a
//
// Functions supported for real scalar types (float used as exampler), as signed plus
// ---------
// Math_ApproxEqualF(float const a, float const b, float epsilon) = abs(b - a) < epsilon
// Math_IsNanF(float const in) = isnan(in)
// Math_SaturateF(float const in) = min(max(v, 0), 1)
// Math_PiF() = pi
// Math_PiOver2F() = pi / 2
// Math_TwoPiF() = pi * 2
// Math_DegreesToRadiansF(float const input) = radian version of input angle in degrees
// Math_RadiansToDegreesF(type const input) = degree version of input angle in radians
// Math_ReciprocalF(float const a) = 1 / a
// Math_SignF(float const a) = -1 if a < 0 or 1 if a > 0 or 0 if a == 0
// Math_SqrtF(float const a) sqrt(a)
// Math_ReciprocalSqrtF(float const a) 1 / sqrt(a)

// Functions supported for unsigned integer types (uint32_t used as exampler)
// Math_IsPowerOf2U32(uint32_t const x) = true if x is power of 2, x == 0 return true
// Math_NextPowerOfTwoU32(uint32_t const x) = next power of 2 greater than x, x == 0 returns 1
// Math_ClosestPowerOfTwoU32(uint32_t const x) = closest power of 2 greater or less than x, x == 0, returns 0
// Math_Log2U32(uint32_t const x) = highest bit set in x

/// Additional some functions are not supported across the entire range of types
/// these are for specific (or a few types) so are not autogenerated by the macro
/// system used to build the generic CMath types
// Math_Float2Half(float f) = float in, uint16_t encoded half out
// Math_Half2Float(uint16_t h) = uint16_t encoded half in, float out

/// TODO sqrt functions use system double sqrt for all types needs replacing
/// Some functions can be defined for integer only types, at the moment real
/// use same base functions as integer meaning those can't be easily shared

#pragma once
#ifndef AL2O3_CMATH_SCALAR_H
#define AL2O3_CMATH_SCALAR_H

#include "al2o3_platform/platform.h"
#include <math.h>

AL2O3_EXTERN_C uint8_t Math_LogTable256[256];

#define MATH_FM_CREATE_UNSIGNED(postfix, type) \
AL2O3_LINK_OR_INLINE type Math_Lerp##postfix(type const a, type const b, float t) { return a + (type)((b - a) * t); } \
AL2O3_LINK_OR_INLINE type Math_Min##postfix(type const v, type const a) { return (v < a) ? v : a; } \
AL2O3_LINK_OR_INLINE type Math_Max##postfix(type const v, type const a) { return (v > a) ? v : a; } \
AL2O3_LINK_OR_INLINE type Math_Clamp##postfix(type const v, type const a, type const b) { return Math_Min##postfix(Math_Max##postfix(v, a), b); } \
AL2O3_LINK_OR_INLINE bool Math_Equal##postfix(type const a, type const b) { return a == b; } \
AL2O3_LINK_OR_INLINE type Math_RoundUpTo##postfix(type value, type multiple) { return ((value + multiple - 1) / multiple) * multiple; }

#define MATH_FM_CREATE_SIGNED(postfix, type) \
MATH_FM_CREATE_UNSIGNED(postfix, type) \
AL2O3_LINK_OR_INLINE type Math_Abs##postfix(type const a) { return (a < 0) ? -a : a; }

#define MATH_FM_CREATE_REAL(postfix, type) \
MATH_FM_CREATE_SIGNED(postfix, type) \
AL2O3_LINK_OR_INLINE bool Math_ApproxEqual##postfix(type const a, type const b, type const epsilon) { return (Math_Abs##postfix(b - a) <= epsilon); } \
AL2O3_LINK_OR_INLINE bool Math_IsNan##postfix(type const a) { return a != a; } \
AL2O3_LINK_OR_INLINE type Math_Saturate##postfix(type const x) { return Math_Clamp##postfix(x, (type)0, (type)1); } \
AL2O3_LINK_OR_INLINE type Math_Pi##postfix() { return (type) (3.14159265358979323846264338327950L); } \
AL2O3_LINK_OR_INLINE type Math_PiOver2##postfix() { return Math_Pi##postfix() / 2; } \
AL2O3_LINK_OR_INLINE type Math_TwoPi##postfix() { return 2 * Math_Pi##postfix(); } \
AL2O3_LINK_OR_INLINE type Math_DegreesToRadians##postfix(type const val) { return val * (Math_Pi##postfix() / 180); } \
AL2O3_LINK_OR_INLINE type Math_RadiansToDegrees##postfix(type const val) { return (180 * val) / Math_Pi##postfix(); } \
AL2O3_LINK_OR_INLINE type Math_Reciprocal##postfix(type const a) { return 1 / a; } \
AL2O3_LINK_OR_INLINE int Math_Sign##postfix(type val) { return (0 < val) - (val < 0); } \
AL2O3_LINK_OR_INLINE type Math_Sqrt##postfix(type const a) { return (type)sqrt((double)a); } \
AL2O3_LINK_OR_INLINE type Math_ReciprocalSqrt##postfix(type const a) { return 1 / (type)sqrt((double)a); }

#define MATH_FM_CREATE_UNSIGNED_INTEGER(postfix, type) \
MATH_FM_CREATE_UNSIGNED(postfix, type) \
AL2O3_LINK_OR_INLINE bool Math_IsPowerOf2##postfix(type const x) { return (x & (x - 1)) == 0; } \
AL2O3_LINK_OR_INLINE type Math_NextPowerOfTwo##postfix(type x) { \
  if(x == 0) return 1; \
  x = x - 1; \
  if(sizeof(type) >= 8) { x |= ((uint64_t)x) >> 32; } \
  if(sizeof(type) >= 4) { x |= ((uint32_t)x) >> 16; } \
  if(sizeof(type) >= 2) { x |= ((uint16_t)x) >> 8; } \
  x |= x >> 4; \
  x |= x >> 2; \
  x |= x >> 1; \
  return x + 1; \
} \
AL2O3_LINK_OR_INLINE type Math_ClosestPowerOfTwo##postfix(type const x) { \
  type upow2 = Math_NextPowerOfTwo##postfix(x); \
  if (4 * x < 3 * upow2) return upow2 >> 1; \
  else return upow2; \
} \
AL2O3_LINK_OR_INLINE uint8_t Math_Log2##postfix(type const v) { \
  uint8_t r = 0; \
  type t = v; \
  if(sizeof(type) >= 8) { \
    uint32_t tt = ((uint64_t)t) >> 32; \
    r = r + (tt ? 32 : 0); \
    t = tt ? tt : (t & 0xFFFFFFFF); \
  } \
  if(sizeof(type) >= 4) { \
    uint16_t tt = ((uint32_t)t) >> 16; \
    r = r + (tt ? 16 : 0); \
    t = tt ? tt : (t & 0xFFFF); \
  } \
  if(sizeof(type) >= 2) { \
    uint8_t tt = ((uint16_t)t) >> 8; \
    r = r + (tt ? 8 : 0); \
    t = tt ? tt : (t & 0xFF); \
  } \
  return r + Math_LogTable256[(uint8_t)t]; \
}

#define MATH_FM_CREATE_SIGNED_INTEGER(postfix, type) \
MATH_FM_CREATE_SIGNED(postfix, type)

MATH_FM_CREATE_REAL(F, float)
MATH_FM_CREATE_REAL(D, double)
MATH_FM_CREATE_SIGNED_INTEGER(I8, int8_t)
MATH_FM_CREATE_UNSIGNED_INTEGER(U8, uint8_t)
MATH_FM_CREATE_SIGNED_INTEGER(I16, int16_t)
MATH_FM_CREATE_UNSIGNED_INTEGER(U16, uint16_t)
MATH_FM_CREATE_SIGNED_INTEGER(I32, int32_t)
MATH_FM_CREATE_UNSIGNED_INTEGER(U32, uint32_t)
MATH_FM_CREATE_SIGNED_INTEGER(I64, int64_t)
MATH_FM_CREATE_UNSIGNED_INTEGER(U64, uint64_t)
MATH_FM_CREATE_UNSIGNED_INTEGER(SizeT, size_t)

#undef MATH_FM_CREATE_SIGNED_INTEGER
#undef MATH_FM_CREATE_UNSIGNED_INTEGER
#undef MATH_FM_CREATE_UNSIGNED
#undef MATH_FM_CREATE_SIGNED
#undef MATH_FM_CREATE_REAL

// the half to float and vice versa is from Rygorous publid domain code
AL2O3_EXTERN_C uint16_t Math_Float2Half(float f_);
AL2O3_EXTERN_C float Math_Half2Float(uint16_t h_);

#endif //AL2O3_CMATH_CMATH_H
