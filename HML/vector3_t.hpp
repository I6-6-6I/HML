#pragma once
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct vector<3, T>
	{
#ifdef HMATH_USE_ONLY_XYZW
		T x;
		T y;
		T z;
#else
		union { T x, r, s; };
		union { T y, g, t; };
		union { T z, b, p; };
#endif
		//Access Operators------------------------------------------------------------------------------
#pragma region ACCESS_OPERATORS
		T& operator[](size_t i)
		{
			switch (i)
			{
				case 0:		return this->x;
				case 1:		return this->y;
				case 2:		return this->z;
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
				default:	return this->x;
			}
		}
#pragma endregion

		//Construtors-----------------------------------------------------------------------------------
#pragma region CONSTRUCTORS
		vector() : x(0), y(0), z(0) {  }
		vector(T val_x, T val_y, T val_z) : x(val_x), y(val_y), z(val_z) {  }
		template<typename O>
		vector(const vector<3, O>& other) { *this = vector<3, T>(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z)); }
		vector(const vector<2, T>& xy, const T& z) { this->x = xy.x; this->y = xy.y; this->z = z; }
		template<typename O>
		vector(const vector<2, O>& xy, const T& z) { this->x = xy.x; this->y = xy.y; this->z = z; }
		vector(const T& x, const vector<2, T>& yz) { this->x = x; this->y = yz.y; this->z = yz.z; }
#pragma endregion

		//Static Funcs----------------------------------------------------------------------------------
#pragma region STATIC_FUNCS
		static inline size_t constexpr length() { return 3; }
		inline vector<2, T> constexpr xy() { return vector<2, T>(this->x, this->y); }
#pragma endregion

		//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
		template<typename T>
		constexpr bool operator==(vector<3, T> const& vec)
		{
			return (this->x == vec.x) && (this->y == vec.y) && (this->z == vec.z);
		}

		template<typename T>
		constexpr bool operator !=(vector<3, T> const& vec)
		{
			return !(this == vec);
		}
