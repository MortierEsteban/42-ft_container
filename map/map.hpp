#pragma once

#include <iostream>
#include "pair.hpp"

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
class map
{
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef ft::pair<key_type, mapped_type>						value_type;
		typedef Compare												key_compare;
		//typedef value_compare
		typedef Alloc     											allocator_type;
		typedef allocator_type::reference 							reference;
		typedef allocator_type::const_reference  					const_reference;
		typedef allocator_type::pointer 							pointer;
		typedef allocator_type::const_pointer						const_pointer;
		typedef bidirectional_iterator<value_type>					iterator
		typedef bidirectional_iterator<value_type>					const_iterator
		typedef reverse_iterator;
		typedef ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t												size_type;
};