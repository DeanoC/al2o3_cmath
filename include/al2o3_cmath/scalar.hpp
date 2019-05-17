#pragma once
#ifndef AL2O3_CMATH_SCALAR_HPP
#define AL2O3_CMATH_SCALAR_HPP 1

#include <cmath>
#include <cstdlib>
#include <limits>
#include <algorithm>

namespace Math {

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	static constexpr auto pi() -> T { return T(3.14159265358979323846264338327950L); }

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	static constexpr auto pi_over_2() -> T { return pi<T>() / T(2); }
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	static constexpr auto two_pi() -> T { return T(2) * pi<T>(); }

	template<typename T>
	static constexpr auto square(T const val_) -> T { return val_ * val_; }

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	static constexpr auto degreesToRadians(T const val_) -> T {
		return val_ * (pi<T>() / T(180));
	}

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	static constexpr auto radiansToDegrees(T const val_) -> T {
		return (T(180) * val_) / pi<T>();
	}

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	constexpr auto ApproxEqual(T const a_, T const b_, T const eps_ = T(1e-5)) -> bool {
		return std::fabs(a_ - b_) < eps_;
	}

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	constexpr T Reciprocal(T a) { return T(1.0) / a; }

	template<typename T>
	constexpr int Sign(T val) { return (T(0) < val) - (val < T(0)); }

	//! Length^2 of a 1D Vector for orthogonality
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	constexpr T LengthSquared(T a) { return a * a; }

	//! Length of a 1D Vector for orthogonality
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	constexpr T Length(T a) { return a; }

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>{}>::type>
	constexpr T ReciprocalSqrt(T a) { return T(1.0) / std::sqrt(a); }

	template<typename genType>
	constexpr genType Clamp(genType x, genType minVal, genType maxVal) {
		static_assert(std::numeric_limits<genType>::is_iec559 || std::numeric_limits<genType>::is_integer,
									"'clamp' only accept floating-point or integer inputs");
		return std::min(std::max(x, minVal), maxVal);
	}

}

#endif