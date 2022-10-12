#pragma once
#include "matrix_operations.hpp"
#define R 4
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
		constexpr matrix() { this->values[0] = vector<C, T>(); this->values[1] = vector<C, T>(); this->values[2] = vector<C, T>(); this->values[3] = vector<C, T>(); }
		constexpr matrix(matrix<R, C, T> const& mat) { *this = mat; }
		explicit constexpr matrix(T scalar)
		{
			this->values[0] = vector<C, T>(scalar, scalar, scalar, scalar);
			this->values[1] = vector<C, T>(scalar, scalar, scalar, scalar);
			this->values[2] = vector<C, T>(scalar, scalar, scalar, scalar);
			this->values[3] = vector<C, T>(scalar, scalar, scalar, scalar);
		}
		constexpr matrix(T const& x1, T const& y1, T const& z1, T const& w1,
			T const& x2, T const& y2, T const& z2, T const& w2, T const& x3,
			T const& y3, T const& z3, T const& w3, T const& x4, T const& y4, T const& z4, T const& w4)
		{
			this->values[0].x = x1; this->values[0].y = y1;	this->values[0].z = z1;	this->values[0].w = w1;
			this->values[1].x = x2; this->values[1].y = y2;	this->values[1].z = z2;	this->values[1].w = w2;
			this->values[2].x = x3; this->values[2].y = y3;	this->values[2].z = z3;	this->values[2].w = w3;
			this->values[3].x = x4; this->values[3].y = y4;	this->values[3].z = z4;	this->values[3].w = w4;
		}
		constexpr matrix(vector<C, T> const& v1, vector<C, T> const& v2, vector<C, T> const& v3, vector<C, T> const& v4) { this->values[0] = v1; this->values[1] = v2; this->values[2] = v3; this->values[3] = v4; }
	#pragma endregion

		//Conversions-----------------------------------------------------------------------------------
	#pragma region CONVERSIONS
		template<typename U, typename V, typename M, typename N, typename P, typename D, typename Z, typename Y,
		typename S, typename B, typename O, typename Q, typename W, typename E, typename I, typename A>
		constexpr matrix(U const& x1, V const& y1, S const& z1, W const& w1, M const& x2,
			N const& y2, B const& z2, E const& w2, P const& x3, D const& y3, O const& z3, I const& w3,
			Z const& x4, Y const& y4, Q const& z4, A const& w4)
		{
			this->values[0].x = x1; this->valuesp[0].y = y1; this->valuesp[0].z = z1; this->valuesp[0].w = w1;
			this->values[1].x = x2; this->valuesp[1].y = y2; this->valuesp[1].z = z2; this->valuesp[1].w = w2;
			this->values[2].x = x3; this->valuesp[2].y = y3; this->valuesp[2].z = z3; this->valuesp[2].w = w3;
			this->values[3].x = x4; this->valuesp[3].y = y4; this->valuesp[3].z = z4; this->valuesp[3].w = w4;
		}

		template<typename U, typename V, typename Z, typename D>
		constexpr matrix(vector<C, U> const& v1, vector<C, V> const& v2, vector<C, Z> const& v3, vector<C, D> const& v4) { this->values[0] = v1; this->values[1] = v2; this->values[2] = v3; this->values[3] = v4; }

		template<typename U>
		explicit constexpr matrix(matrix<R, C, U> const& mat)
		{
			this->values[0] = static_cast<vector<C, T>>(mat.values[0]);
			this->values[1] = static_cast<vector<C, T>>(mat.values[1]);
			this->values[2] = static_cast<vector<C, T>>(mat.values[2]);
			this->values[3] = static_cast<vector<C, T>>(mat.values[3]);
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
			this->values[2] = vector<C, T>();
			this->values[3] = vector<C, T>();
		}

		explicit constexpr matrix(matrix<2, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[1][2];
			this->values[1].w = static_cast<T>(0);
			this->values[2] = vector<C, T>();
			this->values[3] = vector<C, T>();

		}
		explicit constexpr matrix(matrix<2, 4, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
			this->values[2] = vector<C, T>();
			this->values[3] = vector<C, T>();
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
			this->values[2].x = mat[2][0];
			this->values[2].y = mat[2][1];
			this->values[2].z = static_cast<T>(0);
			this->values[2].w = static_cast<T>(0);
			this->values[3] = vector<C, T>();
		}
		explicit constexpr matrix(matrix<3, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[1][2];
			this->values[1].w = static_cast<T>(0);
			this->values[2].x = mat[2][0];
			this->values[2].y = mat[2][1];
			this->values[2].z = mat[2][2];
			this->values[2].w = static_cast<T>(0);
			this->values[3] = vector<C, T>();
		}
		explicit constexpr matrix(matrix<3, 4, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
			this->values[2] = mat[2];
			this->values[3] = vector<C, T>();
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
			this->values[2].x = mat[2][0];
			this->values[2].y = mat[2][1];
			this->values[2].z = static_cast<T>(0);
			this->values[2].w = static_cast<T>(0);
			this->values[3].x = mat[3][0];
			this->values[3].y = mat[3][1];
			this->values[3].z = static_cast<T>(0);
			this->values[3].w = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<4, 3, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[0].w = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[1][2];
			this->values[1].w = static_cast<T>(0);
			this->values[2].x = mat[2][0];
			this->values[2].y = mat[2][1];
			this->values[2].z = mat[2][2];
			this->values[2].w = static_cast<T>(0);
			this->values[3].x = mat[3][0];
			this->values[3].y = mat[3][1];
			this->values[3].z = mat[3][2];
			this->values[3].w = static_cast<T>(0);
		}
	#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
	#pragma region ARITHMETHIC_OPERATORS
		template<typename U>
		matrix<R, C, T>& operator=(matrix<R, C, U> const& matrix)
		{
			this->values[0] = matrix[0];
			this->values[1] = matrix[1];
			this->values[2] = matrix[2];
			this->values[3] = matrix[3];
			return *this;
		}
		template<typename U>
		matrix<R, C, T>& operator+=(U s)
		{
			this->values[0] += s;
			this->values[1] += s;
			this->values[2] += s;
			this->values[3] += s;
			return *this;
		}
		template<typename U>
		matrix<R, C, T>& operator+=(matrix<R, C, U> const& matrix)
		{
			this->values[0] += matrix[0];
			this->values[1] += matrix[1];
			this->values[2] += matrix[2];
			this->values[3] += matrix[3];
			return *this;
		}
		template<typename U>
		matrix<R, C, T>& operator-=(U s)
		{
			this->values[0] -= s;
			this->values[1] -= s;
			this->values[2] -= s;
			this->values[3] -= s;
			return *this;
		}
		template<typename U>
		matrix<R, C, T>& operator-=(matrix<R, C, U> const& matrix)
		{
			this->values[0] -= matrix[0];
			this->values[1] -= matrix[1];
			this->values[2] -= matrix[2];
			this->values[3] -= matrix[3];
			return *this;
		}
		template<typename U>
		matrix<R, C, T>& operator*=(U s)
		{
			this->values[0] *= s;
			this->values[1] *= s;
			this->values[2] *= s;
			this->values[3] *= s;
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
			this->values[2] /= s;
			this->values[3] /= s;
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
				 this->values[2]++;
				 this->values[3]++;
				 return *this;
			}
			matrix<R, C, T>& operator--()
			{
				 this->values[0]--;
				 this->values[1]--;
				 this->values[2]--;
				 this->values[3]--;
				 return *this;
			}
			matrix<R, C, T> operator++(int)
			{
				 matrix<R, C, T> ret(*this);
				 ++* this;
				 return ret;
			}
			matrix<R, C, T> operator--(int)
			{
				 matrix<R, C, T> ret(*this);
				 --* this;
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
			-m[1],
			-m[2],
			-m[3]);
	}
