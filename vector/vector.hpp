#ifndef FT_VECTOR
# define FT_VECTOR

#include "../utils/iterator_base.hpp"
#include "../utils/iterators.hpp"
#include <memory>

namespace ft
{
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
		// typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:

			size_type	_size;
			size_type	_capacity;
			value_type	*storage;
			allocator_type 	_alloc;
			//Create 1 storage
			
		public:
			explicit	vector(const allocator_type& alloc = allocator_type()): _size(0), storage(nullptr), _alloc(alloc)
			{}
			explicit 	vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), storage(nullptr),_alloc(alloc)
			{
				storage = _alloc.allocate(_size);
				_capacity = _size;
				for(size_type i = 0; i < _size; i++)
					_alloc.construct(storage[i], val);
			}
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):_size(last - first), _alloc(alloc)
			{
				storage = _alloc.allocate(_size);
				_capacity = _size;
				for(size_type i = 0; first < last; first++)
					_alloc.construct(storage[i++], *first);
			}

			vector(const	vector& x):  _size(x._size), storage(nullptr), _alloc(x._alloc)
			{
				storage = _alloc.allocate(_size);
				_capacity = _size;
				for(size_type i = 0; i < _size; i++;)
					_alloc.construct(storage[i], x.storage[i]);
			}

			~vector()
			{
				for(size_type i = 0; i < _size; i++;)
					_alloc.destroy(storage[i]);
				_alloc.deallocate(storage, _size);
				storage = nullptr;
			}

			//Iterators
			iterator begin()
				{	return(iterator(storage));	}
			const_iterator begin() const
				{	return(const_iterator(storage));	}
			iterator end()
				{	return(iterator(storage[_size]);	}
			const_iterator end() const
				{	return(const_iterator(storage[_size]));	}
			
			//Reverse iterators
			// reverse_iterator begin();
			// const_reverse_iterator begin() const;
			// reverse_iterator end();
			// const_reverse_iterator end() const;

			//Capacity
			size_type size() const
				{	return( _size );	}
			size_type max_size() const
				{	return(_alloc.max_size());	}
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const
				{	return(_capacity);	}
			bool empty() const
				{	return(_size == 0);	}
			void reserve (size_type n)
			{	
				_alloc.allocate(n, storage[_size]);
				_capacity += n;
			}

			//Element access
			reference operator[] (size_type n)
			{	return(*(storage[n]));	}
			const_reference operator[] (size_type n) const
			{	return(*(storage[n]));	}
			reference at (size_type n)
			{
				if (n > _size)
					throw(std::out_of_range(const string("vector::_M_range_check")));
				return((*this)[n]);
			}
			const_reference at (size_type n) const
			{
				if (n > _size)
					throw(OutOfRange());
				return((*this)[n]);
			}
			reference front()
				{	return(*storage);	}
			const_reference front() const
				{	return(*storage);	}
			reference back()
				{	return(*(storage[_size]));	}
			const_reference back() const;
				{	return(*(storage[_size]));	}
			value_type*	data()
				{	return(storage);	}
			const value_type*	data() const
				{	return(const_cast<value_type *>(storage));	}

			//Modifiers
			void assign (size_type n, const value_type& val);
			template <class InputIterator> 
			void assign (InputIterator first, InputIterator last);
			void push_back (const value_type& val)
			{
				if (_size + 1 >= _capacity)
				{
					_alloc.allocate(1, (storage[_size]));
					_capacity++;
				}
				_alloc.construct(storage[_size], val);
				_size++;

			}
			void pop_back()
			{
				_alloc.destroy(storage[_size]);
				_size--;
			}
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>    
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				size_type _size = last - first;
			}
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);
			void clear();

			//Allocator
			allocator_type get_allocator() const;

			

	};


	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

}

#endif