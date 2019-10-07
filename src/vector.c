#include "al2o3_platform/platform.h"
#include "al2o3_cmath/vector.h"

// left handed column major
AL2O3_EXTERN_C Math_Mat4F Math_LookAtMat4F(Math_Vec3F const position, Math_Vec3F const lookAtPoint, Math_Vec3F upVector) {
	Math_Vec3F const f = Math_NormaliseVec3F(Math_SubVec3F(lookAtPoint, position));
	Math_Vec3F const s = Math_NormaliseVec3F(Math_CrossVec3F(upVector, f));
	Math_Vec3F const u = Math_CrossVec3F(f, s);

	Math_Mat4F ret = {
		 s.x,  s.y,  s.z, 0,
		 u.x,  u.y,  u.z, 0,
		 f.x,  f.y,  f.z, 0,
		 -Math_DotVec3F(s, position), -Math_DotVec3F(u, position), -Math_DotVec3F(f, position), 1
	};
	return ret;
}
