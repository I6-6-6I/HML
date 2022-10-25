#pragma once
#include "matrix_operations.hpp"
#define R 2
#define C 2

HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct matrix<R, C, T>
	{
	private:
		vector<C, T> values[R];
	public:
	//Access Operators------------------------------------------------------------------------------
#pragma region ACCESS_OPERATORS
	vector<C, T>& operator[](size_t i)
	{
		return this->values[i];
	}
	vector<C, T> constexpr const& operator[](size_t i) const
	{
		return this->values[i];
	}
#pragma endregion

	//Static Funcs----------------------------------------------------------------------------------
#pragma region STATIC_FUNCS
	static constexpr size_t length() { return 2; }
#pragma endregion

	//Construtors-----------------------------------------------------------------------------------
#pragma region CONSTRUCTORS
	constexpr matrix() { this->values[0] = vector<C, T>(); this->values[1] = vector<C, T>(); }
	constexpr matrix(matrix<R, C, T> const& mat) { *this = mat; }
	explicit constexpr matrix(T scalar) { this->values[0] = vector<C, T>(scalar, static_cast<T>(0)); this->values[1] = vector<C, T>(static_cast<T>(0), scalar); }
	constexpr matrix(T const& x1, T const& y1, T const& x2, T const& y2) { this->values[0].x = x1; this->values[0].y = y1; this->values[1].x = x2; this->values[1].y = y2; }
	constexpr matrix(vector<C, T> const& v1, vector<C, T> const& v2) { this->values[0] = v1; this->values[1] = v2; }
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
	constexpr matrix(vector<C, U> const& v1, vector<C, V> const& v2) { this->values[0] = v1; this->values[1] = v2; }

	template<typename U>
	explicit constexpr matrix(matrix<R, C, U> const& mat)
	{
		this->values[0] = static_cast<vector<C, T>>(mat.values[0]);
		this->values[1] = static_cast<vector<C, T>>(mat.values[1]);
	}

	explicit constexpr matrix(matrix<2, 3, T> const& mat)
	{
		this->values[0].x = mat[0][0];
		this->values[0].y = mat[0][1];
		this->values[1].x = mat[1][0];
		this->values[1].y = mat[1][1];
	}
	explicit constexpr matrix(matrix<2, 4, T> const& mat)
	{
		this->values[0].x = mat[0][0];
		this->values[0].y = mat[0][1];
		this->values[1].x = mat[1][0];
		this->values[1].y = mat[1][1];
	}
	explicit constexpr matrix(matrix<3, 2, T> const& mat)
	{ 
		this->values[0] = mat[0];
		this->values[1] = mat[1];
	}
	explicit constexpr matrix(matrix<3, 3, T> const& mat)
	{ 
		this->values[0].x = mat[0][0];
		this->values[0].y = mat[0][1];
		this->values[1].x = mat[1][0];
		this->values[1].y = mat[1][1];
	}
	explicit constexpr matrix(matrix<3, 4, T> const& mat)
	{
		this->values[0].x = mat[0][0];
		this->values[0].y = mat[0][1];
		this->values[1].x = mat[1][0];
		this->values[1].y = mat[1][1];
	}
	explicit constexpr matrix(matrix<4, 2, T> const& mat)
	{
		this->values[0] = mat[0];
		this->values[1] = mat[1];
	}
	explicit constexpr matrix(matrix<4, 3, T> const& mat)
	{ 
		this->values[0].x = mat[0][0];
		this->values[0].y = mat[0][1];
		this->values[1].x = mat[1][0];
		this->values[1].y = mat[1][1];
	}
	explicit constexpr matrix(matrix<4, 4, T> const& mat)
	{ 
		this->values[0].x = mat[0][0];
		this->values[0].y = mat[0][1];
		this->values[1].x = mat[1][0];
		this->values[1].y = mat[1][1];
	}
#pragma endregion

	//Arithmetic Operators--------------------------------------------------------------------------
#pragma region ARITHMETHIC_OPERATORS
	template<typename U>
	matrix<R, C, T>& operator=(matrix<R, C, U> const& matrix)
	{
		this->values[0] = matrix[0];
		this->values[1] = matrix[1];
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator+=(U s)
	{
		this->values[0] += s;
		this->values[1] += s;
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator+=(matrix<R, C, U> const& matrix)
	{
		this->values[0] += matrix[0];
		this->values[1] += matrix[1];
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator-=(U s)
	{
		this->values[0] -= s;
		this->values[1] -= s;
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator-=(matrix<R, C, U> const& matrix)
	{
		this->values[0] -= matrix[0];
		this->values[1] -= matrix[1];
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator*=(U s)
	{
		this->values[0] *= s;
		this->values[1] *= s;
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator*=(matrix<R, C, U> const& matrix)
	{
		return  (*this = *this * matrix);
	}
	template<typename U>
	matrix<R, C, T>& operator/=(U s)
	{
		this->values[0] /= s;
		this->values[1] /= s;
		return *this;
	}
	template<typename U>
	matrix<R, C, T>& operator/=(matrix<R, C, U> const& matrix)
	{
		return  (*this = *this * inverse(matrix));
	}
#pragma endregion

	//Increment and Decrement Operators-------------------------------------------------------------
#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		matrix<R, C, T>& operator++ ()
		{
			 this->values[0]++;
			 this->values[1]++;
			 return *this;
		}
		matrix<R, C, T>& operator--()
		{
			 this->values[0]--;
			 this->values[1]--;
			 return *this;
		}
		matrix<R, C, T> operator++(int)
		{
			 matrix<R, C, T> ret(*this);
			 ++*this;
			 return ret;
		}
		matrix<R, C, T> operator--(int)
		{
			 matrix<R, C, T> ret(*this);
			 --*this;
			 return ret;
		}
#pragma endregion
	};
	//Unary Arithmetic Operators--------------------------------------------------------------------
#pragma region UNARY_ARITHMETIC_OPERATORS
	template<typename T>
	matrix<R, C, T> operator+(matrix<R, C, T> const& m)
	{
		return m;
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m)
	{
		return matrix<R, C, T>(
			-m[0],
			-m[1]);
	}
#pragma endregion

	//Binary Arithmetic Operators-------------------------------------------------------------------
#pragma region BINARY_ARITHMETHIC_OPERATORS
	template<typename T>
	matrix<R, C, T> operator+(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] + scalar, m[1] + scalar);
	}

	template<typename T>
	matrix<R, C, T> operator+(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return matrix<R, C, T>(m1[0] + m2[0], m1[1] + m2[1]);
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] - scalar, m[1] - scalar);
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return matrix<C, 3, T>(m1[0] - m2[0], m1[1] - m2[1]);
	}

	template<typename T>
	matrix<R, C, T> operator*(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] * scalar, m[1] * scalar);
	}

	template<typename T>
	matrix<R, C, T> operator*(T scalar, matrix<R, C, T> const& m)
	{
		return matrix<R, C, T>(m[0] * scalar, m[1] * scalar);
	}

	template<typename T>
	vector<C, T> operator*(matrix<R, C, T> const& m, vector<C, T> const& v)
	{
		return vector<C, T>(
			m[0][0] * v.x + m[1][0] * v.y,
			m[0][1] * v.x + m[1][1] * v.y);
	}

	template<typename T>
	vector<C, T> operator*(vector<C, T> const& v, matrix<R, C, T> const& m)
	{
		return vector<C, T>(
			v.x * m[0][0] + v.y * m[0][1],
			v.x * m[1][0] + v.y * m[1][1]);
	}

	template<typename T>
	matrix<R, C, T> operator*(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return matrix<R, C, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1]);
	}

	template<typename T>
	matrix<3, 2, T> operator*(matrix<R, C, T> const& m1, matrix<3, 2, T> const& m2)
	{
		return matrix<3, 2, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1]);
	}

	template<typename T>
	matrix<4, 2, T> operator*(matrix<R, C, T> const& m1, matrix<4, 2, T> const& m2)
	{
		return matrix<4, 2, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1]);
	}

	template<typename T>
	matrix<R, C, T> operator/(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(
			m[0] / scalar,
			m[1] / scalar);
	}

	template<typename T>
	matrix<R, C, T> operator/(T scalar, matrix<R, C, T> const& m)
	{
		return matrix<R, C, T>(
			scalar / m[0],
			scalar / m[1]);
	}

	template<typename T>
	vector<C,T> operator/(matrix<R, C, T> const& m, vector<C, T> const& v)
	{
		return HML::Inverse(m) * v;
	}

	template<typename T>
	vector<C,T> operator/(vector<C, T> const& v, matrix<R, C, T> const& m)
	{
		return v *  HML::Inverse(m);
	}

	template<typename T>
	matrix<R, C, T> operator/(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		matrix<R, C, T> m1_copy(m1);
		return m1_copy /= m2;
	}
#pragma endregion

	//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
	template<typename T>
	bool operator==(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]);
	}

	template<typename T>
	bool operator!=(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]);
	}
#pragma endregion
}

#undef R
#undef C