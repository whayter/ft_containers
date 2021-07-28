/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:35:11 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/28 11:38:38 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <stdint.h>

# ifdef __linux__
#  include <uchar.h>
# endif

namespace ft
{
    /* --- integral_constant class ------------------------------------------ */

	template <class T, T v>
	struct integral_constant
	{
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;

		operator value_type()
		{
			return value;
		}
	};

	/* --- true_type / false_type ------------------------------------------- */

	typedef ft::integral_constant<bool, true> true_type;
	
	typedef ft::integral_constant<bool, false> false_type;

	/* --- is_integral class ------------------------------------------------ */

	template <class T> struct is_integral: public ft::false_type {};

	template <>
	struct is_integral<bool>: public ft::true_type {};

	template <>
	struct is_integral<char>: public ft::true_type {};
	
	template <>
	struct is_integral<char16_t>: public ft::true_type {};
	
	template <>
	struct is_integral<char32_t>: public ft::true_type {};
	
	template <>
	struct is_integral<wchar_t>: public ft::true_type {};
	
	template <>
	struct is_integral<signed char>: public ft::true_type {};
	
	template <>
	struct is_integral<short int>: public ft::true_type {};
	
	template <>
	struct is_integral<int>: public ft::true_type {};
	
	template <>
	struct is_integral<long int>: public ft::true_type {};
	
	template <>
	struct is_integral<long long int>: public ft::true_type {};
	
	template <>
	struct is_integral<unsigned char>: public ft::true_type {};
	
	template <>
	struct is_integral<unsigned short int>: public ft::true_type {};
	
	template <>
	struct is_integral<unsigned int>: public ft::true_type {};
	
	template <>
	struct is_integral<unsigned long int>: public ft::true_type {};
	
	template <>
	struct is_integral<unsigned long long int>: public ft::true_type {};

	/* --- enable_if class -------------------------------------------------- */

	template<bool Cond, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
};

#endif