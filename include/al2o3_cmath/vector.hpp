#pragma once

#include "al2o3_cmath/vector.h"

#define MATH_FM_CREATE_VTYPE2(postfix, type) struct Vec2##postfix {  \
	static Vec2##postfix From(Math_Vec2##postfix const& a) { return { a.x, a.y }; }; \
	static Vec2##postfix From(type const* a) { return { a[0], a[1] }; }; \
	operator Math_Vec2##postfix() { Math_Vec2##postfix ret { x, y}; return ret;} \
	operator Math_Vec2##postfix() const { Math_Vec2##postfix ret { x, y}; return ret;} \
	type& operator[](size_t const index) { ASSERT(index < 2); return *((&x) + index); } \
	type const& operator[](size_t const index) const { ASSERT(index < 2); return *((&x) + index); } \
	Vec2##postfix operator+(Math_Vec2##postfix const& a) const { return From(Math_AddVec2##postfix(*this,a)); } \
	Vec2##postfix operator-(Math_Vec2##postfix const& a) const { return From(Math_SubVec2##postfix(*this,a)); } \
	type x; type y; \
};
#define MATH_FM_CREATE_VTYPE3(postfix, type) struct Vec3##postfix { \
	static Vec3##postfix From(Math_Vec3##postfix const& a) { return { a.x, a.y, a.z }; }; \
	static Vec3##postfix From(type const* a) { return { a[0], a[1], a[2] }; }; \
	operator Math_Vec3##postfix() { Math_Vec3##postfix ret { x, y, z}; return ret;} \
	operator Math_Vec3##postfix() const { Math_Vec3##postfix ret { x, y, z}; return ret;} \
	type& operator[](size_t const index) { ASSERT(index < 3); return *((&x) + index); } \
	type const& operator[](size_t const index) const { ASSERT(index < 3); return *((&x) + index); } \
	Vec3##postfix operator+(Math_Vec3##postfix const& a) const { return From(Math_AddVec3##postfix(*this,a)); } \
	Vec3##postfix operator-(Math_Vec3##postfix const& a) const { return From(Math_SubVec3##postfix(*this,a)); } \
	type x; type y; type z; \
};
#define MATH_FM_CREATE_VTYPE4(postfix, type) struct Vec4##postfix { \
	static Vec4##postfix From(Math_Vec4##postfix const& a) { return { a.x, a.y, a.z, a.w }; }; \
	static Vec4##postfix From(type const* a) { return { a[0], a[1], a[2], a[3] }; }; \
	operator Math_Vec4##postfix() { Math_Vec4##postfix ret { x, y, z, w }; return ret;} \
	operator Math_Vec4##postfix() const { Math_Vec4##postfix ret { x, y, z, w }; return ret;} \
	type& operator[](size_t const index) { ASSERT(index < 4); return *((&x) + index); } \
	type const& operator[](size_t const index) const { ASSERT(index < 4); return *((&x) + index); } \
	Vec4##postfix operator+(Math_Vec4##postfix const& a) const { return From(Math_AddVec4##postfix(*this,a)); } \
	Vec4##postfix operator-(Math_Vec4##postfix const& a) const { return From(Math_SubVec4##postfix(*this,a)); } \
	type x; type y; type z; type w; \
};


#define MATH_FM_VTYPE(postfix, count) Math::Vec##count##postfix

