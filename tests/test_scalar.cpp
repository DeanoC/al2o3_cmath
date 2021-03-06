#include "al2o3_cmath/scalar.h"
#include "al2o3_catch2/catch2.hpp"

#define MST_UNSIGNED(postfix, type) \
	type const a##postfix= (type)1; \
	type const b##postfix = (type)2; \
	type c##postfix = (type)1; \
	REQUIRE(Math_Min##postfix((type)1, (type)2) == (type)1); \
	REQUIRE(Math_Min##postfix((type)2, (type)1) == (type)1); \
	REQUIRE(Math_Min##postfix((type)1, (type)1) == (type)1); \
	REQUIRE(Math_Max##postfix((type)1, (type)2) == (type)2); \
	REQUIRE(Math_Max##postfix((type)2, (type)1) == (type)2); \
	REQUIRE(Math_Max##postfix((type)1, (type)1) == (type)1); \
	REQUIRE(Math_Clamp##postfix((type)1, (type)2, (type)3) == (type)2); \
	REQUIRE(Math_Clamp##postfix((type)2, (type)1, (type)3) == (type)2); \
	REQUIRE(Math_Clamp##postfix((type)4, (type)1, (type)3) == (type)3); \
	REQUIRE(Math_Clamp##postfix((type)4, (type)5, (type)3) == (type)3); \
	REQUIRE(Math_Clamp##postfix((type)4, (type)0, (type)1) == (type)1); \
	REQUIRE(Math_Equal##postfix(a##postfix, a##postfix)); \
	REQUIRE(Math_Equal##postfix(a##postfix, c##postfix)); \
	REQUIRE_FALSE(Math_Equal##postfix(a##postfix, b##postfix)); \
	REQUIRE_FALSE(Math_Equal##postfix(b##postfix, c##postfix));


#define MST_SIGNED(postfix, type) \
	type const d##postfix = (type) -1; \
	MST_UNSIGNED(postfix, type) \
	REQUIRE(Math_Equal##postfix(d##postfix, d##postfix)); \
	REQUIRE_FALSE(Math_Equal##postfix(a##postfix, d##postfix)); \
	REQUIRE_FALSE(Math_Equal##postfix(c##postfix, d##postfix)); \
	c##postfix = Math_Abs##postfix(d##postfix); \
	REQUIRE(Math_Equal##postfix(c##postfix, a##postfix)); \
	REQUIRE_FALSE(Math_Equal##postfix(a##postfix, d##postfix)); \

#define MST_REAL(postfix, type) \
	type const e##postfix = (type) NAN; \
	MST_SIGNED(postfix, type) \
	REQUIRE(Math_ApproxEqual##postfix(c##postfix, a##postfix, (type)0)); \
	REQUIRE_FALSE(Math_Equal##postfix(e##postfix, e##postfix)); \
	REQUIRE(Math_IsNan##postfix(e##postfix)); \
	REQUIRE_FALSE(Math_IsNan##postfix(d##postfix)); \
	c##postfix = b##postfix - a##postfix; \
	REQUIRE(Math_ApproxEqual##postfix(a##postfix, c##postfix, (type)1e-5f)); \
	c##postfix = Math_Lerp##postfix(a##postfix, b##postfix, 0.0f); \
	REQUIRE(Math_ApproxEqual##postfix(a##postfix, c##postfix, (type)1e-5f)); \
	c##postfix = Math_Lerp##postfix(a##postfix, b##postfix, 1.0f); \
	REQUIRE(Math_ApproxEqual##postfix(b##postfix, c##postfix, (type)1e-5f));

TEST_CASE("Math Min/Max (C)", "[Math Scalar]") {

	MST_UNSIGNED(U8, uint8_t);
	MST_SIGNED(I8, int8_t);
	MST_UNSIGNED(U16, uint16_t);
	MST_SIGNED(I16, int16_t);
	MST_UNSIGNED(U32, uint32_t);
	MST_SIGNED(I32, int32_t);
	MST_UNSIGNED(U64, uint64_t);
	MST_SIGNED(I64, int64_t);
	MST_REAL(F, float);
	MST_REAL(D, double);

}

uint8_t SlowLogU8(uint8_t n) {
	for (int i = 7; i >= 0; --i) {
		if (n & (1 << i)) {
			return i;
		}
	}
	return 0;
}

uint8_t SlowLogU16(uint16_t n) {
	for (int i = 15; i >= 0; --i) {
		if (n & (1 << i)) {
			return i;
		}
	}
	return 0;
}

uint8_t SlowLogU32(uint32_t n) {
	for (int i = 31; i >= 0; --i) {
		if (n & (1 << i)) {
			return i;
		}
	}
	return 0;
}

uint8_t SlowLogU64(uint64_t n) {
	for (int i = 63; i >= 0; --i) {
		if (n & (1ULL << i)) {
			return i;
		}
	}
	return 0;
}

TEST_CASE("Math Log2 (C)", "[Math Scalar]") {
	for (int i = 0; i < 256; ++i) {
		REQUIRE(SlowLogU8(i) == Math_Log2U8(i));
	}

	for (int i = 0; i < 65536; ++i) {
		REQUIRE(SlowLogU16(i) == Math_Log2U16(i));
	}

	for (int i = 0; i < 65536; ++i) {
		REQUIRE(SlowLogU32(i * 10000) == Math_Log2U32(i * 10000));
	}

	for (int i = 0; i < 65536; ++i) {
		REQUIRE(SlowLogU64(i * 1000000) == Math_Log2U64(i * 1000000));
	}

}
