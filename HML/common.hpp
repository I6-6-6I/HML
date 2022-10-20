#pragma once
#include <limits>
#include "vector_common.hpp"

HEADER_MATH_NAMESPACE
{
#pragma region MIN
	template<typename T>
	constexpr T Min(T x, T y)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "only floating-point or intager inputs are acceptable here!");
		return (y < x) ? y : x;
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Min(vector<L, T> const& x, vector<L, T> const& y)
	{
		return COMP::func2(x, y, Min);
	}
#pragma endregion
#pragma region MAX
	template<typename T>
	constexpr T Max(T x, T y)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "only floating-point or intager inputs are acceptable here!");
		return (x < y) ? y : x;
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Max(vector<L, T> const& x, vector<L, T> const& y)
	{
		return COMP::func2(x, y, Max);
	}
#pragma endregion
#pragma region ABS
	template<typename T>
	constexpr T Abs(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_signed, "only floating-point, integer, vector, scalar or signed inputs are acceptable here!");
		return x >= T(0) ? x : -x;
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Abs(vector<L, T> const& x)
	{
		return COMP::func1(x, Abs);
	}
#pragma endregion
#pragma region ROUND
	template<typename T>
	constexpr T Round(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");
		if (x < static_cast<T>(0)) return static_cast<T>(int(x - static_cast<T>(0.5)));
		else return static_cast<T>(int(x + static_cast<T>(0.5)));
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Round(vector<L, T> const& x)
	{
		return COMP::func1(x, Round);
	}
#pragma endregion
#pragma region CEIL
	template<typename T>
	constexpr T Ceil(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");
		return static_cast<T>(std::ceil(static_cast<double>(x)));
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Ceil(vector<L, T> const& x)
	{
		return COMP::func1(x, Ceil);
	}
#pragma endregion
#pragma region FLOOR
	template<typename T>
	constexpr T Floor(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");
		return static_cast<T>(std::floor(static_cast<double>(x)));
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Floor(vector<L, T> const& x)
	{
		return COMP::func1(x, Floor);
	}
#pragma endregion
#pragma region CLAMP
	template<typename T>
	constexpr T Clamp(T x, T val1, T val2)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "only floating-point or integer inputs are acceptable here!");
		return Min(Max(x, val1), val2);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Clamp(vector<L, T> const& x, vector<L, T> const& y, vector<L, T> const& z)
	{
		return COMP::func3(x, y, z, Clamp);
	}
#pragma endregion
#pragma region POW
	template<typename T>
	constexpr T Pow(T x, T y)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "only floating-point or integer inputs are acceptable here!");
		return std::pow(x,y);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Pow(vector<L, T> const& x, vector<L, T> const& y)
	{
		return COMP::func2(x, y, Pow);
	}
#pragma endregion
#pragma region FACT
	template<typename T>
	constexpr T Fact(T n)
	{
		static_assert(std::numeric_limits<T>::is_signed, "only integer or signed inputs are acceptable here!");
		T ret = 1;
		for (size_t i = 1; i <= n; i++)
			ret *= i;

		return ret;
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Fact(vector<L, T> const& n)
	{
		return COMP::func1(n, Fact);
	}
#pragma endregion
#pragma region LOG
	template<typename T>
	constexpr T Log_(T base, T val)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_signed, "only floating-point or signed inputs are acceptable here!");
		if (val == 1)
			return static_cast<T>(0);
		return 1 + Log_(base, val / base);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Log_(vector<L, T> const& base, vector<L, T> const& val)
	{
		return COMP::func2(base, val, Log_);
	}
	template<typename T>
	constexpr T Log(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_signed, "only floating-point or signed inputs are acceptable here!");
		return std::log(x);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Log(vector<L, T> const& x)
	{
		return COMP::func1(x, Log);
	}
	template<typename T>
	constexpr T Log10(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_signed, "only floating-point or signed inputs are acceptable here!");
		return std::log10(x);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Log10(vector<L, T> const& x)
	{
		return COMP::func1(x, Log10);
	}
#pragma endregion
#pragma region FMOD
	template<typename T>
	constexpr T Fmod(T x, T y)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point or signed inputs are acceptable here!");
		return std::fmod(x, y);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Fmod(vector<L, T> const& x, vector<L, T> const& y)
	{
		return COMP::func2(x, y, Fmod);
	}
#pragma endregion
#pragma region MODF
	template<typename T>
	constexpr T ModF(T x, T y)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point or signed inputs are acceptable here!");
		return std::modf(x, y);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> ModF(vector<L, T> const& x, vector<L, T> const& y)
	{
		return COMP::func2(x, y, ModF);
	}
#pragma endregion
#pragma region EXP
	template<typename T>
	constexpr T Exp(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point or signed inputs are acceptable here!");
		return std::exp(x);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Exp(vector<L, T> const& x)
	{
		return COMP::func1(x, Exp);
	}
#pragma endregion
#pragma region SQRT
	template<typename T>
	constexpr T Sqrt(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "only floating-point or integer inputs are acceptable here!");
		return std::sqrt(x);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> Sqrt(vector<L, T> const& x)
	{
		return COMP::func1(x, Sqrt);
	}
	template<typename T>
	constexpr T InvSqrt(T x)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_integer, "only floating-point or integer inputs are acceptable here!");
		return T(1) / std::sqrt(x);
	}
	template<size_t L, typename T>
	constexpr vector<L, T> InvSqrt(vector<L, T> const& x)
	{
		return COMP::func1(x, InvSqrt);
	}
#pragma endregion
}