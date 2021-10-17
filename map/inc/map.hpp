/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:46:06 by hwinston          #+#    #+#             */
/*   Updated: 2021/10/17 15:38:37 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>

# ifdef __linux__
#  include <cstddef>
#  include <limits>
# endif

# include "../../utility/utility.hpp"
# include "../../utility/type_traits.hpp"
# include "../../utility/iterator.hpp"
# include "../../utility/algorithm.hpp"
# include "../../utility/binary_search_tree.hpp"

namespace ft
{
	/* ---------------------------------------------------------------------- */
	/* --- map class -------------------------------------------------------- */

	template <class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		/* --- Member types ------------------------------------------------- */
    
		public:

			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::mapTree<Key, T>::iterator			iterator;
			typedef typename ft::mapTree<Key, T>::const_iterator 	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		/* --- Nested class ------------------------------------------------- */

			class value_compare: public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				
				protected:

					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:

					typedef bool		result_type;
					typedef	value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		/* --- Member variables --------------------------------------------- */

		private:

			allocator_type											_alloc;
			key_compare												_comp;
			ft::mapTree<key_type, mapped_type, key_compare>			_tree;

		/* --- Constructors & destructor ------------------------------------ */

		public:

			explicit map(const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type()):
				 _alloc(alloc), _comp(comp), _tree() {}

			template <class InputIterator>
  			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = NULL): _alloc(alloc), _comp(comp), _tree()
			{
				this->insert(first, last);
			}

			map(const map& x): _alloc(x._alloc), _comp(x._comp), _tree()
			{
				this->insert(x.begin(), x.end());
			}

			~map()
			{
				this->clear();
			}

			map& operator=(const map& x)
			{
				this->clear();
				this->insert(x.begin(), x.end());
				return *this;
			}

		/* --- Iterators ---------------------------------------------------- */

			iterator begin(void)
			{
				return _tree.begin();
			}

			const_iterator begin(void) const
			{
				return _tree.begin();
			}

			iterator end(void)
			{
				return _tree.end();
			}

			const_iterator end(void) const
			{
				return _tree.end();
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

			bool empty(void) const
			{
				return _tree.empty();
			}

			size_type size(void) const
			{
				return _tree.size();
			}

			size_type max_size(void) const
			{
				return _tree.max_size();
				
				// return allocator_type().max_size();

				// return std::numeric_limits<difference_type>::max() / (sizeof(ft::mapNode<value_type>) / 2);
			}

		/* --- Element access ----------------------------------------------- */
			
			mapped_type& operator[](const key_type& k)
			{
				return this->insert(ft::make_pair(k, mapped_type())).first->second;
			}

		/* --- Modifiers ---------------------------------------------------- */

			ft::pair<iterator, bool> insert(const value_type& val)
			{
				return _tree.insert(val);
			}

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				return iterator((_tree.insert(val)).first);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					insert(*first);
			}

			void erase(iterator position)
			{
				_tree.erase(position.base());
			}

			size_type erase(const key_type& k)
			{
				iterator it = this->find(k);
				if (it == this->end())
					return 0;
				_tree.erase(it.base());
				return 1;
			}

			void erase(iterator first, iterator last)
			{				
				for (difference_type dist = ft::distance(first, last); dist; dist--)
					_tree.erase((first++).base());
			}

			void swap(map& x)
			{
				_tree.swap(x._tree);
			}

			void clear()
			{
				this->erase(this->begin(), this->end());
			}

		/* --- Observers ---------------------------------------------------- */

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_compare());
			}

		/* --- Operations --------------------------------------------------- */

			iterator find(const key_type& k)
			{
				return _tree.find(k);
			}

			const_iterator find(const key_type& k) const
			{
				return _tree.find(k);
			}

			size_type count(const key_type& k) const
			{
				if (_tree.find(k)->first == k)
					return 1;
				return 0;
			}

			iterator lower_bound(const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!_comp((*it).first, k))
						return it;
				}
				return this->end();
			}

			const_iterator lower_bound(const key_type& k) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
				{
					if (!_comp((*it).first, k))
						return it;
				}
				return this->end();
			}

			iterator upper_bound(const key_type& k)
			{
				iterator it = this->lower_bound(k);

				if (it.base()->value.first == k)
					return ++it;
				else
					return it;
			}

			const_iterator upper_bound(const key_type& k) const
			{
				const_iterator it = this->lower_bound(k);

				if (it.base()->value.first == k)
					return ++it;
				else
					return it;
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				const_iterator lo = this->lower_bound(k);
				const_iterator up = this->upper_bound(k);
				return ft::make_pair(lo, up);
			}

			ft::pair<iterator, iterator> equal_range(const key_type& k)
			{
				iterator lo = this->lower_bound(k);
				iterator up = this->upper_bound(k);
				return ft::make_pair(lo, up);
			}
	};
	
	/* --- Non-member functions --------------------------------------------- */
		
	template <class Key, class T, class Compare,class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare,class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare,class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare,class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare,class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare,class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

};

#endif