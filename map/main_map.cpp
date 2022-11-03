#include "tester/map_tester.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

bool compare( FT_ITER ft_beg,FT_ITER ft_end, STD_ITER std_beg, STD_ITER std_end)
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

bool	time_eval(std::time_t ft_stamp, std::time_t std_stamp, std::string test)
{
	std::cout << "Time (ft:std in ms) "<< ft_stamp << " : " << std_stamp << std::endl;
	if (ft_stamp > (20 * std_stamp))
	{
		std::cout << " Error :" << test << " Exceeded max allowed runtime." <<std::endl;
		return (true);
	}
	return (false); 
}

time_t getms(void)
{
	struct timeval time_now;
    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	return( msecs_time );
}

int main ()
{
	std::string		val = "INSERT TESTING";
	std::vector< int>			rand_store;

	std::time_t			start;(void ) start;
	std::time_t 			ft_stamp;(void ) ft_stamp;
	std::time_t 			std_stamp;(void) std_stamp;

	FT_MAP 	m_ft;
	STD_MAP 	m_std;

	srand(0);
	for (int i = 0 ; i < LIMITE ; i++)
	{
		rand_store.push_back(rand());
	}
	start = getms();
	test_insert<FT_MAP, ft::pair<const int, std::string> >(m_ft ,rand_store,  TRACE_DIR + std::string("ft/insert_log.txt"));
	ft_stamp = getms();
	ft_stamp = ft_stamp - start;
	start = getms();
	test_insert<STD_MAP, std::pair< const int, std::string> >(m_std, rand_store, TRACE_DIR + std::string("std/insert_log.txt"));
	std_stamp = getms();
	std_stamp = std_stamp - start;
	time_eval(ft_stamp, std_stamp, val);
	// if (!compare(m_ft.begin(),m_ft.end(), m_std.begin(), m_std.end()))
	// 	exit (1);
	// return(0);

}