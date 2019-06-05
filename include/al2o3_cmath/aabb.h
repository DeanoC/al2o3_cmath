#pragma once
#ifndef AL2O3_CMATH_AABB_H
#define AL2O3_CMATH_AABB_H

#include "al2o3_platform/platform.h"
#include "al2o3_cmath/scalar.h"
#include "al2o3_cmath/vector.h"

typedef struct Math_Aabb3F {
	Math_Vec3F_t minExtent;
	Math_Vec3F_t maxExtent;
} Math_Aabb3F;

AL2O3_EXTERN_C inline Math_Aabb3F Math_Aabb3FFromCenterAndLength(Math_Vec3F_t center, Math_Vec3F_t length) {
	Math_Vec3F_t halfLength = Math_ScalarMulVec3F(length, 0.5f);
	Math_Aabb3F ret = {
		Math_SubVec3F(center, halfLength),
		Math_AddVec3F(center, halfLength),
	};
	return ret;
}
AL2O3_EXTERN_C inline Math_Aabb3F Math_Aabb3FFromCenterAndHalfLength(Math_Vec3F_t center, Math_Vec3F_t halfLength) {
	Math_Aabb3F ret = {
		Math_SubVec3F(center, halfLength),
		Math_AddVec3F(center, halfLength),
	};
	return ret;
}

AL2O3_EXTERN_C inline bool Math_IsValidAabb3F(Math_Aabb3F const* aabb) {
	Math_Vec3F_t diff = Math_SubVec3F(aabb->maxExtent, aabb->minExtent);
	return (Math_DotVec3F(diff, diff) > 0.0f);
}

AL2O3_EXTERN_C Math_Vec3F_t Math_CenterAabb3F(Math_Aabb3F const* aabb) {
	Math_Vec3F_t total = Math_AddVec3F(aabb->maxExtent, aabb->minExtent);
	return Math_ScalarMulVec3F(total, 0.5f);
}

AL2O3_EXTERN_C Math_Vec3F_t Math_HalfLengthAabb3F(Math_Aabb3F const* aabb) {
	Math_Vec3F_t diff = Math_SubVec3F(aabb->maxExtent, aabb->minExtent);
	return Math_ScalarMulVec3F(diff, 0.5f);
}
AL2O3_EXTERN_C void Math_SetCenterAabb3F(Math_Aabb3F* aabb, Math_Vec3F_t center) {
	Math_Vec3F_t const oldCenter = Math_CenterAabb3F(aabb);

	aabb->minExtent = Math_AddVec3F( Math_SubVec3F(aabb->minExtent,oldCenter), center);
	aabb->maxExtent = Math_AddVec3F( Math_SubVec3F(aabb->maxExtent,oldCenter), center);
}
AL2O3_EXTERN_C void Math_ExpandAabb3F(Math_Aabb3F* aabb, Math_Vec3F_t by) {
	aabb->minExtent = Math_MinVec3F(aabb->minExtent, by);
	aabb->maxExtent = Math_MaxVec3F(aabb->maxExtent, by);
}

AL2O3_EXTERN_C void Math_UnionAabb3F(Math_Aabb3F* aabb, Math_Aabb3F* with) {
	aabb->minExtent = Math_MinVec3F(aabb->minExtent, with->minExtent);
	aabb->maxExtent = Math_MaxVec3F(aabb->maxExtent, with->maxExtent);
}

AL2O3_EXTERN_C void Math_IntersectionAabb3F(Math_Aabb3F* aabb, Math_Aabb3F* with) {
	aabb->minExtent = Math_MaxVec3F(aabb->minExtent, with->minExtent);
	aabb->maxExtent = Math_MinVec3F(aabb->maxExtent, with->maxExtent);
}

AL2O3_EXTERN_C bool Math_DoesIntersectAabb3F(Math_Aabb3F const* aabb, Math_Aabb3F const* with) {
	Math_Vec3F_t minI = Math_MaxVec3F(aabb->minExtent, with->minExtent);
	Math_Vec3F_t maxI = Math_MinVec3F(aabb->maxExtent, with->maxExtent);

	return((minI.v[0] < maxI.v[0]) && (minI.v[1] < maxI.v[1]) && (minI.v[2] < maxI.v[2]));
}
AL2O3_EXTERN_C bool Math_DoesIntersectPointAabb3F(Math_Aabb3F const* aabb, Math_Vec3F_t const with) {
	return(
		(with.v[0] > aabb->minExtent.v[0] && with.v[0] < aabb->maxExtent.v[0]) &&
		(with.v[1] > aabb->minExtent.v[1] && with.v[1] < aabb->maxExtent.v[1]) &&
		(with.v[2] > aabb->minExtent.v[2] && with.v[2] < aabb->maxExtent.v[2]));
}
#endif