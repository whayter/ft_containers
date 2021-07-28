/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:12:39 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/28 11:37:55 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# ifdef __linux__
#  include <cstddef>
# endif

# include "../../utility/utility.hpp"
# include "../../utility/algorithm.hpp"
# include "../../utility/type_traits.hpp"
# include "../../utility/iterator.hpp"

namespace ft
{
	/* ---------------------------------------------------------------------- */
	/* --- vectorIterator class --------------------------------------------- */

	template <class T>
	class vectorIterator: public ft::iterator<ft::random_access_iterator_tag, T>
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef T         								value_type;
			typedef ptrdiff_t  								difference_type;
			typedef T*  									pointer;
			typedef T&										reference;
			typedef typename ft::random_access_iterator_tag iterator_category;

		/* --- member variables --------------------------------------------- */

		private:
			pointer _it;

		/* --- member functions --------------------------------------------- */

		public:
			vectorIterator() {}

			vectorIterator(pointer it)
			{
				_it = it;
			}
	
			template <class Iter>
			vectorIterator(const vectorIterator<Iter>& it)
			{
				_it = it.base();
			}

			virtual ~vectorIterator() {}

			pointer base() const
			{
				return _it;
			}

			reference operator*() const
			{
				return *(this->base());
			}

			vectorIterator operator+(difference_type n) const
			{
				return vectorIterator(this->base() + n);
			}

			vectorIterator& operator++()
			{
				_it++;
				return *this;
			}

			vectorIterator operator++(int)
			{
				vectorIterator it = *this;
				++(*this);
				return it;
			}

			vectorIterator& operator+=(difference_type n)
			{
				_it += n;
				return *this;
			}

			vectorIterator operator-(difference_type n) const
			{
				return vectorIterator(this->base() - n);
			}

			vectorIterator& operator--()
			{
				_it--;
				return *this;
			}

			vectorIterator operator--(int)
			{
				vectorIterator it = *this;
				--(*this);
				return it;
			}

			vectorIterator& operator-=(difference_type n)
			{
				_it -= n;
				return *this;
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			reference operator[](difference_type n) const
			{
				return this->base()[n];
			}
	};

	/* ---------------------------------------------------------------------- */
	/* --- non-member function overloads (vectorIterator) ------------------- */

