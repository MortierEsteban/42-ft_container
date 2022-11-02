#pragma once

#include "iterator_base.hpp"

namespace ft
{
	template <class T>
	class reverse_iterator
	{
	public:
		typedef T													iterator_type;
		typedef typename ft::iterator_trait<T>::value_type			value_type;
		typedef typename ft::iterator_trait<T>::iterator_category	iterator_category;
		typedef typename ft::iterator_trait<T>::difference_type		difference_type;
		typedef typename ft::iterator_trait<T>::pointer				pointer;
		typedef typename ft::iterator_trait<T>::reference			reference;

	public: // Member functions

		reverse_iterator() : _iter() {}

		explicit
		reverse_iterator(iterator_type it) : _iter(it) {}

		template <class Iterator>
		reverse_iterator(const reverse_iterator<Iterator>& rev_it) :_iter(rev_it.base())
		{}

		~reverse_iterator() {}

		iterator_type 		base() const {return _iter;}

		reference			operator*() const {return *(--T(_iter));}
		reference			operator*() {return *(--T(_iter));}

		reverse_iterator	operator+(difference_type n) const {reverse_iterator copy(*this); copy._iter -= n; return copy;}

		reverse_iterator&	operator++(void) {_iter--; return *this;}
		reverse_iterator	operator++(int)	{reverse_iterator	copy(*this); ++(*this); return copy;}

		reverse_iterator&	operator+=(difference_type n) {_iter -= n; return *this;}

		reverse_iterator	operator-(difference_type n) const {reverse_iterator copy(*this); copy._iter += n; return copy;}
		
		reverse_iterator&	operator--(void) {_iter++; return *this;}
		reverse_iterator	operator--(int) {reverse_iterator	copy(*this); --(*this); return copy;}

		reverse_iterator&	operator-=(difference_type n) {_iter += n; return *this;}

		pointer				operator->() const {return &(operator*());}
		pointer				operator->() {return &(operator*());}

		reference			operator[](difference_type n) {reverse_iterator copy(*this); copy._iter -= n; return *(--copy._iter);}

	private:

		iterator_type		_iter;
	};

	// non-member Operator overflows
	template <class T>
	bool operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() == rhs.base(); }

	template <class L, class R>
	bool operator==(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return lhs.base() == rhs.base(); }

	template <class T>
	bool operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return !(lhs.base() == rhs.base()); }

	template <class L, class R>
	bool operator!=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return !(lhs.base() == rhs.base()); }

	template <class T>
	bool operator< (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() > rhs.base(); }

	template <class L, class R>
	bool operator< (const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return lhs.base() > rhs.base(); }

	template <class T>
	bool operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return !(rhs.base() > lhs.base()); }

	template <class L, class R>
	bool operator<=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return !(rhs.base() > lhs.base()); }

	template <class T>
	bool operator> (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return rhs.base() > lhs.base(); }

	template <class L, class R>
	bool operator> (const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return rhs.base() > lhs.base(); }

	template <class T>
	bool operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return !(lhs.base() > rhs.base()); }

	template <class L, class R>
	bool operator>=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return !(lhs.base() > rhs.base()); }

	template <class T>
	reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& rev_it)
	{ return rev_it + n; }

	template <class T>
	typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() - rhs.base(); }

	template <class L, class R>
	typename reverse_iterator<R>::difference_type operator-(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs)
	{ return rhs.base() - lhs.base(); }
}