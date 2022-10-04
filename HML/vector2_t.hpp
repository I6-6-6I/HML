#pragma once
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct vector<2, T>
	{
#ifdef HMATH_USE_ONLY_XYZW
		T x;
		T y;
#else
		union { T x, r, s; };
		union { T y, g, t; };
#endif
		//Access Operators------------------------------------------------------------------------------
#pragma region ACCESS_OPERATORS
		T& operator[](size_t i)
		{
			switch (i)
			{
				case 0:		return this->x;
				case 1:		return this->y;
				default:	return this->x;
			}
		}
		T constexpr const& operator[](size_t i) const
		{
			switch (i)
			{
				case 0:		return this->x;
				case 1:		return this->y;
				default:	return this->x;
			}
		}
#pragma endregion

		//Construtors-----------------------------------------------------------------------------------
#pragma region CONSTRUCTORS
		vector() : x(0), y(0) {  }
		vector(T val_x, T val_y) : x(val_x), y(val_y) {  }
		template<typename O>
		vector(const vector<2, O>& other) { *this = vector<2, T>(static_cast<T>(other.x), static_cast<T>(other.y)); }

		vector(const vector<1, T>& x, const T& y) { this->x = x.x; this->y = y; }
		vector(const vector<1, T>& x, const vector<1, T>& y) { this->x = x.x; this->y = y.y; }
		vector(const T& x, const vector<1, T>& y) { this->x = x; this->y = y.y; }
#pragma endregion

		//Static Funcs----------------------------------------------------------------------------------
#pragma region STATIC_FUNCS
		static inline size_t constexpr length() { return 2; }
#pragma endregion

		//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
		template<typename T>
		constexpr bool operator==(vector<2, T> const& vec)
		{
			return (this->x == vec.x) && (this->y == vec.y);
		}

		template<typename T>
		constexpr bool operator !=(vector<2, T> const& vec)
		{
			return !(this == vec);
		}
#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
#pragma region ARITHMETIC_OPERATORS

		constexpr vector<2, T>& operator=(vector<2, T> const& vec)
		{
			this->x = vec.x;
			this->y = vec.y;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator=(vector<2, U> const& vec)
		{
			this->x = static_cast<T>(vec.x);
			this->y = static_cast<T>(vec.y);
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator+=(vector<1, U> const& vec)
		{
			this->x += vec.x;
			this->y += vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator+=(vector<2, U> const& vec)
		{
			this->x += vec.x;
			this->y += vec.y;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator+=(U scalar)
		{
			this->x += scalar;
			this->y += scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator-=(vector<1, U> const& vec)
		{
			this->x -= vec.x;
			this->y -= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator-=(vector<2, U> const& vec)
		{
			this->x -= vec.x;
			this->y -= vec.y;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator-=(U scalar)
		{
			this->x -= scalar;
			this->y -= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator*=(vector<1, U> const& vec)
		{
			this->x *= vec.x;
			this->y *= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator*=(vector<2, U> const& vec)
		{
			this->x *= vec.x;
			this->y *= vec.y;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator*=(U scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator/=(vector<1, U> const& vec)
		{
			this->x /= vec.x;
			this->y /= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator/=(vector<2, U> const& vec)
		{
			this->x /= vec.x;
			this->y /= vec.y;
			return *this;
		}

		template<typename U>
		constexpr vector<2, T>& operator/=(U scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			return *this;
		}

		template<typename T>
		constexpr vector<2, T> operator+(vector<1, T> const& vec)
		{
			return vector<2, T>(this->x + vec.x, this->y + vec.x);
		}

		template<typename T>
		constexpr vector<2, T> operator+(vector<2, T> const& vec)
		{
			return vector<2, T>(this->x + vec.x, this->y + vec.y);
		}

		template<typename U>
		constexpr vector<2, T> operator+(U scalar)
		{
			return vector<2, T>(this->x + scalar, this->y + scalar);
		}

		template<typename T>
		constexpr vector<2, T> operator-(vector<1, T> const& vec)
		{
			return vector<2, T>(this->x - vec.x, this->y - vec.x);
		}

		template<typename T>
		constexpr vector<2, T> operator-(vector<2, T> const& vec)
		{
			return vector<2, T>(this->x - vec.x, this->y - vec.y);
		}

		template<typename U>
		constexpr vector<2, T> operator-(U scalar)
		{
			return vector<2, T>(this->x - scalar, this->y - scalar);
		}

		template<typename T>
		constexpr vector<2, T> operator*(vector<1, T> const& vec)
		{
			return vector<2, T>(this->x * vec.x, this->y * vec.x);
		}

		template<typename T>
		constexpr vector<2, T> operator*(vector<2, T> const& vec)
		{
			return vector<2, T>(this->x * vec.x, this->y * vec.y);
		}

		template<typename U>
		constexpr vector<2, T> operator*(U scalar)
		{
			return vector<2, T>(this->x * scalar, this->y * scalar);
		}

		template<typename T>
		constexpr vector<2, T> operator/(vector<1, T> const& vec)
		{
			return vector<2, T>(this->x / vec.x, this->y / vec.x);
		}

		template<typename T>
		constexpr vector<2, T> operator/(vector<2, T> const& vec)
		{
			return vector<2, T>(this->x / vec.x, this->y / vec.y);
		}

		template<typename U>
		constexpr vector<2, T> operator/(U scalar)
		{
			return vector<2, T>(this->x / scalar, this->y / scalar);
		}

		template<typename T>
		constexpr vector<2, T> operator%(vector<1, T> const& vec)
		{
			return vector<2, T>(this->x % vec.x, this->y % vec.x);
		}

		template<typename T>
		constexpr vector<2, T> operator%(vector<2, T> const& vec)
		{
			return vector<2, T>(this->x % vec.x, this->y % vec.y);
		}

		template<typename U>
		constexpr vector<2, T> operator%(U scalar)
		{
			return vector<2, T>(this->x % scalar, this->y % scalar);
		}

#pragma endregion

		//Increment and Decrement Operators-------------------------------------------------------------
#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		constexpr vector<2, T>& operator++()
		{
			this->x++;
			this->y++;
			return *this;
		}
		constexpr vector<2, T> operator++(int)
		{
			vector<2, T> res(*this);
			++* this;
			return res;
		}
		constexpr vector<2, T>& operator--()
		{
			this->x--;
			this->y--;
			return *this;
		}
		constexpr vector<2, T> operator--(int)
		{
			vector<2, T> res(*this);
			--* this;
			return res;
		}
#pragma endregion
	};
}