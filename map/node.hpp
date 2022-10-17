#pragma once 
#include "../utils/pair.hpp"
#include "../utils/pair.tpp"

namespace ft
{
	template<class T = ft::pair<int, void *> >
	struct node
	{
			using typedef T::T1		key_type;
			using typedef T::T2		value_type;
			typedef		getFirst()	first;
			typedef		getSecond()	second;
			typedef		std::allocator<ft::pair<key_type,value_type>	allocator_type;

			allocator_type _alloc;
			ft::pair<key_type, value_type>	*value;
			node			*_prev;
			node			*_left;
			node			*_right;
			int				_balance;
			
			node(Key _key, T _mapped_value, node *prev = NULL, node *left = NULL, node *right = NULL): value(_alloc.allocate(1)), _prev(prev), _left(left),_right(rigth), _balance(0)
			{	_alloc.construct(value, make_pair(_key, _mapped_value));	}	//Creates an unrelated node with a key/mapped pair

			key_type getFirst() const
			{	return (value->first);	}
			value_type getSecond() const
			{	return (value->second);	}
			void	evaluate( void )
			{
				node *tmp = this;
				int ldepth = 0;
				int rdepth = 0;
				while (tmp->_left)
				{
					tmp = tmp->_left;
					ldepth++;
				}
				tmp = this;
				while (tmp->_right)
				{
					tmp = tmp->_right;
					rdepth++;
				}
				_balance = ldepth - rdepth;
			}
	};

}