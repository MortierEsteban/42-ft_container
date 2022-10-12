#ifndef RD_BD_ITER
# define RD_BD_ITER
# include "iterator_base.hpp"

namespace ft
{
	//Random Access Iterator
	template <class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:
			//Getting inherited typedefs
			using typename iterator<random_access_iterator_tag, T>::value_type	;		//value_type;
			using typename iterator<random_access_iterator_tag, T>::difference_type	;//	difference_type;
			using typename iterator<random_access_iterator_tag, T>::pointer		;	//	pointer;
			using typename iterator<random_access_iterator_tag, T>::reference	;	//	reference;
			using typename iterator<random_access_iterator_tag, T>::iterator_category;//	iterator_category;
			operator random_access_iterator<const T> () const  { return (random_access_iterator<const T>(this->_ptr)); }

		private:
		
			value_type*	_ptr;
			// std::__1::__wrap_iter<random_access_iterator> __i;

		public:
			// Constructors / destructor , can be expanded (param = iterator?)

			random_access_iterator() : _ptr( NULL )
			{}
			// random_access_iterator( const value_type* ptr) : _ptr(ptr)
			// {}
			random_access_iterator( value_type* ptr) : _ptr(ptr)
			{}
			~random_access_iterator()
			{}

			random_access_iterator(const iterator_trait<random_access_iterator<value_type> >& cpy) : _ptr(cpy._ptr)
			{}
			random_access_iterator& operator=(const random_access_iterator cpy)
				{	this->_ptr = cpy._ptr;	return (*this);}

			// Comparisons

			bool					operator==( const random_access_iterator b ) const 
				{	return(this->base() == b.base());	}
			bool         	operator!=(const random_access_iterator& lhs, const random_access_iterator& rhs) 
				{ return !(lhs.base() == rhs.base()); }
			bool					operator<( const random_access_iterator b ) const 
				{	return(this->base() < b.base());	}
			bool					operator<=( const random_access_iterator b ) const 
				{	return(this->base() <= b.base());	}
			bool					operator>( const random_access_iterator b ) const 
				{	return(this->base() > b.base());	}
			bool					operator>=( const random_access_iterator b ) const 
				{	return(this->base() >= b.base());	}

			// Value Access
			reference				operator[](	difference_type n )
				{	return(*(_ptr + n));	}
			reference				operator*( void )
				{	return(*_ptr);	}
			pointer					operator->( void )
				{	return(_ptr);	}

			// Iterator modification
			random_access_iterator& operator++( void )
			{	_ptr++; return(*this);	}
			random_access_iterator& operator--( void )
			{	_ptr--; return(*this);	}
			random_access_iterator operator++( int )
			{
				random_access_iterator<value_type> tmp(_ptr);
				_ptr++;
				return (tmp);
			}
			random_access_iterator operator--( int )
			{
				random_access_iterator<value_type> tmp(_ptr);
				_ptr--;
				return (tmp);
			}

			random_access_iterator& operator+=(	difference_type n )
				{	_ptr += n;	return(*this);	}
			random_access_iterator& operator-=(	difference_type n )
				{	_ptr -= n;	return(*this);	}

			//	ADD MINUS temp values
			random_access_iterator	operator+( difference_type n ) const
				{
					random_access_iterator<value_type> tmp(_ptr);
					tmp += n;
					return(tmp);
				}
			random_access_iterator	operator-( difference_type n ) const
			{	
				random_access_iterator<value_type> tmp(_ptr);
				tmp -= n;
				return(tmp);
			}
			// difference_type			operator+( const random_access_iterator b ) const 
			difference_type			operator-( const random_access_iterator b ) const 
				{	return( this->base() - b.base());	}

			// Safegetter
			value_type*	base( void ) const 
				{	return(this->_ptr);	}
	};



}

#endif