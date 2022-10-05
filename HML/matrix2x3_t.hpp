#pragma once
#include "matrix_operations.hpp"
#include "vector2_t.hpp"
#include "vector3_t.hpp"
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct matrix<2, 3, T>
	{
	private:
		vector<3, T> values[2];
	public:
		//Access Operators------------------------------------------------------------------------------
	#pragma region ACCESS_OPERATORS
		vector<3, T>& operator[](size_t i)
		{
			return this->values[i];
		}
		vector<3, T> constexpr const& operator[](size_t i) const
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
		constexpr matrix() { values[0] = vector<3, T>(); values[1] = vector<3, T>(); }
		constexpr matrix(matrix<2, 3, T> const& mat) { *this = mat; }
		explicit constexpr matrix(T scalar) { values[0] = vector<3, T>(scalar, scalar, scalar); values[0] = vector<3, T>(scalar, scalar, scalar); }
		constexpr matrix(T const& x1, T const& y1, T const& z1, T const& x2, T const& y2, T const& z2) 
		{ 
			this->values[0].x = x1; this->values[0].y = y1; this->values[0].z = z1;
			this->values[1].x = x2; this->values[1].y = y2; this->values[0].z = z2;
		}
		constexpr matrix(vector<3, T> const& v1, vector<3, T> const& v2) { this->values[0] = v1; this->values[1] = v2; }
	#pragma endregion

		//Conversions-----------------------------------------------------------------------------------
	#pragma region CONVERSIONS
		template<typename U, typename V, typename M, typename N, typename K, typename S>
		constexpr matrix(U const& x1, V const& y1, K const& z1, M const& x2, N const& y2, S const& z2)
		{
			this->values[0].x = x1; this->values[0].y = y1; this->values[0].z = z1;
			this->values[1].x = x2; this->values[1].y = y2; this->values[1].z = z2;
		}

		template<typename U, typename V>
		constexpr matrix(vector<3, U> const& v1, vector<3, V> const& v2) { this->values[0] = v1; this->values[1] = v2; }

		template<typename U>
		explicit constexpr matrix(matrix<2, 3, U> const& mat)
		{
			this->values[0] = static_cast<vector<2, T>>(mat.values[0]);
			this->values[1] = static_cast<vector<2, T>>(mat.values[1]);
		}

		explicit constexpr matrix(matrix<2, 2, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<2, 4, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][2];
		}
		explicit constexpr matrix(matrix<3, 2, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<3, 3, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
		}
		explicit constexpr matrix(matrix<3, 4, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][2];
		}
		explicit constexpr matrix(matrix<4, 2, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = static_cast<T>(0);
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = static_cast<T>(0);
		}
		explicit constexpr matrix(matrix<4, 3, T> const& mat)
		{
			this->values[0] = mat[0];
			this->values[1] = mat[1];
		}
		explicit constexpr matrix(matrix<4, 4, T> const& mat)
		{
			this->values[0].x = mat[0][0];
			this->values[0].y = mat[0][1];
			this->values[0].z = mat[0][2];
			this->values[1].x = mat[1][0];
			this->values[1].y = mat[1][1];
			this->values[1].z = mat[0][2];
		}
	#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
	#pragma region ARITHMETHIC_OPERATORS
		template<typename U>
		matrix<2, 3, T>& operator=(matrix<2, 3, U> const& matrix)
		{
			this->values[0] = static_cast<T>(matrix[0]);
			this->values[1] = static_cast<T>(matrix[1]);
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator+=(U s)
		{
			this->values[0] += s;
			this->values[1] += s;
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator+=(matrix<2, 3, U> const& matrix)
		{
			this->values[0] += matrix[0];
			this->values[1] += matrix[1];
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator-=(U s)
		{
			this->values[0] -= s;
			this->values[1] -= s;
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator-=(matrix<2, 3, U> const& matrix)
		{
			this->values[0] -= matrix[0];
			this->values[1] -= matrix[1];
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator*=(U s)
		{
			this->values[0] *= s;
			this->values[1] *= s;
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator*=(matrix<2, 3, U> const& matrix)
		{
			return  (*this = *this * matrix);
		}
		template<typename U>
		matrix<2, 3, T>& operator/=(U s)
		{
			this->values[0] /= s;
			this->values[1] /= s;
			return *this;
		}
		template<typename U>
		matrix<2, 3, T>& operator/=(matrix<2, 3, U> const& matrix)
		{
			return  (*this = *this * inverse(matrix));
		}
	#pragma endregion

		//Increment and Decrement Operators-------------------------------------------------------------
	#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		matrix<2, 3, T>& operator++ ()
		{
			 ++this->values[0];
			 ++this->values[1];
			 return *this;
		}
		matrix<2, 3, T>& operator--()
		{
			 --this->values[0];
			 --this->values[1];
			 return *this;
		}
		matrix<2, 3, T> operator++(int)
		{
			 matrix<2, 3, T> ret(*this);
			 ++* this;
			 return ret;
		}
		matrix<2, 3, T> operator--(int)
		{
			 matrix<2, 3, T> ret(*this);
			 --* this;
			 return ret;
		}
	#pragma endregion
	};
	//Binary Arithmetic Operators-------------------------------------------------------------------
#pragma region BINARY_ARITHMETHIC_OPERATORS
	template<typename T>
	matrix<2, 3, T> operator+(matrix<2, 3, T> const& m, T scalar)
	{
		return matrix<2, 3, T>(m[0] + scalar, m[1] + scalar);
	}

	template<typename T>
	matrix<2, 3, T> operator+(matrix<2, 3, T> const& m1, matrix<2, 3, T> const& m2)
	{
		return matrix<2, 3, T>(m1[0] + m2[0], m1[1] + m2[1]);
	}

	template<typename T>
	matrix<2, 3, T> operator-(matrix<2, 3, T> const& m, T scalar)
	{
		return matrix<2, 3, T>(m[0] - scalar, m[1] - scalar);
	}

	template<typename T>
	matrix<2, 3, T> operator-(matrix<2, 3, T> const& m1, matrix<2, 3, T> const& m2)
	{
		return matrix<2, 3, T>(m1[0] - m2[0], m1[1] - m2[1]);
	}

	template<typename T>
	matrix<2, 3, T> operator*(matrix<2, 3, T> const& m, T scalar)
	{
		return matrix<2, 3, T>(m[0] * scalar, m[1] * scalar);
	}

	template<typename T>
	matrix<2, 3, T> operator*(T scalar, matrix<2, 3, T> const& m)
	{
		return matrix<2, 3, T>(m[0] * scalar, m[1] * scalar);
	}

	template<typename T>
	vector<3, T> operator*(matrix<2, 3, T> const& m, vector<2, T> const& v)
	{
		return vector<3, T>(
			m[0][0] * v.x + m[1][0] * v.y,
			m[0][1] * v.x + m[1][1] * v.y,
			m[0][2] * v.x + m[1][2] * v.y);
	}

	template<typename T>
	vector<2, T> operator*(vector<3, T> const& v, matrix<2, 3, T> const& m)
	{
		return vector<2, T>(
			v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2],
			v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2]);
	}

	template<typename T>
	matrix<2, 3, T> operator*(matrix<2, 3, T> const& m1, matrix<2, 2, T> const& m2)
	{
		return matrix<2, 3, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1]);
	}
		template<typename T>
	matrix<3, 3, T> operator*(matrix<2, 3, T> const& m1, matrix<3, 2, T> const& m2)
	{
		T SrcA00 = m1[0][0];
		T SrcA01 = m1[0][1];
		T SrcA02 = m1[0][2];
		T SrcA10 = m1[1][0];
		T SrcA11 = m1[1][1];
		T SrcA12 = m1[1][2];

		T SrcB00 = m2[0][0];
		T SrcB01 = m2[0][1];
		T SrcB10 = m2[1][0];
		T SrcB11 = m2[1][1];
		T SrcB20 = m2[2][0];
		T SrcB21 = m2[2][1];

		matrix<3, 3, T> ret;
		ret[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01;
		ret[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01;
		ret[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01;
		ret[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11;
		ret[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11;
		ret[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11;
		ret[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21;
		ret[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21;
		ret[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21;
		return ret;
	}

	template<typename T>
	matrix<4, 3, T> operator*(matrix<2, 3, T> const& m1, matrix<4, 2, T> const& m2)
	{
		return matrix<4, 3, T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1],
			m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1]);
	}

	template<typename T>
	matrix<2, 3, T> operator/(matrix<2, 3, T> const& m, T scalar)
	{
		return matrix<2, 3, T>(
			m[0] / scalar,
			m[1] / scalar);
	}

	template<typename T>
	matrix<2, 3, T> operator/(T scalar, matrix<2, 3, T> const& m)
	{
		return matrix<2, 3, T>(
			scalar / m[0],
			scalar / m[1]);
	}
#pragma endregion

	//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
	template<typename T>
	bool operator==(matrix<2, 3, T> const& m1, matrix<2, 3, T> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]);
	}

	template<typename T>
	bool operator!=(matrix<2, 3, T> const& m1, matrix<2, 3, T> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]);
	}
#pragma endregion
}