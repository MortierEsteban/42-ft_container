#pragma once
# include <cstddef>
# include <stdexcept>

namespace ft
{
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public	input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	struct contiguous_iterator_tag : public random_access_iterator_tag { };

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template<class Iterator>
	struct iterator_trait 
	{
		typedef typename	Iterator::value_type			value_type;
		typedef typename	Iterator::difference_type		difference_type;
		typedef typename	Iterator::pointer				pointer;
		typedef typename	Iterator::reference				reference;
		typedef typename	Iterator::iterator_category		iterator_category;
	};

	template<class Iterator>
	struct iterator_trait<Iterator *>
	{
		typedef Iterator						value_type;
		typedef ptrdiff_t						difference_type;
		typedef Iterator*						pointer;
		typedef Iterator&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template<class Iterator>
	struct iterator_trait<const Iterator*>
	{
		typedef Iterator						value_type;
		typedef ptrdiff_t						difference_type;
		typedef const Iterator*					pointer;
		typedef const Iterator&					reference;
		typedef random_access_iterator_tag		iterator_category;
	};
}
