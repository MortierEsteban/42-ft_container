#include "avl_tree.hpp"
#include <stdlib.h>
#include "../utils/bidir_iterator.hpp"
#include "map.hpp"
#define LIMITE 150

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
	std::string tmp ("Test");
    srand(time(NULL));
	int rd = 1;
    ft::map<int, std::string> m;
    ft::map<int, std::string>::iterator beg;
    for (size_t i = LIMITE; i > 0; i--)
    {
        rd = rand() % LIMITE;
        std::cout << "inserting :" << rd << std::endl;
        if (rd % 2 )
            std::cout << "created new :" << m.insert(ft::make_pair<const int, std::string>(rd, "BITE")).second << std::endl;
        else 
        {
            m[rd] = tmp;
        std::cout << "m["<< rd << "] = \""<< m[rd] << "\"" << std::endl;
        }
    }
    beg = m.begin();
    std::cout << m.lower_bound(5000)->first << std::endl;

    // std::cout << "beg = " << beg->first << std::endl;
    // m.erase(beg++);
    // int sizeb4 = m.size();
    // std::cout << m.size() << std::endl;
    // int nbrm = 0;
    //  for (size_t i = LIMITE / 2; i > 0; i--)
    // {
    //     rd = rand() % LIMITE;
    //     if (m.erase(rd))
    //     {
    //         nbrm++;
    //      std::cout << "removing " << rd<< std::endl;
    //     }
    // }
    
    // std::cout << sizeb4 - nbrm << " = " <<  m.size() << std::endl;
    // std::cout << "Ding!" << std::endl;
    // // for( int i = LIMITE / 2 ; i > 0; i --)
    // //     {
	// // 	    rd = rand() % LIMITE;
    // //         m.remove(rd);
    // //    }
    std::cout << std::endl << " Dong!" << std::endl;
}