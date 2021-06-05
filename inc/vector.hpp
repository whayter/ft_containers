/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:12:39 by hwinston          #+#    #+#             */
/*   Updated: 2021/06/05 16:29:44 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:	/* member types */
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T*			pointer;
			typedef const T*	const_pointer;

			typedef ptrdiff_t	difference_type;
			typedef size_t		size_type;

		private: /* member variables */
			pointer				_container;
			size_type			_size;
			size_type			_capacity;

		public: /* member functions */
			explicit Vector(): _container(nullptr), _size(0), _capacity(0) {}
			explicit Vector()
			Vector(const Vector &ref) {}
			~Vector() {}	
			/* ------------------ iterators ------------------ */

			/* ------------------- capacity ------------------ */

			size_type		size(void) const {}
			size_type		max_size(void) const {}
			void			resize(size_type n, value_type val = value_type()) {}
			size_type		capacity() const {}
			bool			empty(void) const {}
			void			reserve(size_type n) {}

			/* ---------------- element access --------------- */
			
			reference		operator[](size_type n) {}
			const_reference	operator[](size_type n) const {}
			reference		at(size_type n) {}
			const_reference	at(size_type n) const {}
			reference		front(void) {}
			const_reference front(void) const {}
			reference		back(void) {}
			const_reference	back(void) const {}
			/* ------------------ modifiers ------------------ */

	};
};

#endif