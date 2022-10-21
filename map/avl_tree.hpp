#pragma once
#include "node.hpp"
#define RIGHT true
#define LEFT false

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

		avl_tree(	void	): top( NULL ), size( 0 ), min(NULL)
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

		node_ptr get_key_ptr( const Key &key)
		{
			node_ptr pos = top;
			while (pos != NULL)
			{
				if (pos->getFirst() == key)
					return( pos );
				else if (pos->getFirst() > key)
					pos = pos->_left;
				else if (pos->getFirst() < key)
					pos = pos->_right;
			}
			return( pos );
		}

		void 	insert( const Key &key, const Value& val)
		{
			node_ptr 	pos = top;
			pos = rec_get_pos(top, key);
			if (pos && pos->getFirst() == key)
				pos->value->second = val;
			// if (pos)
			// 	std::cout << "key = " << key << "pos = " << pos->getFirst() << " addr = " << pos <<std::endl;
			try
			{
				node_ptr tmp = new node_type(key, val, pos);
				if (!top)
					top = tmp;
				if ( pos && key > pos->getFirst())
					pos->_right = tmp;
				else if (pos)
					pos->_left = tmp;
				// std::cout << "Adding : <" << key << ", " << val << "> pair to tree at " << tmp <<  " pair ptraddr = " << tmp->value <<std::endl;
				min = left_most_node_from(top);
				balance(tmp, key);
			}
			catch (std::bad_alloc &e)
				{ std::cout << e.what() << std::endl;	}
		}
		
		void	swap_prev_desc( node_ptr old, node_ptr target)
		{
			if (old->_prev && old->_prev->_right == old)
					old->_prev->_right = target;
			else if (old->_prev && old->_prev->_left == old)
					old->_prev->_left = target;
		}

		void	remove( const Key &key )
		{
			node_ptr rm = rec_get_pos (top, key );
			if (rm == NULL)
				return ;
			node_ptr stead = left_most_node_from(rm->_right);
			if (stead == NULL)
				stead = rm->_left;
			if (stead == NULL)
			{
				node_ptr tmp = rm->_prev;
				swap_prev_desc(rm, NULL);
				rm_balance(tmp);
				delete rm;
				rm = NULL;
				return;
			}
			if (stead->_right)	
				stead = right_most_node_from(stead);
			if (stead->_left)
				stead = left_most_node_from(stead);
			if (stead == NULL)
			{
				node_ptr tmp = rm->_prev;
				swap_prev_desc(rm, NULL);
				rm_balance(tmp);
				delete rm;
				rm = NULL;
				return;
			}
			if (rm == top)
				top = stead;
			node_ptr tmp;
			if (stead->_prev != rm)
				tmp = stead->_prev;
			else
				tmp = rm->_prev;
			if ( rm->_left && rm->_left != stead)
			{
				stead->_left = rm->_left;
				rm->_left->_prev = stead;
			}
			if (rm->_right && rm->_right != stead )
			{
				stead->_right = rm->_right;
				rm->_right->_prev = stead;
			}
			swap_prev_desc(stead, NULL);
			swap_prev_desc(rm,stead);
			stead->_prev = rm->_prev;
			rm->_right = rm->_left =rm->_prev = NULL;
			rm_balance(tmp);
			delete rm;
			rm = NULL;
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

		//Rotations
		void	rm_balance(node_ptr root)
		{
			if (root == NULL)
				return;
			for(node_ptr tmp= root; tmp != NULL;tmp = tmp->_prev)
			{
				tmp->evaluate();
				if (tmp->_balance > 1)
				{
					if (tmp->_left->_balance >= 0)
						R_Rotation(tmp);
					else if (tmp->_left->_balance < 0)
					{
						L_Rotation(tmp->_left);
						R_Rotation(tmp);
					}
				}
				else if (tmp->_balance < -1)
				{
					if (tmp->_right->_balance <= 0)
						L_Rotation(tmp);
					else if (tmp->_right->_balance > 0)
					{
						R_Rotation(tmp->_right);
						L_Rotation(tmp);
					}
				}
			}
		}

		node_ptr	rec_get_pos(node_ptr pos,const Key &key)
		{
			if (!pos || (!pos->_left && !pos->_right))
				return(pos);
			if (key > pos->getFirst())
				pos = rec_get_pos(pos->_right, key);
			else if (key < pos->getFirst())
				pos = rec_get_pos(pos->_left, key);
			return (pos);

		}
		void balance(node_ptr root,const Key &key)
		{
 	  		if( root == NULL)
				return;
			for(node_ptr tmp = root; tmp != NULL; tmp = tmp->_prev)
			{
				tmp->evaluate();
				if (tmp->_balance > 1)
				{
					if (key > tmp->_left->getFirst())
						L_Rotation(tmp->_left);
					R_Rotation(tmp);

				}
				if (tmp->_balance < -1)
				{
					if (key < tmp->_right->getFirst())//prblm
						R_Rotation(tmp->_right);
					L_Rotation(tmp);
				}
			}
		}

		void	L_Rotation( node_type* unbalanced )
		{
			// std::cout << "Unbalanced " << unbalanced->getFirst() << std::endl;
			node_ptr	tmp = NULL;
			if (unbalanced->_right)
				tmp = unbalanced->_right->_left;
			if (!unbalanced->_right)
				return;
			update_prev(unbalanced , unbalanced->_right);
			if (tmp)
				tmp->_prev = unbalanced;
			unbalanced->_right = tmp;
			unbalanced->_prev->_left = unbalanced;
		}

		void	R_Rotation( node_type* unbalanced )
		{
			// std::cout << "Unbalanced " << unbalanced->getFirst() << std::endl;
			node_ptr	tmp = NULL;
			if (unbalanced->_left)
				tmp = unbalanced->_left->_right;
			if (!unbalanced->_left)
				return ;
			update_prev(unbalanced , unbalanced->_left);
			if (tmp)
				tmp->_prev = unbalanced;
			unbalanced->_left = tmp; 
			unbalanced->_prev->_right = unbalanced;
		}

		void	update_prev(node_ptr rm, node_ptr alter)
		{
			if (rm->_prev == NULL)
				top = alter;
			swap_prev_desc(rm, alter);
			alter->_prev = rm->_prev;
			rm->_prev = alter;
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

			void	slide_in_dms(node_ptr pos, node_ptr subtree)
			{
				if (!subtree || !pos)
					return;
				node_ptr tmp = NULL;
				tmp = insert_pos(pos, subtree->getFirst());
				if (tmp->getFirst() > subtree->getFirst())
				{
					tmp->_left = subtree;
					subtree->_prev = tmp;
				}
				else
				{
					tmp->_right = subtree;
					subtree->_prev = tmp;
				}
			}
			node_ptr insert_pos(node_ptr pos, const Key &key)
			{
				node_ptr tmp = pos;
				node_ptr	fin = tmp;
				while (tmp != NULL)
				{
					fin = tmp;
					if (tmp->getFirst() > key)
						tmp = tmp->_left;
					else if (tmp->getFirst() < key)
						tmp = tmp->_right;
				}
				return( fin );
			}
			
			void printTree(node_ptr root, std::string indent, bool last, int i)
			{
 		  	 if( root != NULL )
  		 	 {
		 		   std::cout<< i  << " " << indent ;
		 		   std::cout << (last ? "├──" : "└──" );
		  		  std::cout << "[ "<< root->getFirst() <<" ]" << std::endl;
		 	 	  printTree(root->_left, indent + (last ? "│   " : "    "), true, i);
		 	 	  printTree(root->_right, indent + (last ? "│   " : "    "), false, i);
   			 }
			}
	};
}
