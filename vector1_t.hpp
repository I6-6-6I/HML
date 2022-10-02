#pragma once
HEADER_MATH_NAMESPACE
{
	template<typename T>
	struct vector<1, T>
	{
		T x;
#ifndef HMATH_USE_ONLY_XYZW
		T& r = x;
		T& s = x;
#endif
		//Construtors-----------------------------------------------------------------------------------
#pragma region CONSTRUCTORS
		vector() : x(0) {  }
		vector(T val_x) : x(val_x) {  }
		vector(const vector<1, T>& other) { *this = other; }
		template<typename O>
		vector(const vector<1, O>& other) { *this = vector<1, T>(static_cast<T>(other.x)); }
#pragma endregion

		//Static Funcs----------------------------------------------------------------------------------
#pragma region STATIC_FUNCS
		static size_t constexpr length() { return 1; }
		static size_t constexpr size() { return sizeof(T); }
#pragma endregion

		//Logic Operators-------------------------------------------------------------------------------
#pragma region LOGIC_OPERATORS
		template<typename T>
		constexpr bool operator==(vector<1, T> const& vec)
		{
			return (this->x == vec.x);
		}

		template<typename T>
		constexpr bool operator !=(vector<1, T> const& vec)
		{
			return !(this == vec);
		}
#pragma endregion

		//Arithmetic Operators--------------------------------------------------------------------------
#pragma region ARITHMETIC_OPERATORS

		constexpr vector<1, T>& operator=(vector<1, T> const& vec)
		{
			this->x = vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator=(vector<1, U> const& vec)
		{
			this->x = vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator+=(vector<1, U> const& vec)
		{
			this->x += vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator+=(U scalar)
		{
			this->x += scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator-=(vector<1, U> const& vec)
		{
			this->x -= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator-=(U scalar)
		{
			this->x -= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator*=(vector<1, U> const& vec)
		{
			this->x *= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator*=(U scalar)
		{
			this->x *= scalar;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator/=(vector<1, U> const& vec)
		{
			this->x /= vec.x;
			return *this;
		}

		template<typename U>
		constexpr vector<1, T>& operator/=(U scalar)
		{
			this->x /= scalar;
			return *this;
		}

		template<typename T>
		constexpr vector<1, T> operator+(vector<1, T> const& vec)
		{
			return this->x + vec.x;
		}

		template<typename U>
		constexpr vector<1, T> operator+(U scalar)
		{
			return this->x + scalar;
		}

		template<typename T>
		constexpr vector<1, T> operator-(vector<1, T> const& vec)
		{
			return this->x - vec.x;
		}

		template<typename U>
		constexpr vector<1, T> operator-(U scalar)
		{
			return this->x - scalar;
		}

		template<typename T>
		constexpr vector<1, T> operator*(vector<1, T> const& vec)
		{
			return this->x * vec.x;
		}

		template<typename U>
		constexpr vector<1, T> operator*(U scalar)
		{
			return this->x * scalar;
		}

		template<typename T>
		constexpr vector<1, T> operator/(vector<1, T> const& vec)
		{
			return this->x / vec.x;
		}

		template<typename U>
		constexpr vector<1, T> operator/(U scalar)
		{
			return this->x / scalar;
		}

		template<typename T>
		constexpr vector<1, T> operator%(vector<1, T> const& vec)
		{
			return this->x % vec.x;
		}

		template<typename U>
		constexpr vector<1, T> operator%(U scalar)
		{
			return this->x % scalar;
		}

#pragma endregion

		//Increment and Decrement Operators-------------------------------------------------------------
#pragma region INCREMENT_AND_DECREMENT_OPERATORS
		constexpr vector<1, T>& operator++()
		{
			this->x++;
			return *this;
		}
		constexpr vector<1, T> operator++(int)
		{
			vector<1, T> res(*this);
			++* this;
			return res;
		}
		constexpr vector<1, T>& operator--()
		{
			this->x--;
			return *this;
		}
		constexpr vector<1, T> operator--(int)
		{
			vector<1, T> res(*this);
			--* this;
			return res;
		}
#pragma endregion
	};
}