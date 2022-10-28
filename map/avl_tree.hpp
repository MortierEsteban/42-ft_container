#pragma once
#include "node.hpp"

namespace ft
{
	template<class Key,class Value, class Compare = std::less<Key> >
	class avl_tree
	{
		private:

			typedef Compare						key_compare;
			key_compare							comp;

		public:

			typedef ft::pair<const Key, Value >			pair_type;
			typedef node<pair_type> 					node_type;
			typedef node<pair_type>* 					node_ptr;
			node_ptr	top;
			size_t 		size;

			avl_tree( const key_compare &_comp = key_compare()): comp (_comp),top(NULL), size(0){}
			~avl_tree()
			{	deleteall(top);}

			void deleteall(node_ptr root)
			{
				size = 0;
 		  		if( root != NULL )
  		 		{
		 			deleteall(root->_right);
		 			deleteall(root->_left);
					delete root;
   				}
			}
			
			int max(int a, int b) { return ((a > b) ? a : b); }

			//INSERT REMOVE
			void	insert(const Key& key, const Value& val)
			{	
				top = insert_Node(top, key, val);
				top->_prev = NULL;	
			}

			void	insert(const pair_type &pair)
			{
				top = insert_Node(top, pair.first, pair.second);
				top->_prev = NULL;
			}

			node_ptr insert_Node( node_ptr pos,const Key &key, const Value& val)
			{
				if (!pos)
				{
					size++;
					return(new node_type(key,val));
				}
				if (comp(pos->getFirst(), key))
				{
					pos->_right = insert_Node(pos->_right, key, val);
					if (pos->_right)
						pos->_right->_prev = pos;
				}
				else if (comp(key, pos->getFirst()))
				{
					pos->_left = insert_Node(pos->_left, key, val);
					if (pos->_left)
						pos->_left->_prev = pos;
				}
				else 
				{
					// pos->value.second = val;
					return (pos);
				}
				return(balance(pos, key));
			}

			void	remove(const Key& key)
				{
					top = remove(top, key);
					if (top)
						top->_prev = NULL;
				}

			node_ptr remove(node_ptr pos, const Key& key)
			{
				if (!pos)
					return(NULL);
				if (comp(pos->getFirst(), key))
				{
					pos->_right = remove(pos->_right, key);
					if (pos->_right)
						pos->_right->_prev = pos;
				}
				else if (comp(key, pos->getFirst()))
				{
					pos->_left = remove(pos->_left, key);
					if (pos->_left)
						pos->_left->_prev = pos;
				}
				else
				{
					if (!pos->_right && !pos->_left)
					{
						size--;
						delete pos;
						pos = NULL;
						return (NULL);
					}
					else
					{
						node_ptr tmp = pos;
						tmp = pos->_right? pos->_right:pos->_left;
						tmp = left_most_node_from(tmp);
						node_ptr tmp2 = unlink(pos, tmp->getFirst());
						if (tmp2 != pos)
							tmp2->_right = tmp;
						else
							tmp2 = tmp;
						tmp->_height = pos->_height;
						tmp->_left = pos->_left;
						if (tmp->_left)
							tmp->_left->_prev = tmp;
						tmp->_right = pos->_right;
						if (tmp->_right)
							tmp->_right->_prev = tmp;
						tmp->_prev = pos->_prev;
						size--;
						delete pos;
						return(tmp2);
					}
				}
				return(balance(pos));
			}

			node_ptr	unlink(node_ptr pos, const Key &key)
			{
				if (pos == NULL)
					return NULL;
				if(comp(pos->getFirst(), key))
					pos->_right = unlink(pos->_right,key);
				else if (comp(key,pos->getFirst()))
					pos->_left = unlink(pos->_left,key);
				else
					return(pos->_right);
				return(balance(pos));
			}

			//BALANCE
			node_ptr	balance(node_ptr pivot)
			{
				pivot->_height = 1 + max(height(pivot->_left), height(pivot->_right));
				int balance_factor = BalanceFactor(pivot);
				if (balance_factor > 1)
				{
					if (BalanceFactor(pivot->_left) >= 0)
						return(R_Rotate(pivot));	
					else  if (BalanceFactor(pivot->_left ) < 0 )
					{
						pivot->_left = L_Rotate(pivot->_left);
						if (pivot->_left)
							pivot->_left->_prev = NULL;
						return(R_Rotate(pivot));
					}
				}
				if (balance_factor < -1)
				{
					if (BalanceFactor(pivot->_right) <= 0)
						return(L_Rotate(pivot));
					else if (BalanceFactor(pivot->_right ) > 0 )
					{
						pivot->_right = R_Rotate(pivot->_right);
						if (pivot->_right)
							pivot->_right->_prev = NULL;
						return(L_Rotate(pivot));
					}
				}
				return (pivot);
			}
			
