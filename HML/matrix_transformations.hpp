#pragma once
#include "geometric_common.hpp"
HEADER_MATH_NAMESPACE
{
	HEADER_COMP_NAMESPACE
	{
		template<typename T = float>
		vector<3, T> scale(vector<3, T> const& x, T len)
		{
			return x * len / HML::Length(x);
		}
	}
	HEADER_TRANSFORM_NAMESPACE
	{
	template<typename T = float>
	static constexpr bool DecomposeTransform(const HML::matrix<4, 4, T>&transform, HML::vector<3, T>&outTranslation, HML::vector<3, T>&outRotation, HML::vector<3, T>&outScale)
			{
				HML::matrix<4, 4, T> LocalMatrix(transform);
	
				if (HML::EpsilonEqual(LocalMatrix[3][3], static_cast<T>(0), HML::Epsilon<T>()))
					return false;
				if (HML::EpsilonNotEqual(LocalMatrix[0][3], static_cast<T>(0), HML::Epsilon<T>()) ||
					HML::EpsilonNotEqual(LocalMatrix[1][3], static_cast<T>(0), HML::Epsilon<T>()) ||
					HML::EpsilonNotEqual(LocalMatrix[2][3], static_cast<T>(0), HML::Epsilon<T>()))
				{
					LocalMatrix[0][3] = LocalMatrix[1][3] = LocalMatrix[2][3] = static_cast<T>(0);
					LocalMatrix[3][3] = static_cast<T>(1);
				}
				outTranslation = HML::vector<3, T>(LocalMatrix[3]);
				LocalMatrix[3] = HML::vector<4, T>(0, 0, 0, LocalMatrix[3].w);
	
				HML::vector<3, T> Row[3]/*, Pdum3*/;			//IDK FIX if it is needed
				for (size_t i = 0; i < 3; ++i)
					for (size_t j = 0; j < 3; ++j)
						Row[i][j] = LocalMatrix[i][j];
	
				// Compute X scale factor and normalize first row.
				outScale.x = HML::Length(Row[0]);
				Row[0] = HML::COMP::scale(Row[0], static_cast<T>(1));
				outScale.y = HML::Length(Row[1]);
				Row[1] = HML::COMP::scale(Row[1], static_cast<T>(1));
				outScale.z = HML::Length(Row[2]);
				Row[2] = HML::COMP::scale(Row[2], static_cast<T>(1));
	
				outRotation.y = HML::Asin(-Row[0][2]);
				if (HML::Cos(outRotation.y) != 0) {
					outRotation.x = HML::Atan(Row[1][2], Row[2][2]);
					outRotation.z = HML::Atan(Row[0][1], Row[0][0]);
				}
				else {
					outRotation.x = -HML::Atan(-Row[2][0], Row[1][1]);
					outRotation.z = 0;
				}
	
	
				return true;
			}
	#pragma region VIEW
	template<typename T = float>
	static constexpr HML::matrix<4,4,T> View_RH(HML::vector<3, T> const& eye, HML::vector<3, T> const& center, HML::vector<3, T> const& up)
		{
			HML::vector<3, T> const w(HML::Normalize(center - eye));
			HML::vector<3, T> const u(HML::Normalize(HML::Cross(w, up)));
			HML::vector<3, T> const v(HML::Cross(u, w));

			HML::matrix<4, 4, T> ret(static_cast<T>(0));
			ret[0][0] = u.x;
			ret[1][0] = u.y;
			ret[2][0] = u.z;
			ret[0][1] = v.x;
			ret[1][1] = v.y;
			ret[2][1] = v.z;
			ret[0][2] = -w.x;
			ret[1][2] = -w.y;
			ret[2][2] = -w.z;
			ret[3][0] = -HML::Dot(u, eye);
			ret[3][1] = -HML::Dot(v, eye);
			ret[3][2] = HML::Dot(w, eye);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4,4,T> View_LH(HML::vector<3, T> const& eye, HML::vector<3, T> const& center, HML::vector<3, T> const& up)
		{
			HML::vector<3, T> const w(HML::Normalize(center - eye));
			HML::vector<3, T> const u(HML::Normalize(HML::Cross(up, w)));
			HML::vector<3, T> const v(HML::Cross(w, u));

			HML::matrix<4, 4, T> ret(static_cast<T>(0));
			ret[0][0] = u.x;
			ret[1][0] = u.y;
			ret[2][0] = u.z;
			ret[0][1] = v.x;
			ret[1][1] = v.y;
			ret[2][1] = v.z;
			ret[0][2] = w.x;
			ret[1][2] = w.y;
			ret[2][2] = w.z;
			ret[3][0] = -HML::Dot(u, eye);
			ret[3][1] = -HML::Dot(v, eye);
			ret[3][2] = -HML::Dot(w, eye);
			return ret;
		}
#pragma endregion
	}
}