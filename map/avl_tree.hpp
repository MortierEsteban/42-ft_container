#pragma once
#include "node.hpp"

namespace ft
{
	template<class Key, class Value>
	struct avl_tree
	{
		typedef node<Key, Value> node_type;

		node_type *top;
		size_t	size;
		node *min;//????
		node *max;//????

		avl_tree(	void	): top( NULL ), size( 0 ), min(NULL), max(NULL)
		{}

		void 	insert( Key &key, Value& val)
		{
			node_type *pos = top;
			bool		inf = true;
			node_type *prev = top;
			while(pos)
			{
				if (key == pos->first)
				{
					pos->value->second = val;
					return;
				}
				//COMPARE?
				if (key < pos->first)
				{
					inf = true;
					prev = pos;
					pos = pos->left;
				}
				else
				{
					inf = false;
					prev = pos;
					pos = pos->right;
				}
			}

			node_type *tmp = new node_type(key, val, prev);
			if (!top)
				top = tmp;
			else if (inf == true)
				prev.left = tmp;
			else
				prev.right = tmp;
			//balance?
		}
		//ROTATIONS
		void	L_Rotation( node *unbalanced)
		{
			if (unbalanced->_prev)
				update_prev( unbalanced->_prev, unbalanced , unbalanced->_right);
			left_most_node_from (unbalanced->_right)->_left = unbalanced;
		}
		void	R_Rotation( node *unbalanced)
		{
			if (unbalanced->_prev)
				update_prev( unbalanced->_prev, unbalanced , unbalanced->_left);
			right_most_node_from(unbalanced->_left)->right = unbalanced;
		}

		void	LR_Rotation( node * unbalanced)
		{
			L_Rotation( unbalanced->left );
			R_Rotation( unbalanced );
		}

		void	RL_Rotation( node * unbalanced)
		{
			L_Rotation( unbalanced->left );
			R_Rotation( unbalanced );
		}
		/*
				Left-Right rotation
					Right-Left rotation*/
		
		void	balance( void )
		{
			node *tmp = min;

			set_min();set_max();
		}


		//UTILS
			//Get Deepest
			node *left_most_node_from( node *_orig	)
			{
				node *tmp = orig;
				while (tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}
			node *right_most_node_from( node *_orig)
			{
				node *tmp = orig;
				while (tmp->_right)
					tmp = tmp->_right;
				return tmp;
			}
			// Set minmax
			void	set_min( void )
			{
				node *tmp = top;
				while ( tmp && tmp->_left)
					tmp = tmp->_left;
				min = left;
			}

			void	set_max( void )
			{
				node *tmp = top;
				while ( tmp && tmp->_right)
					tmp = tmp->_right;
				min = left;
			}

			void	update_prev( node* parent, node* son, node *alter)
			{
				if (parent->_right == son)
					parent->right = alter;
				else
					parent->left = alter;
			
			}
	};
}
