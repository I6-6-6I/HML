#pragma once
#define DECLARE_VECTOR3										\
using u8Vector3		= vector3_t<unsigned char>;				\
using u16Vector3	= vector3_t<unsigned short>;			\
using u32Vector3	= vector3_t<unsigned int>;				\
using u64Vector3	= vector3_t<unsigned long long>;		\
using uVector3		= vector3_t<unsigned int>;				\
using i8Vector3		= vector3_t<signed char>;				\
using i16Vector3	= vector3_t<signed short>;				\
using i32Vector3	= vector3_t<signed int>;				\
using i64Vector3	= vector3_t<signed long long>;			\
using iVector3		= vector3_t<signed int>;				\
using fVector3		= vector3_t<float>;						\
using dVector3		= vector3_t<double>;					\
using ldVector3		= vector3_t<long double>;				\
using Vector3		= vector3_t<float>;