
#pragma once
#ifndef AL2O3_CMATH_VECTOR_H
#define AL2O3_CMATH_VECTOR_H

#include "al2o3_platform/platform.h"
#include "al2o3_cmath/scalar.h"

#define MATH_FM_CREATE_VTYPE2(postfix, type) typedef union Math_Vec2##postfix { type v[2]; struct { type x; type y; }; } Math_Vec2##postfix;
#define MATH_FM_CREATE_VTYPE3(postfix, type) typedef union Math_Vec3##postfix { type v[3]; struct { type x; type y; type z; }; } Math_Vec3##postfix;
#define MATH_FM_CREATE_VTYPE4(postfix, type) typedef union Math_Vec4##postfix { type v[4]; struct { type x; type y; type z; type w; }; } Math_Vec4##postfix;

// matrices are column major (exampler Mat2)
// a[ 11 | 21 ] = | a.v[0] = a11 = a.col[0].x | a.v[1] = a21 = a.col[1].x |
//  [ 12 | 22 ] = | a.v[2] = a12 = a.col[0].y | a.v[3] = a22 = a.col[1].y |

#define MATH_FM_CREATE_MATTYPE(postfix, type, count) \
typedef union Math_Mat##count##postfix { \
  type v[count * count];\
  Math_Vec##count##postfix col[count]; \
} Math_Mat##count##postfix;

MATH_FM_CREATE_VTYPE2(I32, int32_t);
MATH_FM_CREATE_VTYPE2(U32, uint32_t);
MATH_FM_CREATE_VTYPE2(I64, int64_t);
MATH_FM_CREATE_VTYPE2(U64, uint64_t);
MATH_FM_CREATE_VTYPE2(F, float);
MATH_FM_CREATE_VTYPE2(D, double);

MATH_FM_CREATE_VTYPE3(I32, int32_t);
MATH_FM_CREATE_VTYPE3(U32, uint32_t);
MATH_FM_CREATE_VTYPE3(I64, int64_t);
MATH_FM_CREATE_VTYPE3(U64, uint64_t);
MATH_FM_CREATE_VTYPE3(F, float);
MATH_FM_CREATE_VTYPE3(D, double);

MATH_FM_CREATE_VTYPE4(I32, int32_t);
MATH_FM_CREATE_VTYPE4(U32, uint32_t);
MATH_FM_CREATE_VTYPE4(I64, int64_t);
MATH_FM_CREATE_VTYPE4(U64, uint64_t);
MATH_FM_CREATE_VTYPE4(F, float);
MATH_FM_CREATE_VTYPE4(D, double);

MATH_FM_CREATE_MATTYPE(F, float, 2)
MATH_FM_CREATE_MATTYPE(D, double, 2)
MATH_FM_CREATE_MATTYPE(I32, int32_t, 2)
MATH_FM_CREATE_MATTYPE(U32, uint32_t, 2)
MATH_FM_CREATE_MATTYPE(I64, int64_t, 2)
MATH_FM_CREATE_MATTYPE(U64, uint64_t, 2)

MATH_FM_CREATE_MATTYPE(F, float, 3)
MATH_FM_CREATE_MATTYPE(D, double, 3)
MATH_FM_CREATE_MATTYPE(I32, int32_t, 3)
MATH_FM_CREATE_MATTYPE(U32, uint32_t, 3)
MATH_FM_CREATE_MATTYPE(I64, int64_t, 3)
MATH_FM_CREATE_MATTYPE(U64, uint64_t, 3)

MATH_FM_CREATE_MATTYPE(F, float, 4)
MATH_FM_CREATE_MATTYPE(D, double, 4)
MATH_FM_CREATE_MATTYPE(I32, int32_t, 4)
MATH_FM_CREATE_MATTYPE(U32, uint32_t, 4)
MATH_FM_CREATE_MATTYPE(I64, int64_t, 4)
MATH_FM_CREATE_MATTYPE(U64, uint64_t, 4)

#undef MATH_FM_CREATE_VTYPE2
#undef MATH_FM_CREATE_VTYPE3
#undef MATH_FM_CREATE_VTYPE4
#undef MATH_FM_CREATE_MATTYPE

#define MATH_FM_VTYPE(postfix, type, count) Math_Vec##count##postfix
#define MATH_FM_MATTYPE(postfix, type, count) Math_Mat##count##postfix

