#pragma once
HEADER_MATH_NAMESPACE
{
	HEADER_DETAIL_NAMESPACE
	{
		template<size_t C, size_t R, typename T>
		struct _inverse {};

		template<typename T>
		struct _inverse<2, 2, T>
		{
			static matrix<2, 2, T> inv(matrix<2, 2, T> const& m)
			{
				T OneOverDeterminant = static_cast<T>(1) / (
					+m[0][0] * m[1][1]
					- m[1][0] * m[0][1]);
	
				matrix<2, 2, T> Inverse(
					+m[1][1] * OneOverDeterminant,
					-m[0][1] * OneOverDeterminant,
					-m[1][0] * OneOverDeterminant,
					+m[0][0] * OneOverDeterminant);
	
				return Inverse;
			}
		};
	}
	template<size_t C, size_t R, typename T>
	matrix<C, R, T> inverse(matrix<C, R, T> const& m)
	{
		return DETAIL_HML::_inverse<C,R,T>::inv(m);
	}
}