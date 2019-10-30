#pragma once

#include "al2o3_platform/platform.h"
#include "al2o3_cmath/vector.h"

// matrices are column major (exampler Mat2)
// a[ 11 | 21 ] = | a.v[0] = a11 = a.col[0].x | a.v[1] = a21 = a.col[1].x |
//  [ 12 | 22 ] = | a.v[2] = a12 = a.col[0].y | a.v[3] = a22 = a.col[1].y |

#define MATH_FM_CREATE_MATTYPE(postfix, type, count) \
typedef union Math_Mat##count##postfix { \
  type v[count * count];\
  Math_Vec##count##postfix col[count]; \
} Math_Mat##count##postfix;

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

#undef MATH_FM_CREATE_MATTYPE

#define MATH_FM_VTYPE(postfix, type, count) Math_Vec##count##postfix
#define MATH_FM_MATTYPE(postfix, type, count) Math_Mat##count##postfix

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

MATH_FM_CREATE_MATUNSIGNED(U32, uint32_t, 2)
MATH_FM_CREATE_MATSIGNED(I32, int32_t, 2)
MATH_FM_CREATE_MATREAL(F, float, 2)
MATH_FM_CREATE_MATREAL(D, double, 2)

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

#undef MATH_FM_CREATE_MATUNSIGNED
#undef MATH_FM_CREATE_MATSIGNED
#undef MATH_FM_CREATE_MATREAL
#undef MATH_FM_MATTYPE
#undef MATH_FM_VECTYPE

AL2O3_EXTERN_C Math_Mat4F Math_LookAtMat4F(Math_Vec3F const position,
																					 Math_Vec3F const lookAtPoint,
																					 Math_Vec3F upVector);
AL2O3_EXTERN_C Math_Mat4F Math_TranslationMat4F(Math_Vec3F const translate);
AL2O3_EXTERN_C Math_Mat4F Math_ScaleMat4F(Math_Vec3F const scale);
// angles in radians
AL2O3_EXTERN_C Math_Mat4F Math_RotateAxisAngleMat4F(Math_Vec3F const axis, float const angle);
AL2O3_EXTERN_C Math_Mat4F Math_RotateEulerXYZMat4F(Math_Vec3F const angles);
AL2O3_EXTERN_C Math_Mat4F Math_RotateXAxisMat4F(float const angle);
AL2O3_EXTERN_C Math_Mat4F Math_RotateYAxisMat4F(float const angle);
AL2O3_EXTERN_C Math_Mat4F Math_RotateZAxisMat4F(float const angle);

typedef Math_Vec4F Math_QuatF;