// Function supported for unsigned math vector types (Math_Vec4F used as exampler)
// n = 0 to dims-1 (n = 0 to 3 in the exampler)
// ----------------
// Math_FromVec4F(float const* in) = vector from float[4]
// Math_CopyVec4F(Math_Vec4F const in) = copy of input Math_Vec4
// Math_AddVec4F(Math_Vec4F const a, Math_Vec4F const b) = a + b
// Math_SubVec4F(Math_Vec4F const a, Math_Vec4F const b) = a - b
// Math_ScalarMulVec4F(Math_Vec4F const a, float const b) = a[n] * b
// Math_ComponentMulVec4F(Math_Vec4F const a, Math_Vec4F const b) = a[n] * b[n]
// Math_LerpVec4F(Math_Vec4F const a, Math_Vec4F const b, float t) = a + (b - a) * t
// Math_DotVec4F(Math_Vec4F const a, Math_Vec4F const b) = Sum[n](a[n] * b[n])
// Math_EqualVec4F(Math_Vec4F const a, Math_Vec4F const b) = Sum(a[n] == b[n])
// Math_MinVec4F(Math_Vec4F const a, Math_Vec4F const b) = (a[n] < b[n]) ? a[n] : b[n]
// Math_MaxVec4F(Math_Vec4F const a, Math_Vec4F const b) = (a[n] > b[n]) ? a[n] : b[n]
// Math_ClampVec4F(Math_Vec4F const v, Math_Vec4F const a, Math_Vec4F b) = min(max(v, a), b)

