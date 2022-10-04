#ifndef FT_VECTOR
# define FT_VECTOR

#include "../utils/iterator_base.hpp"
#include <memory>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector : std::vector<T, Allocator>
	{
		typedef T 												value_type;
		typedef Allocator 										allocator_type;
		typedef	size_t											size_type;
		typedef	std::ptrdiff_t									difference_type;
		typedef	value_type&										reference;
		typedef const value_type&								const_reference;
		typedef	typename Allocator::pointer						pointer;
		typedef	typename Allocator::const_pointer				const_pointer;
		// typedef	LegacyRandomAcessIterator<value_type>			iterator;
		// typedef	LegacyRandomAcessIterator<const value_type>		const_iterator;
		// typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		// typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:

			size_type	size;
			value_type	*storage;


		public:
	};

}

#endif