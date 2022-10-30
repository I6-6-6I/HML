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
	template<typename T>
	matrix<4, 4, T> Translate(matrix<4, 4, T> const& m, vector<3, T> const& v)
	{
		matrix<4, 4, T> ret(m);
		ret[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return ret;
	}

	template<typename T>
	matrix<4, 4, T> Rotate(matrix<4, 4, T> const& m, T angle, vector<3, T> const& v)
	{
		T const a = angle;
		T const c = cos(a);
		T const s = sin(a);

		vector<3, T> xyz(HML::Normalize(v));
		vector<3, T> temp((T(1) - c) * xyz);

		matrix<4, 4, T> rot;
		rot[0][0] = c + temp[0] * xyz[0];
		rot[0][1] = temp[0] * xyz[1] + s * xyz[2];
		rot[0][2] = temp[0] * xyz[2] - s * xyz[1];

		rot[1][0] = temp[1] * xyz[0] - s * xyz[2];
		rot[1][1] = c + temp[1] * xyz[1];
		rot[1][2] = temp[1] * xyz[2] + s * xyz[0];

		rot[2][0] = temp[2] * xyz[0] + s * xyz[1];
		rot[2][1] = temp[2] * xyz[1] - s * xyz[0];
		rot[2][2] = c + temp[2] * xyz[2];

		matrix<4, 4, T> ret;
		ret[0] = m[0] * rot[0][0] + m[1] * rot[0][1] + m[2] * rot[0][2];
		ret[1] = m[0] * rot[1][0] + m[1] * rot[1][1] + m[2] * rot[1][2];
		ret[2] = m[0] * rot[2][0] + m[1] * rot[2][1] + m[2] * rot[2][2];
		ret[3] = m[3];
		return ret;
	}
	template<typename T>
	vector<3, T> Rotate(quat<T> const& q, vector<3, T> const& v)
	{
		return q * v;
	}
	template<typename T>
	vector<4, T> Rotate(quat<T> const& q, vector<4, T> const& v)
	{
		return q * v;
	}
	template<typename T>
	matrix<4, 4, T> Scale(matrix<4, 4, T> const& m, vector<3, T> const& v)
	{
		matrix<4, 4, T> ret;
		ret[0] = m[0] * v[0];
		ret[1] = m[1] * v[1];
		ret[2] = m[2] * v[2];
		ret[3] = m[3];
		return ret;
	}
	template<typename T = float>
	static constexpr bool DecomposeTransform(const HML::matrix<4, 4, T>&transform, HML::vector<3, T>&outTranslation, HML::vector<3, T>&outRotation, HML::vector<3, T>&outScale)		//Might need fix test it later
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
	
				HML::vector<3, T> Row[3];
				for (size_t i = 0; i < 3; ++i)
					for (size_t j = 0; j < 3; ++j)
						Row[i][j] = LocalMatrix[i][j];

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

			HML::matrix<4, 4, T> ret(static_cast<T>(1));
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

			HML::matrix<4, 4, T> ret(static_cast<T>(1));
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