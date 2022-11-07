#ifndef FT_VECTOR
# define FT_VECTOR

#include "../utils/iterator_base.hpp"
#include "../utils/random_iterator.hpp"
#include "../utils/reverse_it.hpp"
#include "../utils/compare.hpp"
#include "../utils/types.hpp"
#include <memory>

namespace ft
{
	template<class InputIt>
	typename InputIt::difference_type distance (InputIt beg,InputIt last)
	{
		typename InputIt::difference_type dist = 0;
		while(beg != last)
		{
			beg++;
			dist++;
		}
		return (dist);
	}
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T 												value_type;
			typedef Allocator 										allocator_type;
			typedef	size_t											size_type;
			typedef	std::ptrdiff_t									difference_type;
			typedef	value_type&										reference;
			typedef const value_type&								const_reference;
			typedef	typename Allocator::pointer						pointer;
			typedef	typename Allocator::const_pointer				const_pointer;
			typedef	ft::random_access_iterator<value_type>			iterator;
			typedef	ft::random_access_iterator<const value_type>	const_iterator;
			typedef	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:

			size_type	_size;
			size_type	_capacity;
			value_type	*storage;
			allocator_type 	_alloc;

		public:
			explicit	vector(const allocator_type& alloc =allocator_type()): _size(0), _capacity(0), storage(NULL), _alloc(alloc)
			{	reserve( 1 );}
		
			explicit 	vector(typename ft::enable_if<ft::is_integral<size_type>::value, size_type>::type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):_size(0), _capacity(n), storage(NULL),_alloc(alloc)
			{
				if (_capacity == 0)
					throw(std::out_of_range("vector::_M_range_check"));
				reserve(_capacity * 2);
				_size = n;
				for(size_type i = 0; i < _size; i++)
					_alloc.construct(&storage[i], val);
			}

