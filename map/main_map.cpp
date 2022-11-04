#include "tester/map_tester.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

void	Constructors(std::vector< KEY_TYPE > &rand_store);
void	Deletion(std::vector< KEY_TYPE > &rand_store);
void	Insert(std::vector< KEY_TYPE > &rand_store);
time_t getms(void)
{
	struct timeval time_now;
    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	return( msecs_time );
}

int main ()
{
	std::vector< KEY_TYPE >			rand_store;
	srand(RAND_SEED);
	std::cout << NAME_NS ;
	for (int i = 0 ; i < LIMITE ; i++)
	{	rand_store.push_back(rand());	}
	// Constructors(rand_store);
	// Insert(rand_store);
	Deletion(rand_store); 
}

// void	template(std::vector< int > &rand_store)
// {
// 	std::time_t				start;(void ) start;
// 	std::time_t 			ft_stamp;(void ) ft_stamp;

// 	MAP_TYPE m;

// 	start = getms();
// 	std::string logdir ( TRACE_DIR + std::string (NAME_NS) +"/insert_log.txt") ;
// 	std::ofstream out(logdir.c_str());
// 	TEMPLATE FCT;
// 	ft_stamp = getms();
// 	ft_stamp = ft_stamp - start;
// 	out << "Runtime = " << ft_stamp << std::endl;
// }

void	Deletion(std::vector< KEY_TYPE > &rand_store)
{
	std::time_t				start;(void ) start;
	std::time_t 			ft_stamp;(void ) ft_stamp;

	start = getms();
	std::string logdir ( TRACE_DIR + std::string (NAME_NS) +"/delete_log.txt") ;
	std::ofstream out(logdir.c_str());
	erases(rand_store, out);
	ft_stamp = getms();
	ft_stamp = ft_stamp - start;
	out << "Runtime = " << ft_stamp << std::endl;
}

void	Constructors(std::vector< KEY_TYPE > &rand_store)
{
	std::time_t				start;(void ) start;
	std::time_t 			ft_stamp;(void ) ft_stamp;

	start = getms();
	std::string logdir ( TRACE_DIR + std::string (NAME_NS) +"/construct_log.txt") ;
	std::ofstream out(logdir.c_str());
	test_constructors( rand_store, out );
	ft_stamp = getms();
	ft_stamp = ft_stamp - start;
	out << "Runtime = " << ft_stamp << std::endl;
}

void	Insert(std::vector< KEY_TYPE > &rand_store)
{
	std::time_t				start;(void ) start;
	std::time_t 			ft_stamp;(void ) ft_stamp;

	MAP_TYPE m;

	start = getms();
	std::string logdir ( TRACE_DIR + std::string (NAME_NS) +"/insert_log.txt") ;
	std::ofstream out(logdir.c_str());
	test_insert(m ,rand_store, out);
	ft_stamp = getms();
	ft_stamp = ft_stamp - start;
	out << "Runtime = " << ft_stamp << std::endl;
}