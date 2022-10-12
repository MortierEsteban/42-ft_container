#pragma once

#include "iterator_base.hpp"
#include "iterators.hpp"

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

	private:
		iterator_type		_ptr;

	public:
		reverse_iterator(void) : _ptr(NULL) {}
		reverse_iterator(value_type* ptr) : _ptr(ptr) {} 
		reverse_iterator(const reverse_iterator& src) : _ptr(src._ptr) {}
		~reverse_iterator() {}

		//ASSIGNS ANTOHER ITERATOR OVERLOAD
		reverse_iterator&				operator=(const reverse_iterator& rhs) {_ptr = rhs._ptr; return (*this);}

		//+ - OPERATOR OVERLOAD
		reverse_iterator				operator+(difference_type n) const { reverse_iterator tmp(*this); tmp._ptr -= n; return (tmp); }
		//return value : reverse_iterator(base()-n)
		reverse_iterator				operator-(difference_type n) const { reverse_iterator tmp(*this); tmp._ptr += n; return (tmp); }
		//return value : reverse_iterator(base()+n)


		//POST/PRE IN/DECREMENT OPERATOR OVERLOAD
		reverse_iterator&				operator++(void) { _ptr--; return (*this); }
		reverse_iterator				operator++(int)	{ reverse_iterator	copy(*this); _ptr--; return (copy); }
		reverse_iterator&				operator--(void) { _ptr++; return (*this); }
		reverse_iterator				operator--(int) { reverse_iterator	copy(*this); _ptr++; return (copy); }

		reverse_iterator&				operator+=(difference_type n) { _ptr -= n; return (*this); }
		reverse_iterator&				operator-=(difference_type n) { _ptr += n; return (*this); }

		//ACCESS POINTED-TO ELEMENT OVERLOAD (&*reverse == &*(iter-1) Doc. says it's always true)
		const reference					operator*() const { return *(--T(_ptr)); }
		reference						operator*() { return *(--T(_ptr)); }

		const pointer					operator->() const { return &(*(--T(_ptr))); }
		pointer							operator->() { return &(*(--T(_ptr))); }

		//ACCESS AN ELEMENT BY INDEX OVERLOAD
		reference						operator[](difference_type index) { reverse_iterator tmp(*this) ; tmp._ptr -= index ; return *(--tmp._ptr[index]); }
		const reference					operator[](difference_type index) const { reverse_iterator tmp(*this) ; tmp._ptr -= index ; return *(--tmp._ptr[index]); }
		//return value : base()[-n-1]

		//ACCES THE UNDERLYING ITERATOR
		iterator_type					base() const { return (_ptr); }
	};

	template<class T>
	bool				operator> (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return (lhs.base() > rhs.base()); }

	template<class T>
	bool				operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return !(rhs.base() > lhs.base()); }

	template<class T>
	bool				operator< (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return (rhs.base() < lhs.base()); }

	template<class T>
	bool				operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return !(lhs.base() > rhs.base()); }

	template<class T>
	bool				operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return (lhs.base() == rhs.base()); }

	template<class T>
	bool				operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return !(lhs.base() == rhs.base()); }

	template<class T>
	typename reverse_iterator<T>::difference_type
						operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return (rhs.base() - lhs.base()); }

	template<class T>
	reverse_iterator<T>	operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& rhs) { return (reverse_iterator<T>(rhs.base() - n)); }
}