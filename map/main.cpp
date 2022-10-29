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

#define T1 float
#define T2 foo<int>
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 - i, (i + 1) * 7));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator it(mp.rbegin());
	TESTED_NAMESPACE::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
	printSize(mp);
	std::cout << it->first << " " << mp.rbegin()->first << std::endl;

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

	return (0);
}
