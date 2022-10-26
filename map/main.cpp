#include "avl_tree.hpp"
#include <stdlib.h>

#define LIMITE 25

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
	std::string tmp ("Test");
    srand(time(NULL));
	int rd = 1;
    ft::avl_tree<const int    , std::string> bin_tree;
    // std::map<int    , std::string> bin_tree;
    for (size_t i = LIMITE; i > 0; i--)
    {
        rd = i;
        // rd = rand() % LIMITE;
            bin_tree.insert(rd, tmp);
    }
    std::cout << "Ding!" << std::endl;
    for( int i = LIMITE / 2 ; i > 0; i --)
        {
		    rd = rand() % LIMITE;
            // rd = i;
    // bin_tree.printTree(bin_tree.top, "before" ,true , rd);
            bin_tree.remove(rd);
    // bin_tree.printTree(bin_tree.top, "After  " ,true , rd);
    // bin_tree.checkBalance(bin_tree.top);
       }
    bin_tree.printTree(bin_tree.top, "Inserted " ,true , 0);
    ft::avl_tree<const int, std::string>::node_ptr ptr = bin_tree.left_most_node_from(bin_tree.top);
    std::cout << std::endl <<"incrementing" << std::endl;
    while (ptr)
    {
        std::cout << ptr->getFirst() << " -> ";
        ptr = ++(*ptr);
    }
    ptr = bin_tree.right_most_node_from(bin_tree.top);
    std::cout << std::endl <<"decrementing" << std::endl;
    while (ptr)
    {
        std::cout << ptr->getFirst() << " -> ";
        ptr = --(*ptr);
    }
    // bin_tree.checkBalance(bin_tree.top);
    std::cout << std::endl << " Dong!" << std::endl;
}