#pragma once
#include "node.hpp"
// #include "../utils/bidir_it.hpp"
// #include "../utils/reverse_it.hpp"

namespace ft
{
	template<class Key,class Value, class Compare = std::less<Key> >
	class avl_tree
	{
		// friend class bidirectional_iterator<ft::pair<const Key, Value> > ;
		// typename Value::template rebind<key>::other _allocbinded;
		private:
	
			typedef Compare						key_compare;
			key_compare							comp;

		public:
			typedef node<ft::pair<const Key, Value > > node_type;
			typedef node<ft::pair<const Key, Value > >* node_ptr;
			node_ptr top;

			avl_tree( const key_compare &_comp = key_compare()): comp (_comp),top(NULL){}
			~avl_tree()
			{	deleteall(top);}

			void deleteall(node_ptr root)
			{
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
			{	top = insert_Node(top, key, val);}

			node_ptr insert_Node( node_ptr pos,const Key &key, const Value& val)
			{
				if (!pos)
					return(new node_type(key,val));
				if (comp(pos->getFirst(), key))
					pos->_right = insert_Node(pos->_right, key, val);
				else if (comp(key, pos->getFirst()))
					pos->_left = insert_Node(pos->_left, key, val);
				else 
				{
					pos->value.second = val;
					return (pos);
				}
				return(balance(pos, key));
			}
			void	remove(const Key& key)
				{	top = remove(top, key);	}
			node_ptr remove(node_ptr pos, const Key& key)
			{
				if (!pos)
					return(NULL);
				if (comp(pos->getFirst(), key))
					pos->_right = remove(pos->_right, key);
				else if (comp(key, pos->getFirst()))
					pos->_left = remove(pos->_left, key);
				else
				{
					if (!pos->_right && !pos->_left)
					{
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
						tmp->_right = pos->_right;
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
						pivot->_left = L_Rotate(pivot->_left);
					return(R_Rotate(pivot));
				}
				if (balance_factor < -1)
				{
					if (comp(key , pivot->_right->getFirst()))
						pivot->_right = R_Rotate(pivot->_right);
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
				piv->_left = sub;
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

			node_ptr left_most_node_from( node_type* _orig )
			{
				node_type* tmp = _orig;
				if (!tmp)
					return(NULL);
				while (tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}
			node_ptr right_most_node_from( node_type* _orig )
			{
				node_type* tmp = _orig;
				if (!tmp)
					return(NULL);
				while (tmp->_right)
					tmp = tmp->_right;
				return tmp;
			}
			//ITERATORS

			node_ptr getNext(node_ptr orig, const Key& obj)
			{
				if (!orig || orig == right_most_node_from(top))
					return(NULL);
				if (obj == top->getFirst())
					return(left_most_node_from(top->_right));
				if (orig->getFirst() == obj && !orig->_right)
					return(getNext(top, obj));
				else if (orig->_right && orig->getFirst() == obj)
					return(left_most_node_from(orig->_right));
				else if ( orig->_left && orig->_left->getFirst() == obj)
					return (orig);
				else if (orig->_right && orig->_right->getFirst() == obj)
					return(getNext(top, orig->getFirst()));
				else if (comp(orig->getFirst(), obj))
						return(getNext(orig->_right, obj));
				else if (comp(obj, orig->getFirst()))
					return(getNext(orig->_left, obj));
				return( NULL );

			}
				// if (orig == top)
				// 	std::cout << "Back to top" << std::endl;
				// if (!orig)
				// 	return(NULL);
				// if (orig->_right && orig->getFirst() == obj)
				// 	return(left_most_node_from(orig->_right));
				// if (comp(orig->getFirst(), obj))
				// {
				// 	if(orig->_right && orig->_right->getFirst() == obj)
				// 		return(orig);
				// 	else
				// 		return(NULL);
				// }
				// else if (comp(obj, orig->getFirst()))
				// {
				// 	if ( orig->_left && orig->_left->getFirst()==obj)
				// 	{
				// 		if (orig->_right)
				// 			return(left_most_node_from(orig->_right));
				// 		else
				// 			return(orig);
				// 	}
				// }
				// else if (orig->getFirst() == obj)
				// 	return(getNext(top, obj));

			node_ptr getPrev(node_ptr orig, const Key& obj)
			{
			}
			
	};
}