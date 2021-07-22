/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:46:06 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/23 01:14:06 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "../../utility/utility.hpp"
# include "../../utility/type_traits.hpp"
# include "../../utility/iterator.hpp"
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
			typedef typename ft::mapIterator<value_type>			iterator;
			typedef typename ft::mapIterator<const value_type>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		/* --- Nested class ------------------------------------------------- */

			class value_compare
			: public std::binary_function<value_type, value_type, bool>
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

			typedef typename ft::mapNode<value_type>				_node_type;

			allocator_type											_alloc;
			key_compare												_comp;
			ft::mapTree<key_type, mapped_type>						_tree;

		/* --- Constructors & destructor ------------------------------------ */

		public:

			explicit map(const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _tree() {}

			template <class InputIterator>
  			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = NULL)
			: _alloc(alloc), _comp(comp), _tree()
			{
				this->insert(first, last);
			}

			map(const map& x)
			: _alloc(x._alloc), _comp(x._comp), _tree()
			{
				this->insert(x.begin(), x.end());
			}

			~map()
			{
				// this->clear();
			}

			map& operator=(const map& x)
			{
				if (*this != x)
				{
					this->clear();
					this->insert(x.begin(), x.end());
				}
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
				return allocator_type().max_size();
			}

		/* --- Element access ----------------------------------------------- */
			
			mapped_type& operator[](const key_type& k)
			{
				return *((this->insert(ft::make_pair(k, mapped_type()))).first).second;	
			}

		/* --- Modifiers ---------------------------------------------------- */

			ft::pair<iterator, bool> insert(const value_type& val)
			{
				return _tree.insert(val);
			}

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				return iterator(insert(val));
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					insert(*first);
			}

			// void erase(iterator position)
			// {}

			// size_type erase(const key_type& k)
			// {}

			// void erase(iterator first, iterator last)
			// {}

			// void swap (map& x)
			// {}

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

			// size_type count(const key_type& k) const
			// {}

			iterator lower_bound(const key_type& k)
			{
				for (iterator it = _tree.begin(); it != _tree.end(); it++)
				{
					if (!_comp((*it).first, k))
						return it;
				}
				return this->end();
			}

			const_iterator lower_bound(const key_type& k) const
			{
				for (const_iterator it = _tree.begin(); it != _tree.end(); it++)
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

			// ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			// {}

			// ft::pair<iterator, iterator> equal_range(const key_type& k)
			// {}
	};
};

#endif