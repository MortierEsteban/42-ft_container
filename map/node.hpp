#pragma once 
#include "../utils/pair.hpp"
#include "../utils/pair.tpp"
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
			int				_height;
			
			node (first_type _key,second_type _mapped_value): value(ft::make_pair<first_type, second_type>(_key, _mapped_value)),_left(NULL),_right(NULL), _height(1)
			{}

			~node()
			{}

			first_type getFirst() const
			{	return (value.first);	}

			second_type getSecond() const
			{	return (value.second);	}

			bool	operator<(node *Node) const
			{	return (value.first < Node->getFirst());	}	
			bool	operator<(const first_type& first) const
			{	return (value.first < first);	}	
			bool	operator>(node *Node) const
			{	return (value.first > Node->getFirst());	}	
			bool	operator>(const first_type& first) const
			{	return (value.first > first);	}	
			
			bool	operator<=(node *Node) const
			{	return (value.first <= Node->getFirst());	}	
			bool	operator<=(const first_type& first) const
			{	return (value.first <= first);	}	
			bool	operator>=(node *Node) const
			{	return (value.first >= Node->getFirst());	}	
			bool	operator>=(const first_type& first) const
			{	return (value.first >= first);	}	

	};
}