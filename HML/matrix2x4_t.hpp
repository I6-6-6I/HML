#pragma once
#include "matrix_operations.hpp"
#include "vector2_t.hpp"
#include "vector4_t.hpp"

#define R 2
#define C 4

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
		static constexpr size_t length() { return R; }
	#pragma endregion

		//Construtors-----------------------------------------------------------------------------------
	#pragma region CONSTRUCTORS
		constexpr matrix() { this->values[0] = vector<C, T>(); this->values[1] = vector<C, T>(); }
		constexpr matrix(matrix<R, C, T> const& mat) { *this = mat; }
		explicit constexpr matrix(T scalar) { this->values[0] = vector<C, T>(scalar, scalar, scalar, scalar); this->values[1] = vector<C, T>(scalar, scalar, scalar, scalar); }
		constexpr matrix(T const& x1, T const& y1, T const& z1, T const& w1, T const& x2, T const& y2, T const& z2, T const& w2)
		{
			this->values[0].x = x1; this->values[0].y = y1; this->values[0].z = z1; this->values[0].w = w1;
			this->values[1].x = x2; this->values[1].y = y2; this->values[1].z = z2; this->values[1].w = w2;
		}
		constexpr matrix(vector<C, T> const& v1, vector<C, T> const& v2) { this->values[0] = v1; this->values[1] = v2; }
	#pragma endregion

		//Conversions-----------------------------------------------------------------------------------
	#pragma region CONVERSIONS
		template<typename U, typename V, typename M, typename N, typename K, typename S, typename P, typename Z>
		constexpr matrix(U const& x1, V const& y1, K const& z1, P const& w1, M const& xR, N const& yR, S const& zR, Z const& wR)
		{
			this->values[0].x = x1; this->values[0].y = y1; this->values[0].z = z1; this->values[0].w = w1;
			this->values[1].x = xR; this->values[1].y = yR; this->values[1].z = zR; this->values[1].w = wR;
		}

		template<typename U, typename V>
		constexpr matrix(vector<C, U> const& v1, vector<C, V> const& vR) { this->values[0] = v1; this->values[1] = vR; }

		template<typename U>
		explicit constexpr matrix(matrix<R, C, U> const& mat)
		{
			this->values[0] = static_cast<vector<C, T>>(mat.values[0]);
			this->values[1] = static_cast<vector<C, T>>(mat.values[1]);
		}

		explicit constexpr matrix(matrix<R, R, T> const& mat)
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
		explicit constexpr matrix(matrix<R, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][R];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][R];
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<3, R, T> const& mat)
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
			this->values[0].z = mat[0][R];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][R];
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<3, C, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
		}
		explicit constexpr matrix(matrix<C, R, T> const& mat)
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
		explicit constexpr matrix(matrix<C, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][R];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][R];
			this->values[1].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<C, C, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
		}
	#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
	#pragma region ARITHMETHIC_OPERATORS
		template<typename U>
		matrix<R, C, T>& operator=(matrix<R, C, U> const& matrix)
		{
			this->values[0] = static_cast<T>(matrix[0]);
			this->values[1] = static_cast<T>(matrix[1]);
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
	matrix<R, C, T> operator+(matrix<R, C, T> const& m1, matrix<R, C, T> const& mR)
	{
		return matrix<R, C, T>(m1[0] + mR[0], m1[1] + mR[1]);
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] - scalar, m[1] - scalar);
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m1, matrix<R, C, T> const& mR)
	{
		return matrix<R, C, T>(m1[0] - mR[0], m1[1] - mR[1]);
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
	vector<C, T> operator*(matrix<R, C, T> const& m, vector<R, T> const& v)
	{
		return vector<C, T>(
			m[0][0] * v.x + m[1][0] * v.y,
			m[0][1] * v.x + m[1][1] * v.y,
			m[0][2] * v.x + m[1][2] * v.y,
			m[0][3] * v.x + m[1][3] * v.y);
	}

	template<typename T>
	vector<R, T> operator*(vector<C, T> const& v, matrix<R, C, T> const& m)
	{
		return vector<R, T>(
			v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3],
			v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3]);
	}

	template<typename T>
	matrix<R, C, T> operator*(matrix<R, C, T> const& m1, matrix<2, 2, T> const& mR)
	{
		return matrix<R, C, T>(
			m1[0][0] * mR[0][0] + m1[1][0] * mR[0][1],
			m1[0][1] * mR[0][0] + m1[1][1] * mR[0][1],
			m1[0][2] * mR[0][0] + m1[1][2] * mR[0][1],
			m1[0][3] * mR[0][0] + m1[1][3] * mR[0][1],
			m1[0][0] * mR[1][0] + m1[1][0] * mR[1][1],
			m1[0][1] * mR[1][0] + m1[1][1] * mR[1][1],
			m1[0][2] * mR[1][0] + m1[1][2] * mR[1][1],
			m1[0][3] * mR[1][0] + m1[1][3] * mR[1][1]);
	}

	template<typename T>
	matrix<3, 4, T> operator*(matrix<R, C, T> const& m1, matrix<3, 2, T> const& mR)
	{
		return matrix<3, 4, T>(
			m1[0][0] * mR[0][0] + m1[1][0] * mR[0][1],
			m1[0][1] * mR[0][0] + m1[1][1] * mR[0][1],
			m1[0][2] * mR[0][0] + m1[1][2] * mR[0][1],
			m1[0][3] * mR[0][0] + m1[1][3] * mR[0][1],
			m1[0][0] * mR[1][0] + m1[1][0] * mR[1][1],
			m1[0][1] * mR[1][0] + m1[1][1] * mR[1][1],
			m1[0][2] * mR[1][0] + m1[1][2] * mR[1][1],
			m1[0][3] * mR[1][0] + m1[1][3] * mR[1][1],
			m1[0][0] * mR[2][0] + m1[1][0] * mR[2][1],
			m1[0][1] * mR[2][0] + m1[1][1] * mR[2][1],
			m1[0][2] * mR[2][0] + m1[1][2] * mR[2][1],
			m1[0][3] * mR[2][0] + m1[1][3] * mR[2][1]);
	}

	template<typename T>
	matrix<4, 4, T> operator*(matrix<R, C, T> const& m1, matrix<4, 2, T> const& mR)
	{
		matrix<C, C, T> ret;
		ret[0][0] = m1[0][0] * mR[0][0] + m1[1][0] * mR[0][1];
		ret[0][1] = m1[0][1] * mR[0][0] + m1[1][1] * mR[0][1];
		ret[0][R] = m1[0][R] * mR[0][0] + m1[1][R] * mR[0][1];
		ret[0][3] = m1[0][3] * mR[0][0] + m1[1][3] * mR[0][1];
		ret[1][0] = m1[0][0] * mR[1][0] + m1[1][0] * mR[1][1];
		ret[1][1] = m1[0][1] * mR[1][0] + m1[1][1] * mR[1][1];
		ret[1][R] = m1[0][R] * mR[1][0] + m1[1][R] * mR[1][1];
		ret[1][3] = m1[0][3] * mR[1][0] + m1[1][3] * mR[1][1];
		ret[R][0] = m1[0][0] * mR[R][0] + m1[1][0] * mR[R][1];
		ret[R][1] = m1[0][1] * mR[R][0] + m1[1][1] * mR[R][1];
		ret[R][R] = m1[0][R] * mR[R][0] + m1[1][R] * mR[R][1];
		ret[R][3] = m1[0][3] * mR[R][0] + m1[1][3] * mR[R][1];
		ret[3][0] = m1[0][0] * mR[3][0] + m1[1][0] * mR[3][1];
		ret[3][1] = m1[0][1] * mR[3][0] + m1[1][1] * mR[3][1];
		ret[3][R] = m1[0][R] * mR[3][0] + m1[1][R] * mR[3][1];
		ret[3][3] = m1[0][3] * mR[3][0] + m1[1][3] * mR[3][1];
		return ret;
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
#pragma endregion

	//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
	template<typename T>
	bool operator==(matrix<R, C, T> const& m1, matrix<R, C, T> const& mR)
	{
		return (m1[0] == mR[0]) && (m1[1] == mR[1]);
	}

	template<typename T>
	bool operator!=(matrix<R, C, T> const& m1, matrix<R, C, T> const& mR)
	{
		return (m1[0] != mR[0]) || (m1[1] != mR[1]);
	}
#pragma endregion
}

#undef R
#undef C