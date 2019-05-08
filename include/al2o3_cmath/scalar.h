// Apache Licensed (full license and info at end of file)

#pragma once
#ifndef AL2O3_CMATH_SCALAR_H
#define AL2O3_CMATH_SCALAR_H

#include "al2o3_platform/platform.h"
#include <math.h>

#define MATH_FUNC_MACRO_CREATE(postfix, type)\
AL2O3_EXTERN_C inline type Math_Min##postfix(type const v, type const a) { return (v < a) ? v : a; } \
AL2O3_EXTERN_C inline type Math_Max##postfix(type const v, type const a) { return (v > a) ? v : a; } \
AL2O3_EXTERN_C inline type Math_Clamp##postfix(type const v, type const a, type const b) { return Math_Min##postfix(Math_Max##postfix(v, a), b); }

MATH_FUNC_MACRO_CREATE(F, float)
MATH_FUNC_MACRO_CREATE(D, double)
MATH_FUNC_MACRO_CREATE(I32, int32_t)
MATH_FUNC_MACRO_CREATE(U32, uint32_t)
MATH_FUNC_MACRO_CREATE(I64, int64_t)
MATH_FUNC_MACRO_CREATE(U64, uint64_t)

#undef MATH_FUNC_MACRO_CREATE

AL2O3_EXTERN_C inline float Math_SaturateF(const float x) { return Math_ClampF(x, 0.0f, 1.0f); }
AL2O3_EXTERN_C inline double Math_SaturateD(const double x) { return Math_ClampD(x, 0.0, 1.0); }

AL2O3_EXTERN_C inline double Math_PiD() { return (double) (3.14159265358979323846264338327950L); }
AL2O3_EXTERN_C inline double Math_PiOver2D() { return Math_PiD() / 2.0; }
AL2O3_EXTERN_C inline double Math_TwoPiD() { return 2.0 * Math_PiD(); }
AL2O3_EXTERN_C inline double Math_SqrD(double const val) { return val * val; }
AL2O3_EXTERN_C inline double Math_DegreesToRadiansD(double const val) {
	return val * (Math_PiD() / 180.0);
}
AL2O3_EXTERN_C inline double Math_RadiansToDegreesD(double const val) {
	return (180.0 * val) / Math_PiD();
}
AL2O3_EXTERN_C inline double Math_ReciprocalD(double const a) { return 1.0 / a; }
AL2O3_EXTERN_C inline int Math_SignD(double val) { return (0.0 < val) - (val < 0.0); }

//! Length^2 of a 1D Vector for orthogonality
AL2O3_EXTERN_C inline double Math_LengthSquaredD(double const a) { return a * a; }

//! Length of a 1D Vector for orthogonality
AL2O3_EXTERN_C inline double Math_Length(double const a) { return a; }

AL2O3_EXTERN_C inline double Math_ReciprocalSqrtD(double const a) { return 1.0 / sqrt(a); }

// Note: returns true for 0
AL2O3_EXTERN_C inline bool Math_IsPowerOf2U32(const uint32_t x) {
	return (x & (x - 1)) == 0;
}

// Note: returns true for 0
AL2O3_EXTERN_C inline bool Math_IsPowerOf2U64(const uint64_t x) {
	return (x & (x - 1)) == 0;
}

AL2O3_EXTERN_C inline uint32_t Math_UpperPowerOfTwoU32(uint32_t x) {
	if(x == 0) return 1;

	x -= 1;

	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;

	return x + 1;
}

AL2O3_EXTERN_C inline uint64_t Math_UpperPowerOfTwoU64(uint64_t x) {
	if(x == 0) return 1;

	x -= 1;

	x |= x >> 32;
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;

	return x + 1;
}
AL2O3_EXTERN_C inline uint32_t
Math_GetClosestPowerOfTwoU32(const uint32_t x) {
	uint32_t upow2 = Math_UpperPowerOfTwoU32(x);
	if (4 * x < 3 * upow2)
		return upow2 >> 1;
	else
		return upow2;
}

AL2O3_EXTERN_C inline uint64_t
Math_GetClosestPowerOfTwoU64(const uint64_t x) {
	uint64_t upow2 = Math_UpperPowerOfTwoU64(x);
	if (4 * x < 3 * upow2)
		return upow2 >> 1;
	else
		return upow2;
}

AL2O3_EXTERN_C uint8_t
Math_LogTable256[256];

/// \brief	return Log2 of v.
/// return log2 of an int. this is equivalent to finding the highest bit that has been set
/// or the number to shift 1 left by to get the nearest lower power of 2
/// \param	v	The number to get the log2 of.
/// \return	log2(v).
AL2O3_EXTERN_C inline unsigned int Math_Log2(unsigned int v) {
	unsigned int r = 0;     // r will be lg(v)
	unsigned int t = 0, tt = 0; // temporaries

	if ((tt = v >> 16) != 0) {
		r = ((t = tt >> 8) != 0) ? 24 + ((unsigned int) Math_LogTable256[t]) : 16 + ((unsigned int) Math_LogTable256[tt]);
	} else {
		r = ((t = v >> 8) != 0) ? 8 + ((unsigned int) Math_LogTable256[t]) : ((unsigned int) Math_LogTable256[v]);
	}
	return r;
}

// From Chunk Walbourns code from DirectXTexConvert.cpp
// e5b9g9r9 are positive only shared exponent float formats
AL2O3_EXTERN_C uint32_t
Math_Floats2E5b9g9r9(float const in_[3]);
AL2O3_EXTERN_C void Math_E5b9g9r92Floats(uint32_t const in_, float *r, float *g, float *b);

// the half to float and vice versa is from Rygorous publid domain code
AL2O3_EXTERN_C uint16_t
Math_Float2Half(float f_);
AL2O3_EXTERN_C float Math_Half2Float(uint16_t h_);


AL2O3_EXTERN_C inline uint32_t Math_RoundUp(uint32_t value, uint32_t multiple) {
	return ((value + multiple - 1) / multiple) *multiple;
}

AL2O3_EXTERN_C inline uint64_t Math_RoundUp64(uint64_t value, uint64_t multiple ) {
	return ((value + multiple - 1) / multiple) * multiple;
}

#endif //AL2O3_CMATH_CMATH_H

/*
 * Copyright (c) 2018-2019 Confetti Interactive Inc.
 * Copyright (c) 2019 Deano Calver

 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 * and al2o3
 * (see https://github.com/DeanoC/al2o3).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/