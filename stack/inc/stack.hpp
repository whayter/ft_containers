/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:05:25 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/19 12:59:53 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../../vector/inc/vector.hpp"

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

		private:

			container_type			_container;

			template <class TY, class C>
			friend bool	operator==(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

			template <class TY, class C>
			friend bool	operator!=(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

			template <class TY, class C>
			friend bool	operator<(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

			template <class TY, class C>
			friend bool	operator<=(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

			template <class TY, class C>
			friend bool	operator>(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

			template <class TY, class C>
			friend bool	operator>=(const stack<TY, C> &lhs, const stack<TY, C> &rhs);

		/* --- Member functions --------------------------------------------- */

		public:	

			explicit stack(const container_type& ctnr = container_type())
			: _container(ctnr) {}

			bool empty() const
			{
				return _container.empty();
			}

			size_type size() const
			{
				return _container.size();
			}

			value_type& top()
			{
				return _container.back();
			}

			const value_type& top() const
			{
				return _container.back();
			}

			void push(const value_type& val)
			{
				_container.push_back(val);
			}

			void pop()
			{
				_container.pop_back();
			}
	};

	/* ---------------------------------------------------------------------- */
	/* --- non-member functions (stack) ------------------------------------- */

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container == rhs._container;
	}

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container != rhs._container;
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container < rhs._container;
	}
	
	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container <= rhs._container;
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container > rhs._container;
	}
	
	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._container >= rhs._container;
	}
};

#endif