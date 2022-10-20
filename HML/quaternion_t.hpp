#pragma once
#include "common.hpp"
#include "geometric_common.hpp"
#include "trigonometry_common.hpp"

HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct quat
	{
		T x, y, z, w;
		//Access Operators------------------------------------------------------------------------------
	#pragma region ACCESS_OPERATORS
		T& operator[](size_t i)
		{
			switch (i)
			{
			case 0:		return this->x;
			case 1:		return this->y;
			case 2:		return this->z;
			case 3:		return this->w;
			default:	return this->x;
			}
		}
		T constexpr const& operator[](size_t i) const
		{
			switch (i)
			{
			case 0:		return this->x;
			case 1:		return this->y;
			case 2:		return this->z;
			case 3:		return this->w;
			default:	return this->x;
			}
		}
	#pragma endregion

		//Static Funcs----------------------------------------------------------------------------------
	#pragma region STATIC_FUNCS
		static constexpr size_t length() { return 4; }
	#pragma endregion

		//Construtors-----------------------------------------------------------------------------------
	#pragma region CONSTRUCTORS
		constexpr quat() { this->x = T(0); this->y = T(0); this->z = T(0); this->w = T(0); }
		constexpr quat(quat<T> const& qua) { *this = qua; }
		template <typename Q>
		constexpr quat(quat<Q> const& qua) { *this = qua; }
		constexpr quat(T scalar)
		{
			this->x = scalar;
			this->y = scalar;
			this->z = scalar;
			this->w = scalar;
		}
		constexpr quat(T x, T y, T z, T w) { this->x = x; this->y = y; this->z = z; this->w = w; }
		constexpr quat(vector<4, T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
		}
	#pragma endregion

		//Conversions-----------------------------------------------------------------------------------
	#pragma region CONVERSIONS
		template<typename T>
		constexpr quat(vector<3, T> const& v1, vector<3, T> const& v2)
		{
			T norm_u_norm_v = HML::Sqrt(HML::Dot(v1, v1) * HML::Dot(v2, v2));
			T real_part = norm_u_norm_v + HML::Dot(v1, v2);
			vector<3, T> temp;

			if (real_part < static_cast<T>(1.e-6f) * norm_u_norm_v)
			{
				// If u and v are exactly opposite, rotate 180 degrees
				// around an arbitrary orthogonal axis. Axis normalisation
				// can happen later, when we normalise the quaternion.
				real_part = static_cast<T>(0);
				temp = HML::Abs(v1.x) > HML::Abs(v1.z) ? vector<3, T>(-v1.y, v1.x, static_cast<T>(0)) : vector<3, T>(static_cast<T>(0), -v1.z, v1.y);
			}
			else
			{
				// Otherwise, build quaternion the standard way.
				temp = HML::Cross(v1, v2);
			}

			*this = HML::Normalize(quat<T>(real_part, temp.x, temp.y, temp.z));
		}
		template<typename T>
		constexpr explicit quat(vector<3, T> const& eulerAngles)
		{
			vector<3, T> c = HML::Cos(eulerAngles * T(0.5));
			vector<3, T> s = HML::Sin(eulerAngles * T(0.5));

			this->w = c.x * c.y * c.z + s.x * s.y * s.z;
			this->x = s.x * c.y * c.z - c.x * s.y * s.z;
			this->y = c.x * s.y * c.z + s.x * c.y * s.z;
			this->z = c.x * c.y * s.z - s.x * s.y * c.z;
		}
		template<typename T>
		constexpr quat(matrix<3, 3, T> const& m)
		{
			T fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
			T fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
			T fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
			T fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

			int biggestIndex = 0;
			T fourBiggestSquaredMinus1 = fourWSquaredMinus1;
			if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
			{
				fourBiggestSquaredMinus1 = fourXSquaredMinus1;
				biggestIndex = 1;
			}
			if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
			{
				fourBiggestSquaredMinus1 = fourYSquaredMinus1;
				biggestIndex = 2;
			}
			if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
			{
				fourBiggestSquaredMinus1 = fourZSquaredMinus1;
				biggestIndex = 3;
			}

			T biggestVal = HML::Sqrt(fourBiggestSquaredMinus1 + static_cast<T>(1)) * static_cast<T>(0.5);
			T mult = static_cast<T>(0.25) / biggestVal;

			switch (biggestIndex)
			{
			case 0:
				this->x = biggestVal;
				this->y = (m[1][2] - m[2][1]) * mult;
				this->z = (m[2][0] - m[0][2]) * mult;
				this->w = (m[0][1] - m[1][0]) * mult;
				break;
			case 1:
				this->x = (m[1][2] - m[2][1]) * mult;
				this->y = biggestVal;
				this->z = (m[0][1] - m[1][0]) * mult;
				this->w = (m[2][0] - m[0][2]) * mult;
				break;
			case 2:
				this->x = (m[2][0] - m[0][2]) * mult;
				this->y = (m[0][1] - m[1][0]) * mult;
				this->z = biggestVal;
				this->w = (m[1][2] - m[2][1]) * mult;
				break;
			case 3:
				this->x = (m[0][1] - m[1][0]) * mult;
				this->y = (m[2][0] - m[0][2]) * mult;
				this->z = (m[1][2] - m[2][1]) * mult;
				this->w = biggestVal;
				break;
			default:
				this->x = static_cast<T>(0);
				this->y = static_cast<T>(0);
				this->z = static_cast<T>(0);
				this->w = static_cast<T>(0);
				break;
			}
		}
		template<typename T>
		constexpr quat(matrix<4, 4, T> const& m)
		{
			*this = quat(matrix<3, 3, T>(m));
		}

		template<typename T>
		operator matrix<3, 3, T>() const
		{
			matrix<3, 3, T> ret(T(1));
			ret[0][0] = T(1) - T(2) * ((this->y * this->y) + (this->z * this->z));
			ret[0][1] = T(2) * ((this->x * this->y) + (this->w * this->z));
			ret[0][2] = T(2) * ((this->x * this->z) - (this->w * this->y));

			ret[1][0] = T(2) * ((this->x * this->y) - (this->w * this->z));
			ret[1][1] = T(1) - T(2) * ((this->x * this->x) + (this->z * this->z));
			ret[1][2] = T(2) * ((this->y * this->z) + (this->w * this->x));

			ret[2][0] = T(2) * ((this->x * this->z) + (this->w * this->y));
			ret[2][1] = T(2) * ((this->y * this->z) - (this->w * this->x));
			ret[2][2] = T(1) - T(2) * ((this->x * this->x) + (this->y * this->y));
			return ret;
		}

		template<typename T>
		operator matrix<4, 4, T>() const
		{
			return matrix<4, 4, T>(matrix<3, 3, T>(*this));
		}
	#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
	#pragma region ARITHMETHIC_OPERATORS
		constexpr quat<T>& operator=(quat<T> const& qua)
		{
			this->x = qua.x;
			this->y = qua.y;
			this->z = qua.z;
			this->w = qua.w;
			return *this;
		}

		template<typename U>
		constexpr quat<T>& operator=(quat<U> const& qua)
		{
			this->x = static_cast<T>(qua.x);
			this->y = static_cast<T>(qua.y);
			this->z = static_cast<T>(qua.z);
			this->w = static_cast<T>(qua.w);
			return *this;
		}

		template<typename U>
		constexpr quat<T>& operator+=(quat<U> const& qua)
		{
			this->x += qua.x;
			this->y += qua.y;
			this->z += qua.z;
			this->w += qua.w;
			return *this;
		}

		template<typename U>
		constexpr quat<T>& operator-=(quat<U> const& qua)
		{
			this->x -= qua.x;
			this->y -= qua.y;
			this->z -= qua.z;
			this->w -= qua.w;
			return *this;
		}

		template<typename U>
		constexpr quat<T>& operator*=(quat<U> const& qua)
		{
			quat<T> const p(*this);
			quat<T> const q(qua);

			this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
			this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
			this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
			this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
			return *this;
		}

		template<typename U>
		constexpr quat<T>& operator*=(U scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
			return *this;
		}

		template<typename U>
		constexpr quat<T>& operator/=(U scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			this->w /= scalar;
			return *this;
		}
	#pragma endregion
		};
	//Unary Arithmetic Operators--------------------------------------------------------------------
