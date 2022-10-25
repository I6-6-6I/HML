#pragma once

HEADER_MATH_NAMESPACE
{
	HEADER_CLIPSPACE_NAMESPACE
	{
#pragma region ORTHO
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Ortho_RH_ZO(T left, T right, T top, T bottom, T zNear, T zFar)
		{
			HML::matrix<4, 4, T> ret(static_cast<T>(1));
			ret[0][0] = static_cast<T>(2) / (right - left);
			ret[1][1] = static_cast<T>(2) / (bottom - top);
			ret[2][2] = -static_cast<T>(1) / (zNear - zFar);
			ret[3][0] = -(right + left) / (right - left);
			ret[3][1] = -(bottom + top) / (bottom - top);
			ret[3][2] = -zNear / (zFar - zNear);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Ortho_RH_NO(T left, T right, T top, T bottom, T zNear, T zFar)
		{
			HML::matrix<4, 4, T> ret(static_cast<T>(1));
			ret[0][0] = static_cast<T>(2) / (right - left);
			ret[1][1] = static_cast<T>(2) / (bottom - top);
			ret[2][2] = -static_cast<T>(2) / (zNear - zFar);
			ret[3][0] = -(right + left) / (right - left);
			ret[3][1] = -(bottom + top) / (bottom - top);
			ret[3][2] = -(zFar + zNear) / (zFar - zNear);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Ortho_LH_ZO(T left, T right, T top, T bottom, T zNear, T zFar)
		{
			HML::matrix<4,4,T> ret(static_cast<T>(1));
			ret[0][0] = static_cast<T>(2) / (right - left);
			ret[1][1] = static_cast<T>(2) / (bottom - top);
			ret[2][2] = static_cast<T>(1) / (zNear - zFar);
			ret[3][0] = -(right + left) / (right - left);
			ret[3][1] = -(bottom + top) / (bottom - top);
			ret[3][2] = -zNear / (zFar - zNear);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Ortho_LH_NO(T left, T right, T top, T bottom, T zNear, T zFar)
		{
			HML::matrix<4, 4, T> ret(static_cast<T>(1));
			ret[0][0] = static_cast<T>(2) / (right - left);
			ret[1][1] = static_cast<T>(2) / (bottom - top);
			ret[2][2] = static_cast<T>(2) / (zNear - zFar);
			ret[3][0] = -(right + left) / (right - left);
			ret[3][1] = -(bottom + top) / (bottom - top);
			ret[3][2] = -(zFar + zNear) / (zFar - zNear);
			return ret;
		}
#pragma endregion
#pragma region PERSPECTIVE
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Perspective_RH_ZO(T fov, T aspectRatio, T nearClip, T farClip)
		{
			HML::matrix<4,4,T> ret(static_cast<T>(0));
			const float tanHalfFovy = HML::Tan(fov / static_cast<T>(2));
			ret[0][0] = static_cast<T>(1) / (aspectRatio * tanHalfFovy);
			ret[1][1] = static_cast<T>(1) / (tanHalfFovy);
			ret[2][2] = farClip / (nearClip - farClip);
			ret[2][3] = -static_cast<T>(1);
			ret[3][2] = -(farClip * nearClip) / (farClip - nearClip);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Perspective_RH_NO(T fov, T aspectRatio, T nearClip, T farClip)
		{
			HML::matrix<4, 4, T> ret(static_cast<T>(0));
			const float tanHalfFovy = HML::Tan(fov / static_cast<T>(2));
			ret[0][0] = static_cast<T>(1) / (aspectRatio * tanHalfFovy);
			ret[1][1] = static_cast<T>(1) / (tanHalfFovy);
			ret[2][2] = -(farClip + nearClip) / (nearClip - farClip);
			ret[2][3] = static_cast<T>(1);
			ret[3][2] = -(static_cast<T>(2) * farClip * nearClip) / (farClip - nearClip);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4, 4, T> Perspective_LH_ZO(T fov, T aspectRatio, T nearClip, T farClip)
		{
			HML::matrix<4, 4, T> ret(static_cast<T>(0));
			const float tanHalfFovy = HML::Tan(fov / static_cast<T>(2));
			ret[0][0] = static_cast<T>(1) / (aspectRatio * tanHalfFovy);
			ret[1][1] = static_cast<T>(1) / (tanHalfFovy);
			ret[2][2] = farClip / (nearClip - farClip);
			ret[2][3] = static_cast<T>(1);
			ret[3][2] = -(farClip * nearClip) / (farClip - nearClip);
			return ret;
		}
	template<typename T = float>
	static constexpr HML::matrix<4,4,T> Perspective_LH_NO(T fov, T aspectRatio, T nearClip, T farClip)
		{
			HML::matrix<4, 4, T> ret(static_cast<T>(0));
			const float tanHalfFovy = HML::Tan(fov / static_cast<T>(2));
			ret[0][0] = static_cast<T>(1) / (aspectRatio * tanHalfFovy);
			ret[1][1] = static_cast<T>(1) / (tanHalfFovy);
			ret[2][2] = (farClip + nearClip) / (nearClip - farClip);
			ret[2][3] = static_cast<T>(1);
			ret[3][2] = -(static_cast<T>(2) * farClip * nearClip) / (farClip - nearClip);
			return ret;
		}
#pragma endregion
	}
}