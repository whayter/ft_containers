/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:12:09 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/22 14:16:36 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "utility.hpp"


/*-----------------------------------------------------------------------------/

						10
				       /  \
				  	  /    \
				 	 5	    16
					/ \	   /  \
			   	   3   8  12   18
					  		  /	 \
							17    20

/---------------------------------------------------------------------------- */


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
				if (_node == _head->right)
					_node = _head;
				else if (_node->right != _node)
				{
					_node = _node->right;
					while (_node->left)
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
				if (_node == _head-> left)
					return *this;
				if (_node->left != _node)
				{
					_node = _node->left;
					while (_node->right)
						_node = _node->right;
				}
				else
				{
					while (_node == _node->parent->left)
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

		/* --- Capacity ----------------------------------------------------- */

			bool empty() const
			{
				return _size == 0;
			}

			size_type size() const
			{
				return _size;
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
				return iterator(_head, _head);
			}

			iterator lower_bound(const key_type& key)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!_comp((*it).first, key))
						return it;
				}
				return end();
			}

			const_iterator lower_bound(const key_type& key) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
				{
					if (!_comp((*it).first, key))
						return it;
				}
				return this->end();
			}

			iterator upper_bound(const key_type& key)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
				{
					if (!_comp((*it).first, key) && !_comp(key, (*it).first))
						return ++it;
					else
						return it;
				}
				return this->end();
			}

			iterator upper_bound(const key_type& key) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
				{
					if (!_comp((*it).first, key) && !_comp(key, (*it).first))
						return ++it;
					else
						return it;
				}
				return this->end();
			}

		/* --- Element access ----------------------------------------------- */

			node_type* root() const
			{
				return _head->parent;
			}
			
			node_type* head() const							// utile ?
			{
				return _head;
			}


			node_type *search(node_type *root, key_type key)
			{
				if (!root || root->value.first == key)
       				return root;
				if (_comp(root->value.first, key))
					return find_rec(root->right, key);
       			return search(root->right, key);
			}

/*
						10
				       /  \
				  	  /    \
				 	 5	    16
					/ \	   /  \
			   	   3   8  12   18
					  		  /	 \
							17    20
*/
			node_type* find_insert_position(value_type& pair)
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
						if (cursor->left != cursor)							// check if leaf... working ?
							break ;
						else
							cursor = cursor->left;
					}
					else
					{
						if (cursor->right != cursor)						// check if leaf... working ?
							break ;
						else
							cursor = cursor->right;
					}
				}
				return cursor;
			}

		/* --- Modifiers ---------------------------------------------------- */

			ft::pair<iterator, bool> insert(value_type pair)
			{
				node_type* cursor = this->find_insert_position(pair);
				node_type* new_node;

				if (this->empty())
				{
					new_node = _alloc.allocate(1);
					_alloc.construct(new_node, pair);
					_head->parent = new_node;
					_head->left = new_node;
					_head->right = new_node;
				}
				else if (!cursor)
					return ft::make_pair(iterator(_head, _head), false);
				else
				{
					std::cout << "insert position found: " << cursor->value.first << " | " << cursor->value.second << std::endl;
					new_node = _alloc.allocate(1);
					_alloc.construct(new_node, pair);
					new_node->parent = cursor;
					new_node->left = new_node;
					new_node->right = new_node;
					
					if (_comp(cursor->value.first, pair.first))
					{
						cursor->right = new_node;
						if (cursor == _head->right)
							_head->right = new_node;
					}
					else
					{
						cursor->left = new_node;
						if (cursor == _head->left)
							_head->left = new_node;
					}
				}
				_size++;
				return ft::make_pair(iterator(new_node, _head), true);
			}




			// ft::pair<iterator, bool> insert(value_type pair)
			// {
			// 	node_type* new_node;

			// 	if (this->root())												// MAP IS NOT EMPTY
			// 	{
			// 		node_type* cursor = this->begin().base();
			// 		while (cursor != this->end().base())						// FIND INSERT POSITION
			// 		{
			// 			if (pair.first == cursor->value.first)
			// 				return ft::make_pair(iterator(_head, _head), false);
			// 			else if (_comp(pair.first, cursor->value.first))
			// 			{
			// 				if (cursor->left != cursor)							// check if leaf... working ?
			// 					break ;
			// 				else
			// 					cursor = cursor->left;
			// 			}
			// 			else
			// 			{
			// 				if (cursor->right  != cursor)						// check if leaf... working ?
			// 					break ;
			// 				else
			// 					cursor = cursor->right;
			// 			}
			// 		}
			// 	}
			// 	else															// MAP IS EMPTY
			// 	{
			// 		new_node = _alloc.allocate(1);
			// 		_alloc.construct(new_node, pair);
			// 		_head->parent = new_node;
			// 		_head->left = new_node;
			// 		_head->right = new_node;
			// 	}
				
			// 	new_node = _alloc.allocate(1);
			// 	_alloc.construct(new_node, pair);
			// 	new_node->parent = cursor;
			// 	new_node->left = new_node;
			// 	new_node->right = new_node;
				
			// 	if (_comp(cursor->value.first, pair.first))
			// 		cursor->right = new_node;
			// 	else
			// 		cursor->left = new_node;
			// 	_size++;
			// 	return ft::make_pair(iterator(new_node, _head), true);
			// }








				// if (!this->root())
				// {
				// 	std::cout << "[0] Ajout d'un nouveau noeud...\n";
				// 	new_node = _alloc.allocate(1);
				// 	_alloc.construct(new_node, pair);
				// 	_head->parent = new_node;
				// 	_head->left = new_node;
				// 	_head->right = new_node;
				// }
				/* ----- TOUT CE QUI PRÉCÈDE SEMBLE BON ----- */

