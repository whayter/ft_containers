/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:12:09 by hwinston          #+#    #+#             */
/*   Updated: 2022/01/19 17:25:32 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "utility.hpp"
# include <string>

/*--------------------------------------------------------------------------- */
/*                                                                            */
/*                        ----- head of tree ------                           */
/*                                                                            */                                                                     
/*         			head						  min						  */
/*					  |							    |						  */
/*		   	        head -- null				  head -- root  			  */
/*		   			  |								|						  */
/*		   			head						  max						  */
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
			if (&value == &n->value)
				return true;
			return false;
		}
	};

	/* ---------------------------------------------------------------------- */
	/* --- mapIterator class ------------------------------------------------ */

	template <class T, class N>
	class mapIterator: public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef T         									value_type;
			typedef ptrdiff_t  									difference_type;
			typedef T*   										pointer;
			typedef T&											reference;
			typedef typename ft::bidirectional_iterator_tag 	iterator_category;
			typedef N											node_type;

		/* --- member variables --------------------------------------------- */

		private:

			node_type*											_node;
			node_type*											_head;

		/* --- member functions --------------------------------------------- */

		public:

			mapIterator(): _node(NULL), _head(NULL) {}

			mapIterator(node_type* nd, node_type* tk): _node(nd), _head(tk) {}

			template <class Ty, class Tyy>
			mapIterator<Ty, Tyy>(const mapIterator<Ty, Tyy>& x)
			{
				_node = x.base();
				_head = x.head();
			}

			mapIterator& operator=(const mapIterator& x)
			{
				_node = x.base();
				_head = x.head();
				return *this;
			}

			~mapIterator() {}

			node_type* base() const
			{
				return _node;
			}

			node_type* head() const
			{
				return _head;
			}

			bool operator==(const mapIterator& x) const
			{
				return _node == x._node;
			}

			bool operator!=(const mapIterator& x) const
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
				else if (_node == _head->left)
					_node = _head;
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

	template <	class Key, class T, class Compare = std::less<Key>,
				class Pair = ft::pair<const Key, T>, class Node = ft::mapNode<Pair>,
				class Alloc = std::allocator<Node> >
	class mapTree
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef Key													key_type;
			typedef T   												mapped_type;
			typedef Pair												value_type;
			typedef Node												node_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename ft::mapIterator<Pair, Node> 				iterator;
			typedef typename ft::mapIterator<const Pair, const Node> 	const_iterator;
			typedef size_t												size_type;
		
		/* --- member variables --------------------------------------------- */

		private:
			
			allocator_type											_alloc;
			key_compare												_comp;
			node_type*												_head;
			size_type												_size;

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
				node_type* node = this->_search(key);
				return iterator(node, _head);
			}

			const_iterator find(const key_type& key) const
			{
				node_type* node = this->_search(key);
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

			size_type max_size() const
			{
				return allocator_type().max_size();
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
					new_node->parent = new_node;
					new_node->right = new_node;
					new_node->left = new_node;
				}		
				else if (!cursor)
					return ft::make_pair(iterator(_head, _head), false);		
				else if (cursor == _head)
				{
					new_node = (this->find(pair.first)).base();
					return ft::make_pair(iterator(new_node, _head), false);
				}
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

			void erase(node_type* to_remove)
			{	
				node_type* hook;

				if (!to_remove || to_remove == _head)
				{
					return ;
				}
				else if (to_remove == this->root())
				{
					if (_size == 1)
					{
						_head->parent = NULL;
						_head->left = _head;
						_head->right = _head;
					}
					else if (to_remove->left != to_remove && to_remove->right != to_remove)
					{
						_head->parent = to_remove->left;
						hook = this->_rightmost(to_remove->left);
						hook->right = to_remove->right;
						to_remove->right->parent = hook;
						if (to_remove->value.first == _head->right->value.first)
							_head->right = hook;
						else if (to_remove->value.first == _head->left->value.first)
							_head->left = hook;
					}
					else if (to_remove->left != to_remove)
					{
						_head->parent = to_remove->left;
						_head->right = this->_rightmost(to_remove->left);
						to_remove->left->parent = to_remove->left;
					}
					else if (to_remove->right != to_remove)
					{
						_head->parent = to_remove->right;
						_head->left = this->_leftmost(to_remove->right);
						to_remove->right->parent = to_remove->right;
					}	
				}
				else if (to_remove->is_leaf("left") && to_remove->is_leaf("right"))
				{
					hook = to_remove->parent;
					if (_comp(hook->value.first, to_remove->value.first))
						hook->right = hook;
					else
						hook->left = hook;
					if (to_remove->value.first == _head->right->value.first)
						_head->right = hook;
					else if (to_remove->value.first == _head->left->value.first)
						_head->left = hook;
				}	
				else if (to_remove->is_leaf("left"))
				{
					hook = to_remove->parent;
					if (_comp(hook->value.first, to_remove->value.first))
						hook->right = to_remove->right;
					else
						hook->left = to_remove->right;
					to_remove->right->parent = hook;
					if (to_remove->value.first == _head->left->value.first)
						_head->left = hook;
				}
				else if (to_remove->is_leaf("right"))
				{
					hook = to_remove->parent;
					if (_comp(hook->value.first, to_remove->value.first))
						hook->right = to_remove->left;
					else
						hook->left = to_remove->left;
					to_remove->left->parent = hook;
					if (to_remove->value.first == _head->right->value.first)
						_head->right = this->_rightmost(to_remove->left);
				}
				else
				{
				 	node_type* l = to_remove->left;
					node_type* r = to_remove->right;

					hook = to_remove->parent;
					if (_comp(hook->value.first, to_remove->value.first))
					{
						hook->right = l;
						l->parent = hook;
						r->parent = this->_rightmost(l);
						this->_rightmost(l)->right = r;
					}
					else
					{
						hook->left = r;
						r->parent = hook;
						l->parent = this->_leftmost(r);
						this->_leftmost(r)->left = l;
					}
				}
				_alloc.destroy(to_remove);
				_alloc.deallocate(to_remove, 1);
				_size--;
			}

			void swap(mapTree& x)
			{
				node_type* tmp_head = _head;
				size_type tmp_size = _size;		
				_head = x._head;
				_size = x._size;			
				x._head = tmp_head;
				x._size = tmp_size;
			}

		/* --- Allocator ---------------------------------------------------- */

			allocator_type get_allocator() const
			{
				return _alloc;
			}

		/* --- private member functions ------------------------------------- */

		private:

			node_type* _search(key_type key) const
			{
				node_type* root = this->root();
				
				if (!root || root == _head)
					return _head;
				while (1)
				{
					if (root->value.first == key)
						break;
					else if (_comp(root->value.first, key))
					{
						if (root->right == root)
							break;
						root = root->right;
					}
					else
					{
						if (root->left == root)
							break;
						root = root->left;
					}
				}
				if (root->value.first == key)
					return root;
				return _head;
			}

			node_type* _find_insert_position(value_type& pair)
			{
				if (this->empty())
					return NULL;
				node_type* cursor = this->root();

				while (1)
				{

					// std::cout << "  pair = " << pair.first << std::endl;
					// std::cout << "cursor = " << cursor->value.first << std::endl;	
					// std::cout << "  comp = " << _comp(pair.first, cursor->value.first) << std::endl;
				
					if (pair.first == cursor->value.first)
						return _head;
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

			node_type* _leftmost(node_type *root)
			{
				while (root->left != root)
					root = root->left;
				return root;
			}

			node_type* _rightmost(node_type *root)
			{
				while (root->right != root)
					root = root->right;
				return root;
			}
	};
};

#endif