#include "tests.cpp"

#include <iostream>
#include <ctime>
#include <cstdlib>




bool compare( FT_MAP_ITER ft_beg,FT_MAP_ITER ft_end, STD_MAP_ITER std_beg, STD_MAP_ITER std_end)
{
	while (ft_beg != ft_end && std_beg != std_end)
	{
		if ((ft_beg->first != std_beg->first) || (ft_beg->second != std_beg->second))
		{
			std::cout << "ERROR RANGES ARE NOT SIMILAR!" << std::endl;
			return (false);
		}
		ft_beg++;std_beg++;
	}
	if (ft_beg != ft_end)
	{
		std::cout << "ERROR: FT_MAP didn't reach end!" << std::endl;
		return (false);
	}
	if (std_beg != std_end)
	{
		std::cout << "ERROR: STD_MAP didn't reach end!" << std::endl;
		return (false);
	}
	return (true);
}

template<class A, class B>
bool	compare (const A& ft_, const B& std_, std::string test)
{
	if (ft_ == std_)
	{
		std::cout << test << " was Success FUll" << std::endl; 
		return true;
	}
	return false;
}

bool	time_eval(time_t ft_stamp, time_t std_stamp, std::string test)
{
	if (ft_stamp == (20 * std_stamp))
		return (true);
	std::cout << " Error :" << test << " Exceeded max allowed runtime." <<std::endl;
	return (false); 
}

int main ()
{
	std::string		val = "INSERT TESTING";
	std::vector<int>			rand_store;
	ft::pair<int , std::string> ft_pair;
	std::pair<int , std::string> std_pair;

	time_t			start;
	time_t 			ft_stamp;
	time_t 			std_stamp;

	FT_MAP_TYPE 	m_ft;
	STD_MAP_TYPE 	m_std;

	// srand(0);
	// for (int i = 0 ; i < LIMITE ; i++)
	// {
	// 	rand_store.push_back(rand());
	// }
	// ft_pair = ft::make_pair(rand_store[0], val);
	// time(&start);
	// test_insert(m_ft, ft_pair, rand_store);
	// time(&ft_stamp);
	// ft_stamp = ft_stamp - start;
	// std_pair = std::make_pair(rand_store[0], val);
	// time (&start);
	// test_insert(m_std, std_pair, rand_store);
	// time (&std_stamp);
	// std_stamp = std_stamp - start;
	// time_eval(ft_stamp, std_stamp, val);
	// if (!compare(m_ft.begin(),m_ft.end(), m_std.begin(), m_std.end()))
	// 	exit (1);
	// return(0);

}