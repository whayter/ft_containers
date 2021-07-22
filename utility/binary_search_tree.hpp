/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:12:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/23 01:12:17 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "utility.hpp"

/*--------------------------------------------------------------------------- */
/*                                                                            */
/*                            ----- head ------                               */
/*                                                                            */                                                                     
/*         			head						  min						  */
/*					  |							    |						  */
/*		   	        head -- null				  head -- root  			  */
/*		   			  |								|						  */
/*		   			head						  max						  */
/*                                                                            */
/*                                                                            */
/*                           --- tree exemple ---                             */
/*                                                                            */
/*                               100 (root)                                   */
/*                              /	\                                         */
/*                             /	 \                                        */
/*                            /      200                                      */
/*                           /      /   \                                     */
/*                          /     150  	220                                   */
/*                         50                                   			  */
/*                                                                            */
/*--------------------------------------------------------------------------- */

namespace ft
{
	/* ---------------------------------------------------------------------- */
	/* --- mapNode structure ------------------------------------------------ */

	template <class T>
	struct mapNode
	{
		/* --- member types ------------------------------------------------- */

		typedef T				value_type;
		typedef mapNode*		pointer;
		typedef mapNode&		reference;
		typedef const mapNode&	const_reference;

		/* --- member variables --------------------------------------------- */

		value_type				value;
		pointer					parent;
		pointer					left;
		pointer					right;

		/* --- member functions --------------------------------------------- */

		mapNode()
		: value(), parent(NULL), left(NULL), right(NULL) {}

		mapNode(const value_type& val, pointer prt = NULL,
			pointer lft = NULL, pointer rgt = NULL)
		: value(val), parent(prt), left(lft), right(rgt) {}
		
		mapNode(const_reference x)
		: value(x.value), parent(x.parent), left(x.left), right(x.right) {}

		reference operator=(const_reference x)
		{
			if (*this != x)
			{
				value = x.value;
				parent = x.parent;
				left = x.left;
				right = x.right;
			}
			return *this;
		}

		virtual ~mapNode() {}

		bool operator==(const mapNode& x)
		{
			return value == x.value;
		}

		bool is_leaf(std::string side)
		{
			pointer n = (side == "left" ? left : right);
			
			if (value == n->value)
				return true;
			return false;
		}
	};

	/* ---------------------------------------------------------------------- */
	/* --- mapIterator class ------------------------------------------------ */

	template <class T>
	class mapIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef T         								value_type;
			typedef ptrdiff_t  								difference_type;
			typedef T*   									pointer;
			typedef T&										reference;
			typedef typename ft::bidirectional_iterator_tag iterator_category;
			typedef typename ft::mapNode<value_type>		node_type;

		/* --- member variables --------------------------------------------- */

		private:

			node_type*										_node;
			node_type*										_head;

		/* --- member functions --------------------------------------------- */

		public:

			mapIterator(): _node(NULL), _head(NULL) {}

			mapIterator(node_type* nd, node_type* tk): _node(nd), _head(tk) {}
	
			mapIterator(const mapIterator& x): _node(x._node), _head(x._head) {}

			mapIterator& operator=(const mapIterator& x)
			{
				if (*this == x)
					return *this;
				_node = x._node;
				_head = x._head;
				return *this;
			}

			~mapIterator() {}

			node_type* base()
			{
				return _node;
			}

			bool operator==(const mapIterator& x)
			{
				return _node == x._node;
			}

			bool operator!=(const mapIterator& x)
			{
				return _node != x._node;
			}

			reference operator*() const
			{
				return _node->value;
			}

			pointer operator->() const
			{
				return &_node->value;
			}

			mapIterator& operator++()
			{
				if (_node == _head)
					_node = _head->right;
				else if (_node == _head->right)
					_node = _head;
				else if (_node->right != _node)
				{
					_node = _node->right;
					while (_node->left != _node)
						_node = _node->left;
				}
				else
				{
					while (_node == _node->parent->right)
						_node = _node->parent;
					if (_node->parent)
						_node = _node->parent;
				}
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
				if (_node == _head)
					_node = _head->right;
				else if (_node->left != _node)
				{
					_node = _node->left;
					while (_node->right != _node)
						_node = _node->right;
				}
				else
				{
					while (_node == _node->parent->left)
						_node = _node->parent;
					if (_node->parent)
						_node = _node->parent;
				}
				return *this;
			}

