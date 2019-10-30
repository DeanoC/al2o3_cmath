#include "al2o3_platform/platform.h"
#include "al2o3_cmath/matrix.h"

// left handed column major
AL2O3_EXTERN_C Math_Mat4F Math_LookAtMat4F(Math_Vec3F const position,
																					 Math_Vec3F const lookAtPoint,
																					 Math_Vec3F upVector) {
	Math_Vec3F const f = Math_NormaliseVec3F(Math_SubVec3F(lookAtPoint, position));
	Math_Vec3F const s = Math_NormaliseVec3F(Math_CrossVec3F(upVector, f));
	Math_Vec3F const u = Math_CrossVec3F(f, s);

	Math_Mat4F ret = {
			s.x, s.y, s.z, 0,
			u.x, u.y, u.z, 0,
			f.x, f.y, f.z, 0,
			-Math_DotVec3F(s, position), -Math_DotVec3F(u, position), -Math_DotVec3F(f, position), 1
	};
	return ret;
}

AL2O3_EXTERN_C Math_Mat4F Math_TranslationMat4F(Math_Vec3F const translate) {
	Math_Mat4F ret = {
			1, 0, 0, translate.x,
			0, 1, 0, translate.y,
			0, 0, 1, translate.z,
			0, 0, 0, 1
	};
	return ret;
}
AL2O3_EXTERN_C Math_Mat4F Math_ScaleMat4F(Math_Vec3F const scale) {
	Math_Mat4F ret = {
			scale.x, 0, 0, 0,
			0, scale.y, 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
	};
	return ret;
}
AL2O3_EXTERN_C Math_Mat4F Math_RotateXAxisMat4F(float const angle) {
	float const c = cosf(angle);
	float const s = sinf(angle);

	Math_Mat4F ret = {
			1, 0, 0, 0,
			0, c, s, 0,
			0, -s, c, 0,
			0, 0, 0, 1
	};
	return ret;
}
AL2O3_EXTERN_C Math_Mat4F Math_RotateYAxisMat4F(float const angle) {
	float const c = cosf(angle);
	float const s = sinf(angle);

	Math_Mat4F ret = {
			c, 0, -s, 0,
			0, 1, 0, 0,
			s, 0, c, 0,
			0, 0, 0, 1
	};
	return ret;
}

AL2O3_EXTERN_C Math_Mat4F Math_RotateZAxisMat4F(float const angle) {
	float const c = cosf(angle);
	float const s = sinf(angle);

	float const tmp = 1.0f - c;
	Math_Mat4F ret = {
			c, s, 0, 0,
			-s, c, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
	};
	return ret;
}

AL2O3_EXTERN_C Math_Mat4F Math_RotateAxisAngleMat4F(Math_Vec3F const axis, float const angle) {
	float const c = cosf(angle);
	float const s = sinf(angle);

	Math_Vec3F const tmp = Math_ScalarMulVec3F(axis, 1.0f - c);
	Math_Vec3F const saxis = Math_ScalarMulVec3F(axis, s);
	Math_Mat4F ret = {
			c + tmp.x * axis.x, 0 + tmp.x * axis.y + saxis.z, 0 + tmp.x * axis.z - saxis.y, 0,
			0 + tmp.y * axis.x - saxis.z, c + tmp.y * axis.y, 0 + tmp.y * axis.z + saxis.x, 0,
			0 + tmp.z * axis.x + saxis.y, 0 + tmp.z * axis.y - saxis.x, c + tmp.z * axis.z, 0,
			0, 0, 0, 1
	};
	return ret;
}

AL2O3_EXTERN_C Math_Mat4F Math_RotateEulerXYZMat4F(Math_Vec3F const angles) {
	// this is far from the fastest way, optimize if it shows up in profiles.
	Math_Mat4F const xrot = Math_RotateXAxisMat4F(angles.x);
	Math_Mat4F const yrot = Math_RotateYAxisMat4F(angles.y);
	Math_Mat4F const zrot = Math_RotateZAxisMat4F(angles.z);

	Math_Mat4F const tmp = Math_MultiplyMat4F(xrot, yrot);
	return Math_MultiplyMat4F(tmp, zrot);
}


