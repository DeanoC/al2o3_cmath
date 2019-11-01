#include "al2o3_platform/platform.h"
#include "al2o3_cmath/scalar.h"

// often we want half conversion. so here are Rygorous's ones. These may be
// hw accelerated in future on HW that has a CPU instruction
// the half to float and vice versa is from Rygorous public domain code
// the float to half is his fast round to even
// he has SSE/SIMD versions if required
// Same, but rounding ties to nearest even instead of towards +inf
// Ryg's float_to_half_fast3_rtne
typedef union FP32 {
	uint32_t u;
	float f;
	struct {
		uint32_t Mantissa : 23;
		uint32_t Exponent : 8;
		uint32_t Sign : 1;
	};
} FP32;

typedef union FP16 {
	uint16_t u;
	struct {
		uint32_t Mantissa : 10;
		uint32_t Exponent : 5;
		uint32_t Sign : 1;
	};
} FP16;


AL2O3_EXTERN_C uint16_t Math_Float2Half(float f_) {

	FP32 f32infty = {255 << 23};
	FP32 f16max = {(127 + 16) << 23};
	FP32 denorm_magic = {((127 - 15) + (23 - 10) + 1) << 23};
	uint32_t sign_mask = 0x80000000u;
	FP16 o = {0};
	FP32 f;
	f.f = f_;

	uint32_t sign = f.u & sign_mask;
	f.u ^= sign;

	// NOTE all the integer compares in this function can be safely
	// compiled into signed compares since all operands are below
	// 0x80000000. Important if you want fast straight SSE2 code
	// (since there's no unsigned PCMPGTD).

	if (f.u >= f16max.u) { // result is Inf or NaN (all exponent bits set)
		o.u = (f.u > f32infty.u) ? 0x7e00 : 0x7c00; // NaN->qNaN and Inf->Inf
	} else // (De)normalized number or zero
	{
		if (f.u < (113 << 23)) // resulting FP16 is subnormal or zero
		{
			// use a magic value to align our 10 mantissa bits at the bottom of
			// the float. as long as FP addition is round-to-nearest-even this
			// just works.
			f.f += denorm_magic.f;

			// and one integer subtract of the bias later, we have our final float!
			o.u = f.u - denorm_magic.u;
		} else {
			uint32_t mant_odd = (f.u >> 13) & 1; // resulting mantissa is odd

			// update exponent, rounding bias part 1
			f.u += 0xc8000fff;
			// rounding bias part 2
			f.u += mant_odd;
			// take the bits!
			o.u = f.u >> 13;
		}
	}

	o.u |= sign >> 16;
	return o.u;
}

AL2O3_EXTERN_C float Math_Half2Float(uint16_t h_) {
	static const FP32 magic = {113 << 23};
	static const uint32_t shifted_exp = 0x7c00 << 13; // exponent mask after shift
	FP16 h;
	h.u = h_;
	FP32 o;

	o.u = (h.u & 0x7fff) << 13;     // exponent/mantissa bits
	uint32_t exp = shifted_exp & o.u;   // just the exponent
	o.u += (127 - 15) << 23;        // exponent adjust

	// handle exponent special cases
	if (exp == shifted_exp) { // Inf/NaN?
		o.u += (128 - 16) << 23;    // extra exp adjust
	} else if (exp == 0) // Zero/Denormal?
	{
		o.u += 1 << 23;             // extra exp adjust
		o.f -= magic.f;             // renormalize
	}

	o.u |= (h.u & 0x8000) << 16;    // sign bit
	return o.f;
}