#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
#pragma region ARITHMETIC_OPERATORS

		constexpr vector<3, T>& operator=(vector<3, T> const& vec)
		{
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator=(vector<3, U> const& vec)
		{
			this->x = static_cast<T>(vec.x);
			this->y = static_cast<T>(vec.y);
			this->z = static_cast<T>(vec.z);
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator+=(vector<1, U> const& vec)
		{
			this->x += vec.x;
			this->y += vec.x;
			this->z += vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator+=(vector<3, U> const& vec)
		{
			this->x += vec.x;
			this->y += vec.y;
			this->z += vec.z;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator+=(U scalar)
		{
			this->x += scalar;
			this->y += scalar;
			this->z += scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator-=(vector<1, U> const& vec)
		{
			this->x -= vec.x;
			this->y -= vec.x;
			this->z -= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator-=(vector<3, U> const& vec)
		{
			this->x -= vec.x;
			this->y -= vec.y;
			this->z -= vec.z;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator-=(U scalar)
		{
			this->x -= scalar;
			this->y -= scalar;
			this->z -= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator*=(vector<1, U> const& vec)
		{
			this->x *= vec.x;
			this->y *= vec.x;
			this->z *= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator*=(vector<3, U> const& vec)
		{
			this->x *= vec.x;
			this->y *= vec.y;
			this->z *= vec.z;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator*=(U scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator/=(vector<1, U> const& vec)
		{
			this->x /= vec.x;
			this->y /= vec.x;
			this->z /= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator/=(vector<3, U> const& vec)
		{
			this->x /= vec.x;
			this->y /= vec.y;
			this->z /= vec.z;
			return *this;
		}

		template<typename U>
		constexpr vector<3, T>& operator/=(U scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			return *this;
		}

#pragma endregion
		//Increment and Decrement Operators-------------------------------------------------------------
#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		constexpr vector<3, T>& operator++()
		{
			this->x++;
			this->y++;
			this->z++;
			return *this;
		}
		constexpr vector<3, T> operator++(int)
		{
			vector<3, T> res(*this);
			++* this;
			return res;
		}
		constexpr vector<3, T>& operator--()
		{
			this->x--;
			this->y--;
			this->z--;
			return *this;
		}
		constexpr vector<3, T> operator--(int)
		{
			vector<3, T> res(*this);
			--* this;
			return res;
		}
#pragma endregion
	};
		//Unary Arithmetic Operators
#pragma region UNARY_ARITHMETIC_OPERATORS
	template<typename T>
	constexpr vector<3, T> operator+(vector<3, T> const& v)
	{
		return v;
	}

	template<typename T>
	constexpr vector<3, T> operator-(vector<3, T> const& v)
	{
		return vector<3, T>(
			-v.x,
			-v.y,
			-v.z);
	}
#pragma endregion
		//Unary Arithmetic Operators
#pragma region BINARY_ARITHMETIC_OPERATORS
	template<typename T>
	constexpr vector<3, T> operator+(vector<3, T> const& v, T scalar)
	{
		return vector<3, T>(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar);
	}

	template<typename T>
	constexpr vector<3, T> operator+(vector<3, T> const& v, vector<1, T> const& scalar)
	{
		return vector<3, T>(
			v.x + scalar.x,
			v.y + scalar.x,
			v.z + scalar.x);
	}

	template<typename T>
	constexpr vector<3, T> operator+(T scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator+(vector<1, T> const& scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar.x + v.x,
			scalar.x + v.y,
			scalar.x + v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator+(vector<3, T> const& v1, vector<3, T> const& v2)
	{
		return vector<3, T>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z);
	}

	template<typename T>
	constexpr vector<3, T> operator-(vector<3, T> const& v, T scalar)
	{
		return vector<3, T>(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar);
	}

	template<typename T>
	constexpr vector<3, T> operator-(vector<3, T> const& v, vector<1, T> const& scalar)
	{
		return vector<3, T>(
			v.x - scalar.x,
			v.y - scalar.x,
			v.z - scalar.x);
	}

	template<typename T>
	constexpr vector<3, T> operator-(T scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator-(vector<1, T> const& scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar.x - v.x,
			scalar.x - v.y,
			scalar.x - v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator-(vector<3, T> const& v1, vector<3, T> const& v2)
	{
		return vector<3, T>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z);
	}

	template<typename T>
	constexpr vector<3, T> operator*(vector<3, T> const& v, T scalar)
	{
		return vector<3, T>(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar);
	}

	template<typename T>
	constexpr vector<3, T> operator*(vector<3, T> const& v, vector<1, T> const& scalar)
	{
		return vector<3, T>(
			v.x * scalar.x,
			v.y * scalar.x,
			v.z * scalar.x);
	}

	template<typename T>
	constexpr vector<3, T> operator*(T scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator*(vector<1, T> const& scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar.x * v.x,
			scalar.x * v.y,
			scalar.x * v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator*(vector<3, T> const& v1, vector<3, T> const& v2)
	{
		return vector<3, T>(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z);
	}

	template<typename T>
	constexpr vector<3, T> operator/(vector<3, T> const& v, T scalar)
	{
		return vector<3, T>(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar);
	}

	template<typename T>
	constexpr vector<3, T> operator/(vector<3, T> const& v, vector<1, T> const& scalar)
	{
		return vector<3, T>(
			v.x / scalar.x,
			v.y / scalar.x,
			v.z / scalar.x);
	}

	template<typename T>
	constexpr vector<3, T> operator/(T scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator/(vector<1, T> const& scalar, vector<3, T> const& v)
	{
		return vector<3, T>(
			scalar.x / v.x,
			scalar.x / v.y,
			scalar.x / v.z);
	}

	template<typename T>
	constexpr vector<3, T> operator/(vector<3, T> const& v1, vector<3, T> const& v2)
	{
		return vector<3, T>(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z);
	}
#pragma endregion

}