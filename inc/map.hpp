/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:46:06 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/08 07:14:01 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "utility.hpp"

namespace ft
{
	/* ---------------------------------------------------------------------- */
	/* --- mapIterator class ------------------------------------------------ */

	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class mapIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef T         								value_type;
			typedef Distance  								difference_type;
			typedef Pointer   								pointer;
			typedef Reference 								reference;
			typedef Category  								iterator_category;

		/* --- member variables --------------------------------------------- */

		private:

			pointer _it;

		/* --- member functions --------------------------------------------- */

		public:

			mapIterator() {}

			mapIterator(pointer it)
			{
				_it = it;
			}
	
			template <class Iter>
			mapIterator(const mapIterator<iterator_category, Iter>& it)
			{
				_it = it.base();
			}

			virtual ~mapIterator() {}

			pointer base() const
			{
				return _it;
			}

			mapIterator& operator++()
			{
				_it++;
				return *this;
			}

			mapIterator operator++(int)
			{
				mapIterator it = *this;
				++(*this);
				return it;
			}

			mapIterator& operator--()
			{
				_it--;
				return *this;
			}

			mapIterator operator--(int)
			{
				mapIterator it = *this;
				--(*this);
				return it;
			}

			reference operator*() const
			{
				return *(this->base());
			}

			pointer operator->() const
			{
				return &(operator*());
			}
	};

	/* ---------------------------------------------------------------------------- */
	/* --- non-member function overloads (mapIterator) ------------------- */

    template <class T, class Category>
	bool operator==(const mapIterator<Category, T>& lhs,
		const mapIterator<Category, T>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	template <class T, class TT, class Category>
	bool operator==(const mapIterator<Category, T>& lhs,
		const mapIterator<Category, TT>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T, class Category>
	bool operator!=(const mapIterator<Category, T>& lhs,
		const mapIterator<Category, T>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	template <class T, class TT, class Category>
	bool operator!=(const mapIterator<Category, T>& lhs,
		const mapIterator<Category, TT>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	/* ---------------------------------------------------------------------- */
	/* --- map class -------------------------------------------------------- */

	template <class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		/* --- Member types ------------------------------------------------- */
    
		public:

			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			velue_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::mapIterator<ft::bidirectional_iterator_tag, value_type> iterator;
			typedef typename ft::mapIterator<ft::bidirectional_iterator_tag, const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<iterator>			const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		/* --- Member variables --------------------------------------------- */

		private:

			allocator_type											_alloc;
			pointer													_container;
			size_type												_size;

		/* --- Constructors & destructor ------------------------------------ */

		public:

			map(const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type())
			{}

			template <class InputIterator>
  			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type())
			{}

			map(const map& x)
			{
			}

			~map()
			{
			}

			map& operator=(const map& x)
			{
			}

		/* --- Iterators ---------------------------------------------------- */

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

		/* --- Capacity ----------------------------------------------------- */

			bool			empty(void) const
			{
				return _size == 0;
			}

			size_type		size(void) const
			{
				return _size;
			}

			size_type		max_size(void) const
			{
				return allocator_type().max_size();
			}

		/* --- Element access ----------------------------------------------- */
			
			mapped_type& operator[] (const key_type& k)
			{
				return *((this->insert(ft::make_pair(k, mapped_type()))).first).second;		
			}


		/* --- Modifiers ---------------------------------------------------- */

			ft::pair<iterator,bool> insert(const value_type& val)
			{}

			iterator insert(iterator position, const value_type& val)
			{}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{}

			void erase(iterator position)
			{}

			size_type erase(const key_type& k)
			{}

			void erase(iterator first, iterator last)
			{}

			void swap (map& x)
			{}

			void clear()
			{}

		/* --- Observers ---------------------------------------------------- */

			key_compare key_comp() const
			{}

			value_compare value_comp() const
			{}

		/* --- Operations --------------------------------------------------- */

			iterator find (const key_type& k)
			{}

			const_iterator find (const key_type& k) const
			{}

			size_type count (const key_type& k) const
			{}

			iterator lower_bound (const key_type& k)
			{}

			const_iterator lower_bound (const key_type& k) const
			{}

			iterator upper_bound (const key_type& k)
			{}

			const_iterator upper_bound (const key_type& k) const
			{}

			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
			{}

			ft::pair<iterator, iterator> equal_range (const key_type& k)
			{}
	};
};

#endif