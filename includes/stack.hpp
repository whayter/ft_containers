/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:05:25 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/26 15:21:49 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	/* ---------------------------------------------------------------------- */
	/* --- stack class ------------------------------------------------------ */

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		/* --- Member types ------------------------------------------------- */

		public:

			typedef T				value_type;
			typedef Container		container_type;
			typedef size_t			size_type;

		/* --- Member variables --------------------------------------------- */

		protected:

			container_type			c;

		private:

			template <class TY, class C>
			friend bool	operator==(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

			template <class TY, class C>
			friend bool	operator<(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

		/* --- Member functions --------------------------------------------- */

		public:	

			explicit stack(const container_type& ctnr = container_type())
			: c(ctnr) {}

			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			value_type& top()
			{
				return c.back();
			}

			const value_type& top() const
			{
				return c.back();
			}

			void push(const value_type& val)
			{
				c.push_back(val);
			}

			void pop()
			{
				c.pop_back();
			}
	};

	/* ---------------------------------------------------------------------- */
	/* --- non-member functions (stack) ------------------------------------- */

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c < rhs.c;
	}
	
	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return rhs < lhs;
	}
	
	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
};

#endif