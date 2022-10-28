#pragma once

#include <iostream>
#include "avl_tree.hpp"
// #include "../utils/bidir_iterator.hpp"
#include "../utils/reverse_it.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		private:

			class value_compare : public std::binary_function<T,T,bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		 		 friend class map;
			protected:
		 	 Compare comp;
		 		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
		 		typedef bool result_type;
				typedef	const ft::pair<const Key, T>	value_type;
		 		typedef value_type first_argument_type;
		 		typedef value_type second_argument_type;
		 		bool operator() (const value_type& x, const value_type& y) const
		 		{
		 			return comp(x.first, y.first);
		 		}
			};
			template<class P>
			class bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, P>
			{
				public:
				using typename iterator<bidirectional_iterator_tag, P>::value_type	;			//value_type;
				using typename iterator<bidirectional_iterator_tag, P>::difference_type	;		//	difference_type;
				using typename iterator<bidirectional_iterator_tag, P>::pointer		;			//	pointer;
				using typename iterator<bidirectional_iterator_tag, P>::reference	;			//	reference;
				using typename iterator<bidirectional_iterator_tag, P>::iterator_category;		//	iterator_category;
				


				// typedef typename value_type::first_type first_type;
				// typedef typename value_type::second_type second_type;

				private:
				typedef avl_tree<typename P::first_type, typename P::second_type, Compare>	tree_type;
				typedef typename tree_type::node_type	node_type;
				typedef node_type*	node_ptr;

					node_ptr	_ptr;
					const tree_type	*tree;

				public:

					bidirectional_iterator() : _ptr( NULL ), tree(NULL)
					{}

					bidirectional_iterator( node_ptr nod) : _ptr( nod ), tree(NULL)
					{}

					bidirectional_iterator( node_ptr nod,const tree_type *_tree ) : _ptr( nod ), tree(_tree)
					{}

					~bidirectional_iterator(){}

					bidirectional_iterator(const bidirectional_iterator& cpy) : _ptr(cpy._ptr), tree(cpy.tree)
					{}

					operator bidirectional_iterator<const P>() const  
					{ return (bidirectional_iterator<const P>(this->_ptr)); }

					bidirectional_iterator& operator=( const bidirectional_iterator &cpy)
					{	_ptr = cpy._ptr;tree = cpy.tree; return (*this);	}

					bool operator==(const bidirectional_iterator &b) const
					{	return(_ptr == b._ptr);	}
					bool operator!=(const bidirectional_iterator &b) const
					{	return(_ptr != b._ptr);	}

					reference operator*() 
					{	return(_ptr->value);	}

					reference operator*()const 
					{	return(_ptr->value);	}

					pointer operator->() 
					{	return(&(_ptr->value));	}
					pointer operator->() const
					{	return(&(_ptr->value));	}

					bidirectional_iterator &operator++(void)
					{	_ptr = ++(*_ptr) ; return(*this);}

					bidirectional_iterator operator++( int )
					{
						bidirectional_iterator<value_type> tmp(_ptr);
						_ptr = ++(*_ptr);
						return(tmp);
					}

					bidirectional_iterator &operator--(void)
					{
						if (!_ptr && tree)
						{
							_ptr = tree->right_most_node_from(tree->top);
							return(*this);
						}
						_ptr = --(*_ptr) ;
						 return(*this);
					}

					bidirectional_iterator operator--( int )
					{
						bidirectional_iterator<value_type> tmp(_ptr);
						if (!_ptr && tree)
						{
							_ptr = tree->right_most_node_from(tree->top);
							return(tmp);
						}
						_ptr = --(*_ptr);
						return(tmp);
					}
		 		};
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
			typedef map::bidirectional_iterator<value_type>				iterator;
			typedef map::bidirectional_iterator<const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename	iterator::difference_type				difference_type;

			private :
			
				typedef node<value_type> node_type;
				typedef node<value_type>* node_ptr;
				typedef	avl_tree<const key_type,mapped_type, key_compare> tree_type;

				tree_type				tree;
				const key_compare		comp;
				allocator_type 			alloc;
				value_compare			v_comp;

			public:

			//CONSTRUCTORS / destructor
				explicit map (const key_compare& _comp = key_compare(), const allocator_type& _alloc = allocator_type()): tree(_comp), comp(_comp), alloc(_alloc), v_comp(_comp)
				{}

				template <class InputIterator>
				map (InputIterator first, InputIterator last,       const key_compare& _comp = key_compare(),       const allocator_type& _alloc = allocator_type()): tree(_comp), comp(_comp), alloc(_alloc),v_comp(_comp)
				{
					insert(first, last);
				}

				map (const map& x): tree(x.tree), comp(x.comp), alloc(x.alloc),v_comp(x.v_comp)
				{}
				map& operator=( const map& other )
				{
					const_iterator beg = other.begin();
					while(beg != other.end())
					{
						insert(*beg++);
					}
					return( *this );
				}

				~map()
				{}

			//ITERATORS
	    		iterator begin()
				{	return( iterator(tree.left_most_node_from(tree.top), &tree));	}
				const_iterator begin() const
				{	return(const_iterator(tree.left_most_node_from(tree.top),&tree));	}
				iterator end()
				{	return(iterator(NULL, &tree)); }
				const_iterator end() const
				{	return( const_iterator(NULL,&tree));	}
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
					return ( false );
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
					(void)	position;
					insert(val);
					return(tree.search(val.first));
				}

				template <class InputIterator> 
					void insert (InputIterator first, InputIterator last)
				{
					while (first != last)
					{
						tree.insert(first->first, first->second);
						first++;
					}
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
					{
						if (first->first)
							erase((first++)->first);
					}
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
				value_compare value_comp() const
				{	return(v_comp);	}
			//OPERATIONS
				iterator find (const key_type& k)
				{	return(iterator(tree.search(k)));	}
				const_iterator find (const key_type& k) const
				{
					node_ptr tmp = tree.search(k);
					return(const_iterator(tmp, &tree));	
				}
				size_type count (const key_type& k) const
				{
					if (tree.search(k))
						return((size_type) 1);
					return((size_type) 0);
				}
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
	    		iterator upper_bound (const key_type& k)
				{
					iterator beg = begin();
					while (beg != end())
					{
						if (comp(beg->first, k) || k == beg->first)
							beg++;
						else
							return(beg);
					}
					return(beg);
				}
				const_iterator upper_bound (const key_type& k) const
				{
					const_iterator beg = begin();
					while (beg != end())
					{
						if (comp(beg->first, k) || k == beg->first)
							beg++;
						else
							return(beg);
					}
					return(beg);
				}
				pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
				{	return(ft::make_pair<const_iterator, const_iterator>(lower_bound(k),upper_bound(k)));}
				pair<iterator,iterator>           	equal_range (const key_type& k)
				{	return(ft::make_pair<iterator, iterator>(lower_bound(k),upper_bound(k)));}
			//ALLOCATOR
				allocator_type get_allocator() const
					{	return(alloc);	}

			
	};
}