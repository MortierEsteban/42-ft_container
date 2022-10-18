#pragma once 
#include "../utils/pair.hpp"
#include "../utils/pair.tpp"
#include <memory>

namespace ft
{
	template<class T >
	struct node
	{
			typedef		std::allocator<T>	allocator_type;

			allocator_type _alloc;
			T				*value;
			node			*_prev;
			node			*_left;
			node			*_right;
			int				_balance;
			
			node (typename T::first_type _key,typename  T::second_type _mapped_value, node *prev = NULL, node *left = NULL, node *right = NULL): value(_alloc.allocate(1)), _prev(prev), _left(left),_right(right), _balance(0)
			{	_alloc.construct(value, T(_key, _mapped_value));	}	//Creates an unrelated node with a key/mapped pair

			~node()
			{
				_alloc.destroy(value);
				_alloc.deallocate(value, 1);
			}

			typename T::first_type getFirst() const
			{	return (value->first);	}

			typename T::second_type getSecond() const
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
				if (tmp->_right && ldepth != 0)
					ldepth++;
				tmp = this;
				while (tmp->_right)
				{
					tmp = tmp->_right;
					rdepth++;
				}
				if (tmp->_left && rdepth != 0)
					rdepth++;
				_balance = ldepth - rdepth;
			}
			// typedef		this->getFirst()				first;??
			// typedef		this->getSecond()				second;??
	};

}