#define MATH_FM_CREATE_VUNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_FromVec##count##postfix(type const* in) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = in[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_CopyVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const in) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = in.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_AddVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] + b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_SubVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] - b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_ScalarMulVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, type const b) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] * b; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_ComponentMulVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = a.v[i] * b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_LerpVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b, float const t) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = Math_Lerp##postfix(a.v[i], b.v[i], t); } return r; } \
AL2O3_LINK_OR_INLINE type Math_DotVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  type r = 0; for(size_t i = 0; i < count;++i) { r += a.v[i] * b.v[i]; } return r; } \
AL2O3_LINK_OR_INLINE bool Math_EqualVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  for(size_t i = 0; i < count;++i) { if(Math_Equal##postfix(a.v[i], b.v[i]) == false){ return false; } } return true; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_MinVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = (a.v[i] < b.v[i]) ? a.v[i] : b.v[i]; }; return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_MaxVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = (a.v[i] > b.v[i]) ? a.v[i] : b.v[i]; }; return r; } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_ClampVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const v, MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { return Math_MinVec##count##postfix(Math_MaxVec##count##postfix(v, a), b); }

// Function supported for signed math vector types (Math_Vec4F used as exampler), as unsigned plus
// ----------------
// Math_AbsVec4F(Math_Vec4F* const in) = (in[n] < 0) ? -in[n] : in[n]
#define MATH_FM_CREATE_VSIGNED(postfix, type, count) \
MATH_FM_CREATE_VUNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_AbsVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const a) { \
  MATH_FM_VTYPE(postfix, type, count) r; for(size_t i = 0; i < count;++i) { r.v[i] = Math_Abs##postfix(a.v[i]); }; return r; } \

// Function supported for real math vector types (Math_Vec4F* used as exampler), as signed plus
// ----------------
// Math_ApproxEqualVec4F(Math_Vec4F const a, Math_Vec4F const b, float epsilon) = abs(b[n] - a[n]) < epsilon
// Math_IsNanVec4F(Math_Vec4F const in) = isnan(in[n])
// Math_LengthVec4F(Math_Vec4F const in) = norm2 AKA euclidean distance of in AKA sqrt(dot(in,in))
// Math_Normalise4F(Math_Vec4F const in) = in * LengthVec4F. vector elements are scaled by the largest element
#define MATH_FM_CREATE_VREAL(postfix, type, count)\
MATH_FM_CREATE_VSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE bool Math_ApproxEqualVec##count##postfix( MATH_FM_VTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b, type const epsilon) { \
  for(size_t i = 0; i < count;++i) { if(Math_ApproxEqual##postfix(a.v[i], b.v[i], epsilon) == false){ return false; } } return true; } \
AL2O3_LINK_OR_INLINE bool Math_IsNanVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const a) {  \
  for(size_t i = 0; i < count;++i) { if(Math_IsNan##postfix(a.v[i]) == true){ return true; } } return false; } \
AL2O3_LINK_OR_INLINE type Math_LengthVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const a) {  \
  return Math_Sqrt##postfix( Math_DotVec##count##postfix(a,a)); } \
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_NormaliseVec##count##postfix(MATH_FM_VTYPE(postfix, type, count) const a) {  \
  return Math_ScalarMulVec##count##postfix(a, Math_ReciprocalSqrt##postfix( Math_DotVec##count##postfix(a,a))); }

MATH_FM_CREATE_VREAL(F, float, 2)
MATH_FM_CREATE_VREAL(F, float, 3)
MATH_FM_CREATE_VREAL(F, float, 4)
MATH_FM_CREATE_VREAL(D, double, 2)
MATH_FM_CREATE_VREAL(D, double, 3)
MATH_FM_CREATE_VREAL(D, double, 4)
MATH_FM_CREATE_VSIGNED(I32, int32_t, 2)
MATH_FM_CREATE_VSIGNED(I32, int32_t, 3)
MATH_FM_CREATE_VSIGNED(I32, int32_t, 4)
MATH_FM_CREATE_VUNSIGNED(U32, uint32_t, 2)
MATH_FM_CREATE_VUNSIGNED(U32, uint32_t, 3)
MATH_FM_CREATE_VUNSIGNED(U32, uint32_t, 4)
MATH_FM_CREATE_VSIGNED(I64, int64_t, 2)
MATH_FM_CREATE_VSIGNED(I64, int64_t, 3)
MATH_FM_CREATE_VSIGNED(I64, int64_t, 4)
MATH_FM_CREATE_VUNSIGNED(U64, uint64_t, 2)
MATH_FM_CREATE_VUNSIGNED(U64, uint64_t, 3)
MATH_FM_CREATE_VUNSIGNED(U64, uint64_t, 4)

#undef MATH_FM_CREATE_VREAL
#undef MATH_FM_CREATE_VSIGNED
#undef MATH_FM_CREATE_VUNSIGNED

AL2O3_LINK_OR_INLINE Math_Vec3F Math_CrossVec3F(Math_Vec3F a, Math_Vec3F b) {
	Math_Vec3F ret = {
			a.y * b.z - b.y * a.z,
			a.z * b.x - b.z * a.x,
			a.x * b.y - b.x * a.y};
	return ret;
}

#define MATH_FM_CREATE_MATUNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_FromMat##count##postfix(type const* in) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count*count;++i) { \
    r.v[i] = in[i]; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_CopyMat##count##postfix(MATH_FM_MATTYPE(postfix, type, count) const in) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count*count;++i) { \
    r.v[i] = in.v[i]; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_IdentityMat##count##postfix() { \
  MATH_FM_MATTYPE(postfix, type, count) ret; \
  for(uint8_t i=0;i < count;i++) { \
    for(uint8_t j=0;j < count;j++) { \
      if(i == j) ret.v[i * count + j] = 1; \
      else ret.v[i * count + j] = 0; \
    } \
  } \
  return ret; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_TransposeMat##count##postfix(MATH_FM_MATTYPE(postfix, type, count) const in) { \
  MATH_FM_MATTYPE(postfix, type, count) ret; \
  for(uint8_t i=0;i < count;i++) { \
    for(uint8_t j=0;j < count;j++) { \
    ret.v[i * count + j] = in.v[j * count + i]; \
    } \
  } \
  return ret; \
} \
\
AL2O3_LINK_OR_INLINE void Math_SetElementMat##count##postfix(MATH_FM_MATTYPE(postfix, type, count) * in, uint8_t const c, uint8_t const r, type const val) { \
  in->v[c * count + r] = val; \
} \
AL2O3_LINK_OR_INLINE type Math_GetElementMat##count##postfix(MATH_FM_MATTYPE(postfix, type, count) * const in, uint8_t const c, uint8_t const r) { \
  return in->v[c * count + r]; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_GetRowMat##count##postfix(MATH_FM_MATTYPE(postfix, type, count) const * in, uint8_t const row) { \
  MATH_FM_VTYPE(postfix, type, count) r;  \
  for(size_t i = 0; i < count;++i) { \
    r.v[i] = in->v[ (i * count) + row]; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_AddMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, MATH_FM_MATTYPE(postfix, type, count) const b) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count*count;++i) { \
    r.v[i] = a.v[i] + b.v[i]; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_SubMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, MATH_FM_MATTYPE(postfix, type, count) const b) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count*count;++i) { \
    r.v[i] = a.v[i] - b.v[i]; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_ScalarMulMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, type const b) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count*count;++i) { \
    r.v[i] = a.v[i] * b; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_ComponentMulMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, MATH_FM_MATTYPE(postfix, type, count) const b) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count*count;++i) { \
    r.v[i] = a.v[i] * b.v[i]; \
  } \
  return r; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_MultiplyMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, MATH_FM_MATTYPE(postfix, type, count) const b) { \
  MATH_FM_MATTYPE(postfix, type, count) ret; \
  for(uint8_t i=0;i < count;i++) { \
    for(uint8_t j=0;j < count;j++) { \
      MATH_FM_VTYPE(postfix, type, count) rowj = Math_GetRowMat##count##postfix(&b, j); \
      Math_SetElementMat##count##postfix(&ret, i, j, Math_DotVec##count##postfix(a.col[i], rowj)); \
    } \
  } \
  return ret; \
} \
\
AL2O3_LINK_OR_INLINE MATH_FM_VTYPE(postfix, type, count) Math_MulVecMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, MATH_FM_VTYPE(postfix, type, count) const b) { \
  MATH_FM_VTYPE(postfix, type, count) ret; \
  for(uint8_t i=0;i < count;i++) { \
      ret.v[i] = Math_DotVec##count##postfix(a.col[i], b); \
  } \
  return ret; \
}

