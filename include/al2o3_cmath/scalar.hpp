#pragma once

#include "al2o3_cmath/scalar.h"

#define MATH_FM_CREATE_UNSIGNED(postfix, type) \
AL2O3_FORCE_INLINE type Lerp(type const a, type const b, float t) { return Math_Lerp##postfix(a,b,t); } \
AL2O3_FORCE_INLINE type Min(type const v, type const a) { return Math_Min##postfix(v, a); } \
AL2O3_FORCE_INLINE type Max(type const v, type const a) { return Math_Max##postfix(v, a); } \
AL2O3_FORCE_INLINE type Clamp(type const v, type const a, type const b) { return Math_Clamp##postfix(v, a, b); } \
AL2O3_FORCE_INLINE bool Equal(type const a, type const b) { return Math_Equal##postfix(a, b); } \
AL2O3_FORCE_INLINE type RoundUpTo(type const v, type const m) { return Math_RoundUpTo##postfix(v, m); }

#define MATH_FM_CREATE_SIGNED(postfix, type) \
MATH_FM_CREATE_UNSIGNED(postfix, type) \
AL2O3_FORCE_INLINE type Abs(type const a) { return Math_Abs##postfix(a); }

#define MATH_FM_CREATE_UNSIGNED_INTEGER(postfix, type) \
MATH_FM_CREATE_UNSIGNED(postfix, type) \
AL2O3_FORCE_INLINE bool IsPowerOf2(type const x) { return Math_IsPowerOf2##postfix(x); } \
AL2O3_FORCE_INLINE type NextPowerOfTwo(type const x) { return Math_NextPowerOfTwo##postfix(x); }\
AL2O3_FORCE_INLINE type ClosestPowerOfTwo(type const x) { return Math_ClosestPowerOfTwo##postfix(x); }\
AL2O3_FORCE_INLINE uint8_t Log2(type const v) { return Math_Log2##postfix(v); }\

#define MATH_FM_CREATE_SIGNED_INTEGER(postfix, type) \
MATH_FM_CREATE_SIGNED(postfix, type)

#define MATH_FM_CREATE_REAL(postfix, type) \
MATH_FM_CREATE_SIGNED(postfix, type) \
AL2O3_FORCE_INLINE bool ApproxEqual(type const a, type const b, type const epsilon) { return Math_ApproxEqual##postfix(a,b,epsilon); } \
AL2O3_FORCE_INLINE bool IsNan(type const a) { return Math_IsNan##postfix(a); } \
AL2O3_FORCE_INLINE type Saturate(type const x) { return Math_Saturate##postfix(x); } \
AL2O3_FORCE_INLINE type Pi##postfix() { return Math_Pi##postfix(); } \
AL2O3_FORCE_INLINE type PiOver2##postfix() { return Math_PiOver2##postfix(); } \
AL2O3_FORCE_INLINE type TwoPi##postfix() { return Math_TwoPi##postfix(); } \
AL2O3_FORCE_INLINE type DegreesToRadians(type const val) { return Math_DegreesToRadians##postfix(val); } \
AL2O3_FORCE_INLINE type RadiansToDegrees(type const val) { return Math_RadiansToDegrees##postfix(val); } \
AL2O3_FORCE_INLINE type Reciprocal(type const a) { return Math_Reciprocal##postfix(a); } \
AL2O3_FORCE_INLINE int Sign(type val) { return Math_Sign##postfix(val); } \
AL2O3_FORCE_INLINE type Sqrt(type const a) { return Math_Sqrt##postfix(a); } \
AL2O3_FORCE_INLINE type ReciprocalSqrt(type const a) { return Math_ReciprocalSqrt##postfix(a); }

namespace Math {

	MATH_FM_CREATE_UNSIGNED_INTEGER(U8, uint8_t)
	MATH_FM_CREATE_UNSIGNED_INTEGER(U16, uint16_t)
	MATH_FM_CREATE_UNSIGNED_INTEGER(U32, uint32_t)
	MATH_FM_CREATE_UNSIGNED_INTEGER(U64, uint64_t)
//	MATH_FM_CREATE_UNSIGNED_INTEGER(SizeT, size_t)

	MATH_FM_CREATE_SIGNED_INTEGER(I8, int8_t)
	MATH_FM_CREATE_SIGNED_INTEGER(I16, int16_t)
	MATH_FM_CREATE_SIGNED_INTEGER(I32, int32_t)
	MATH_FM_CREATE_SIGNED_INTEGER(I64, int64_t)

	MATH_FM_CREATE_REAL(F, float)
	MATH_FM_CREATE_REAL(D, double)

	AL2O3_FORCE_INLINE uint16_t Float2Half(float f) { return Math_Float2Half(f); };
	AL2O3_FORCE_INLINE float Half2Float(uint16_t h) { return Math_Half2Float(h); };

};

#undef MATH_FM_CREATE_REAL
#undef MATH_FM_CREATE_SIGNED_INTEGER
#undef MATH_FM_CREATE_UNSIGNED_INTEGER
#undef MATH_FM_CREATE_SIGNED
#undef MATH_FM_CREATE_UNSIGNED