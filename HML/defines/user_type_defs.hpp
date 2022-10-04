#pragma once
//#include "setup.hpp"
HEADER_MATH_NAMESPACE
{
	template<size_t L, typename T> struct vector;
	template<size_t C, size_t R, typename T> struct matrix;
	template<typename T> struct quat;

	//Types-------------------------------------------------------------------------------------------------------------------------
	#pragma region TYPES
	template <typename T> using vector1_t		= vector<1, T>;
	template <typename T> using vector2_t		= vector<2, T>;
	template <typename T> using vector3_t		= vector<3, T>;
	template <typename T> using vector4_t		= vector<4, T>;
	template <typename T> using matrix2x2_t		= matrix<2, 2, T>;
	template <typename T> using matrix2x3_t		= matrix<2, 3, T>;
	template <typename T> using matrix2x4_t		= matrix<2, 4, T>;
	template <typename T> using matrix3x2_t		= matrix<3, 2, T>;
	template <typename T> using matrix3x3_t		= matrix<3, 3, T>;
	template <typename T> using matrix3x4_t		= matrix<3, 4, T>;
	template <typename T> using matrix4x2_t		= matrix<4, 2, T>;
	template <typename T> using matrix4x3_t		= matrix<4, 3, T>;
	template <typename T> using matrix4x4_t		= matrix<4, 4, T>;
	template <typename T> using quat_t			= quat<T>;
	#pragma endregion

	//Declares----------------------------------------------------------------------------------------------------------------------
	#pragma region DECLARES
	DECLARE_VECTOR1
	DECLARE_VECTOR2
	DECLARE_VECTOR3
	DECLARE_VECTOR4

	DECLARE_MAT2
	#pragma endregion
}