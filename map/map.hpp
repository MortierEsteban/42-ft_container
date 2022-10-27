#pragma once

#include <iostream>
#include "avl_tree.hpp"
#include "../utils/bidir_iterator.hpp"
#include "../utils/reverse_it.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef const Key											key_type;
			typedef T													mapped_type;
			typedef ft::pair<const key_type, T>							value_type;
			typedef size_t												size_type;
			typedef Compare												key_compare;
			typedef Alloc     											allocator_type;
			typedef	value_type&											reference;
			typedef	const value_type&									const_reference;
			typedef typename				Alloc::pointer				pointer;
			typedef typename				Alloc::const_pointer		const_pointer;
			typedef bidirectional_iterator<value_type>					iterator;
			typedef bidirectional_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename	iterator::difference_type				difference_type;

			private :
			
				typedef node<value_type> node_type;
				typedef node<value_type>* node_ptr;

				avl_tree<const key_type,mapped_type, key_compare> 	tree;
				const key_compare									comp;
				allocator_type 										alloc;

			public:

			//CONSTRUCTORS / destructor
				explicit map (const key_compare& _comp = key_compare(),              const allocator_type& _alloc = allocator_type()): tree(_comp), comp(_comp), alloc(_alloc)
				{}

				template <class InputIterator>
				map (InputIterator first, InputIterator last,       const key_compare& _comp = key_compare(),       const allocator_type& _alloc = allocator_type()): tree(_comp), comp(_comp), alloc(_alloc)
				{
					insert(first, last);
				}
				map (const map& x);
				~map()
				{}

			//ITERATORS
	    		iterator begin()
				{	return( iterator(tree.left_most_node_from(tree.top)));	}
				const_iterator begin() const
				{	return(const_iterator(tree.left_most_node_from(tree.top)));	}
				iterator end()
				{	return(iterator(NULL));	}
				const_iterator end() const
				{	return( const_iterator(NULL));	}
				reverse_iterator rbegin()
				{	return(reverse_iterator(tree.right_most_node_from(tree.top)));	}
				const_reverse_iterator rbegin() const
				{	return(reverse_iterator(tree.right_most_node_from(tree.top)));	}
				reverse_iterator rend()
				{	return(reverse_iterator(NULL));	}
				const_reverse_iterator rend() const
				{	return(reverse_iterator(NULL));	}
			//CAPACITY
				bool empty() const
				{
					if (tree.top == NULL)
						return( true);
					return ( NULL );
				}
				size_type size() const
					{	return (tree.size);	}
				size_type max_size() const
					{	return(alloc.max_size());	}

			//ELEMENT ACCESS
				mapped_type& operator[] (const key_type& key)
				{
					node_ptr pos= tree.search(key);
					if (!pos)
					{
						tree.insert(ft::make_pair<key_type, mapped_type>(key, T()));
						pos = tree.search(key);
					}
					return(pos->value.second);
					
				}
	    		mapped_type& at (const key_type& k)
				{
					node_ptr pos = tree.search(k);
					if (!pos)//WHat message?????
						throw(std::out_of_range("map::_M_range_check"));
					return(pos->value.second);
				}

				const mapped_type& at (const key_type& k) const
				{
					node_ptr pos = tree.search(k);
					if (!pos)//WHat message?????
						throw(std::out_of_range("map::_M_range_check"));
					return(pos->value.second);
				}
			//MODIFIERS
				pair<iterator,bool> insert (const value_type& val)
				{
					bool tmp = false;
					node_ptr pos = tree.search(val.first);
					if (!pos)
						tmp = true;
					tree.insert(val);
					return(ft::make_pair<iterator, bool>(iterator(tree.search(val.first)), tmp));
				}
				iterator insert (iterator position, const value_type& val)
				{
					insert(val);
				}

				template <class InputIterator> 
					void insert (InputIterator first, InputIterator last)
				{
					while (first != last)
						insert((first++)->first);
				}

				void erase (iterator position)
				{
					tree.remove((*position).first);
				}
				size_type erase (const key_type& k)
				{
					size_type tmp = 0;
					if(tree.search(k))
					{
						tmp = 1;
						tree.remove(k);
					}
					return(tmp);
				}
	    		void erase (iterator first, iterator last)
				{
					while(first != last)
						erase((first++)->first);
				}

				void swap (map& x)
				{
					std::swap(this, x);
				}
				void clear()
				{
					tree.deleteall(tree.top);
					tree.top = NULL;
				}
			//OBSERVERS
				key_compare key_comp() const
				{	return(comp);	}
				// value_compare value_comp() const;
			//OPERATIONS
				iterator find (const key_type& k)
				{	return(iterator(tree.search(k)));	}
				const_iterator find (const key_type& k) const
				{	return(const_iterator(tree.search(k)));	}
	    		iterator lower_bound (const key_type& k)
				{
					iterator beg = begin();
					while (beg != end())
					{
						if (comp(beg->first, k))
							beg++;
						else
							return(beg);
					}
					return( beg );
				}
				const_iterator lower_bound (const key_type& k) const
				{
					const_iterator beg = begin();
					while (beg != end())
					{
						if (comp(beg->first, k))
							beg++;
						else
							return(beg);
					}
					return( beg );
				}
	    		iterator upper_bound (const key_type& k);
				const_iterator upper_bound (const key_type& k) const;
				pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
				pair<iterator,iterator>           	equal_range (const key_type& k);
			//ALLOCATOR
				allocator_type get_allocator() const
					{	return(alloc);	}





	};
}