			template<class InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()):_size(0), _capacity(ft::distance<InputIterator>(first , last)), storage(NULL),_alloc(alloc)
			{
				if (_capacity == 0)
					_capacity++;
				reserve( (_capacity) * 2 );
				insert(this->begin(), first, last);
			}

			vector(const	vector& x):  _size(0),_capacity(x._capacity), storage(NULL), _alloc(x._alloc)
			{
				reserve( _capacity * 2);
				insert(this->begin(),x.begin(), x.end());

			}
			vector& operator= (const vector& x)
			{
				assign(x.begin(),x.end());
				return(*this);
			}


			~vector()
			{
				clear();
				if (storage)
					_alloc.deallocate(storage, _capacity);
				storage = NULL;
			}

			//Iterators
			iterator begin()
				{	return(iterator(storage));	}
			const_iterator begin() const
				{	return(const_iterator(storage));	}
			iterator end()
				{	return(iterator(storage + _size));	}
			const_iterator end() const
				{	return(const_iterator(storage + _size));	}
			
			//Reverse iterators
			reverse_iterator rbegin()
				{	return(reverse_iterator (storage + _size));	}
			const_reverse_iterator rbegin() const
				{	return(const_reverse_iterator (storage + _size));	}
			reverse_iterator rend()
				{	return(reverse_iterator (storage));	}
			const_reverse_iterator rend() const
				{	return(const_reverse_iterator (storage));	}

			//Capacity
			size_type size() const
				{	return( _size );	}
			size_type max_size() const
				{	return(_alloc.max_size());	}
			void resize (size_type n, value_type val = value_type())
			{
				while (n < _size)
					pop_back();
				if (_capacity < n)
					reserve( _capacity + n);
				while (_size < n)
					_alloc.construct(&storage[_size++], val);
			}
			size_type capacity() const
				{	return(_capacity);	}
			bool empty() const
				{	return(_size == 0);	}
			void reserve (size_type new_cap)
			{
				if(_capacity == 1 && new_cap > 2)	
					new_cap--;
				if (new_cap > _capacity)
				{
					alloc_check(new_cap);
					value_type *new_stor = _alloc.allocate(new_cap);
					if (_size)
					{
						size_type tmp = _size;
						while (tmp > 0)
						{
							new_stor[tmp] = storage[tmp];
							tmp--;
						}
						new_stor[tmp] = storage[tmp];
					}
					if (storage)
						_alloc.deallocate(storage, _capacity);
					storage = new_stor;
					_capacity = new_cap;
				}
			}
			//Element access
			reference operator[] (size_type n)
			{	return(storage[n]);	}
			const_reference operator[] (size_type n) const
			{	return(storage[n]);	}
			reference at (size_type n)
			{
				if (n > _size)
					throw(std::out_of_range("vector::_M_range_check"));
				return(storage[n]);
			}
			const_reference at (size_type n) const
			{
				if (n > _size)
					throw(std::out_of_range("vector::_M_range_check"));
				return((*this)[n]);
			}
			reference front()
				{	return(*storage);	}
			const_reference front() const
				{	return(*storage);	}
			reference back()
				{	return((storage[_size - 1]));	}
			const_reference back() const
				{	return((storage[_size - 1]));	}
			value_type*	data()
				{	return(storage);	}
			const value_type*	data() const
				{	return(const_cast<value_type *>(storage));	}

			void assign (size_type n, const value_type& val)
			{
				clear();
				if (n >= _capacity || !storage)
					reserve(_capacity + n );
				resize(n, val);
			}
			
			template <class InputIterator> 
			void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}
			
			void push_back (const value_type& val)
			{
				if (_size + 1 >= _capacity)
					reserve ((_capacity)  * 2);
				_alloc.construct(storage + _size, val);
				_size++;
			}
			void pop_back()
			{
				if (_size == 0)
					return ;
				_alloc.destroy(&storage[_size]);
				_size--;
			}
			iterator insert (iterator position, const value_type& val)
			{
				return (insert(position, 1, val));
			}
			iterator insert (iterator position, size_type n, const value_type& val)
			{
				size_type tmp = position - begin();
				if (_size + n >= _capacity)
					reserve ((_capacity + n));
				shift_right( tmp ,n);
				size_type stop = tmp + n;
				for(; tmp != stop; tmp++)
				{
					_alloc.construct(&storage[tmp], val);
				}
				_size += n;
				return(iterator(&storage[stop - n]));
			}

			template <class InputIterator>    
			iterator insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type dist = ft::distance<InputIterator>( first, last );
				size_type pos = position - begin();
				if (_size + dist >= _capacity)
					reserve ((_capacity + dist));
				size_type last_pos = pos + dist;
				shift_right(pos, dist);
				while(pos != last_pos)
				{
					_alloc.construct(&storage[pos++], *first);
					first++;
					_size++;
				}
				return (iterator(&storage[pos - dist]));
			}

			iterator erase (iterator position)
			{
				return (erase(position, position + 1));
			}

			iterator erase (iterator first, iterator last)
			{
				if (first == end())
					return (first);
				for(int i = 0; first + i != last; i++)
				{
					_alloc.destroy(&(*(first + i)));
				}
				size_type tmp = last - begin();
				size_type pos = first - begin();
				for (int i = 0; tmp + i <= _size; i++)
				{
					storage[pos + i] = storage[tmp + i];
				}
				_size -= ft::distance<iterator>(first, last);
				return(iterator(&storage[pos]));
			}

			void swap (vector& x)
			{
				value_type		*tmpV = x.storage;
                size_type   	tmpS = x._size;
                size_type    	tmpA = x._capacity;
                x.storage = storage;
                x._size = _size;
                x._capacity =_capacity;
                storage = tmpV;
                _size = tmpS;
               _capacity = tmpA;
			}

			void clear()
				{	erase(begin(),end());	}

			//Allocator
			allocator_type get_allocator() const
				{	return (_alloc);	}

			private:

				void alloc_check(size_type new_cap)
				{
					if (new_cap > max_size())
						throw (std::length_error("vector error length"));
				}

				void shift_right(size_type pos, size_type len)
				{
					if (!storage || !_size)
						return;
					size_type new_end = _size + len - 1;
					size_type _end = _size - 1;
					while (_end >= pos && _end != 0)
					{
						storage[new_end--] = storage[_end--];
					}
					if (_end == 0 && pos == 0)
						storage[new_end--] = storage[_end];
				}
				
	};


	template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
            return (true);
        return (false);
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif