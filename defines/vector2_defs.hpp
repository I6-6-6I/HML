#pragma once
#define DECLARE_VECTOR2										\
using u8Vector2		= vector2_t<unsigned char>;				\
using u16Vector2	= vector2_t<unsigned short>;			\
using u32Vector2	= vector2_t<unsigned int>;				\
using u64Vector2	= vector2_t<unsigned long long>;		\
using uVector2		= vector2_t<unsigned int>;				\
using i8Vector2		= vector2_t<signed char>;				\
using i16Vector2	= vector2_t<signed short>;				\
using i32Vector2	= vector2_t<signed int>;				\
using i64Vector2	= vector2_t<signed long long>;			\
using iVector2		= vector2_t<signed int>;				\
using fVector2		= vector2_t<float>;						\
using dVector2		= vector2_t<double>;					\
using ldVector2		= vector2_t<long double>;				\
using Vector2		= vector2_t<float>;