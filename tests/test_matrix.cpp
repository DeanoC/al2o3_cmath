#include "al2o3_cmath/matrix.h"
#include "al2o3_catch2/catch2.hpp"

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


