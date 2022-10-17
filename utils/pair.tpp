#include "pair.hpp"

namespace ft
{
	template< class T1, class T2 >
	bool operator==( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator!=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		if (!(lhs == rhs))
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator<( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		if (lhs.first < rhs.first || lhs.second < rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		if (lhs.first <= rhs.first || lhs.second <= rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		if (lhs.first > rhs.first || lhs.second > rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		if (lhs.first >= rhs.first || lhs.second >= rhs.second)
			return true;
		return false;
	}

}