/*
						10
				       /  \
				  	  /    \
				 	 5	    16
					/ \	   /  \
			   	   3   8  12   18
					  		  /	 \
							17    20
*/
				
				// else
				// {
				// 	//node_type* cursor = this->begin().base();
				// 	node_type* cursor = this->root();

				// 	std::cout << "[1] Ajout d'un nouveau noeud...\n";





				// 	/* ça plante dans cette boucle while. revoir les conditions.
				// 	   bien revoir les liens de parenté entre les nodes.
				// 	*/

				// 	while (cursor != this->end().base())
				// 	{
				// 		if (pair.first == cursor->value.first)
				// 		{
				// 			std::cout << " doublon!\n";
				// 			return ft::make_pair(iterator(_head, _head), false);
				// 		}

				// 		std::cout << "  ---\n";

				// 		if (_comp(pair.first, cursor->value.first))
				// 		{
				// 			if (cursor->left != cursor)							// check if leaf... working ?
				// 			{
				// 				//cursor->left = new_node;
				// 				break ;
				// 			}
				// 			else
				// 				cursor = cursor->left;
				// 		}
				// 		else
				// 		{
				// 			if (cursor->right  != cursor)				// check if leaf... working ?
				// 			{
				// 				//cursor->right = new_node;
				// 				break ;
				// 			}
				// 			else
				// 				cursor = cursor->right;
				// 		}
				// 		std::cout << "  ---\n";
				// 	}




					
					// while (1)
					// {
					// 	if (pair.first == cursor->value.first)
					// 		return ft::make_pair(iterator(_head, _head), false);
						
					// 	if (_comp(pair.first, cursor->value.first))
					// 	{
					// 		if (cursor->left == cursor)				// check if leaf... working ?
					// 		{
					// 			cursor->left = new_node;
					// 			break ;
					// 		}
					// 		else
					// 			cursor = cursor->left;
					// 	}
					// 	else
					// 	{
					// 		if (cursor->right == cursor)				// check if leaf... working ?
					// 		{
					// 			cursor->right = new_node;
					// 			break ;
					// 		}
					// 		else
					// 			cursor = cursor->right;
					// 	}
					// }
					
					
		
					

					// iterator it(this->begin().base(), _head);
					// iterator next = it++;
					// while (next.base() != _head &&
					// 	_comp(next.base()->value.first, pair.first))
					// {
					// 	it++;
					// 	next++;
					// }

				/* ----- TOUT CE QUI SUIT SEMBLE BON ----- */
					
					// if (pair.first == it.base()->value.first)
					// 	return ft::make_pair(iterator(_head, _head), false);
					// new_node = _alloc.allocate(1);
					// _alloc.construct(new_node, pair);
					// new_node->parent = it.base();
					// new_node->parent = cursor;
					// new_node->left = new_node;
					// new_node->right = new_node;


				/* x- ajout -x */

					// if (_comp(cursor->value.first, pair.first))
					// 	cursor->right = new_node;
					// else
					// 	cursor->left = new_node;


				/* x---------x */

					// if (_comp(it.base()->value.first, pair.first))
					// 	it.base()->right = new_node;
					// else
					// 	it.base()->left = new_node;
			// 	}
			// 	_size++;

			// 	std::cout << "  done.\n";

			// 	return ft::make_pair(iterator(new_node, _head), true);
			// }




					// while (it.base()->left != it.base()->right)						// really ?
					// {
					// 	key_type key = it.base()->value.first;

					// 	if (pair.first == key)										// if entry already exists
					// 		return ft::make_pair(iterator(_head, _head), false);
						
					// 	else if (_comp(pair.first, key))							// if pair < it value
					// 		it--;
					// 	else														// if pair > it value
					// 		it++:

					// }



				// 	iterator it(_head, _head);
				// 	while (it.base()->left != it.base()->right)
				// 	{
				// 		key_type key = it.base()->value.first;
				// 		if (pair.first == key)
				// 			return ft::make_pair(iterator(_head, _head), false);
				// 		else if (_comp(pair.first, key))
				// 			it--;
				// 		else
				// 			it++;
				// 	}	
				// 	new_node = _alloc.allocate(1);
				// 	_alloc.construct(new_node, pair);
				// 	new_node->parent = it.base();	
				// 	if (_comp(it.base()->value.first, pair.first))
				// 		_head->right = new_node;
				// 	else
				// 		_head->left = new_node;
				// }
				// /* -------------------------------------- */		
				// _size++;													// LOCK
				// return ft::make_pair(iterator(new_node, _head), true);		// LOCK
			// }

		

		// node_type* nd(this->root());
		// while (1)
		// {
		// 	int comp_result = _comp(pair.first, nd->value.first);
		// 	if (comp_result == false && !_comp(nd->value.first, pair.first))
		// 		return (ft::make_pair(iterator(_head), false));
		// 	else if (comp_result == true)
		// 	{
		// 		if (nd->left->leaf())
		// 		{
		// 			_alloc.destroy(nd->left);
		// 			nd->left = new_node;
		// 			break ;
		// 		}
		// 		else
		// 			nd = nd->left;
		// 	}
		// 	else
		// 	{
		// 		if (nd->right->leaf())
		// 		{
		// 			_alloc.destroy(nd->right);
		// 			nd->right = new_node;
		// 			break ;
		// 		}
		// 		else
		// 			nd = nd->right;
		// 	}
		// }
		// new_node = _alloc.allocate(1);
		// _alloc.construct(new_node, pair);
		// new_node->parent = nd;
		// if (nd == this->end() && new_node == nd->right)
		// 	_head->right = new_node;
		// else if (nd == this->begin() && new_node == nd->left)
		// 	_head->left = new_node;
		// }
		// _size++;				
		// return ft::make_pair(iterator(new_node), true);
    };
};

#endif