			node_ptr	balance(node_ptr pivot, const Key &key)
			{
				pivot->_height = 1 + max(height(pivot->_left), height(pivot->_right));
				int balance_factor = BalanceFactor(pivot);
				if (balance_factor > 1)
				{
					if (comp(pivot->_left->getFirst(), key))
					{
						pivot->_left = L_Rotate(pivot->_left);
						if (pivot->_left)
							pivot->_left->_prev = NULL;
					}
					return(R_Rotate(pivot));
				}
				if (balance_factor < -1)
				{
					if (comp(key , pivot->_right->getFirst()))
					{
						pivot->_right = R_Rotate(pivot->_right);
						if (pivot->_right)
							pivot->_right->_prev = NULL;
					}
					return(L_Rotate(pivot));
				}
				return (pivot);
			}

			//Rotations
			node_ptr	R_Rotate( node_ptr piv)
			{
				node_ptr	left = piv->_left;
				node_ptr	sub = left->_right;
				left->_right = piv;
				left->_prev = piv->_prev;
				piv->_prev = left;
				piv->_left = sub;
				if (sub)
					sub->_prev = piv;
				piv->_height = max(height(piv->_left), height(piv->_right)) + 1;
				left->_height = max(height(left->_left), height(left->_right)) + 1;
				return(left);
			}

			node_ptr	L_Rotate( node_ptr piv)
			{
				node_ptr	right = piv->_right;
				node_ptr	sub =	right->_left;
				right->_left = piv;
				piv->_right = sub;
				right->_prev = piv->_prev;
				piv->_prev = right;
				if (sub)
					sub->_prev = piv;
				piv->_height = max(height(piv->_left), height(piv->_right)) + 1;
				right->_height = max(height(right->_left), height(right->_right)) + 1;
				return(right);
			}

			//UTILS
		void checkBalance(node_ptr root)
		{
 	  		if( root != NULL )
  	 		{
				int tmp = BalanceFactor(root);
				if (tmp > 1 || tmp < -1)
					std::cout << "Unbalanced node at : " << root->getFirst() << std::endl;
				if (root != top)
					std::cout << "prev of " << root->getFirst() << " is " << root->_prev->getFirst() << std::endl;
				checkBalance(root->_left);
				checkBalance(root->_right);
   			}
		}
		void printTree(node_ptr root, std::string indent, bool last, int i)
		{
 			if( root != NULL )
  			{
				std::cout<< " "<<  i  << " " << indent ;
				std::cout << (last ? "├──" : "└──" );
				std::cout << "[ "<< root->getFirst() <<" ]" << std::endl;
		 		printTree(root->_left, indent + (last ? "│   " : "    "), true, i);
		 		printTree(root->_right, indent + (last ? "│   " : "    "), false, i);
   			}
			if (!top)
				std::cout << "Tree is empty lol" << std::endl;
		}

		int	height(node_ptr pos)
		{
			if (!pos)
				return(0);
			return(pos->_height);
		}
		int BalanceFactor(node_ptr pos)
		{
			if (!pos)
				return (0);
			return (height (pos->_left) - height (pos->_right));
		}

			node_ptr left_most_node_from( node_type* _orig ) const 
			{
				node_type* tmp = _orig;
				if (!tmp)
					return(NULL);
				while (tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}
			node_ptr right_most_node_from( node_type* _orig ) const 
			{
				node_type* tmp = _orig;
				if (!tmp)
					return(NULL);
				while (tmp->_right)
					tmp = tmp->_right;
				return tmp;
			}
		node_ptr	search(const Key& key) const
		{	return(search(key,top));	}

		node_ptr	search(const Key& key, node_ptr pos) const
		{
			if (!pos)
				return(NULL);
			if (pos->getFirst() == key)
				return(pos);
			else if (comp(key,pos->getFirst()))
				return(search(key, pos->_left));
			else
				return(search(key,pos->_right));
			return NULL;
		}
	};
}