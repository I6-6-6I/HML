#pragma once
HEADER_MATH_NAMESPACE
{
	HEADER_COMP_NAMESPACE
	{
		template<size_t C, size_t R, typename T>
		struct _inverse {};

		template<typename T>
		struct _inverse<2, 2, T>
		{
			static matrix<2, 2, T> inv(matrix<2, 2, T> const& m)
			{
				T OneDivideDeterminant = static_cast<T>(1) / (
					+m[0][0] * m[1][1]
					- m[1][0] * m[0][1]);
	
				matrix<2, 2, T> Inversion(
					+m[1][1] * OneDivideDeterminant,
					-m[0][1] * OneDivideDeterminant,
					-m[1][0] * OneDivideDeterminant,
					+m[0][0] * OneDivideDeterminant);
	
				return Inversion;
			}
		};
	}
	template<size_t C, size_t R, typename T>
	matrix<C, R, T> Inverse(matrix<C, R, T> const& m)
	{
		return COMP::_inverse<C,R,T>::inv(m);
	}
}