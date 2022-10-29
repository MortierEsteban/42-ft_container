#pragma once 
#include "../utils/pair.hpp"
#include "../utils/pair.hpp"
#include <memory>

namespace ft
{
	template<class T>
	struct node
	{
			typedef		T		pair_type;
			typedef		typename pair_type::first_type first_type;
			typedef		typename pair_type::second_type second_type;
			pair_type		value;
			node			*_left;
			node			*_right;
			node			*_prev;
			int				_height;
			
			node (first_type _key,second_type _mapped_value,node *prev = NULL): value(ft::make_pair<first_type, second_type>(_key, _mapped_value)),_left(NULL),_right(NULL) ,_prev(prev), _height(1)
			{}

			node (const pair_type &pair): value(ft::make_pair<first_type, second_type>(pair.first, pair.second)),_left(NULL),_right(NULL) ,_prev(NULL), _height(1)
			{}

			~node()
			{}

			first_type getFirst() const
			{	return (value.first);	}

			second_type getSecond() const
			{	return (value.second);	}

			node*operator++( void )
			{
				node *ret = NULL;

				if (_right)
				{
					ret = _right;
					while (ret->_left)
						ret = ret->_left;
					return (ret);
				}
				else
				{
					ret = this;
					while (ret)
					{
						if (ret->_prev && ret->_prev->_left == ret)
						{
							ret = ret->_prev;
							break;
						}
						ret = ret->_prev;
					}
					return (ret);
				}
				return ret;
			}

			node*operator--( void )
			{
				node *ret = this;

				if (ret && _left)
				{
					ret = _left;
					while (ret->_right)
						ret = ret->_right;
					return (ret);
				}
				else
				{
					ret = this;
					while (ret)
					{
						if (ret->_prev && ret->_prev->_right == ret)
						{
							ret = ret->_prev;
							break;
						}
						ret = ret->_prev;
					}
					return (ret);
				}
				return ret;
			}
	};
}