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
TEST_CASE("Math Matrix Identity (C)", "[Math Vector]") {
	Math_Mat2I32 const r0 = Math_IdentityMat2I32();
	REQUIRE(r0.v[0] == 1);
	REQUIRE(r0.v[1] == 0);
	REQUIRE(r0.v[2] == 0);
	REQUIRE(r0.v[3] == 1);
	REQUIRE(r0.col[0].x == 1);
	REQUIRE(r0.col[1].x == 0);
	REQUIRE(r0.col[0].y == 0);
	REQUIRE(r0.col[1].y == 1);
	Math_Mat3I32 const r1 = Math_IdentityMat3I32();
	REQUIRE(r1.col[0].x == 1);
	REQUIRE(r1.col[1].x == 0);
	REQUIRE(r1.col[2].x == 0);
	REQUIRE(r1.col[0].y == 0);
	REQUIRE(r1.col[1].y == 1);
	REQUIRE(r1.col[2].y == 0);
	REQUIRE(r1.col[0].z == 0);
	REQUIRE(r1.col[1].z == 0);
	REQUIRE(r1.col[2].z == 1);

}

TEST_CASE("Math Matrix Multiply (C)", "[Math Vector]") {

	Math_Mat2I32 const a = Math_IdentityMat2I32();
	Math_Mat2I32 const r0 = Math_MultiplyMat2I32(a, a);
	REQUIRE(r0.v[0] == 1);
	REQUIRE(r0.v[1] == 0);
	REQUIRE(r0.v[2] == 0);
	REQUIRE(r0.v[3] == 1);
	REQUIRE(r0.col[0].x == 1);
	REQUIRE(r0.col[1].x == 0);
	REQUIRE(r0.col[0].y == 0);
	REQUIRE(r0.col[1].y == 1);

	Math_Mat2I32 const b = {1, 0, 0, 2};
	Math_Mat2I32 const r1 = Math_MultiplyMat2I32(a, b);
	REQUIRE(r1.col[0].x == 1);
	REQUIRE(r1.col[1].x == 0);
	REQUIRE(r1.col[0].y == 0);
	REQUIRE(r1.col[1].y == 2);

	Math_Mat2I32 const c = {0, 0, 0, 0};
	Math_Mat2I32 const r2 = Math_MultiplyMat2I32(a, c);
	REQUIRE(r2.col[0].x == 0);
	REQUIRE(r2.col[1].x == 0);
	REQUIRE(r2.col[0].y == 0);
	REQUIRE(r2.col[1].y == 0);

	Math_Mat2I32 const d = {1, 2, 3, 4};
	Math_Mat2I32 const r3 = Math_MultiplyMat2I32(a, d);
	REQUIRE(r3.col[0].x == 1);
	REQUIRE(r3.col[1].x == 3);
	REQUIRE(r3.col[0].y == 2);
	REQUIRE(r3.col[1].y == 4);

	Math_Mat2I32 const r4 = Math_MultiplyMat2I32(d, d);
	REQUIRE(r4.col[0].x == 7);
	REQUIRE(r4.col[1].x == 15);
	REQUIRE(r4.col[0].y == 10);
	REQUIRE(r4.col[1].y == 22);

}

TEST_CASE("Math Matrix MulVec (C)", "[Math Vector]") {

	Math_Mat2I32 const identity = Math_IdentityMat2I32();
	Math_Vec2I32 const a = {1, 2};
	Math_Vec2I32 const r0 = Math_MulVecMat2I32(identity, a);
	REQUIRE(r0.x == 1);
	REQUIRE(r0.y == 2);

	Math_Mat2I32 const flipX = {-1, 0, 0, 1};
	Math_Vec2I32 const r1 = Math_MulVecMat2I32(flipX, a);
	REQUIRE(r1.x == -1);
	REQUIRE(r1.y == 2);

	Math_Mat2I32 const flipY = {1, 0, 0, -1};
	Math_Vec2I32 const r2 = Math_MulVecMat2I32(flipY, a);
	REQUIRE(r2.x == 1);
	REQUIRE(r2.y == -2);

	Math_Mat3I32 const translateXY = {1, 0, 10,
																		0, 1, 20,
																		0, 0, 1
	};
	Math_Vec3I32 const b = {1, -5, 1};
	Math_Vec3I32 const r3 = Math_MulVecMat3I32(translateXY, b);
	REQUIRE(r3.x == 11);
	REQUIRE(r3.y == 15);
	REQUIRE(r3.z == 1);

}
