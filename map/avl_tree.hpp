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
		node_ptr latest;

		avl_tree(	void	): top( NULL ), size( 0 ), min(NULL), latest(NULL)
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
		void 	insert( const Key &key, const Value& val)
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
			try
			{
				node_ptr tmp = new node_type(key, val, prev);
				latest = tmp;
				if (!top)
					top = tmp;
				else if (inf == true)
					prev->_left = tmp;
				else
					prev->_right = tmp;
				// std::cout << "Adding : <" << key << ", " << val << "> pair to tree at " << tmp << "\n\t\t\t pair ptraddr = " << tmp->value<< std::endl;
				min = left_most_node_from(top);
				balance(tmp);
			}
			catch (std::bad_alloc &e)
				{ std::cout << e.what() << std::endl;	}
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
	  		  std::cout << /*"["<<*/ root->getFirst() /*<<"]" */<< std::endl;
	 	 	  printTree(root->_left, indent + (last ? "│   " : "    "), true);
	 	 	  printTree(root->_right, indent + (last ? "│   " : "    "), false);
   		 }
		}
		void checkBalance(node_ptr root)
		{
 	  	 if( root != NULL )
  	 	 {
	 		root->evaluate();
			if (root ->_balance > 1 || root->_balance < -1)
				std::cout << "Unbalanced node at : " << root->getFirst() << std::endl;
			checkBalance(root->_left);
			checkBalance(root->_right);
   		 }
		}

		void	L_Rotation( node_type* unbalanced )
		{
			node_ptr	tmp = unbalanced->_right->_left;
			update_prev( unbalanced->_prev, unbalanced , unbalanced->_right);
			if (tmp)
				tmp->_prev = unbalanced;
			unbalanced->_right = tmp;
			unbalanced->_prev->_left = unbalanced;
		}

		void	R_Rotation( node_type* unbalanced )
		{
			node_ptr	tmp = unbalanced->_left->_right;
			update_prev( unbalanced->_prev, unbalanced , unbalanced->_left);
			if (tmp)
				tmp->_prev = unbalanced;
			unbalanced->_left = tmp;
			unbalanced->_prev->_right = unbalanced;
		}
		
		// void	balance( void )
		// {
		// 	node_type* tmp = min;

		// 	set_min();set_max();
		// }

		void choose_Rotation(node_ptr root)
		{
			 root->evaluate();
			if (root->_balance > 1)
			{
				// if (root->_left->_right && root->getFirst() > root->_left->_right->getFirst())
				if (latest->getFirst() > root->_left->getFirst())
				{
					std::cout << "L";
					L_Rotation(root->_left);
				}
				R_Rotation(root);
			}
			if (root->_balance < -1)
			{
				if (latest->getFirst() > root->_right->getFirst())
				{
					R_Rotation(root->_right);
				}
				L_Rotation(root);
			}
		}
		// node_ptr find_unbalanced( node_ptr ptr )
		// {
		// 	ptr->evaluate();
		// 	if (ptr == NULL)
		// 		return (NULL);
		// 	if (ptr->_balance)

		// }
		
		void balance(node_ptr root)
		{
 	  		if( root == NULL)
				return;
			for(node_ptr tmp = root; tmp != NULL; tmp = tmp->_prev)
			{
	 			choose_Rotation(tmp);
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

			void	update_prev( node_type* prev, node_type* rm, node_type* alter)
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