#define MATH_FM_CREATE_VUNSIGNED(postfix, type, count) \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) operator*(MATH_FM_VTYPE(postfix, count) const a, type const b) { return MATH_FM_VTYPE(postfix, count)::From(Math_ScalarMulVec##count##postfix(a, b)); } \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) ComponentMul( MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b) { return MATH_FM_VTYPE(postfix, count)::From(Math_ComponentMulVec##count##postfix(a,b)); } \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) Lerp( MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b, float const t) { return MATH_FM_VTYPE(postfix, count)::From(Math_LerpVec##count##postfix(a, b, t)); } \
AL2O3_FORCE_INLINE type DotVec( MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b) { return Math_DotVec##count##postfix(a, b); } \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) Min(MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b) { return MATH_FM_VTYPE(postfix, count)::From(Math_MinVec##count##postfix(a,b)); } \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) Max(MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b) { return MATH_FM_VTYPE(postfix, count)::From(Math_MaxVec##count##postfix(a,b)); } \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) Clamp(MATH_FM_VTYPE(postfix, count) const v, MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b) { return MATH_FM_VTYPE(postfix, count)::From(Math_ClampVec##count##postfix(v, a, b)); } \
AL2O3_FORCE_INLINE size_t HorizontalMaxIndex( MATH_FM_VTYPE(postfix, count) const a) { return Math_HorizontalMaxIndex##count##postfix(a); }

#define MATH_FM_CREATE_VSIGNED(postfix, type, count) \
MATH_FM_CREATE_VUNSIGNED(postfix, type, count) \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) Abs##count##postfix(MATH_FM_VTYPE(postfix, count) const a) { return MATH_FM_VTYPE(postfix, count)::From(Math_AbsVec##count##postfix(a)); }


#define MATH_FM_CREATE_VREAL(postfix, type, count)\
MATH_FM_CREATE_VSIGNED(postfix, type, count) \
AL2O3_FORCE_INLINE bool ApproxEqual( MATH_FM_VTYPE(postfix, count) const a, MATH_FM_VTYPE(postfix, count) const b, type const epsilon) { return Math_ApproxEqualVec##count##postfix(a, b, epsilon); } \
AL2O3_FORCE_INLINE bool IsNan(MATH_FM_VTYPE(postfix, count) const a) {  return Math_IsNanVec##count##postfix(a); } \
AL2O3_FORCE_INLINE type Length(MATH_FM_VTYPE(postfix, count) const a) {  return Math_LengthVec##count##postfix(a); } \
AL2O3_FORCE_INLINE MATH_FM_VTYPE(postfix, count) Normalise(MATH_FM_VTYPE(postfix, count) const a) {  return MATH_FM_VTYPE(postfix, count)::From(Math_NormaliseVec##count##postfix(a)); }

namespace Math {

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

	MATH_FM_CREATE_VUNSIGNED(U32, uint32_t, 2)
	MATH_FM_CREATE_VUNSIGNED(U32, uint32_t, 3)
	MATH_FM_CREATE_VUNSIGNED(U32, uint32_t, 4)
	MATH_FM_CREATE_VUNSIGNED(U64, uint64_t, 2)
	MATH_FM_CREATE_VUNSIGNED(U64, uint64_t, 3)
	MATH_FM_CREATE_VUNSIGNED(U64, uint64_t, 4)

	MATH_FM_CREATE_VSIGNED(I32, int32_t, 2)
	MATH_FM_CREATE_VSIGNED(I32, int32_t, 3)
	MATH_FM_CREATE_VSIGNED(I32, int32_t, 4)
	MATH_FM_CREATE_VSIGNED(I64, int64_t, 2)
	MATH_FM_CREATE_VSIGNED(I64, int64_t, 3)
	MATH_FM_CREATE_VSIGNED(I64, int64_t, 4)

	MATH_FM_CREATE_VREAL(F, float, 2)
	MATH_FM_CREATE_VREAL(F, float, 3)
	MATH_FM_CREATE_VREAL(F, float, 4)
	MATH_FM_CREATE_VREAL(D, double, 2)
	MATH_FM_CREATE_VREAL(D, double, 3)
	MATH_FM_CREATE_VREAL(D, double, 4)

};

#undef MATH_FM_CREATE_VTYPE2
#undef MATH_FM_CREATE_VTYPE3
#undef MATH_FM_CREATE_VTYPE4
#undef MATH_FM_CREATE_VREAL
#undef MATH_FM_CREATE_VSIGNED
#undef MATH_FM_CREATE_VUNSIGNED
#undef MATH_FM_VTYPE
