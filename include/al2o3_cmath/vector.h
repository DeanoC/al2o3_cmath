// Apache Licensed (full license and info at end of file)

#pragma once
#ifndef AL2O3_CMATH_VECTOR_H
#define AL2O3_CMATH_VECTOR_H

#include "al2o3_platform/platform.h"
#include "al2o3_cmath/scalar.h"

#define MATH_FM_CREATE_TYPE2(postfix, type) typedef union Math_Vec2##postfix##_t { struct { type x; type y; }; type v[2]; } Math_Vec2##postfix##_t;
#define MATH_FM_CREATE_TYPE3(postfix, type) typedef union Math_Vec3##postfix##_t { struct { type x; type y; type z; }; type v[3]; } Math_Vec3##postfix##_t;
#define MATH_FM_CREATE_TYPE4(postfix, type) typedef union Math_Vec4##postfix##_t { struct { type x; type y; type z; type w; }; type v[4]; } Math_Vec4##postfix##_t;

#define MATH_FM_CREATE_MATTYPE2(postfix) \
typedef union Math_Mat2##postfix##_t { \
	struct { Math_Vec2##postfix##_t col0; Math_Vec2##postfix##_t col1; }; \
	Math_Vec2##postfix##_t cols[2]; } Math_Mat2##postfix##_t;

#define MATH_FM_CREATE_MATTYPE3(postfix) \
typedef union Math_Mat3##postfix##_t { \
	struct { Math_Vec3##postfix##_t col0; Math_Vec3##postfix##_t col1; Math_Vec3##postfix##_t col2; }; \
	Math_Vec3##postfix##_t cols[3]; } Math_Mat3##postfix##_t;

#define MATH_FM_CREATE_MATTYPE4(postfix) \
typedef union Math_Mat4##postfix##_t { \
	struct { Math_Vec4##postfix##_t col0; Math_Vec4##postfix##_t col1; Math_Vec4##postfix##_t col2; Math_Vec4##postfix##_t col3; }; \
	Math_Vec4##postfix##_t cols[4]; } Math_Mat4##postfix##_t;

MATH_FM_CREATE_TYPE2(I32, int32_t);
MATH_FM_CREATE_TYPE2(U32, uint32_t);
MATH_FM_CREATE_TYPE2(I64, int64_t);
MATH_FM_CREATE_TYPE2(U64, uint64_t);
MATH_FM_CREATE_TYPE2(F, float);
MATH_FM_CREATE_TYPE2(D, double);

MATH_FM_CREATE_TYPE3(I32, int32_t);
MATH_FM_CREATE_TYPE3(U32, uint32_t);
MATH_FM_CREATE_TYPE3(I64, int64_t);
MATH_FM_CREATE_TYPE3(U64, uint64_t);
MATH_FM_CREATE_TYPE3(F, float);
MATH_FM_CREATE_TYPE3(D, double);

MATH_FM_CREATE_TYPE4(I32, int32_t);
MATH_FM_CREATE_TYPE4(U32, uint32_t);
MATH_FM_CREATE_TYPE4(I64, int64_t);
MATH_FM_CREATE_TYPE4(U64, uint64_t);
MATH_FM_CREATE_TYPE4(F, float);
MATH_FM_CREATE_TYPE4(D, double);

MATH_FM_CREATE_MATTYPE2(F)
MATH_FM_CREATE_MATTYPE2(D)
MATH_FM_CREATE_MATTYPE2(I32)
MATH_FM_CREATE_MATTYPE2(U32)
MATH_FM_CREATE_MATTYPE2(I64)
MATH_FM_CREATE_MATTYPE2(U64)

MATH_FM_CREATE_MATTYPE3(F)
MATH_FM_CREATE_MATTYPE3(D)
MATH_FM_CREATE_MATTYPE3(I32)
MATH_FM_CREATE_MATTYPE3(U32)
MATH_FM_CREATE_MATTYPE3(I64)
MATH_FM_CREATE_MATTYPE3(U64)

MATH_FM_CREATE_MATTYPE4(F)
MATH_FM_CREATE_MATTYPE4(D)
MATH_FM_CREATE_MATTYPE4(I32)
MATH_FM_CREATE_MATTYPE4(U32)
MATH_FM_CREATE_MATTYPE4(I64)
MATH_FM_CREATE_MATTYPE4(U64)

#undef MATH_FM_CREATE_TYPE2
#undef MATH_FM_CREATE_TYPE3
#undef MATH_FM_CREATE_TYPE4
#undef MATH_FM_CREATE_MATTYPE2
#undef MATH_FM_CREATE_MATTYPE3
#undef MATH_FM_CREATE_MATTYPE4

#define MATH_FM_TYPE(postfix, type, count) Math_Vec##count##postfix##_t
#define MATH_FM_CREATE_UNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_Vec##count##postfix##From(type const* in) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = in[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_Vec##count##postfix##Copy(MATH_FM_TYPE(postfix, type, count) const in) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = in.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_AddVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] + b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_SubVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] - b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_ScalarMulVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, type const b) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] * b; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_ComponentMulVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] * b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_LerpVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b, float const t) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = Math_Lerp##postfix(a.v[i], b.v[i], t); } return r; } \
AL2O3_LINK_OR_INLINE type Math_DotVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	type r = 0; for(size_t i = 0; i < count;++i) { r += a.v[i] * b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE bool Math_EqualVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	for(size_t i = 0; i < count;++i) { if(Math_Equal##postfix(a.v[i], b.v[i]) == false){ return false; } } return true; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_MinVec##count##postfix(MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = (a.v[i] < b.v[i]) ? a.v[i] : b.v[i]; }; return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_MaxVec##count##postfix(MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = (a.v[i] > b.v[i]) ? a.v[i] : b.v[i]; }; return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_ClampVec##count##postfix(MATH_FM_TYPE(postfix, type, count) const v, MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b) { return Math_MinVec##count##postfix(Math_MaxVec##count##postfix(v, a), b); }

#define MATH_FM_CREATE_SIGNED(postfix, type, count) \
MATH_FM_CREATE_UNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_AbsVec##count##postfix(MATH_FM_TYPE(postfix, type, count) const a) { \
	MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = Math_Abs##postfix(a.v[i]); }; return r; } \

#define MATH_FM_CREATE_REAL(postfix, type, count)\
MATH_FM_CREATE_SIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE bool Math_ApproxEqualVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b, type const epsilon) { \
	for(size_t i = 0; i < count;++i) { if(Math_ApproxEqual##postfix(a.v[i], b.v[i], epsilon) == false){ return false; } } return true; } \
AL2O3_LINK_OR_INLINE bool Math_IsNan##count##postfix(MATH_FM_TYPE(postfix, type, count) const a) {	\
	for(size_t i = 0; i < count;++i) { if(Math_IsNan##postfix(a.v[i]) == true){ return true; } } return false; }

MATH_FM_CREATE_REAL(F, float, 2)
MATH_FM_CREATE_REAL(F, float, 3)
MATH_FM_CREATE_REAL(F, float, 4)
MATH_FM_CREATE_REAL(D, double, 2)
MATH_FM_CREATE_REAL(D, double, 3)
MATH_FM_CREATE_REAL(D, double, 4)
MATH_FM_CREATE_SIGNED(I32, int32_t, 2)
MATH_FM_CREATE_SIGNED(I32, int32_t, 3)
MATH_FM_CREATE_SIGNED(I32, int32_t, 4)
MATH_FM_CREATE_UNSIGNED(U32, uint32_t, 2)
MATH_FM_CREATE_UNSIGNED(U32, uint32_t, 3)
MATH_FM_CREATE_UNSIGNED(U32, uint32_t, 4)
MATH_FM_CREATE_SIGNED(I64, int64_t, 2)
MATH_FM_CREATE_SIGNED(I64, int64_t, 3)
MATH_FM_CREATE_SIGNED(I64, int64_t, 4)
MATH_FM_CREATE_UNSIGNED(U64, uint64_t, 2)
MATH_FM_CREATE_UNSIGNED(U64, uint64_t, 3)
MATH_FM_CREATE_UNSIGNED(U64, uint64_t, 4)

#undef MFM_CREATE
#undef MATH_FM_TYPE

typedef Math_Vec4F_t Math_QuatF_t;

#endif // end AL2O3_CMATH_VECTOR_H