#include "avl_tree.hpp"
#include <stdlib.h>

#define LIMITE 250

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
            bin_tree.insert(rd, tmp);
    }
    std::cout << "Ding!" << std::endl;
    for( int i = LIMITE / 2 ; i > 0; i --)
        {
		    rd = rand() % LIMITE;
            rd = i;
            bin_tree.remove(rd);
       }
    bin_tree.printTree(bin_tree.top, "RMed", true, rd);
    ft::avl_tree<int   , std::string>::node_ptr ptr = bin_tree.left_most_node_from(bin_tree.top);
    // ft::avl_tree<int   , std::string>::node_ptr prev = bin_tree.right_most_node_from(bin_tree.top);
    std::cout << "test next "<< std::endl;
    while (ptr)
    {
        std::cout << ptr->getFirst() << " -> ";
        ptr = bin_tree.getNext(ptr, ptr->getFirst());
    }
    // std::cout << std::endl << "test prev "<< std::endl;
    // while (prev)
    // {
    //     std::cout << prev->getFirst() << " -> "<< std::endl;
    //     prev = bin_tree.getPrev(prev, prev->getFirst());
    // }
    std::cout << std::endl  << " Dong!" << std::endl;
    bin_tree.checkBalance(bin_tree.top);
}