#pragma once
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct vector<4, T>
	{
#ifdef HMATH_USE_ONLY_XYZW
		T x;
		T y;
		T z;
		T w;
#else
		union { T x, r, s; };
		union { T y, g, t; };
		union { T z, b, p; };
		union { T w, a, q; };
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

		//Construtors-----------------------------------------------------------------------------------
#pragma region CONSTRUCTORS
		vector() : x(0), y(0), z(0), w(0) {  }
		vector(T val_x, T val_y, T val_z, T val_w) : x(val_x), y(val_y), z(val_z), w(val_w) {  }
		template<typename O>
		vector(const vector<4, O>& other) { *this = vector<4, T>(static_cast<T>(other.x), static_cast<T>(other.y), static_cast<T>(other.z), static_cast<T>(other.w)); }
		vector(const vector<3, T>& xyz, const T& w) { this->x = xyz.x; this->y = xyz.y; this->z = xyz.z; this->w = w; }
		template<typename O>
		vector(const vector<3, O>& xyz, const T& w) { this->x = xyz.x; this->y = xyz.y; this->z = xyz.z; this->w = w; }
		vector(const T& x, const vector<3, T>& yzw) { this->x = x; this->y = yzw.x; this->z = yzw.y; this->w = yzw.z; }
		vector(const vector<2, T>& xy, const vector<2, T>& zw) { this->x = xy.x; this->y = xy.y; this->z = zw.x; this->w = zw.y; }
#pragma endregion

		//Static Funcs----------------------------------------------------------------------------------
#pragma region STATIC_FUNCS
		static inline size_t constexpr length() { return 4; }
		inline vector<2, T> constexpr xy() { return vector<2, T>(this->x, this->y); }
		inline vector<3, T> constexpr xyz() { return vector<3, T>(this->x, this->y, this->z); }
#pragma endregion

		//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
		template<typename T>
		constexpr bool operator==(vector<4, T> const& vec)
		{
			return (this->x == vec.x) && (this->y == vec.y) && (this->z == vec.z) && (this->w == vec.w);
		}

		template<typename T>
		constexpr bool operator !=(vector<4, T> const& vec)
		{
			return !(this == vec);
		}
#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
#pragma region ARITHMETIC_OPERATORS

		constexpr vector<4, T>& operator=(vector<4, T> const& vec)
		{
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
			this->w = vec.w;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator=(vector<4, U> const& vec)
		{
			this->x = static_cast<T>(vec.x);
			this->y = static_cast<T>(vec.y);
			this->z = static_cast<T>(vec.z);
			this->w = static_cast<T>(vec.w);
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator+=(vector<1, U> const& vec)
		{
			this->x += vec.x;
			this->y += vec.x;
			this->z += vec.x;
			this->w += vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator+=(vector<4, U> const& vec)
		{
			this->x += vec.x;
			this->y += vec.y;
			this->z += vec.z;
			this->w += vec.w;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator+=(U scalar)
		{
			this->x += scalar;
			this->y += scalar;
			this->z += scalar;
			this->w += scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator-=(vector<1, U> const& vec)
		{
			this->x -= vec.x;
			this->y -= vec.x;
			this->z -= vec.x;
			this->w -= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator-=(vector<4, U> const& vec)
		{
			this->x -= vec.x;
			this->y -= vec.y;
			this->z -= vec.z;
			this->w -= vec.w;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator-=(U scalar)
		{
			this->x -= scalar;
			this->y -= scalar;
			this->z -= scalar;
			this->w -= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator*=(vector<1, U> const& vec)
		{
			this->x *= vec.x;
			this->y *= vec.x;
			this->z *= vec.x;
			this->w *= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator*=(vector<4, U> const& vec)
		{
			this->x *= vec.x;
			this->y *= vec.y;
			this->z *= vec.z;
			this->w *= vec.w;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator*=(U scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator/=(vector<1, U> const& vec)
		{
			this->x /= vec.x;
			this->y /= vec.x;
			this->z /= vec.x;
			this->w /= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator/=(vector<4, U> const& vec)
		{
			this->x /= vec.x;
			this->y /= vec.y;
			this->z /= vec.z;
			this->w /= vec.w;
			return *this;
		}

		template<typename U>
		constexpr vector<4, T>& operator/=(U scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			this->w /= scalar;
			return *this;
		}

		template<typename T>
		constexpr vector<4, T> operator+(vector<1, T> const& vec)
		{
			return vector<4, T>(this->x + vec.x, this->y + vec.x, this->z + vec.x, this->w + vec.x);
		}

#pragma endregion

		//Increment and Decrement Operators-------------------------------------------------------------
#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		constexpr vector<4, T>& operator++()
		{
			this->x++;
			this->y++;
			this->z++;
			this->w++;
			return *this;
		}
		constexpr vector<4, T> operator++(int)
		{
			vector<4, T> res(*this);
			++*this;
			return res;
		}
		constexpr vector<4, T>& operator--()
		{
			this->x--;
			this->y--;
			this->z--;
			this->w--;
			return *this;
		}
		constexpr vector<4, T> operator--(int)
		{
			vector<4, T> res(*this);
			--* this;
			return res;
		}
#pragma endregion
	};
	//Unary Arithmetic Opeartors------------------------------------------------------------------------
#pragma region UNARY_ARITHMETIC_OPERATORS
	template<typename T>
	constexpr vector<4, T> operator+(vector<4, T> const& v)
	{
		return v;
	}

	template<typename T>
	constexpr vector<4, T> operator-(vector<4, T> const& v)
	{
		return vector<4, T>(0) -= v;
	}
#pragma endregion

	//Binary Arithmetic Opeartors-----------------------------------------------------------------------
#pragma region BINARY_ARITHMETIC_OPERATORS
	template<typename T>
	constexpr vector<4, T> operator+(vector<4, T> const& v, T const& scalar)
	{
		return vector<4, T>(v) += scalar;
	}

	template<typename T>
	constexpr vector<4, T> operator+(vector<4, T> const& v1, vector<1, T> const& v2)
	{
		return vector<4, T>(v1) += v2;
	}

	template<typename T>
	constexpr vector<4, T> operator+(T scalar, vector<4, T> const& v)
	{
		return vector<4, T>(v) += scalar;
	}

	template<typename T>
	constexpr vector<4, T> operator+(vector<1, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v2) += v1;
	}

	template<typename T>
	constexpr vector<4, T> operator+(vector<4, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v1) += v2;
	}

	template<typename T>
	constexpr vector<4, T> operator-(vector<4, T> const& v, T const& scalar)
	{
		return vector<4, T>(v) -= scalar;
	}

	template<typename T>
	constexpr vector<4, T> operator-(vector<4, T> const& v1, vector<1, T> const& v2)
	{
		return vector<4, T>(v1) -= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator-(T scalar, vector<4, T> const& v)
	{
		return vector<4, T>(scalar) -= v;
	}

	template<typename T>
	constexpr vector<4, T> operator-(vector<1, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v1.x) -= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator-(vector<4, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v1) -= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator*(vector<4, T> const& v, T const& scalar)
	{
		return vector<4, T>(v) *= scalar;
	}

	template<typename T>
	constexpr vector<4, T> operator*(vector<4, T> const& v1, vector<1, T> const& v2)
	{
		return vector<4, T>(v1) *= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator*(T scalar, vector<4, T> const& v)
	{
		return vector<4, T>(v) *= scalar;
	}

	template<typename T>
	constexpr vector<4, T> operator*(vector<1, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v2) *= v1;
	}

	template<typename T>
	constexpr vector<4, T> operator*(vector<4, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v1) *= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator/(vector<4, T> const& v, T const& scalar)
	{
		return vector<4, T>(v) /= scalar;
	}

	template<typename T>
	constexpr vector<4, T> operator/(vector<4, T> const& v1, vector<1, T> const& v2)
	{
		return vector<4, T>(v1) /= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator/(T scalar, vector<4, T> const& v)
	{
		return vector<4, T>(scalar) /= v;
	}

	template<typename T>
	constexpr vector<4, T> operator/(vector<1, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v1.x) /= v2;
	}

	template<typename T>
	constexpr vector<4, T> operator/(vector<4, T> const& v1, vector<4, T> const& v2)
	{
		return vector<4, T>(v1) /= v2;
	}

#pragma endregion
}