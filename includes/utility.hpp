/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:46:40 by hwinston          #+#    #+#             */
/*   Updated: 2022/02/04 10:02:16 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	/* ---------------------------------------------------------------------- */
	/* --- pair class ------------------------------------------------------- */

	template <class T1, class T2>
	class pair
	{
		/* --- Member types ------------------------------------------------- */
	
		public:

			typedef T1	first_type;
			typedef T2	sedond_type;

		/* --- Member variables --------------------------------------------- */

			first_type	first;
			sedond_type second;	

		/* --- Member functions --------------------------------------------- */

			pair(): first(), second() {}

			pair(const pair& pr): first(pr.first), second(pr.second) {}

			template<class U, class V>
			pair(const pair<U, V>& pr): first(pr.first), second(pr.second) {}

			pair(const first_type& a, const sedond_type& b): first(a), second(b) {}

			pair& operator=(const pair& pr)
			{
				this->first = pr.first;
				this->second = pr.second;
				return *this;
			}
			~pair() {}
	};

	/* ---------------------------------------------------------------------- */
	/* --- non-member function overloads (pair) ----------------------------- */

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second; 
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first < rhs.first ||
			(!(lhs.first < rhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs<rhs);
	}

	/* ---------------------------------------------------------------------- */
	/* --- make_pair function ----------------------------------------------- */

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return pair<T1,T2>(x,y);
	}
};

#endif