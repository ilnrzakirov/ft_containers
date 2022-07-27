#ifndef UNTITLED_IS_INTEGRAL_HPP
#define UNTITLED_IS_INTEGRAL_HPP
#include  <type_traits>

namespace ft {
template<class T, T value_>
    struct integral_constant {
        static const T value = value_;
    };
struct true_type: public  integral_constant<bool, true> {};
struct false_type: public  integral_constant<bool, false> {};

template<class>
struct is_integral : public false_type{};
template<> struct is_integral<bool>: public true_type {};
template<> struct is_integral<char>: public true_type {};
template<> struct is_integral<signed char>: public true_type {};
template<> struct is_integral<unsigned char>: public true_type {};
template<> struct is_integral<wchar_t>: public true_type {};
template<> struct is_integral<char16_t>: public true_type {};
template<> struct is_integral<char32_t>: public true_type {};
template<> struct is_integral<short>: public true_type {};
template<> struct is_integral<unsigned short>: public true_type {};
template<> struct is_integral<int>: public true_type {};
template<> struct is_integral<unsigned int>: public true_type {};
template<> struct is_integral<long>: public true_type {};
template<> struct is_integral<unsigned long>: public true_type {};
template<> struct is_integral<long long>: public true_type {};
template<> struct is_integral<unsigned long long>: public true_type {};
template<> struct is_integral<__int128_t>: public true_type {};
template<> struct is_integral<__uint128_t>: public true_type {};

}

#endif
