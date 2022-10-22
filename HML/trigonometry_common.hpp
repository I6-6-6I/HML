#pragma once
#include <cmath>

HEADER_MATH_NAMESPACE
{
#pragma region RADIANS
		template<typename T>
		T Radians(T deg)
		{
			return deg * static_cast<T>(0.01745329251994329576923690768489);
		}
		template<size_t L, typename T>
		vector<L,T> Radians(vector<L, T> const& deg)
		{
			return deg * static_cast<T>(0.01745329251994329576923690768489);
		}
#pragma endregion
#pragma region DEGREES
		template<typename T>
		T Degrees(T rad)
		{
			return rad * static_cast<T>(57.295779513082320876798154814105);
		}
		template<size_t L, typename T>
		vector<L, T> Degrees(vector<L, T> const& rad)
		{
			return rad * static_cast<T>(57.295779513082320876798154814105);
		}
#pragma endregion
#pragma region SIN
		template<typename T>
		T Sin(T x)
		{
			return static_cast<T>(std::sin(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> Sin(vector<L, T> const& x)
		{
			return COMP::func1(x, Sin);
		}
#pragma endregion
#pragma region COS
		template<typename T>
		T Cos(T x)
		{
			return static_cast<T>(std::cos(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> Cos(vector<L, T> const& x)
		{
			return COMP::func1(x, Cos);
		}
#pragma endregion
#pragma region TAN
		template<typename T>
		T Tan(T x)
		{
			return static_cast<T>(std::tan(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> Tan(vector<L, T> const& x)
		{
			return COMP::func1(x, Tan);
		}
#pragma endregion
#pragma region ASIN
		template<typename T>
		T Asin(T x)
		{
			return static_cast<T>(std::asin(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> Asin(vector<L, T> const& x)
		{
			return COMP::func1(x, Asin);
		}
#pragma endregion
#pragma region ACOS
		template<typename T>
		T Acos(T x)
		{
			return static_cast<T>(std::acos(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> Acos(vector<L, T> const& x)
		{
			return COMP::func1(x, Acos);
		}
#pragma endregion
#pragma region ATAN
		template<typename T>
		T Atan(T x, T y)
		{
			return static_cast<T>(std::atan2(static_cast<double>(x), static_cast<double>(y)));
		}
		template<size_t L, typename T>
		vector<L, T> Atan(vector<L, T> const& x, vector<L, T> const& y)
		{
			return COMP::func2(x, y, Atan);
		}
		template<typename T>
		T Atan(T x)
		{
			return static_cast<T>(std::atan(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> Atan(vector<L, T> const& x)
		{
			return COMP::func1(x, Atan);
		}
#pragma endregion
#pragma region SINH
		template<typename T>
		T SinH(T x)
		{
			return static_cast<T>(std::sinh(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> SinH(vector<L, T> const& x)
		{
			return COMP::func1(x, SinH);
		}
#pragma endregion
#pragma region COSH
		template<typename T>
		T CosH(T x)
		{
			return static_cast<T>(std::cosh(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> CosH(vector<L, T> const& x)
		{
			return COMP::func1(x, CosH);
		}
#pragma endregion
#pragma region TANH
		template<typename T>
		T TanH(T x)
		{
			return static_cast<T>(std::tanh(static_cast<double>(x)));
		}
		template<size_t L, typename T>
		vector<L, T> TanH(vector<L, T> const& x)
		{
			return COMP::func1(x, TanH);
		}
#pragma endregion
#pragma region ASINH
		template<typename T>
		T AsinH(T x)
		{
			static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");

			return (x < static_cast<T>(0) ? static_cast<T>(-1) : (x > static_cast<T>(0) ? static_cast<T>(1) : static_cast<T>(0))) * HML::Log(HML::Abs(x) + HML::Sqrt(static_cast<T>(1) + x * x));
		}
		template<size_t L, typename T>
		vector<L, T> AsinH(vector<L, T> const& x)
		{
			return COMP::func1(x, AsinH);
		}
#pragma endregion
#pragma region ACOSH
		template<typename T>
		T AcosH(T x)
		{
			static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");
			return x < static_cast<T>(1) ? static_cast<T>(0) : HML::Log(x + HML::Sqrt(x * x - static_cast<T>(1)));		
		}
		template<size_t L, typename T>
		vector<L, T> AcosH(vector<L, T> const& x)
		{
			return COMP::func1(x, AcosH);
		}
#pragma endregion
#pragma region ATANH
		template<typename T>
		T AtanH(T x)
		{
			static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");
			return HML::Abs(x) >= static_cast<T>(1) ? static_cast<T>(0) : static_cast<T>(0.5) * HML::Log((static_cast<T>(1) + x) / (static_cast<T>(1) - x));
		}
		template<size_t L, typename T>
		vector<L, T> AtanH(vector<L, T> const& x)
		{
			return COMP::func1(x, AtanH);
		}
#pragma endregion
#pragma region LENGTH
		template<typename T>
		T Length(T x)
		{
			return HML::Abs(x);
		}
		template<size_t L, typename T>
		vector<L, T> Length(vector<L, T> x)
		{
			return COMP::func1(x, Length);
		}
#pragma endregion
}