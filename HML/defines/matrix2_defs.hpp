#pragma once
#define DECLARE_MAT2x2											\
using u8Matrix2		= matrix2x2_t<unsigned char>;				\
using u16Matrix2	= matrix2x2_t<unsigned short>;				\
using u32Matrix2	= matrix2x2_t<unsigned int>;				\
using u64Matrix2	= matrix2x2_t<unsigned long long>;			\
using uMatrix2		= matrix2x2_t<unsigned int>;				\
using i8Matrix2		= matrix2x2_t<signed char>;					\
using i16Matrix2	= matrix2x2_t<signed short>;				\
using i32Matrix2	= matrix2x2_t<signed int>;					\
using i64Matrix2	= matrix2x2_t<signed long long>;			\
using iMatrix2		= matrix2x2_t<signed int>;					\
using fMatrix2		= matrix2x2_t<float>;						\
using dMatrix2		= matrix2x2_t<double>;						\
using ldMatrix2		= matrix2x2_t<long double>;					\
using Matrix2		= matrix2x2_t<float>;

#define DECLARE_MAT2x3											\
using u8Matrix2x3	= matrix2x3_t<unsigned char>;				\
using u16Matrix2x3	= matrix2x3_t<unsigned short>;				\
using u32Matrix2x3	= matrix2x3_t<unsigned int>;				\
using u64Matrix2x3	= matrix2x3_t<unsigned long long>;			\
using uMatrix2x3	= matrix2x3_t<unsigned int>;				\
using i8Matrix2x3	= matrix2x3_t<signed char>;					\
using i16Matrix2x3	= matrix2x3_t<signed short>;				\
using i32Matrix2x3	= matrix2x3_t<signed int>;					\
using i64Matrix2x3	= matrix2x3_t<signed long long>;			\
using iMatrix2x3	= matrix2x3_t<signed int>;					\
using fMatrix2x3	= matrix2x3_t<float>;						\
using dMatrix2x3	= matrix2x3_t<double>;						\
using ldMatrix2x3	= matrix2x3_t<long double>;					\
using Matrix2x3		= matrix2x3_t<float>;

#define DECLARE_MAT2x4											\
using u8Matrix2x4	= matrix2x4_t<unsigned char>;				\
using u16Matrix2x4	= matrix2x4_t<unsigned short>;				\
using u32Matrix2x4	= matrix2x4_t<unsigned int>;				\
using u64Matrix2x4	= matrix2x4_t<unsigned long long>;			\
using uMatrix2x4	= matrix2x4_t<unsigned int>;				\
using i8Matrix2x4	= matrix2x4_t<signed char>;					\
using i16Matrix2x4	= matrix2x4_t<signed short>;				\
using i32Matrix2x4	= matrix2x4_t<signed int>;					\
using i64Matrix2x4	= matrix2x4_t<signed long long>;			\
using iMatrix2x4	= matrix2x4_t<signed int>;					\
using fMatrix2x4	= matrix2x4_t<float>;						\
using dMatrix2x4	= matrix2x4_t<double>;						\
using ldMatrix2x4	= matrix2x4_t<long double>;					\
using Matrix2x4		= matrix2x4_t<float>;

#define DECLARE_MAT2	\
DECLARE_MAT2x2			\
DECLARE_MAT2x3			\
DECLARE_MAT2x4