#pragma endregion

	//Binary Arithmetic Operators-------------------------------------------------------------------
#pragma region BINARY_ARITHMETHIC_OPERATORS
	template<typename T>
	matrix<R, C, T> operator+(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar, m[3] + scalar);
	}

	template<typename T>
	matrix<R, C, T> operator+(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return matrix<R, C, T>(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2], m1[3] + m2[3]);
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar, m[3] - scalar);
	}

	template<typename T>
	matrix<R, C, T> operator-(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return matrix<R, C, T>(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2], m1[3] - m2[3]);
	}

	template<typename T>
	matrix<R, C, T> operator*(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
	}

	template<typename T>
	matrix<R, C, T> operator*(T scalar, matrix<R, C, T> const& m)
	{
		return matrix<R, C, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
	}

	template<typename T>
	vector<C, T> operator*(matrix<R, C, T> const& m, vector<R, T> const& v)
	{
		return vector<C, T>(
			m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w,
			m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w,
			m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2] * v.w,
			m[0][3] * v.x + m[1][3] * v.y + m[2][3] * v.z + m[3][3] * v.w);
	}

	template<typename T>
	vector<R, T> operator*(vector<C, T> const& v, matrix<R, C, T> const& m)
	{
		return vector<R, T>(
			v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3],
			v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + v.w * m[1][3],
			v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + v.w * m[2][3],
			v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + v.w * m[3][3]);
	}

	template<typename T>
	matrix<2, 4, T> operator*(matrix<R, C, T> const& m1, matrix<2, 4, T> const& m2)
	{
		return matrix<2, 4, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3]);
	}

	template<typename T>
	matrix<3, 4, T> operator*(matrix<R, C, T> const& m1, matrix<3, 4, T> const& m2)
	{
		return matrix<3, 4, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3]);
	}

	template<typename T>
	matrix<R, C, T> operator*(matrix<R, C, T> const& m1, matrix<4, 4, T> const& m2)
	{
		return matrix<R, C, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3],
			m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1] + m1[2][2] * m2[3][2] + m1[3][2] * m2[3][3],
			m1[0][3] * m2[3][0] + m1[1][3] * m2[3][1] + m1[2][3] * m2[3][2] + m1[3][3] * m2[3][3]);
	}

	template<typename T>
	matrix<R, C, T> operator/(matrix<R, C, T> const& m, T scalar)
	{
		return matrix<R, C, T>(
			m[0] / scalar,
			m[1] / scalar,
			m[2] / scalar,
			m[3] / scalar);
	}

	template<typename T>
	matrix<R, C, T> operator/(T scalar, matrix<R, C, T> const& m)
	{
		return matrix<R, C, T>(
			scalar / m[0],
			scalar / m[1],
			scalar / m[2],
			scalar / m[3]);
	}

	template<typename T>
	vector<C, T> operator/(matrix<R, C, T> const& m, vector<C, T> const& v)
	{
		return inverse(m) * v;
	}

	template<typename T>
	vector<C, T> operator/(vector<C, T> const& v, matrix<R, C, T> const& m)
	{
		return v * inverse(m);
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
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template<typename T>
	bool operator!=(matrix<R, C, T> const& m1, matrix<R, C, T> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}
#pragma endregion
}

#undef R
#undef C