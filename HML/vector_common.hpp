#pragma once
#include <limits>

HEADER_MATH_NAMESPACE
{
	HEADER_COMP_NAMESPACE
	{
#pragma region FUNC1
		template<typename T>
		vector<1, T> func1(vector<1, T> x, T(*function)(T))
		{
			return vector<1,T>(function(x.x));
		}
		template<typename T>
		vector<2, T> func1(vector<2, T> x, T(*function)(T))
		{
			return vector<2,T>(function(x.x), function(x.y));
		}
		template<typename T>
		vector<3, T> func1(vector<3, T> x, T(*function)(T))
		{
			return vector<3,T>(function(x.x), function(x.y), function(x.z));
		}
		template<typename T>
		vector<4, T> func1(vector<4, T> x, T(*function)(T))
		{
			return vector<4,T>(function(x.x), function(x.y), function(x.z), function(x.w));
		}
#pragma endregion
#pragma region FUNC2
		template<typename T>
		vector<1, T> func2(vector<1, T> x, vector<1, T> y, T (*function)(T, T))
		{
			return vector<1,T>(function(x.x, y.x));
		}
		template<typename T>
		vector<2, T> func2(vector<2, T> x, vector<2, T> y, T(*function)(T, T))
		{
			return vector<2,T>(function(x.x, y.x), function(y.y, y.y));
		}
		template<typename T>
		vector<3, T> func2(vector<3, T> x, vector<3, T> y, T(*function)(T, T))
		{
			return vector<3,T>(function(x.x, y.x), function(x.y, y.y), function(x.z, y.z));
		}
		template<typename T>
		vector<4, T> func2(vector<4, T> x, vector<4, T> y, T(*function)(T, T))
		{
			return vector<4,T>(function(x.x, y.x), function(x.y, y.y), function(x.z, y.z), function(x.w, y.w));
		}
#pragma endregion
#pragma region FUNC3
		template<typename T>
		vector<1, T> func3(vector<1, T> x, vector<1, T> y, vector<1, T> z, T(*function)(T, T, T))
		{
			return vector<1,T>(function(x.x, y.x, z.x));
		}
		template<typename T>
		vector<2, T> func3(vector<2, T> x, vector<2, T> y, vector<2, T> z, T(*function)(T, T, T))
		{
			return vector<2,T>(function(x.x, y.x, z.x), function(y.y, y.y, z.y));
		}
		template<typename T>
		vector<3, T> func3(vector<3, T> x, vector<3, T> y, vector<3, T> z, T(*function)(T, T, T))
		{
			return vector<3,T>(function(x.x, y.x, z.x), function(x.y, y.y, z.y), function(x.z, y.z, z.z));
		}
		template<typename T>
		vector<4, T> func3(vector<4, T> x, vector<4, T> y, vector<4, T> z, T(*function)(T, T, T))
		{
			return vector<4,T>(function(x.x, y.x, z.x), function(x.y, y.yz.y), function(x.z, y.z, z.z), function(x.w, y.w, z.w));
		}
#pragma endregion
	}
}