			mapIterator operator--(int)
			{
				mapIterator it = *this;
				--(*this);
				return it;
			}
	};

	/* ---------------------------------------------------------------------- */
	/* --- mapTree class ---------------------------------------------------- */

	template <	class Key, class T, class Pair = ft::pair<const Key, T>,
				class Compare = std::less<Key>, class Node = ft::mapNode<Pair>,
				class Alloc = std::allocator<Node> >
	class mapTree
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef Key										key_type;
			typedef T   									mapped_type;
			typedef Pair									value_type;
			typedef Node									node_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef typename ft::mapIterator<Pair> 			iterator;
			typedef typename ft::mapIterator<const Pair>	const_iterator;
			typedef size_t									size_type;
		
		/* --- member variables --------------------------------------------- */

		private:
			
			allocator_type									_alloc;
			key_compare										_comp;
			node_type*										_head;
			size_type										_size;

		/* --- Constructors & destructor ------------------------------------ */

		public:
				
			mapTree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _head((_alloc.allocate(1))), _size(0)
			{
				_alloc.construct(_head, node_type());
				_head->parent = NULL;
				_head->left = _head;
				_head->right = _head;
			}

			~mapTree()
			{
				_alloc.destroy(_head);
				_alloc.deallocate(_head, 1);
			}
		
		/* --- Iterators ---------------------------------------------------- */

			iterator begin()
			{
				return iterator(_head->left, _head);
			}
			
			const_iterator begin() const
			{
				return const_iterator(_head->left, _head);
			}

			iterator end()
			{
				return iterator(_head, _head);
			}

			const_iterator end() const
			{
				return const_iterator(_head, _head);
			}

			iterator find(const key_type& key)
			{
				node_type* node = this->_search(this->root(), key);
				return iterator(node, _head);
			}

			const_iterator find(const key_type& key) const
			{
				node_type* node = this->_search(this->root(), key);
				return const_iterator(node, _head);
			}

		/* --- Capacity ----------------------------------------------------- */

			bool empty() const
			{
				return _size == 0;
			}

			size_type size() const
			{
				return _size;
			}

		/* --- Element access ----------------------------------------------- */

			node_type* root() const
			{
				return _head->parent;
			}

		/* --- Modifiers ---------------------------------------------------- */

			ft::pair<iterator, bool> insert(value_type pair)
			{
				node_type* cursor = this->_find_insert_position(pair);
				node_type* new_node;

				if (this->empty())
				{
					new_node = _alloc.allocate(1);
					_alloc.construct(new_node, pair);
					_head->parent = new_node;
					_head->left = new_node;
					_head->right = new_node;
					new_node->right = new_node;
					new_node->left = new_node;
				}
				else if (!cursor)
					return ft::make_pair(iterator(_head, _head), false);
				else
				{
					new_node = _alloc.allocate(1);
					_alloc.construct(new_node, pair);
					new_node->parent = cursor;
					new_node->left = new_node;
					new_node->right = new_node;			
					if (_comp(cursor->value.first, pair.first))
					{
						cursor->right = new_node;
						if (_comp(_head->right->value.first, pair.first))
							_head->right = new_node;
					}
					else
					{
						cursor->left = new_node;
						if (_comp(pair.first, _head->left->value.first))
							_head->left = new_node;
					}
				}
				_size++;
				return ft::make_pair(iterator(new_node, _head), true);
			}

			// void erase_node(node_type* to_remove)
			// {
			// 	if (!to_remove || to_remove == _head)
			// 		return ;
	
			// 	else if (to_remove == this->root())
			// 	{
			// 		if ()
			// 		_header->parent =
			// 	}
			// 	else if (to_remove->is_leaf())
			// 	{
					
			// 	}
			// 	else
			// 	{
					
			// 	}


			// 	if (n->is_leaf())
			// 	{
			// 		if (_comp(n->value.first, n->parent->value.first))
			// 		n->parent->left = n->parent;
			// 	}
			// }


		/* --- private member functions ------------------------------------- */

		private:

			node_type* _search(node_type *root, key_type key)
			{
				if (!root || root == _head)
					return _head;
				if (root->value.first == key)
					return root;
				if (root == _head->right)
					return _head;
				if (_comp(root->value.first, key))
					return _search(root->right, key);
				return _search(root->left, key);
			}

			node_type* _find_insert_position(value_type& pair)
			{
				if (this->empty())
					return NULL;
				node_type* cursor = this->root();
				while (1)
				{
					if (pair.first == cursor->value.first)
						return NULL;										// retourner cursor ?
					else if (_comp(pair.first, cursor->value.first))
					{
						if (cursor->is_leaf("left"))
							break ;
						else
							cursor = cursor->left;
					}
					else
					{
						if (cursor->is_leaf("right"))
							break ;
						else
							cursor = cursor->right;
					}
				}
				return cursor;
			}
    };
};

#endif