
#pragma once
#ifndef AL2O3_CMATH_VECTOR_H
#define AL2O3_CMATH_VECTOR_H

#include "al2o3_platform/platform.h"
#include "al2o3_cmath/scalar.h"

#define MATH_FM_CREATE_TYPE2(postfix, type) typedef union Math_Vec2##postfix##_t { struct { type x; type y; }; type v[2]; } Math_Vec2##postfix##_t;
#define MATH_FM_CREATE_TYPE3(postfix, type) typedef union Math_Vec3##postfix##_t { struct { type x; type y; type z; }; type v[3]; } Math_Vec3##postfix##_t;
#define MATH_FM_CREATE_TYPE4(postfix, type) typedef union Math_Vec4##postfix##_t { struct { type x; type y; type z; type w; }; type v[4]; } Math_Vec4##postfix##_t;

#define MATH_FM_CREATE_MATTYPE2(postfix, type) \
typedef union Math_Mat2##postfix##_t { \
  type v[4];\
  struct { Math_Vec2##postfix##_t col0; Math_Vec2##postfix##_t col1; }; \
  Math_Vec2##postfix##_t cols[2]; \
} Math_Mat2##postfix##_t;

#define MATH_FM_CREATE_MATTYPE3(postfix, type) \
typedef union Math_Mat3##postfix##_t { \
  type v[9];\
  struct { Math_Vec3##postfix##_t col0; Math_Vec3##postfix##_t col1; Math_Vec3##postfix##_t col2; }; \
  Math_Vec3##postfix##_t cols[3]; \
} Math_Mat3##postfix##_t;

#define MATH_FM_CREATE_MATTYPE4(postfix, type) \
typedef union Math_Mat4##postfix##_t { \
  type v[16]; \
  struct { Math_Vec4##postfix##_t col0; Math_Vec4##postfix##_t col1; Math_Vec4##postfix##_t col2; Math_Vec4##postfix##_t col3; }; \
  Math_Vec4##postfix##_t cols[4]; } \
  Math_Mat4##postfix##_t;

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

MATH_FM_CREATE_MATTYPE2(F, float)
MATH_FM_CREATE_MATTYPE2(D, double)
MATH_FM_CREATE_MATTYPE2(I32, int32_t)
MATH_FM_CREATE_MATTYPE2(U32, uint32_t)
MATH_FM_CREATE_MATTYPE2(I64, int64_t)
MATH_FM_CREATE_MATTYPE2(U64, uint64_t)

MATH_FM_CREATE_MATTYPE3(F, float)
MATH_FM_CREATE_MATTYPE3(D, double)
MATH_FM_CREATE_MATTYPE3(I32, int32_t)
MATH_FM_CREATE_MATTYPE3(U32, uint32_t)
MATH_FM_CREATE_MATTYPE3(I64, int64_t)
MATH_FM_CREATE_MATTYPE3(U64, uint64_t)

MATH_FM_CREATE_MATTYPE4(F, float)
MATH_FM_CREATE_MATTYPE4(D, double)
MATH_FM_CREATE_MATTYPE4(I32, int32_t)
MATH_FM_CREATE_MATTYPE4(U32, uint32_t)
MATH_FM_CREATE_MATTYPE4(I64, int64_t)
MATH_FM_CREATE_MATTYPE4(U64, uint64_t)

#undef MATH_FM_CREATE_TYPE2
#undef MATH_FM_CREATE_TYPE3
#undef MATH_FM_CREATE_TYPE4
#undef MATH_FM_CREATE_MATTYPE2
#undef MATH_FM_CREATE_MATTYPE3
#undef MATH_FM_CREATE_MATTYPE4

#define MATH_FM_TYPE(postfix, type, count) Math_Vec##count##postfix##_t

// Function supported for unsigned math vector types (Math_Vec4F_t used as exampler)
// n = 0 to dims-1 (n = 0 to 3 in the exampler)
// ----------------
// Math_FromVec4F(float const* in) = vector from float[4]
// Math_CopyVec4F(Math_Vec4_t const in) = copy of input Math_Vec4_t
// Math_AddVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = a + b
// Math_SubVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = a - b
// Math_ScalarMulVec4F(Math_Vec4F_t const a, float const b) = a[n] * b
// Math_ComponentMulVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = a[n] * b[n]
// Math_LerpVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b, float t) = a + (b - a) * t
// Math_DotVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = Sum[n](a[n] * b[n])
// Math_EqualVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = Sum(a[n] == b[n])
// Math_MinVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = (a[n] < b[n]) ? a[n] : b[n]
// Math_MaxVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b) = (a[n] > b[n]) ? a[n] : b[n]
// Math_ClampVec4F(Math_Vec4F_t const v, Math_Vec4F_t const a, Math_Vec4F_t b) = min(max(v, a), b)

#define MATH_FM_CREATE_UNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_FromVec##count##postfix(type const* in) { \
  MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = in[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_CopyVec##count##postfix(MATH_FM_TYPE(postfix, type, count) const in) { \
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

// Function supported for signed math vector types (Math_Vec4F_t used as exampler), as unsigned plus
// ----------------
// Math_AbsVec4F(Math_Vec4F_t const in) = (in[n] < 0) ? -in[n] : in[n]
#define MATH_FM_CREATE_SIGNED(postfix, type, count) \
MATH_FM_CREATE_UNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_TYPE(postfix, type, count) Math_AbsVec##count##postfix(MATH_FM_TYPE(postfix, type, count) const a) { \
  MATH_FM_TYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = Math_Abs##postfix(a.v[i]); }; return r; } \

// Function supported for real math vector types (Math_Vec4F_t used as exampler), as signed plus
// ----------------
// Math_ApproxEqualVec4F(Math_Vec4F_t const a, Math_Vec4F_t const b, float epsilon) = abs(b[n] - a[n]) < epsilon
// Math_IsNanVec4F(Math_Vec4F_t const in) = isnan(in[n])
#define MATH_FM_CREATE_REAL(postfix, type, count)\
MATH_FM_CREATE_SIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE bool Math_ApproxEqualVec##count##postfix( MATH_FM_TYPE(postfix, type, count) const a, MATH_FM_TYPE(postfix, type, count) const b, type const epsilon) { \
  for(size_t i = 0; i < count;++i) { if(Math_ApproxEqual##postfix(a.v[i], b.v[i], epsilon) == false){ return false; } } return true; } \
AL2O3_LINK_OR_INLINE bool Math_IsNan##count##postfix(MATH_FM_TYPE(postfix, type, count) const a) {  \
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