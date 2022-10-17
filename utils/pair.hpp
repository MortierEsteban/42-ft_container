#pragma once
#include <utility>
#include "pair.tpp"
#include <iostream>

namespace ft
{
	template<class first_type, class second_type>	struct pair
	{
		typedef first_type T1;
		typedef second_type T2;

		T1	first;
		T2	second;

		pair() : first() , second(){}
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}
		pair(const pair<T1,T2>& pr) : first(pr.first), second(pr.second){}
		pair	&operator=(const pair<T1,T2> &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
		}
	};

	template <class T1, class T2>  pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1, T2> ( x,y ));
	}
}