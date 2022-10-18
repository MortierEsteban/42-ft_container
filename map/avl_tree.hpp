#pragma once
#include "node.hpp"

namespace ft
{
	template<class Key, class Value>
	struct avl_tree
	{
		typedef node<ft::pair<Key, Value > > node_type;
		typedef node<ft::pair<Key, Value > >* node_ptr;

		node_ptr top;
		size_t	size;
		node_type*min;//????
		node_type*max;//????

		avl_tree(	void	): top( NULL ), size( 0 ), min(NULL), max(NULL)
		{}
		~avl_tree()
		{
			deleteall(top);
		}

		void deleteall(node_ptr root)
		{
 	  	 if( root != NULL )
  	 	 {
	 	 	deleteall(root->_right);
	 		deleteall(root->_left);
			//   std::cout << "deleting :" << root->getFirst() << std::endl;
			delete root;
   		 }
		}
		void 	insert( Key &key, Value& val)
		{
			node_ptr 	pos = top;
			bool		inf = true;
			node_ptr	prev = top;
			while(pos)
			{
				if (key == pos->getFirst())
				{
					pos->value->second = val;
					return;
				}
				//COMPARE?
				prev = pos;
				if (key < pos->getFirst())
				{
					inf = true;
					pos = pos->_left;
				}
				else
				{
					inf = false;
					pos = pos->_right;
				}
			}
			node_ptr tmp = new node_type(key, val, prev);
			if (!top)
				top = tmp;
			else if (inf == true)
				prev->_left = tmp;
			else
				prev->_right = tmp;
			std::cout << "Adding : <" << key << ", " << val << "> pair to tree at " << tmp << std::endl;
			// min = left_most_node_from(top);
			balance(top);
		}
		//ROTATIONS

		void printTree(node_ptr root, std::string indent, bool last)
		{
 	  	 if( root != NULL )
  	 	 {
	 		   std::cout << indent;
	 		   std::cout << (last ? "├──" : "└──" );
				if (root->_prev == NULL && root != top)
			  	 	std::cout << root->getFirst() << " NO PREV" << std::endl;
	  		  std::cout << "["<< root->getFirst() <<"]" << std::endl;
	 	 	  printTree(root->_left, indent + (last ? "│   " : "    "), true);
	 	 	  printTree(root->_right, indent + (last ? "│   " : "    "), false);
   		 }
		}

		void	L_Rotation( node_type* unbalanced)
		{
			update_prev( unbalanced->_prev, unbalanced , unbalanced->_right);
			node_ptr tmp = left_most_node_from (unbalanced->_prev);
			tmp->_left = unbalanced;
			unbalanced->_prev = tmp;
			unbalanced->_right = NULL;
		}

		void	R_Rotation( node_type* unbalanced)
		{
			update_prev( unbalanced->_prev, unbalanced , unbalanced->_left);
			node_ptr tmp = right_most_node_from (unbalanced->_prev);
			tmp->_right = unbalanced;
			unbalanced->_prev = tmp;
			unbalanced->_left = NULL;
		}
		
		void	balance( void )
		{
			node_type* tmp = min;

			set_min();set_max();
		}

		void balance(node_ptr root)
		{
 	  		if( root != NULL )
  	 		{
	 			balance(root->_right);
	 			balance(root->_left);
				root->evaluate();
				// if ((root->_balance > 1 || root->_balance < -1)) 
				// {
				// 	std::cout << "Balancing on Node : " << root->getFirst() << std::endl;
				// 	printTree(top, "Before", false);
				// 	std::cout << std::endl;
				// }
				if (root->_balance > 1)
				{
					// std::cout << "R_rotate" << std::endl;
					if (root->_left->_right && root->getFirst() > root->_left->_right->getFirst())
					{
						std::cout << "Need double Rotation" << std::endl;
						L_Rotation(root->_left);
					}
					R_Rotation(root);
						balance(top);
						// printTree(top, "After", false);
						// std::cout << "______________________________________________________________" << std::endl;
				}
				if (root->_balance < -1)
				{
					// std::cout << "L_rotate" << std::endl;
					if (root->_right->_left && root->_right->_left->getFirst() < root->getFirst())
					{
						std::cout << "Need double Rotation" << std::endl;
					 	R_Rotation(root->_right);
					}
					L_Rotation(root);
						balance(top);
					// printTree(top, "After", false);
					// std::cout << "______________________________________________________________" << std::endl;
				}
   			}
		}

		//UTILS
			//Get Deepest
			node_type* left_most_node_from( node_type* _orig )
			{
				node_type* tmp = _orig;
				if (!tmp)
					return(NULL);
				while (tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}
			node_type* right_most_node_from( node_type* _orig )
			{
				node_type* tmp = _orig;
				if (!tmp)
					return(NULL);
				while (tmp->_right)
					tmp = tmp->_right;
				return tmp;
			}
			// Set minmax
			void	set_min( void )
			{
				node_type* tmp = top;
				while ( tmp && tmp->_left)
					tmp = tmp->_left;
				min = tmp;
			}

			void	set_max( void )
			{
				node_type* tmp = top;
				while ( tmp && tmp->_right)
					tmp = tmp->_right;
				min = tmp;
			}

			void	update_prev( node_type* prev, node_type* rm, node_type*alter)
			{
				if (prev == NULL)
					top = alter;
				else if (prev->_right && prev->_right == rm)
				{
					prev->_right = alter;
				}
				else if (prev->_left && prev->_left == rm)
				{
					prev->_left = alter;
				}
				rm->_prev = alter;
				alter->_prev = prev;
			}
	};
}
