#pragma once
#include <utility>
#include <iostream>

namespace ft
{
	template<class T1, class T2>	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type ;

		first_type	first;
		second_type	second;

		pair() : first() , second(){}
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}
		pair(const pair<first_type,second_type>& pr) : first(pr.first), second(pr.second){}
		pair	&operator=(const pair<first_type,second_type> &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return(*this);
		}
	};

	template <class first_type, class second_type> 
	pair<first_type,second_type> make_pair (first_type x, second_type y)
	{
		return ( ft::pair<first_type, second_type> ( x,y ));
	}

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (!(lhs == rhs))
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first < rhs.first || lhs.second < rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first <= rhs.first || lhs.second <= rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first > rhs.first || lhs.second > rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first >= rhs.first || lhs.second >= rhs.second)
			return true;
		return false;
	}
}