#define MATH_FM_CREATE_MATSIGNED(postfix, type, count) \
MATH_FM_CREATE_MATUNSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE MATH_FM_MATTYPE(postfix, type, count) Math_AbsMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a) { \
  MATH_FM_MATTYPE(postfix, type, count) r; \
  for(size_t i = 0; i < count;++i) { \
    r.col[i] = Math_AbsVec##count##postfix(a.col[i]); \
  } \
  return r; \
} \

#define MATH_FM_CREATE_MATREAL(postfix, type, count) \
MATH_FM_CREATE_MATSIGNED(postfix, type, count) \
AL2O3_LINK_OR_INLINE bool Math_ApproxEqualMat##count##postfix( MATH_FM_MATTYPE(postfix, type, count) const a, MATH_FM_MATTYPE(postfix, type, count) const b, type const epsilon) { \
  for(size_t i = 0; i < count;++i) { if(Math_ApproxEqualVec##count##postfix(a.col[i], b.col[i], epsilon) == false){ return false; } } return true; } \
AL2O3_LINK_OR_INLINE bool Math_IsNanMat##count##postfix(MATH_FM_MATTYPE(postfix, type, count) const a) {  \
  for(size_t i = 0; i < count;++i) { if(Math_IsNanVec##count##postfix(a.col[i]) == true){ return true; } } return false; }

MATH_FM_CREATE_MATREAL(F, float, 2)
MATH_FM_CREATE_MATREAL(D, double, 2)
MATH_FM_CREATE_MATSIGNED(I32, int32_t, 2)
MATH_FM_CREATE_MATUNSIGNED(U32, uint32_t, 2)
MATH_FM_CREATE_MATSIGNED(I64, int64_t, 2)
MATH_FM_CREATE_MATUNSIGNED(U64, uint64_t, 2)

MATH_FM_CREATE_MATREAL(F, float, 3)
MATH_FM_CREATE_MATREAL(D, double, 3)
MATH_FM_CREATE_MATSIGNED(I32, int32_t, 3)
MATH_FM_CREATE_MATUNSIGNED(U32, uint32_t, 3)
MATH_FM_CREATE_MATSIGNED(I64, int64_t, 3)
MATH_FM_CREATE_MATUNSIGNED(U64, uint64_t, 3)

MATH_FM_CREATE_MATREAL(F, float, 4)
MATH_FM_CREATE_MATREAL(D, double, 4)
MATH_FM_CREATE_MATSIGNED(I32, int32_t, 4)
MATH_FM_CREATE_MATUNSIGNED(U32, uint32_t, 4)
MATH_FM_CREATE_MATSIGNED(I64, int64_t, 4)
MATH_FM_CREATE_MATUNSIGNED(U64, uint64_t, 4)

AL2O3_EXTERN_C Math_Mat4F Math_LookAtMat4F(Math_Vec3F const position,
																					 Math_Vec3F const lookAtPoint,
																					 Math_Vec3F upVector);
AL2O3_EXTERN_C Math_Mat4F Math_TranslationMat4F(Math_Vec3F const translate);
AL2O3_EXTERN_C Math_Mat4F Math_ScaleMat4F(Math_Vec3F const scale);

typedef Math_Vec4F Math_QuatF;

#undef MATH_FM_CREATE_UNSIGNED
#undef MATH_FM_CREATE_SIGNED
#undef MATH_FM_CREATE_MATREAL
#undef MATH_FM_MATTYPE
#undef MATH_FM_VTYPE

#endif // end AL2O3_CMATH_VECTOR_H