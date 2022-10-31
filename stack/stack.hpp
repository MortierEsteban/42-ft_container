#pragma once
#include "../vector/vector.hpp"
#include <deque>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef	size_t		size_type;

		private:	
			container_type	c;

		public:
			explicit stack (const container_type& cXr = container_type()):c(cXr){}
			stack(const stack &cpy): c(cpy.c)
			{}
			stack& operator=( const stack& other )
			{	c = other.c;	}
			~stack(){}
			bool empty() const
			{	return(c.empty());	}
			size_type size() const
			{	return(c.size());	}
			value_type& top()
			{	return(c.back());	}
			const value_type& top() const
			{	return(c.back());	}
			void push (const value_type& val)
			{	c.push_back(val);	}
			void pop()
			{	c.pop_back();	}

			template <class X, class ContainerX>
			friend bool operator== (const ft::stack<X, ContainerX>& lhs, const ft::stack<X, ContainerX>& rhs);

			template <class X, class ContainerX>
			friend bool operator!= (const ft::stack<X, ContainerX>& lhs, const ft::stack<X, ContainerX>& rhs);
			
			template <class X, class ContainerX>
			friend bool operator< (const ft::stack<X, ContainerX>& lhs, const ft::stack<X, ContainerX>& rhs);

			template <class X, class ContainerX>
			friend bool operator<= (const ft::stack<X, ContainerX>& lhs, const ft::stack<X, ContainerX>& rhs);

			template <class X, class ContainerX>
			friend bool operator> (const ft::stack<X, ContainerX>& lhs, const ft::stack<X, ContainerX>& rhs);

			template <class X, class ContainerX>
			friend bool operator>= (const ft::stack<X, ContainerX>& lhs, const ft::stack<X, ContainerX>& rhs);

	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{	return( lhs.c == rhs.c);	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{	return( lhs.c != rhs.c);	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{	return( lhs.c < rhs.c);	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{	return( lhs.c <= rhs.c);	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{	return( lhs.c > rhs.c);	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{	return( lhs.c >= rhs.c);	}

}