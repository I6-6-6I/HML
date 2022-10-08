#pragma once
//#include "setup.hpp"
HEADER_MATH_NAMESPACE
{
	template<size_t L, typename T> struct vector;
	template<size_t C, size_t R, typename T> struct matrix;
	template<typename T> struct quat;

	//Types----------------------------------------------------------------------------------------------------------------------
	#pragma region TYPES
	template <typename T = float> using Vector1		= vector<1, T>;
	template <typename T = float> using Vector2		= vector<2, T>;
	template <typename T = float> using Vector3		= vector<3, T>;
	template <typename T = float> using Vector4		= vector<4, T>;
	template <typename T = float> using Mat2x2		= matrix<2, 2, T>;
	template <typename T = float> using Mat2x3		= matrix<2, 3, T>;
	template <typename T = float> using Mat2x4		= matrix<2, 4, T>;
	template <typename T = float> using Mat3x2		= matrix<3, 2, T>;
	template <typename T = float> using Mat3x3		= matrix<3, 3, T>;
	template <typename T = float> using Mat3x4		= matrix<3, 4, T>;
	template <typename T = float> using Mat4x2		= matrix<4, 2, T>;
	template <typename T = float> using Mat4x3		= matrix<4, 3, T>;
	template <typename T = float> using Mat4x4		= matrix<4, 4, T>;
	template <typename T = float> using Quaternion	= quat<T>;
#pragma endregion								  
}