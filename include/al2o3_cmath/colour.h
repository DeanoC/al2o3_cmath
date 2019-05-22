// Apache Licensed (full license and info at end of file)

#pragma once
#ifndef AL2O3_CMATH_COLOUR_H
#define AL2O3_CMATH_COLOUR_H

#include "al2o3_platform/platform.h"
#include <math.h>
#include "al2o3_cmath/scalar.h"
#include "al2o3_cmath/vector.h"

// from D3DX_DXGIFormatConvert.inl
AL2O3_EXTERN_C inline float Math_Float2SRGB(float val) {
	if (val < 0.0031308f) {
		val *= 12.92f;
	} else {
		val = 1.055f * powf(val, 1.0f / 2.4f) - 0.055f;
	}

	return val;
}

AL2O3_EXTERN_C inline float Math_SRGB2FloatInexact(float val) {
	if (val < 0.04045f) {
		val /= 12.92f;
	} else {
		val = powf((val + 0.055f) / 1.055f, 2.4f);
	}
	return val;
}

AL2O3_EXTERN_C uint32_t Math_SRGBTable[256];

AL2O3_EXTERN_C inline float Math_SRGB2Float(uint32_t val) {
	ASSERT(val <= 255);

	float f;
	memcpy(&f, &Math_SRGBTable[val], sizeof(float));
	return f;
}

AL2O3_EXTERN_C inline uint32_t Math_PackColourU32(uint32_t	r, uint32_t g, uint32_t	b, uint32_t a ) {
	return	((r & 0xff) << 24) |
					((g & 0xff) << 16) |
					((b & 0xff) << 8) |
					((a & 0xff) << 0);
}

//Output format is R8G8B8A8
AL2O3_EXTERN_C inline uint32_t Math_PackColourF32(float r, float g, float b, float a) {
	return Math_PackColourU32(
			(uint32_t)(Math_ClampF(r, 0.0f, 1.0f) * 255),
			(uint32_t)(Math_ClampF(g, 0.0f, 1.0f) * 255),
			(uint32_t)(Math_ClampF(b, 0.0f, 1.0f) * 255),
			(uint32_t)(Math_ClampF(a, 0.0f, 1.0f) * 255));
}

AL2O3_EXTERN_C inline uint32_t Math_PackColourVec44(Math_Vec4F_t rgba) {
	return Math_PackColourF32(rgba.x, rgba.y, rgba.z, rgba.w);
}
AL2O3_EXTERN_C inline Math_Vec4F_t Math_UnpackColourU32(uint32_t colorValue) {
	Math_Vec4F_t r = {
			(float) ((colorValue & 0xFF000000) >> 24) / 255.0f,
			(float) ((colorValue & 0x00FF0000) >> 16) / 255.0f,
			(float) ((colorValue & 0x0000FF00) >> 8) / 255.0f,
			(float) ((colorValue & 0x000000FF)) / 255.0f
	};
	return r;
}

AL2O3_EXTERN_C inline Math_Vec3F_t Math_RGBEToRGB(unsigned char *rgbe) {
	if (rgbe[3]) {
		float const e = ldexpf(1.0f, rgbe[3] - (int) (128 + 8));
		Math_Vec3F_t r = {
				((float) rgbe[0]) * e,
				((float) rgbe[1]) * e,
				((float) rgbe[2]) * e,
		};
		return r;
	}
	Math_Vec3F_t r = {0, 0, 0};
	return r;
}
AL2O3_EXTERN_C inline uint32_t Math_FloatRGBToRGBE8(const float r, const float g, const float b) {
	float const v = Math_MaxF(Math_MaxF(r, g), b);

	if (v < 1e-32f) {
		return 0;
	} else {
		int ex;
		float m = frexpf(v, &ex) * 256.0f / v;

		uint32_t ir = (uint32_t)(m * r);
		uint32_t ig = (uint32_t)(m * g);
		uint32_t ib = (uint32_t)(m * b);
		uint32_t ie = (uint32_t)(ex + 128);

		return ir | (ig << 8) | (ib << 16) | (ie << 24);
	}
}

AL2O3_EXTERN_C inline uint32_t Math_Vec3RGBToRGBE8(const Math_Vec3F_t rgb) {
	return Math_FloatRGBToRGBE8(rgb.x, rgb.y, rgb.z);
}

AL2O3_EXTERN_C inline uint32_t Math_FloatRGBToRGB9E5(const float r, const float g, const float b) {
	float const v = Math_MaxF(Math_MaxF(r, g), b);

	if (v < 1.52587890625e-5f) {
		return 0;
	} else if (v < 65536) {
		int ex;
		float m = frexpf(v, &ex) * 512.0f / v;

		uint32_t ir = (uint32_t)(m * r);
		uint32_t ig = (uint32_t)(m * g);
		uint32_t ib = (uint32_t)(m * b);
		uint32_t ie = (unsigned int) (ex + 15);

		return ir | (ig << 9) | (ib << 18) | (ie << 27);
	} else {
		uint32_t ir = (r < 65536) ? (uint32_t)(r * (1.0f / 128.0f)) : 0x1FF;
		uint32_t ig = (g < 65536) ? (uint32_t)(g * (1.0f / 128.0f)) : 0x1FF;
		uint32_t ib = (b < 65536) ? (uint32_t)(b * (1.0f / 128.0f)) : 0x1FF;
		uint32_t ie = 31;

		return ir | (ig << 9) | (ib << 18) | (ie << 27);
	}
}
AL2O3_EXTERN_C inline uint32_t Math_Vec3RGBToRGB9E5(const Math_Vec3F_t rgb) {
	return Math_FloatRGBToRGB9E5(rgb.x, rgb.y, rgb.z);
}

#endif // end AL2O3_CMATH_COLOUR_H