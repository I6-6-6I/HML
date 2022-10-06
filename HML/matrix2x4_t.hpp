#pragma once
#include "matrix_operations.hpp"
#include "vector2_t.hpp"
#include "vector4_t.hpp"
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct matrix<2, 4, T>
	{
	private:
		vector<4, T> values[2];
	public:
		//Access Operators------------------------------------------------------------------------------
	#pragma region ACCESS_OPERATORS
		vector<4, T>& operator[](size_t i)
		{
			return this->values[i];
		}
		vector<4, T> constexpr const& operator[](size_t i) const
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
		constexpr matrix() { values[0] = vector<4, T>(); values[1] = vector<4, T>(); }
		constexpr matrix(matrix<2, 4, T> const& mat) { *this = mat; }
		explicit constexpr matrix(T scalar) { values[0] = vector<4, T>(scalar, scalar, scalar, scalar); values[1] = vector<4, T>(scalar, scalar, scalar, scalar); }
		constexpr matrix(T const& x1, T const& y1, T const& z1, T const& w1, T const& x2, T const& y2, T const& z2, T const& w2)
		{
			this->values[0].x = x1; this->values[0].y = y1; this->values[0].z = z1; this->values[0].w = w1;
			this->values[1].x = x2; this->values[1].y = y2; this->values[1].z = z2; this->values[1].w = w2;
		}
		constexpr matrix(vector<4, T> const& v1, vector<4, T> const& v2) { this->values[0] = v1; this->values[1] = v2; }
	#pragma endregion

		//Conversions-----------------------------------------------------------------------------------
	#pragma region CONVERSIONS
		template<typename U, typename V, typename M, typename N, typename K, typename S, typename P, typename Z>
		constexpr matrix(U const& x1, V const& y1, K const& z1, P const& w1, M const& x2, N const& y2, S const& z2, Z const& w2)
		{
			this->values[0].x = x1; this->values[0].y = y1; this->values[0].z = z1; this->values[0].w = w1;
			this->values[1].x = x2; this->values[1].y = y2; this->values[1].z = z2; this->values[1].w = w2;
		}

		template<typename U, typename V>
		constexpr matrix(vector<4, U> const& v1, vector<4, V> const& v2) { this->values[0] = v1; this->values[1] = v2; }

		template<typename U>
		explicit constexpr matrix(matrix<2, 4, U> const& mat)
		{
			this->values[0] = static_cast<vector<4, T>>(mat.values[0]);
			this->values[1] = static_cast<vector<4, T>>(mat.values[1]);
		}

		explicit constexpr matrix(matrix<2, 2, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = static_cast<T>(0);
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = static_cast<T>(0);
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<2, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][2];
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<3, 2, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = static_cast<T>(0);
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = static_cast<T>(0);
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<3, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][2];
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<3, 4, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
		}
		explicit constexpr matrix(matrix<4, 2, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = static_cast<T>(0);
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = static_cast<T>(0);
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<4, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][2];
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<4, 4, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
		}
	#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
	#pragma region ARITHMETHIC_OPERATORS
		template<typename U>
		matrix<2, 4, T>& operator=(matrix<2, 4, U> const& matrix)
		{
			this->values[0] = static_cast<T>(matrix[0]);
			this->values[1] = static_cast<T>(matrix[1]);
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator+=(U s)
		{
			this->values[0] += s;
			this->values[1] += s;
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator+=(matrix<2, 4, U> const& matrix)
		{
			this->values[0] += matrix[0];
			this->values[1] += matrix[1];
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator-=(U s)
		{
			this->values[0] -= s;
			this->values[1] -= s;
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator-=(matrix<2, 4, U> const& matrix)
		{
			this->values[0] -= matrix[0];
			this->values[1] -= matrix[1];
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator*=(U s)
		{
			this->values[0] *= s;
			this->values[1] *= s;
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator*=(matrix<2, 4, U> const& matrix)
		{
			return  (*this = *this * matrix);
		}
		template<typename U>
		matrix<2, 4, T>& operator/=(U s)
		{
			this->values[0] /= s;
			this->values[1] /= s;
			return *this;
		}
		template<typename U>
		matrix<2, 4, T>& operator/=(matrix<2, 4, U> const& matrix)
		{
			return  (*this = *this * inverse(matrix));
		}
	#pragma endregion

		//Increment and Decrement Operators-------------------------------------------------------------
	#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		matrix<2, 4, T>& operator++ ()
		{
			 this->values[0]++;
			 this->values[1]++;
			 return *this;
		}
		matrix<2, 4, T>& operator--()
		{
			 this->values[0]--;
			 this->values[1]--;
			 return *this;
		}
		matrix<2, 4, T> operator++(int)
		{
			 matrix<2, 4, T> ret(*this);
			 ++*this;
			 return ret;
		}
		matrix<2, 4, T> operator--(int)
		{
			 matrix<2, 4, T> ret(*this);
			 --*this;
			 return ret;
		}
	#pragma endregion
	};
	//Unary Arithmetic Operators--------------------------------------------------------------------
#pragma region UNARY_ARITHMETIC_OPERATORS
	template<typename T>
	matrix<2, 4, T> operator+(matrix<2, 4, T> const& m)
	{
		return m;
	}

	template<typename T>
	matrix<2, 4, T> operator-(matrix<2, 4, T> const& m)
	{
		return matrix<2, 4, T>(
			-m[0],
			-m[1]);
	}
#pragma endregion
	//Binary Arithmetic Operators-------------------------------------------------------------------
#pragma region BINARY_ARITHMETHIC_OPERATORS
	template<typename T>
	matrix<2, 4, T> operator+(matrix<2, 4, T> const& m, T scalar)
	{
		return matrix<2, 4, T>(m[0] + scalar, m[1] + scalar);
	}

	template<typename T>
	matrix<2, 4, T> operator+(matrix<2, 4, T> const& m1, matrix<2, 4, T> const& m2)
	{
		return matrix<2, 3, T>(m1[0] + m2[0], m1[1] + m2[1]);
	}

	template<typename T>
	matrix<2, 4, T> operator-(matrix<2, 4, T> const& m, T scalar)
	{
		return matrix<2, 3, T>(m[0] - scalar, m[1] - scalar);
	}

	template<typename T>
	matrix<2, 4, T> operator-(matrix<2, 4, T> const& m1, matrix<2, 4, T> const& m2)
	{
		return matrix<2, 4, T>(m1[0] - m2[0], m1[1] - m2[1]);
	}

	template<typename T>
	matrix<2, 4, T> operator*(matrix<2, 4, T> const& m, T scalar)
	{
		return matrix<2, 4, T>(m[0] * scalar, m[1] * scalar);
	}

	template<typename T>
	matrix<2, 4, T> operator*(T scalar, matrix<2, 4, T> const& m)
	{
		return matrix<2, 4, T>(m[0] * scalar, m[1] * scalar);
	}

	template<typename T>
	vector<4, T> operator*(matrix<2, 4, T> const& m, vector<2, T> const& v)
	{
		return vector<4, T>(
			m[0][0] * v.x + m[1][0] * v.y,
			m[0][1] * v.x + m[1][1] * v.y,
			m[0][2] * v.x + m[1][2] * v.y,
			m[0][3] * v.x + m[1][3] * v.y);
	}

	template<typename T>
	vector<2, T> operator*(vector<4, T> const& v, matrix<2, 4, T> const& m)
	{
		return vector<2, T>(
			v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3],
			v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3]);
	}

	template<typename T>
	matrix<2, 4, T> operator*(matrix<2, 4, T> const& m1, matrix<2, 2, T> const& m2)
	{
		return matrix<2, 4, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1]);
	}

	template<typename T>
	matrix<3, 4, T> operator*(matrix<2, 4, T> const& m1, matrix<3, 2, T> const& m2)
	{
		return matrix<3, 4, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1]);
	}

	template<typename T>
	matrix<4, 4, T> operator*(matrix<2, 4, T> const& m1, matrix<4, 2, T> const& m2)
	{
		matrix<4, 4, T> ret;
		ret[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1];
		ret[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1];
		ret[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1];
		ret[0][3] = m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1];
		ret[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1];
		ret[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1];
		ret[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1];
		ret[1][3] = m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1];
		ret[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1];
		ret[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1];
		ret[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1];
		ret[2][3] = m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1];
		ret[3][0] = m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1];
		ret[3][1] = m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1];
		ret[3][2] = m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1];
		ret[3][3] = m1[0][3] * m2[3][0] + m1[1][3] * m2[3][1];
		return ret;
	}

	template<typename T>
	matrix<2, 4, T> operator/(matrix<2, 4, T> const& m, T scalar)
	{
		return matrix<2, 4, T>(
			m[0] / scalar,
			m[1] / scalar);
	}

	template<typename T>
	matrix<2, 4, T> operator/(T scalar, matrix<2, 4, T> const& m)
	{
		return matrix<2, 4, T>(
			scalar / m[0],
			scalar / m[1]);
	}
#pragma endregion

	//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
	template<typename T>
	bool operator==(matrix<2, 4, T> const& m1, matrix<2, 4, T> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]);
	}

	template<typename T>
	bool operator!=(matrix<2, 4, T> const& m1, matrix<2, 4, T> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]);
	}
#pragma endregion
}