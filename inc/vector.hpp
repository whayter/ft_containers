/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:12:39 by hwinston          #+#    #+#             */
/*   Updated: 2021/06/23 23:25:40 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "iterator.hpp"

#include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			
	/* --- Member types ----------------------------------------------------- */

			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;	
			typedef typename ft::random_access_iterator_tag			rai;				
			typedef typename ft::iterator<rai, value_type> 			iterator;
			typedef typename ft::iterator<rai, const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:

	/* --- Member variables ------------------------------------------------- */

			allocator_type											_alloc;
			pointer													_container;
			size_type												_size;
			size_type												_capacity;

		public:

	/* --- Constructors & destructor ---------------------------------------- */

			explicit vector(const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_container(NULL),
				_size(0),
				_capacity(0)
			{}

			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_container(_alloc.allocate(n)),
				_size(n),
				_capacity(n)
			{	
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_container + i, val);
			}

			template <class InputIterator>
         	vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_container(_alloc.allocate(ft::distance(first, last))),
				_size(ft::distance(first, last)),
				_capacity(ft::distance(first, last))
			{
				for (size_type i = 0; i < _size; i++, first++)
					_alloc.construct(_container + i, *first);
			}

			vector(const vector& x)
			:
				_alloc(x._alloc),
				_container(_alloc.allocate(x._size)),
				_size(x._size),
				_capacity(x._capacity)
			{
				*this = x;
			}

			~vector()
			{
				this->clear();
				_alloc.deallocate(_container, _capacity);
			}

			vector &operator=(const vector& x)
			{
				if (!this->empty())
					this->clear();
				_capacity = x._capacity;
				_size = x._size;
				this->reserve(_size);
				iterator it = this->begin();
				for (const_iterator x_it = x.begin(); x_it != x.end(); x_it++)
				{
					_alloc.construct(it.base(), *x_it);
					it++;
				}
				return *this;
			}

	/* --- Iterators -------------------------------------------------------- */

			iterator begin(void)
			{
				return iterator(_container);
			}

			const_iterator begin(void) const
			{
				return const_iterator(_container);
			}

			iterator end(void)
			{
				if (this->empty())
					return this->begin();
				return iterator(_container + (_size));
			}

			const_iterator end(void) const
			{
				if (this->empty())
					return this->begin();
				return const_iterator(_container + (_size));
			}

			reverse_iterator rbegin(void)
			{
				return reverse_iterator(this->end());
			}

			const_reverse_iterator rbegin(void) const
			{
				return const_reverse_iterator(this->end());
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(this->begin());
			}

	/* --- Capacity --------------------------------------------------------- */

			size_type		size(void) const
			{
				return _size;
			}

			size_type		max_size(void) const
			{
				return allocator_type().max_size();
			}

			void			resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
					for (; _size != n ; _size--)
						this->pop_back();
				else if (n > _size)
					this->insert(this->end(), n - _size, val);
			}

			size_type		capacity(void) const
			{
				return _capacity;
			}

			bool			empty(void) const
			{
				return this->size() == 0;
			}

			void			reserve(size_type n)
			{
				if (n <= _capacity)
					return ;
				pointer new_container = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(new_container + i, _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.deallocate(_container, _capacity);
				_capacity = n;
				_container = new_container;
			}

	/* --- Element access --------------------------------------------------- */
			
			reference		operator[](size_type n)
			{
				return *(_container + n);
			}
			
			const_reference	operator[](size_type n) const
			{
				return *(_container + n);
			}

			reference		at(size_type n)
			{
				if (n >= _size)
					throw (std::out_of_range("vector"));
				return _container[n];
			}

			const_reference	at(size_type n) const
			{
				if (n >= _size)
					throw (std::out_of_range("vector"));
				return _container[n];
			}

			reference		front(void)
			{
				return _container[0];
			}

			const_reference front(void) const
			{
				return _container[0];
			}

			reference		back(void)
			{
				return _container[_size - 1];
			}
	
			const_reference	back(void) const
			{
				return _container[_size - 1];
			}

	/* --- Modifiers -------------------------------------------------------- */

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}

			void assign(size_type n, const value_type& val)
			{
				this->clear();
				this->insert(this->begin(), n, val);
			}

			void push_back(const value_type& val)
			{
				this->insert(this->end(), val);
			}

			void pop_back()
			{
				this->erase(this->end() - 1);
			}

			iterator insert(iterator pos, const value_type& val)
			{
				size_type index = ft::distance(this->begin(), pos);
				if (_size + 1 > _capacity)
				{
					if (_size + 1 <= _size * 2)
						this->reserve(_size * 2);
					else
						this->reserve(_size + 1);
				}
				_size += 1;
				for (size_type i = _size - 1; i > index; i--)
					_alloc.construct(_container + i, _container[i - 1]);
				_alloc.construct(_container + index, val);
				return(iterator(_container + index));
			}

			void insert(iterator pos, size_type n, const value_type& val)
			{
				size_type index = ft::distance(this->begin(), pos);
				if (_size + n > _capacity)
				{
					if (_size + n <= _size * 2)
						this->reserve(_size * 2);
					else
						this->reserve(_size + n);
				}
				for (size_type i = 0; i < n; i++, index++)
					this->insert(this->begin() + index, val);
			}

			template <class InputIterator>
    		void insert(iterator pos, InputIterator first, InputIterator last)
			{
				size_type n = ft::distance(first, last);
				size_type index = ft::distance(this->begin(), pos);
				if (_size + n > _capacity)
				{
					if (_size + n <= _size * 2)
						this->reserve(_size * 2);
					else
						this->reserve(_size + n);
				}
				for (; first != last; first++, index++)
					this->insert(this->begin() + index, *first);
			}

			iterator erase(iterator position)
			{	
				if (position > this->end())
					return position;
				size_type index = _size - ft::distance(position, this->end());
				_alloc.destroy(_container + index);
				for (; index + 1 < _size; index++)
				{
					_alloc.construct(_container + index, _container[index + 1]);
					_alloc.destroy(_container + index + 1);
				}
				_size--;
				return position;
			}

			iterator erase(iterator first, iterator last)
			{
				for (size_type n = ft::distance(first, last); n; n--)
					erase(first);
				return first;	
			}

			void swap(vector& x)
			{
				if (*this == x)
					return ;
				vector tmp(x);
				x = *this;
				*this = tmp;
			}

			void clear()
			{
				for (size_type i = 0; i < this->size(); i++)
					_alloc.destroy(_container + i);
				_size = 0;
			}
	};

	/* --- Non-member functions --------------------------------------------- */

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	};

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	};

	// PAS SUR DE MOI SUR CE COUP
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		for (size_t i = 0, j = 0; i < lhs.size() && j < rhs.size(); i++, j++)
			if (lhs[i] != rhs[i])
				return lhs[i] < rhs[i];
		if (lhs.size() >= rhs.size())
			return false;
		return true;
	};

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return rhs < lhs;
	};

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	};
};

#endif