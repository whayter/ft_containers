/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <hwinston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:37:03 by hwinston          #+#    #+#             */
/*   Updated: 2021/07/07 10:37:18 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    /* ---------------------------------------------------------------------- */
	/* --- iterator categories ---------------------------------------------- */

	class input_iterator_tag {};
	class output_iterator_tag {};	
	class forward_iterator_tag : public ft::input_iterator_tag {};
	class bidirectional_iterator_tag : public ft::forward_iterator_tag {};
	class random_access_iterator_tag : public ft::bidirectional_iterator_tag {};

	/* ---------------------------------------------------------------------- */
	/* --- iterator traits -------------------------------------------------- */

	template <class Iterator>
	class iterator_traits
	{
		public:

			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:

			typedef ptrdiff_t								difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef random_access_iterator_tag				iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:

			typedef ptrdiff_t								difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef random_access_iterator_tag				iterator_category;
	};

	/* ---------------------------------------------------------------------- */
	/* --- itterator class template ----------------------------------------- */

	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:

			typedef T										value_type;
			typedef Distance								difference_type;
			typedef Pointer									pointer;
			typedef Reference								reference;
			typedef Category								iterator_category;
	};

	/* ---------------------------------------------------------------------- */
	/* --- reverse_iterator class ------------------------------------------- */

	template <class I>
	class reverse_iterator
	{
		/* --- member types ------------------------------------------------- */

		public:

			typedef I												iterator_type;
			typedef typename iterator_traits<I>::iterator_category	iterator_category;
			typedef typename iterator_traits<I>::value_type			value_type;
			typedef typename iterator_traits<I>::difference_type	difference_type;
			typedef typename iterator_traits<I>::reference			reference;
			typedef typename iterator_traits<I>::pointer			pointer;
		
		/* --- member variables --------------------------------------------- */

		private:

			iterator_type _it;
		
		/* --- member functions --------------------------------------------- */

		public:

			reverse_iterator() {}

			reverse_iterator(iterator_type it)
			{
				_it = it;
			}
	
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it)
			{
				_it = rev_it.base();
			}

			virtual ~reverse_iterator() {}

			iterator_type base() const
			{
				return _it;
			}

			reference operator*() const
			{
				iterator_type r = this->base();
				return *(--r);
			}

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(this->base() - n);
			}

			reverse_iterator& operator++()
			{
				_it--;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator it = *this;
				++(*this);
				return it;
			}

			reverse_iterator& operator+=(difference_type n)
			{
				_it -= n;
				return *this;
			}

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(this->base() + n);
			}

			reverse_iterator& operator--()
			{
				_it++;
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator it = *this;
				--(*this);
				return it;
			}

			reverse_iterator& operator-=(difference_type n)
			{
				_it += n;
				return *this;
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			reference operator[](difference_type n) const
			{
				return this->base()[-n - 1];
			}
	};

	/* ---------------------------------------------------------------------- */
	/* --- non-member function overloads (reverse_iterator) ----------------- */
		
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	template <class Iterator, class It>
	bool operator==(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	template <class Iterator, class It>
	bool operator!=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	template <class Iterator, class It>
	bool operator<(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	template <class Iterator, class It>
	bool operator<=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	template <class Iterator, class It>
	bool operator>(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
	template <class Iterator, class It>
	bool operator>=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}
	template <class Iterator, class It>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<It>& rhs)
	{
		return rhs.base() - lhs.base();
	}

	/* ---------------------------------------------------------------------- */
	/* --- iterator functions ----------------------------------------------- */

	template <class InputIterator>
	ptrdiff_t distance(InputIterator first, InputIterator last)
    {
		ptrdiff_t r = 0;
		for (; first != last; first++)
			r++;
		return r;
	}
};

#endif