    template <class T>
	bool operator==(const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	template <class T, class TT>
	bool operator==(const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T>
	bool operator!=(const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	template <class T, class TT>
	bool operator!=(const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class T>
	bool operator<(const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	template <class T, class TT>
	bool operator<(const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class T>
	bool operator<=(const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
	template <class T, class TT>
	bool operator<=(const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class T>
	bool operator>(const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	template <class T, class TT>
	bool operator>(const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class T>
	bool operator>= (const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	template <class T, class TT>
	bool operator>= (const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class T>
	vectorIterator<T> operator+(
		typename vectorIterator<T>::difference_type n,
		const vectorIterator<T>& it)
	{
		return it + n;
	}

	template <class T>
	typename vectorIterator<T>::difference_type operator-(
		const vectorIterator<T>& lhs,
		const vectorIterator<T>& rhs)
	{
		return lhs.base() - rhs.base();
	}
	template <class T, class TT>
	typename vectorIterator<T>::difference_type operator-(
		const vectorIterator<T>& lhs,
		const vectorIterator<TT>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	/* ---------------------------------------------------------------------- */	
	/* --- vector class ----------------------------------------------------- */

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{		
	/* --- Member types ----------------------------------------------------- */
		
		public:

			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;	
			typedef typename ft::vectorIterator<value_type> 		iterator;
			typedef typename ft::vectorIterator<const value_type> 	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

	/* --- Member variables ------------------------------------------------- */

		private:

			allocator_type											_alloc;
			pointer													_container;
			size_type												_size;
			size_type												_capacity;

	/* --- Constructors & destructor ---------------------------------------- */

		public:

			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _container(NULL), _size(0), _capacity(0) {}

			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _container(_alloc.allocate(n)), _size(n), _capacity(n)
			{	
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_container + i, val);
			}

			template <class InputIterator>
         	vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),	 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = NULL)
			: _alloc(alloc)
			{
				_size = ft::distance(first, last);
				_container = _alloc.allocate(_size);
				_capacity = _size;
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
				if (this == &x)
					return *this;
				this->clear();
				_container = _alloc.allocate(x._size);
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
				return iterator(_container + _size);
			}

			const_iterator end(void) const
			{
				return const_iterator(_container + _size);
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

			size_type size(void) const
			{
				return _size;
			}

			size_type max_size(void) const
			{
				return allocator_type().max_size();
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
					while (_size != n)
						this->pop_back();
				else
					this->insert(this->end(), n - _size, val);
			}

			size_type capacity(void) const
			{
				return _capacity;
			}

			bool empty(void) const
			{
				return _size == 0;
			}

			void reserve(size_type n)
			{
				if (n > this->max_size())
					throw (std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
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
			
			reference operator[](size_type n)
			{
				return *(_container + n);
			}
			
			const_reference	operator[](size_type n) const
			{
				return *(_container + n);
			}

			reference at(size_type n)
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

			reference front(void)
			{
				return _container[0];
			}

			const_reference front(void) const
			{
				return _container[0];
			}

			reference back(void)
			{
				return _container[_size - 1];
			}
	
			const_reference	back(void) const
			{
				return _container[_size - 1];
			}

	/* --- Modifiers -------------------------------------------------------- */

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = NULL)
			{
				this->clear();
				this->reserve(ft::distance(first, last));
				this->insert(this->begin(), first, last);
			}

			void assign(size_type n, const value_type& val)
			{
				this->clear();
				this->reserve(n);
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
				if (_capacity == 0)
					this->reserve(1);
				else if (_size + 1 > _capacity)
					this->reserve(_size * 2);
				_size += 1;
				for (size_type i = _size - 1; i > index; i--)
					_alloc.construct(_container + i, _container[i - 1]);
				_alloc.construct(_container + index, val);
				return(iterator(_container + index));
			}

# ifdef __linux__

			void insert(iterator pos, size_type n, const value_type& val)
			{
				size_type index = ft::distance(this->begin(), pos);
				if (_capacity == 0)
					this->reserve(n);
				else if (_size + n > _capacity)
				{
					if (2 * _size >= _size + n)
						this->reserve(_size * 2);
					else
						this->reserve(_size + n);
				}
				for (size_type i = 0; i < n; i++, index++)
					this->insert(this->begin() + index, val);
			}

			template <class InputIterator>
    		void insert(iterator pos, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = NULL)
			{
				size_type n = ft::distance(first, last);
				size_type index = ft::distance(this->begin(), pos);
				if (_capacity == 0)
					this->reserve(n);
				else if (_size + n > _capacity)
				{
					if (2 * _size >= _size + n)
						this->reserve(_size * 2);
					else
						this->reserve(_size + n);
				}
				for (; first != last; first++, index++)
					this->insert(this->begin() + index, *first);
			}

# else

			void insert(iterator pos, size_type n, const value_type& val)
			{
				size_type index = ft::distance(this->begin(), pos);
				if (_capacity == 0)
					this->reserve(n);
				else if (_size + n > 2 * _capacity)
					this->reserve(_size + n);
				for (size_type i = 0; i < n; i++, index++)
					this->insert(this->begin() + index, val);
			}

			template <class InputIterator>
    		void insert(iterator pos, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = NULL)
			{
				size_type n = ft::distance(first, last);
				size_type index = ft::distance(this->begin(), pos);
				if (_capacity == 0)
					this->reserve(n);
				else if (_size + n > 2 * _capacity)
					this->reserve(_size + n);
				for (; first != last; first++, index++)
					this->insert(this->begin() + index, *first);
			}

# endif

			iterator erase(iterator position)
			{	
				if (position >= this->end())
					return position;
				size_type index = ft::distance(this->begin(), position);
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
				
				pointer		tmp_container = x._container;
				size_type	tmp_size = x._size;
				size_type	tmp_capacity = x._capacity;

				x._container = _container;
				x._size = _size;
				x._capacity = _capacity;
				_container = tmp_container;
				_size = tmp_size;
				_capacity = tmp_capacity;
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_container + i);
				_size = 0;
			}
	};

	/* --- Non-member functions --------------------------------------------- */

	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return rhs < lhs;
	};

	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc> &lhs, ft::vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	};
};

#endif