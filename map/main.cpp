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
// }
#define LIMITE 1000

int main(int ac, char **av)
{
	
    (void)ac;
    (void)av;
	std::string tmp ("Test");
    srand(time(NULL));
	long long rd;
    ft::avl_tree<long long, std::string> bin_tree;
    for (size_t i = LIMITE; i > 0; --i)
    {
		rd = rand() % LIMITE;
        if (i % 2)
            bin_tree.insert(rd, tmp);
        else
            bin_tree.insert(rd, tmp);
    }
	bin_tree.balance(bin_tree.top);
    std::cout << "Root :" << bin_tree.top->value->first << std::endl << std::endl;
	bin_tree.printTree(bin_tree.top, "Final	", true);
    // bin_tree.printTree(bin_tree.root, "", true);
    // while (true)
    //     pause();
}