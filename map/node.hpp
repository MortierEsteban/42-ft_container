#pragma once 
#include "../utils/pair.hpp"
#include "../utils/pair.tpp"
#include <memory>

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	struct node
	{
			typedef		Alloc	allocator_type;
			typedef		T		pair_type;
			typedef		typename pair_type::first_type first_type;
			typedef		typename pair_type::second_type second_type;
			allocator_type 			_alloc;
			pair_type				*value;
			node			*_left;
			node			*_right;
			int				_height;
			
			node (first_type _key,second_type _mapped_value , const allocator_type &alloc = std::allocator<T>()):_alloc(alloc), value(_alloc.allocate(1)),_left(NULL),_right(NULL), _height(1)
			{	_alloc.construct(value, pair_type(_key, _mapped_value));	}	//Creates an unrelated node with a key/mapped pair

			~node()
			{
				_alloc.destroy(value);
				_alloc.deallocate(value, 1);
			}

			first_type getFirst() const
			{	return (value->first);	}

			second_type getSecond() const
			{	return (value->second);	}

			bool	operator<(node *Node) const
			{	return (value->first < Node->getFirst());	}	
			bool	operator<(const first_type& first) const
			{	return (value->first < first);	}	
			bool	operator>(node *Node) const
			{	return (value->first > Node->getFirst());	}	
			bool	operator>(const first_type& first) const
			{	return (value->first > first);	}	
			
			bool	operator<=(node *Node) const
			{	return (value->first <= Node->getFirst());	}	
			bool	operator<=(const first_type& first) const
			{	return (value->first <= first);	}	
			bool	operator>=(node *Node) const
			{	return (value->first >= Node->getFirst());	}	
			bool	operator>=(const first_type& first) const
			{	return (value->first >= first);	}	

	};
}