#pragma region UNARY_ARITHMETIC_OPERATORS
	template<typename T>
	quat<T> operator+(quat<T> const& qua)
	{
		return qua;
	}

	template<typename T>
	quat<T> operator-(quat<T> const& qua)
	{
		return quat<T>(-qua.x, -qua.y, -qua.z, -qua.w);
	}
#pragma endregion

	//Binary Arithmetic Operators-------------------------------------------------------------------
#pragma region BINARY_ARITHMETHIC_OPERATORS
	template<typename T>
	quat<T> operator+(quat<T> const& qua1, quat<T> const& qua2)
	{
		return quat<T>(qua1) += qua2;
	}

	template<typename T>
	quat<T> operator-(quat<T> const& qua1, quat<T> const& qua2)
	{
		return quat<T>(qua1) -= qua2;
	}

	template<typename T>
	quat<T> operator*(quat<T> const& qua1, quat<T> const& qua2)
	{
		return quat<T>(qua1) *= qua2;
	}

	template<typename T>
	vector<3, T> operator*(quat<T> const& qua, vector<3, T> const& vec)
	{
		vector<3, T> const x(qua.x, qua.y, qua.z);
		vector<3, T> const y(HML::Cross(x, vec));
		vector<3, T> const z(HML::Cross(x, y));

		return vec + ((y * qua.w) + z) * static_cast<T>(2);
	}

	template<typename T>
	quat<T> operator*(vector<3, T> const& vec, quat<T> const& qua)
	{
		return HML::Inverse(qua) * vec;
	}

	template<typename T>
	vector<4, T> operator*(quat<T> const& qua, vector<4, T> const& v)
	{
		return vector<4, T>(qua * vector<3, T>(v), v.w);
	}

	template<typename T>
	vector<4, T> operator*(vector<4, T> const& v, quat<T> const& qua)
	{
		return HML::Inverse(qua) * v;
	}

	template<typename T>
	quat<T> operator*(quat<T> const& qua, T scalar)
	{
		return quat<T>(qua.x * scalar, qua.y * scalar, qua.z * scalar, qua.w * scalar);
	}

	template<typename T>
	quat<T> operator*(T scalar, quat<T> const& qua)
	{
		return qua * scalar;
	}

	template<typename T>
	quat<T> operator/(quat<T> const& qua, T scalar)
	{
		return quat<T>(qua.x / scalar, qua.y / scalar, qua.z / scalar, qua.w / scalar);
	}
#pragma endregion

	//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
	template<typename T>
	constexpr bool operator==(quat<T> const& q1, quat<T> const& q2)
	{
		return q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w;
	}

	template<typename T>
	constexpr bool operator!=(quat<T> const& q1, quat<T> const& q2)
	{
		return q1.x != q2.x || q1.y != q2.y || q1.z != q2.z || q1.w != q2.w;
	}
#pragma endregion
}