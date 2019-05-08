// Apache Licensed (full license and info at end of file)

#pragma once
#ifndef AL2O3_CMATH_VECTOR_H
#define AL2O3_CMATH_VECTOR_H

#include "al2o3_platform/platform.h"
#include <math.h>

typedef union Math_vec2F_t { struct { float x; float y; }; float v[2]; } Math_vec2F_t;
typedef union Math_vec2D_t { struct { double x; double y; }; double v[2]; } Math_vec2D_t;
typedef union Math_vec2I32_t { struct { int32_t x; int32_t y; }; int32_t v[2]; } Math_vec2I32_t;
typedef union Math_vec2U32_t { struct { uint32_t x; uint32_t y; }; uint32_t v[2]; } Math_vec2U32_t;

typedef union Math_vec3F_t { struct { float x; float y; float z; }; float v[3]; } Math_vec3F_t;
typedef union Math_vec3D_t { struct { double x; double y; double z; }; double v[3]; } Math_vec3D_t;
typedef union Math_vec3I32_t { struct { int32_t x; int32_t y; int32_t z; }; int32_t v[3]; } Math_vec3I32_t;
typedef union Math_vec3U32_t { struct { uint32_t x; uint32_t y; uint32_t z; }; uint32_t v[3]; } Math_vec3U32_t;

typedef union Math_vec4F_t { struct { float x; float y; float z; float w; }; float v[4]; } Math_vec4F_t;
typedef union Math_vec4D_t { struct { double x; double y; double z; double w; }; double v[4]; } Math_vec4D_t;
typedef union Math_vec4I32_t { struct { int32_t x; int32_t y; int32_t z; int32_t w; }; int32_t v[4]; } Math_vec4I32_t;
typedef union Math_vec4U32_t { struct { uint32_t x; uint32_t y; uint32_t z; uint32_t w; }; uint32_t v[4]; } Math_vec4U32_t;

typedef union Math_mat2F_t {
	struct { Math_vec2F_t col0; Math_vec2F_t col1; };
	Math_vec2F_t cols[2]; } mat2f_t;
typedef union Math_mat3F_t {
	struct { Math_vec3F_t col0; Math_vec3F_t col1; Math_vec3F_t col2; };
	Math_vec3F_t cols[3]; } mat3f_t;
typedef union Math_mat4F_t {
	struct { Math_vec4F_t col0; Math_vec4F_t col1; Math_vec4F_t col2; Math_vec4F_t col3; };
	Math_vec4F_t cols[4]; } mat4f_t;

#endif // end AL2O3_CMATH_VECTOR_H