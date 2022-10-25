#include "avl_tree.hpp"
#include <stdlib.h>

// int	main()
// {
// 	ft::avl_tree<int, std::string> tmp;
// 	std::string tmp2("oopsi");
//  		int i = 7;
// 	for(i = 7 ;i < 16 ; i += 2 )
// 		tmp.insert(i, tmp2);
// 	for(i = 6 ;i > 0 ;i -= 2 )
// 		tmp.insert(i, tmp2);
// 	for(i = 6 ;i < 15 ;i += 2 )
// 		tmp.insert(i, tmp2);
// 	for(;i >= 0 ;i -= 2 )
// 		tmp.insert(i, tmp2);
// 	for(i = 0 ;i > -15 ;i -= 2 )
// 		tmp.insert(i, tmp2);
// 	tmp.printTree(tmp.top, "	", true);
	
// 	return(0);	
// }│
#define LIMITE 2500000
// #include <map>

int main(int ac, char **av)
{
	
    (void)ac;
    (void)av;
	std::string tmp ("Test");
    srand(time(NULL));
	int rd = 1;
    ft::avl_tree<int    , std::string> bin_tree;
    // std::map<int    , std::string> bin_tree;
    for (size_t i = LIMITE; i > 0; i--)
    {
        // rd = i;
        rd = rand() % LIMITE;
        // if (i % 2)
            // bin_tree.insert(std::pair<int,std::string>(rd,tmp));
        // else
            bin_tree.insert(rd, tmp);
    }
    std::cout << "Ding!" << std::endl;
    // bin_tree.printTree(bin_tree.top,"Final", true, rd);
    // bin_tree.printTree(bin_tree.top, "ADDALL", true,0);
    // ft::avl_tree<int,std::string>::iterator it = bin_tree.begin();

    // std::cout << "begin = " << (*it)->getFirst();
    for( int i = LIMITE / 2 ; i > 0; i --)
        {
		    rd = rand() % LIMITE;
            rd = i;
            // bin_tree.remove(10);
	        // bin_tree.printTree(bin_tree.top, "Before", true, rd);
            bin_tree.remove(rd);
            // std::cout << "rmed " << rd << std::endl;
            // bin_tree.erase(rd);
            // bin_tree.remove(10);
	// bin_tree.printTree(bin_tree.top, "After ", true, rd);
    // std::cout << "_______________________________________________________________________" << std::endl;
        // bin_tree.printTree(bin_tree.top, "Rm", true,rd);
            // bin_tree.checkBalance(bin_tree.top);
       }
    std::cout << "Dong!" << std::endl;
            bin_tree.checkBalance(bin_tree.top);
            // bin_tree.remove(10);
	// bin_tree.printTree(bin_tree.top, "RMed", true, rd);
    // bin_tree.remove(155);
    // bin_tree.printTree(bin_tree.root, "", true);
    // while (true)
    //     pause();
}