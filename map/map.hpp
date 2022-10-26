#pragma once

#include <iostream>
#include "avl_tree.hpp"

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
class map
{
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef ft::pair<const key_type, T>							value_type;
		typedef size_t												size_type;
		using	typename	bidirectonal_iterator<value_type>::difference_type;
		typedef Compare												key_compare;
		typedef Alloc     											allocator_type;
		typedef	value_type&											reference;
		typedef	const value_type&									const_reference;
		typedef	std::allocator::pointer								pointer;
		typedef	std::allocator::const_pointer						const_pointer;
		typedef bidirectional_iterator<value_type>					iterator
		typedef bidirectional_iterator<const value_type>			const_iterator
		typedef reverse_iterator<>;

		private :

			avl_tree<const key_type,mapped_type, key_compare> container;
			allocator_type _alloc;

		public:

		//CONSTRUCTORS / destructor
			explicit map (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type());
			template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type());
			map (const map& x);
			~map();
		//ITERATORS
    		iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
		//CAPACITY
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
		//ELEMENT ACCESS
			mapped_type& operator[] (const key_type& k);
    		mapped_type& at (const key_type& k);
			const mapped_type& at (const key_type& k) const;
		//MODIFIERS
			pair<iterator,bool> insert (const value_type& val);
			iterator insert (iterator position, const value_type& val);

			template <class InputIterator> 
				void insert (InputIterator first, InputIterator last);

			void erase (iterator position);
			size_type erase (const key_type& k);
    		void erase (iterator first, iterator last);

			void swap (map& x);
			void clear();
		//OBSERVERS
			key_compare key_comp() const;
			value_compare value_comp() const;
		//OPERATIONS
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
    		iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
    		iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;
			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
			pair<iterator,iterator>           	equal_range (const key_type& k);
		//ALLOCATOR
			allocator_type get_allocator() const;





};