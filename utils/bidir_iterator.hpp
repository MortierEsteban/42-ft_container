#pragma once
#include "../map/node.hpp"
#include "iterator_base.hpp"

namespace ft
{
	template<class T>
	class bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, T>
	{
		public:
		
		using typename iterator<bidirectional_iterator_tag, T>::value_type	;			//value_type;
		using typename iterator<bidirectional_iterator_tag, T>::difference_type	;		//	difference_type;
		using typename iterator<bidirectional_iterator_tag, T>::pointer		;			//	pointer;
		using typename iterator<bidirectional_iterator_tag, T>::reference	;			//	reference;
		using typename iterator<bidirectional_iterator_tag, T>::iterator_category;		//	iterator_category;

		typedef node<T>		node_type;
		typedef node_type*	node_ptr;

		// typedef typename value_type::first_type first_type;
		// typedef typename value_type::second_type second_type;

		private:

			node_ptr	_ptr;
		
		public:

			bidirectional_iterator() : _ptr( NULL )
			{}

			bidirectional_iterator( node_ptr nod ) : _ptr( nod )
			{}

			~bidirectional_iterator(){}

			bidirectional_iterator(const bidirectional_iterator<value_type> & cpy) : _ptr(cpy._ptr)
			{}

			bidirectional_iterator& operator=( const bidirectional_iterator &cpy)
			{	_ptr = cpy._ptr; return *this;	}

			bool operator!=(const bidirectional_iterator &b)
			{	return(_ptr != b._ptr);	}

			reference operator*()
			{	return(_ptr->value);	}

			pointer operator->()
			{	return(&(_ptr->value));	}

			bidirectional_iterator &operator++(void)
			{	_ptr = ++(*_ptr) ; return(*this);}

			bidirectional_iterator operator++( int )
			{
				bidirectional_iterator<value_type> tmp(_ptr);
				_ptr = ++(*_ptr);
				return(tmp);
			}

			bidirectional_iterator &operator--(void)
			{	_ptr = --(*_ptr) ; return(*this);}

			bidirectional_iterator operator--( int )
			{
				bidirectional_iterator<value_type> tmp(_ptr);
				_ptr = --(*_ptr);
				return(tmp);
			}
	};
} // namespace ft
