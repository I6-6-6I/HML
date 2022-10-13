#pragma once
#include <cmath>

HEADER_MATH_NAMESPACE
{
	HEADER_TRIGONOMETRY_NAMESPACE
	{
	#define PI 3.1415926535897932384626433832795;
	
		template<typename T>
		T radians(T deg)
		{
			return deg * static_cast<T>(0.01745329251994329576923690768489);
		}
		template<size_t L, typename T>
		vector<L,T> radians(vector<L, T> const& deg)
		{
			return deg * static_cast<T>(0.01745329251994329576923690768489);		//Might need fix
		}
		template<typename T>
		T degrees(T rad)
		{
			return rad * static_cast<T>(57.295779513082320876798154814105);
		}
		template<size_t L, typename T>
		vector<L, T> degrees(vector<L, T> const& rad)
		{
			return rad * static_cast<T>(57.295779513082320876798154814105);		//Might need fix
		}
		
	}
}