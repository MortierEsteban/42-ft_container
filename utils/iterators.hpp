#ifndef RD_BD_ITER
# define RD_BD_ITER
# include "iterator_base.hpp"

namespace ft
{
	//Random Access Iterator
	template <class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		private:
		
			value_type *_ptr;
			// std::__1::__wrap_iter<random_access_iterator> __i;

		public:
			// Constructors / destructor , can be expanded (param = iterator?)

			random_access_iterator();
			~random_access_iterator();

			random_access_iterator(const random_access_iterator& cpy);
			random_access_iterator& operator=(const random_access_iterator);

			// Comparisons

			bool					operator==( const random_access_iterator b ) const 
				{	return (base() == b.base());	}
			bool					operator!=( const random_access_iterator b ) const ;
				{	return (base() != b.base());	}
			bool					operator<( const random_access_iterator b ) const ;
				{	return (base() < b.base());	}
			bool					operator<=( const random_access_iterator b ) const ;
				{	return (base() <= b.base());	}
			bool					operator>( const random_access_iterator b ) const ;
				{	return (base() > b.base());	}
			bool					operator>=( const random_access_iterator b ) const ;
				{	return (base() >= b.base());	}

			// Value Access
			reference				operator[](	int n );
			reference				operator*( void );
				{	return(*base());	}
			reference				operator*( void );
			reference				operator->( void );

			// Iterator modification
			random_access_iterator& operator++( int );
			random_access_iterator& operator++( void );
			random_access_iterator& operator--( int );
			random_access_iterator& operator--( void );
			random_access_iterator& operator+=(	difference_type n );
			random_access_iterator& operator-=(	difference_type n );
			random_access_iterator& operator+=(	const random_access_iterator b );
			random_access_iterator& operator-=(	const random_access_iterator b );

			//	ADD MINUS temp values
			random_access_iterator operator+( difference_type n ) const ;
			random_access_iterator operator-( difference_type n ) const ;
			random_access_iterator operator+( const random_access_iterator b ) const ;
			random_access_iterator operator-( const random_access_iterator b ) const ;

			// Safegetter
			value_type*	base const ( void )
				{	return(this->_ptr);	}
	};

}

#endif