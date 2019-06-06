#include "al2o3_cmath/aabb.h"
#include "al2o3_catch2/catch2.hpp"

TEST_CASE("Math AABB3F Center And Length (C)", "[Math AABB]") {
	
	Math_Aabb3F const a {
		Math_Vec3F_t{10.0f, 20.0f, 30.0f },
		Math_Vec3F_t{100.0f, 200.0f, 300.0f},
	};
	Math_Aabb3F const b {
		Math_Vec3F_t{-10.0f, -20.0f, -30.0f },
		Math_Vec3F_t{100.0f, 200.0f, 300.0f},
	};

	REQUIRE(Math_IsValidAabb3F(&a));
	Math_Vec3F_t c = Math_CenterAabb3F(&a);
	Math_Vec3F_t hl = Math_HalfLengthAabb3F(&a);
	REQUIRE(c.x == Approx(55.0f));
	REQUIRE(c.y == Approx(110.0f));
	REQUIRE(c.z == Approx(165.0f));
	REQUIRE(hl.x == Approx(45.0f));
	REQUIRE(hl.y == Approx(90.0f));
	REQUIRE(hl.z == Approx(135.0f));

	REQUIRE(Math_IsValidAabb3F(&b));
	c = Math_CenterAabb3F(&b);
	hl = Math_HalfLengthAabb3F(&b);
	REQUIRE(c.x == Approx(45.0f));
	REQUIRE(c.y == Approx(90.0f));
	REQUIRE(c.z == Approx(135.0f));
	REQUIRE(hl.x == Approx(55.0f));
	REQUIRE(hl.y == Approx(110.0f));
	REQUIRE(hl.z == Approx(165.0f));

}

TEST_CASE("Math AABB3F Set Center And Length (C)", "[Math AABB]") {

	Math_Aabb3F a{
		Math_Vec3F_t{0.0f, 0.0f, 0.0f },
		Math_Vec3F_t{100.0f, 200.0f, 300.0f},
	};
	
	Math_SetCenterAabb3F(&a, Math_Vec3F_t{ 20.0f, 30.0f, 40.0f });
	Math_Vec3F_t c = Math_CenterAabb3F(&a);
	Math_Vec3F_t hl = Math_HalfLengthAabb3F(&a);
	REQUIRE(c.x == Approx(20.0f));
	REQUIRE(c.y == Approx(30.0f));
	REQUIRE(c.z == Approx(40.0f));
	REQUIRE(hl.x == Approx(50.0f));
	REQUIRE(hl.y == Approx(100.0f));
	REQUIRE(hl.z == Approx(150.0f));

}