#pragma once
#include <utility>
#include "pair.tpp"
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
}