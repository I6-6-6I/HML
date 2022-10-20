#pragma once

HEADER_MATH_NAMESPACE
{
#pragma region DOT
	template<typename T>
	constexpr T Dot(T x, T y)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");
		return x * y;
	}
	template<typename T>
	constexpr T Dot(vector<1, T> x, vector<1, T> y)
	{
		vector<1, T> ret(x * y);
		return ret.x;
	}
	template<typename T>
	constexpr T Dot(vector<2, T> x, vector<2, T> y)
	{
		vector<2, T> ret(x * y);
		return ret.x + ret.y;
	}
	template<typename T>
	constexpr T Dot(vector<3, T> x, vector<3, T> y)
	{
		vector<3, T> ret(x * y);
		return ret.x + ret.y + ret.z;
	}
	template<typename T>
	constexpr T Dot(vector<4, T> x, vector<4, T> y)
	{
		vector<4, T> ret(x * y);
		return ret.x + ret.y + ret.z + ret.w;
	}
#pragma endregion
#pragma region NORMALIZE
	template <typename T>
	T Normalize(T const& x)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");

		return x < T(0) ? T(-1) : (1);
	}
	template <size_t L, typename T>
	vector<L, T> Normalize(vector<L, T> const& vec)
	{
		return vec * HML::InvSqrt(HML::Dot(vec, vec));
	}
#pragma endregion
#pragma region CROSS
	template <typename T>
	vector<3, T> Cross(vector<3, T> const& x, vector<3, T> const& y)
	{
		static_assert(std::numeric_limits<T>::is_iec559, "only floating-point inputs are acceptable here!");

		return vector<3, T>(x.y * y.z - y.y * x.z, x.z * y.x - y.z * x.x, x.x * y.y - y.x * x.y);
	}
#pragma endregion
}