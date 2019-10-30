#include "al2o3_cmath/vector.h"
#include "al2o3_catch2/catch2.hpp"

TEST_CASE("Math Vector Equal (C)", "[Math Vector]") {

#define MVE_TEST_INT2(postfix, type) \
  Math_Vec2##postfix const a2##postfix { (type)1, (type)3 }; \
  Math_Vec2##postfix const b2##postfix { (type)2, (type)2 }; \
  REQUIRE(Math_EqualVec2##postfix(a2##postfix,a2##postfix)); \
  REQUIRE(!Math_EqualVec2##postfix(a2##postfix, b2##postfix));

#define MVE_TEST_REAL2(postfix, type) \
  MVE_TEST_INT2(postfix, type) \
  Math_Vec2##postfix const c2##postfix { (type)1.01, (type)3.01 }; \
  REQUIRE(Math_ApproxEqualVec2##postfix(a2##postfix, c2##postfix, (type)0.02)); \
  REQUIRE(!Math_ApproxEqualVec2##postfix(a2##postfix, c2##postfix, (type)0.005));

#define MVE_TEST_INT3(postfix, type) \
  Math_Vec3##postfix const a3##postfix { (type)1, (type)3, (type) 6 }; \
  Math_Vec3##postfix const b3##postfix { (type)2, (type)2, (type) 2 }; \
  REQUIRE(Math_EqualVec3##postfix(a3##postfix,a3##postfix)); \
  REQUIRE(!Math_EqualVec3##postfix(a3##postfix, b3##postfix));

#define MVE_TEST_REAL3(postfix, type) \
  MVE_TEST_INT3(postfix, type) \
  Math_Vec3##postfix const c3##postfix { (type)1.01, (type)3.01, (type) 6.01 }; \
  REQUIRE(Math_ApproxEqualVec3##postfix(a3##postfix, c3##postfix, (type)0.02)); \
  REQUIRE(!Math_ApproxEqualVec3##postfix(a3##postfix, c3##postfix, (type)0.005));

#define MVE_TEST_INT4(postfix, type) \
  Math_Vec4##postfix const a4##postfix { (type)1, (type)3, (type) 6, (type) 12 }; \
  Math_Vec4##postfix const b4##postfix { (type)2, (type)2, (type) 2, (type) 2 }; \
  REQUIRE(Math_EqualVec4##postfix(a4##postfix,a4##postfix)); \
  REQUIRE(!Math_EqualVec4##postfix(a4##postfix, b4##postfix));

#define MVE_TEST_REAL4(postfix, type) \
  MVE_TEST_INT4(postfix, type) \
  Math_Vec4##postfix c4##postfix { (type)1.01, (type)3.01, (type) 6.01, (type) 12.01 }; \
  REQUIRE(Math_ApproxEqualVec4##postfix(a4##postfix, c4##postfix, (type)0.02)); \
  REQUIRE(!Math_ApproxEqualVec4##postfix(a4##postfix, c4##postfix, (type)0.005)); \
  c4##postfix = Math_LerpVec4##postfix(a4##postfix, b4##postfix, 0.0f); \
  REQUIRE(Math_ApproxEqualVec4##postfix(a4##postfix, c4##postfix, (type)1e-5f)); \
  c4##postfix = Math_LerpVec4##postfix(a4##postfix, b4##postfix, 1.0f); \
  REQUIRE(Math_ApproxEqualVec4##postfix(b4##postfix, c4##postfix, (type)1e-5f));

	MVE_TEST_REAL2(F, float);
	MVE_TEST_REAL3(F, float);
	MVE_TEST_REAL4(F, float);
	MVE_TEST_REAL2(D, double);
	MVE_TEST_REAL3(D, double);
	MVE_TEST_REAL4(D, double);
	MVE_TEST_INT2(I32, int32_t);
	MVE_TEST_INT3(I32, int32_t);
	MVE_TEST_INT4(I32, int32_t);
	MVE_TEST_INT2(U32, uint32_t);
	MVE_TEST_INT3(U32, uint32_t);
	MVE_TEST_INT4(U32, uint32_t);
	MVE_TEST_INT2(I64, int64_t);
	MVE_TEST_INT3(I64, int64_t);
	MVE_TEST_INT4(I64, int64_t);
	MVE_TEST_INT2(U64, uint64_t);
	MVE_TEST_INT3(U64, uint64_t);
	MVE_TEST_INT4(U64, uint64_t);
#undef MVE_TEST_INT2
#undef MVE_TEST_REAL2
#undef MVE_TEST_INT3
#undef MVE_TEST_REAL3
#undef MVE_TEST_INT4
#undef MVE_TEST_REAL4

}

TEST_CASE("Math Vector Min/Max (C)", "[Math Vector]") {
#define MVE_TEST2(postfix, type) \
  Math_Vec2##postfix const a2##postfix { (type)1, (type)3 }; \
  Math_Vec2##postfix const b2##postfix { (type)2, (type)2 }; \
  Math_Vec2##postfix const c2##postfix { (type)1, (type)2 }; \
  Math_Vec2##postfix const d2##postfix { (type)2, (type)3 }; \
  REQUIRE(Math_EqualVec2##postfix(Math_MinVec2##postfix(a2##postfix, b2##postfix), c2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_MaxVec2##postfix(a2##postfix, b2##postfix), d2##postfix));

#define MVE_TEST3(postfix, type) \
  Math_Vec3##postfix const a3##postfix { (type)1, (type)3, (type) 6 }; \
  Math_Vec3##postfix const b3##postfix { (type)2, (type)2, (type) 2 }; \
  Math_Vec3##postfix const c3##postfix { (type)1, (type)2, (type) 2 }; \
  Math_Vec3##postfix const d3##postfix { (type)2, (type)3, (type) 6 }; \
  REQUIRE(Math_EqualVec3##postfix(Math_MinVec3##postfix(a3##postfix, b3##postfix), c3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_MaxVec3##postfix(a3##postfix, b3##postfix), d3##postfix));

#define MVE_TEST4(postfix, type) \
  Math_Vec4##postfix const a4##postfix { (type)1, (type)3, (type) 6, (type) 12 }; \
  Math_Vec4##postfix const b4##postfix { (type)2, (type)2, (type) 2, (type) 2 }; \
  Math_Vec4##postfix const c4##postfix { (type)1, (type)2, (type) 2, (type) 2 }; \
  Math_Vec4##postfix const d4##postfix { (type)2, (type)3, (type) 6, (type) 12 }; \
  REQUIRE(Math_EqualVec4##postfix(Math_MinVec4##postfix(a4##postfix, b4##postfix), c4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_MaxVec4##postfix(a4##postfix, b4##postfix), d4##postfix));

	MVE_TEST2(F, float);
	MVE_TEST3(F, float);
	MVE_TEST4(F, float);
	MVE_TEST2(D, double);
	MVE_TEST3(D, double);
	MVE_TEST4(D, double);
	MVE_TEST2(I32, int32_t);
	MVE_TEST3(I32, int32_t);
	MVE_TEST4(I32, int32_t);
	MVE_TEST2(U32, uint32_t);
	MVE_TEST3(U32, uint32_t);
	MVE_TEST4(U32, uint32_t);
	MVE_TEST2(I64, int64_t);
	MVE_TEST3(I64, int64_t);
	MVE_TEST4(I64, int64_t);
	MVE_TEST2(U64, uint64_t);
	MVE_TEST3(U64, uint64_t);
	MVE_TEST4(U64, uint64_t);

#undef MVE_TEST2
#undef MVE_TEST3
#undef MVE_TEST4
}

TEST_CASE("Math Vector Clamp (C)", "[Math Vector]") {
#define MVE_TEST2(postfix, type) \
  Math_Vec2##postfix const a2##postfix { (type)1, (type)2 }; \
  Math_Vec2##postfix const b2##postfix { (type)0, (type)1 }; \
  Math_Vec2##postfix const c2##postfix { (type)20, (type)21 }; \
  Math_Vec2##postfix const d2##postfix { (type)25, (type)26 }; \
  REQUIRE(Math_EqualVec2##postfix(Math_ClampVec2##postfix(a2##postfix, b2##postfix, c2##postfix), a2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_ClampVec2##postfix(b2##postfix, a2##postfix, c2##postfix), a2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_ClampVec2##postfix(d2##postfix, b2##postfix, c2##postfix), c2##postfix));

#define MVE_TEST3(postfix, type) \
  Math_Vec3##postfix const a3##postfix { (type)1, (type)2, (type) 3 }; \
  Math_Vec3##postfix const b3##postfix { (type)0, (type)1, (type) 2 }; \
  Math_Vec3##postfix const c3##postfix { (type)20, (type)21, (type) 22 }; \
  Math_Vec3##postfix const d3##postfix { (type)25, (type)26, (type) 27 }; \
  REQUIRE(Math_EqualVec3##postfix(Math_ClampVec3##postfix(a3##postfix, b3##postfix, c3##postfix), a3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_ClampVec3##postfix(b3##postfix, a3##postfix, c3##postfix), a3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_ClampVec3##postfix(d3##postfix, b3##postfix, c3##postfix), c3##postfix));

#define MVE_TEST4(postfix, type) \
  Math_Vec4##postfix const a4##postfix { (type)1, (type)2, (type) 3, (type) 4 }; \
  Math_Vec4##postfix const b4##postfix { (type)0, (type)1, (type) 2, (type) 3 }; \
  Math_Vec4##postfix const c4##postfix { (type)20, (type)21, (type) 22, (type) 23 }; \
  Math_Vec4##postfix const d4##postfix { (type)25, (type)26, (type) 27, (type) 28 }; \
  REQUIRE(Math_EqualVec4##postfix(Math_ClampVec4##postfix(a4##postfix, b4##postfix, c4##postfix), a4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_ClampVec4##postfix(b4##postfix, a4##postfix, c4##postfix), a4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_ClampVec4##postfix(d4##postfix, b4##postfix, c4##postfix), c4##postfix));

	MVE_TEST2(F, float);
	MVE_TEST3(F, float);
	MVE_TEST4(F, float);
	MVE_TEST2(D, double);
	MVE_TEST3(D, double);
	MVE_TEST4(D, double);
	MVE_TEST2(I32, int32_t);
	MVE_TEST3(I32, int32_t);
	MVE_TEST4(I32, int32_t);
	MVE_TEST2(U32, uint32_t);
	MVE_TEST3(U32, uint32_t);
	MVE_TEST4(U32, uint32_t);
	MVE_TEST2(I64, int64_t);
	MVE_TEST3(I64, int64_t);
	MVE_TEST4(I64, int64_t);
	MVE_TEST2(U64, uint64_t);
	MVE_TEST3(U64, uint64_t);
	MVE_TEST4(U64, uint64_t);

#undef MVE_TEST2
#undef MVE_TEST3
#undef MVE_TEST4

}

TEST_CASE("Math Vector Arithmetic (C)", "[Math Vector]") {
#define MVE_TEST_UNSIGNED2(postfix, type) \
  Math_Vec2##postfix const a2##postfix { (type)1, (type)3 }; \
  Math_Vec2##postfix const b2##postfix { (type)2, (type)2 }; \
  Math_Vec2##postfix const c2##postfix { (type)3, (type)5 }; \
  Math_Vec2##postfix const d2##postfix { (type)6, (type)10 }; \
  REQUIRE(Math_EqualVec2##postfix(Math_AddVec2##postfix(a2##postfix,b2##postfix), c2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_SubVec2##postfix(c2##postfix,a2##postfix), b2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_ScalarMulVec2##postfix(c2##postfix,(type)2), d2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_ComponentMulVec2##postfix(c2##postfix, b2##postfix), d2##postfix)); \
  REQUIRE(68 == Math_DotVec2##postfix(c2##postfix, d2##postfix));

#define MVE_TEST_SIGNED2(postfix, type) \
  MVE_TEST_UNSIGNED2(postfix, type) \
  Math_Vec2##postfix const e2##postfix { (type)-1, (type)-3 }; \
  Math_Vec2##postfix const f2##postfix { (type)-3, (type)-5 }; \
  Math_Vec2##postfix const g2##postfix { (type)-1, (type)-1 }; \
  REQUIRE(Math_EqualVec2##postfix(Math_SubVec2##postfix(b2##postfix,c2##postfix), e2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_ScalarMulVec2##postfix(c2##postfix,(type)-1), f2##postfix)); \
  REQUIRE(Math_EqualVec2##postfix(Math_ComponentMulVec2##postfix(c2##postfix, g2##postfix), f2##postfix));

#define MVE_TEST_REAL2(postfix, type) \
  Math_Vec2##postfix const a2##postfix { (type)1, (type)3 }; \
  Math_Vec2##postfix const b2##postfix { (type)2, (type)2 }; \
  Math_Vec2##postfix const c2##postfix { (type)3, (type)5 }; \
  Math_Vec2##postfix const d2##postfix { (type)6, (type)10 }; \
  Math_Vec2##postfix const e2##postfix { (type)-1, (type)-3 }; \
  Math_Vec2##postfix const f2##postfix { (type)-3, (type)-5 }; \
  Math_Vec2##postfix const g2##postfix { (type)-1, (type)-1 }; \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_AddVec2##postfix(a2##postfix,b2##postfix), c2##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_SubVec2##postfix(c2##postfix,a2##postfix), b2##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_ScalarMulVec2##postfix(c2##postfix,(type)2), d2##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_ComponentMulVec2##postfix(c2##postfix, b2##postfix), d2##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_SubVec2##postfix(b2##postfix,c2##postfix), e2##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_ScalarMulVec2##postfix(c2##postfix,(type)-1), f2##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec2##postfix(Math_ComponentMulVec2##postfix(c2##postfix, g2##postfix), f2##postfix, (type)0.e-5)); \
  REQUIRE(Approx(68) == Math_DotVec2##postfix(c2##postfix, d2##postfix));

#define MVE_TEST_UNSIGNED3(postfix, type) \
  Math_Vec3##postfix const a3##postfix { (type)1, (type)3, (type) 6 }; \
  Math_Vec3##postfix const b3##postfix { (type)2, (type)2, (type) 2 }; \
  Math_Vec3##postfix const c3##postfix { (type)3, (type)5, (type) 8 }; \
  Math_Vec3##postfix const d3##postfix { (type)6, (type)10, (type) 16 }; \
  REQUIRE(Math_EqualVec3##postfix(Math_AddVec3##postfix(a3##postfix,b3##postfix), c3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_SubVec3##postfix(c3##postfix,a3##postfix), b3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_ScalarMulVec3##postfix(c3##postfix,(type)2), d3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_ComponentMulVec3##postfix(c3##postfix, b3##postfix), d3##postfix)); \
  REQUIRE(196 == Math_DotVec3##postfix(c3##postfix, d3##postfix));

#define MVE_TEST_SIGNED3(postfix, type) \
  MVE_TEST_UNSIGNED3(postfix, type) \
  Math_Vec3##postfix const e3##postfix { (type)-1, (type)-3, (type)-6 }; \
  Math_Vec3##postfix const f3##postfix { (type)-3, (type)-5, (type) -8 }; \
  Math_Vec3##postfix const g3##postfix { (type)-1, (type)-1, (type) -1 }; \
  REQUIRE(Math_EqualVec3##postfix(Math_SubVec3##postfix(b3##postfix,c3##postfix), e3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_ScalarMulVec3##postfix(c3##postfix,(type)-1), f3##postfix)); \
  REQUIRE(Math_EqualVec3##postfix(Math_ComponentMulVec3##postfix(c3##postfix, g3##postfix), f3##postfix));

#define MVE_TEST_REAL3(postfix, type) \
  Math_Vec3##postfix const a3##postfix { (type)1, (type)3, (type) 6 }; \
  Math_Vec3##postfix const b3##postfix { (type)2, (type)2, (type) 2 }; \
  Math_Vec3##postfix const c3##postfix { (type)3, (type)5, (type) 8 }; \
  Math_Vec3##postfix const d3##postfix { (type)6, (type)10, (type) 16 }; \
  Math_Vec3##postfix const e3##postfix { (type)-1, (type)-3, (type)-6 }; \
  Math_Vec3##postfix const f3##postfix { (type)-3, (type)-5, (type) -8 }; \
  Math_Vec3##postfix const g3##postfix { (type)-1, (type)-1, (type) -1 }; \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_AddVec3##postfix(a3##postfix,b3##postfix), c3##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_SubVec3##postfix(c3##postfix,a3##postfix), b3##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_ScalarMulVec3##postfix(c3##postfix,(type)2), d3##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_ComponentMulVec3##postfix(c3##postfix, b3##postfix), d3##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_SubVec3##postfix(b3##postfix,c3##postfix), e3##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_ScalarMulVec3##postfix(c3##postfix,(type)-1), f3##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec3##postfix(Math_ComponentMulVec3##postfix(c3##postfix, g3##postfix), f3##postfix, (type)0.e-5)); \
  REQUIRE(Approx(196) == Math_DotVec3##postfix(c3##postfix, d3##postfix));

#define MVE_TEST_UNSIGNED4(postfix, type) \
  Math_Vec4##postfix const a4##postfix { (type)1, (type)3, (type) 6, (type) 12 }; \
  Math_Vec4##postfix const b4##postfix { (type)2, (type)2, (type) 2, (type) 2 }; \
  Math_Vec4##postfix const c4##postfix { (type)3, (type)5, (type) 8, (type) 14}; \
  Math_Vec4##postfix const d4##postfix { (type)6, (type)10, (type) 16, (type) 28 }; \
  REQUIRE(Math_EqualVec4##postfix(Math_AddVec4##postfix(a4##postfix,b4##postfix), c4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_SubVec4##postfix(c4##postfix,a4##postfix), b4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_ScalarMulVec4##postfix(c4##postfix,(type)2), d4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_ComponentMulVec4##postfix(c4##postfix, b4##postfix), d4##postfix)); \
  REQUIRE(588 == Math_DotVec4##postfix(c4##postfix, d4##postfix));

#define MVE_TEST_SIGNED4(postfix, type) \
  MVE_TEST_UNSIGNED4(postfix, type) \
  Math_Vec4##postfix const e4##postfix { (type)-1, (type)-3, (type)-6, (type) -12 }; \
  Math_Vec4##postfix const f4##postfix { (type)-3, (type)-5, (type) -8, (type) -14 }; \
  Math_Vec4##postfix const g4##postfix { (type)-1, (type)-1, (type) -1, (type) -1 }; \
  REQUIRE(Math_EqualVec4##postfix(Math_SubVec4##postfix(b4##postfix,c4##postfix), e4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_ScalarMulVec4##postfix(c4##postfix,(type)-1), f4##postfix)); \
  REQUIRE(Math_EqualVec4##postfix(Math_ComponentMulVec4##postfix(c4##postfix, g4##postfix), f4##postfix));

#define MVE_TEST_REAL4(postfix, type) \
  Math_Vec4##postfix const a4##postfix { (type)1, (type)3, (type) 6, (type) 12 }; \
  Math_Vec4##postfix const b4##postfix { (type)2, (type)2, (type) 2, (type) 2 }; \
  Math_Vec4##postfix const c4##postfix { (type)3, (type)5, (type) 8, (type) 14}; \
  Math_Vec4##postfix const d4##postfix { (type)6, (type)10, (type) 16, (type) 28 }; \
  Math_Vec4##postfix const e4##postfix { (type)-1, (type)-3, (type)-6, (type) -12 }; \
  Math_Vec4##postfix const f4##postfix { (type)-3, (type)-5, (type) -8, (type) -14 }; \
  Math_Vec4##postfix const g4##postfix { (type)-1, (type)-1, (type) -1, (type) -1 }; \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_AddVec4##postfix(a4##postfix, b4##postfix), c4##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_SubVec4##postfix(c4##postfix, a4##postfix), b4##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_ScalarMulVec4##postfix(c4##postfix,(type)2), d4##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_ComponentMulVec4##postfix(c4##postfix, b4##postfix), d4##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_SubVec4##postfix(b4##postfix,c4##postfix), e4##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_ScalarMulVec4##postfix(c4##postfix,(type)-1), f4##postfix, (type)0.e-5)); \
  REQUIRE(Math_ApproxEqualVec4##postfix(Math_ComponentMulVec4##postfix(c4##postfix, g4##postfix), f4##postfix, (type)0.e-5)); \
  REQUIRE(Approx(588) == Math_DotVec4##postfix(c4##postfix, d4##postfix));

	MVE_TEST_REAL2(F, float)
	MVE_TEST_REAL3(F, float)
	MVE_TEST_REAL4(F, float);
	MVE_TEST_REAL2(D, double);
	MVE_TEST_REAL3(D, double);
	MVE_TEST_REAL4(D, double);
	MVE_TEST_SIGNED2(I32, int32_t);
	MVE_TEST_SIGNED3(I32, int32_t);
	MVE_TEST_SIGNED4(I32, int32_t);
	MVE_TEST_UNSIGNED2(U32, uint32_t);
	MVE_TEST_UNSIGNED3(U32, uint32_t);
	MVE_TEST_UNSIGNED4(U32, uint32_t);
	MVE_TEST_SIGNED2(I64, int64_t);
	MVE_TEST_SIGNED3(I64, int64_t);
	MVE_TEST_SIGNED4(I64, int64_t);
	MVE_TEST_UNSIGNED2(U64, uint64_t);
	MVE_TEST_UNSIGNED3(U64, uint64_t);
	MVE_TEST_UNSIGNED4(U64, uint64_t);
#undef MVE_TEST_INT2
#undef MVE_TEST_REAL2
#undef MVE_TEST_INT3
#undef MVE_TEST_REAL3
#undef MVE_TEST_INT4
#undef MVE_TEST_REAL4
}

#include "al2o3_cmath/vector.hpp"

TEST_CASE("Math Vector Conversion (C++)", "[Math Vector]") {
	auto zeroOne2F = Math::Vec2F::From( {0, 1});
	REQUIRE(zeroOne2F.x == Approx(0));
	REQUIRE(zeroOne2F.y == Approx(1));
	Math_Vec2F cZeroOne2F = zeroOne2F;
	REQUIRE(cZeroOne2F.x == Approx(0));
	REQUIRE(cZeroOne2F.y == Approx(1));
	auto zeroOneTwo3F = Math::Vec3F::From( {0, 1, 2});
	REQUIRE(zeroOneTwo3F.x == Approx(0));
	REQUIRE(zeroOneTwo3F.y == Approx(1));
	REQUIRE(zeroOneTwo3F.z == Approx(2));
	Math_Vec3F cZeroOneTwo3F = zeroOneTwo3F;
	REQUIRE(cZeroOneTwo3F.x == Approx(0));
	REQUIRE(cZeroOneTwo3F.y == Approx(1));
	REQUIRE(cZeroOneTwo3F.z == Approx(2));
	auto zeroOneTwoThree4F = Math::Vec4F::From( {0, 1, 2, 3});
	REQUIRE(zeroOneTwoThree4F.x == Approx(0));
	REQUIRE(zeroOneTwoThree4F.y == Approx(1));
	REQUIRE(zeroOneTwoThree4F.z == Approx(2));
	REQUIRE(zeroOneTwoThree4F.w == Approx(3));
	Math_Vec4F cZeroOneTwoThree4F = zeroOneTwoThree4F;
	REQUIRE(cZeroOneTwoThree4F.x == Approx(0));
	REQUIRE(cZeroOneTwoThree4F.y == Approx(1));
	REQUIRE(cZeroOneTwoThree4F.z == Approx(2));
	REQUIRE(cZeroOneTwoThree4F.w == Approx(3));

}

TEST_CASE("Math Vector operators (C++)", "[Math Vector]") {

	auto zeroOne2F = Math::Vec2F::From({0, 1});
	REQUIRE(zeroOne2F[0] == Approx(0));
	REQUIRE(zeroOne2F[1] == Approx(1));

	auto apb = zeroOne2F + zeroOne2F;
	REQUIRE(apb[0] == Approx(0));
	REQUIRE(apb[1] == Approx(2));

	auto asb = zeroOne2F - zeroOne2F;
	REQUIRE(asb[0] == Approx(0));
	REQUIRE(asb[1] == Approx(0));

	auto asmb = apb * 2;
	REQUIRE(asmb[0] == Approx(0));
	REQUIRE(asmb[1] == Approx(4));

	auto acmb = ComponentMul(apb, apb);
	REQUIRE(acmb[0] == Approx(0));
	REQUIRE(acmb[1] == Approx(4));

	auto norm = Math::Normalise(acmb);
	REQUIRE(norm[0] == Approx(0));
	REQUIRE(norm[1] == Approx(1));
}