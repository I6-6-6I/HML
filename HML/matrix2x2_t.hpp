#pragma once
#include "vector2_t.hpp"
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct matrix<2, 2, T>
	{
	private:
		vector<2, T> values[2];
	public:
	vector<2, T>& operator[](size_t i)
	{
		static_assert(i < this->length());
		return this->values[i];
	}
	vector<2, T> constexpr const& operator[](size_t i) const
	{
		static_assert(i < this->length());
		return this->values[i];
	}
	static constexpr size_t length() { return 2; }
	//Construtors-----------------------------------------------------------------------------------
#pragma region CONSTRUCTORS
	constexpr matrix() { values[0] = vector<2, T>(); values[0] = vector<2, T>(); }
	constexpr matrix(matrix<2, 2, T> const& mat) { *this = mat; }
	explicit constexpr matrix(T scalar) { values[0] = vector<2, T>(scalar, scalar); values[0] = vector<2, T>(scalar, scalar); }
	constexpr matrix(T const& x1, T const& y1, T const& x2, T const& y2) { this->values[0].x = x1; this->values[0].y = y1; this->values[1].x = x2; this->values[1].y = y2; }
	constexpr matrix(vector<2, T> const& v1, vector<2, T> const& v2) { this->values[0] = v1; this->values[1] = v2; }
#pragma endregion

	//Conversions-----------------------------------------------------------------------------------
#pragma region CONVERSIONS
	template<typename U, typename V, typename M, typename N>
	constexpr matrix(U const& x1, V const& y1, M const& x2, N const& y2)
	{
		this->values[0].x = x1; this->valuesp[0].y = y1;
		this->values[1].x = x2; this->valuesp[1].y = y2;
	}

	template<typename U, typename V>
	constexpr matrix(vector<2, U> const& v1, vector<2, V> const& v2) { this->values[0] = v1; this->values[1] = v2; }

	template<typename U>
	explicit constexpr matrix(matrix<2, 2, U> const& m);

	explicit constexpr matrix(matrix<3, 3, T> const& x);
	explicit constexpr matrix(matrix<4, 4, T> const& x);
	explicit constexpr matrix(matrix<2, 3, T> const& x);
	explicit constexpr matrix(matrix<3, 2, T> const& x);
	explicit constexpr matrix(matrix<2, 4, T> const& x);
	explicit constexpr matrix(matrix<4, 2, T> const& x);
	explicit constexpr matrix(matrix<3, 4, T> const& x);
	explicit constexpr matrix(matrix<4, 3, T> const& x);
#pragma endregion
	};
}