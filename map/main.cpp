// #include "avl_tree.hpp"
// #include <stdlib.h>
// #include "../utils/bidir_iterator.hpp"
// #include "map.hpp"
// #define LIMITE 150

// int main(int ac, char **av)
// {
//     (void)ac;
//     (void)av;
// 	std::string tmp ("Test");
//     srand(time(NULL));
// 	int rd = 1;
//     ft::map<int, std::string> m;
//     ft::map<int, std::string>::iterator beg;
//     for (size_t i = LIMITE; i > 0; i--)
//     {
//         rd = rand() % LIMITE;
//         std::cout << "inserting :" << rd << std::endl;
//         if (rd % 2 )
//             std::cout << "created new :" << m.insert(ft::make_pair<const int, std::string>(rd, "BITE")).second << std::endl;
//         else 
//         {
//             m[rd] = tmp;
//         std::cout << "m["<< rd << "] = \""<< m[rd] << "\"" << std::endl;
//         }
//     }
//     beg = m.end();
//     beg--;
//     // std::cout << m.lower_bound(5000)->first << std::endl;
//     std::cout << beg->first << std::endl;

//     // std::cout << "beg = " << beg->first << std::endl;
//     // m.erase(beg++);
//     // int sizeb4 = m.size();
//     // std::cout << m.size() << std::endl;
//     // int nbrm = 0;
//     //  for (size_t i = LIMITE / 2; i > 0; i--)
//     // {
//     //     rd = rand() % LIMITE;
//     //     if (m.erase(rd))
//     //     {
//     //         nbrm++;
//     //      std::cout << "removing " << rd<< std::endl;
//     //     }
//     // }
    
//     // std::cout << sizeb4 - nbrm << " = " <<  m.size() << std::endl;
//     // std::cout << "Ding!" << std::endl;
//     // // for( int i = LIMITE / 2 ; i > 0; i --)
//     // //     {
// 	// // 	    rd = rand() % LIMITE;
//     // //         m.remove(rd);
//     // //    }
//     std::cout << std::endl << " Dong!" << std::endl;
// }
#include "../containers_test/srcs/map/common.hpp"
#include <list>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	return (0);
}
