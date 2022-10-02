#pragma once
#define DECLARE_VECTOR1										\
using u8Vector1		= vector1_t<unsigned char>;				\
using u16Vector1	= vector1_t<unsigned short>;			\
using u32Vector1	= vector1_t<unsigned int>;				\
using u64Vector1	= vector1_t<unsigned long long>;		\
using uVector1		= vector1_t<unsigned int>;				\
using i8Vector1		= vector1_t<signed char>;				\
using i16Vector1	= vector1_t<signed short>;				\
using i32Vector1	= vector1_t<signed int>;				\
using i64Vector1	= vector1_t<signed long long>;			\
using iVector1		= vector1_t<signed int>;				\
using fVector1		= vector1_t<float>;						\
using dVector1		= vector1_t<double>;					\
using ldVector1		= vector1_t<long double>;				\
using Vector1		= vector1_t<float>;