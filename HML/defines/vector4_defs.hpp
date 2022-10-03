#pragma once
#define DECLARE_VECTOR4										\
using u8Vector4		= vector4_t<unsigned char>;				\
using u16Vector4	= vector4_t<unsigned short>;			\
using u32Vector4	= vector4_t<unsigned int>;				\
using u64Vector4	= vector4_t<unsigned long long>;		\
using uVector4		= vector4_t<unsigned int>;				\
using i8Vector4		= vector4_t<signed char>;				\
using i16Vector4	= vector4_t<signed short>;				\
using i32Vector4	= vector4_t<signed int>;				\
using i64Vector4	= vector4_t<signed long long>;			\
using iVector4		= vector4_t<signed int>;				\
using fVector4		= vector4_t<float>;						\
using dVector4		= vector4_t<double>;					\
using ldVector4		= vector4_t<long double>;				\
using Vector4		= vector4_t<float>;