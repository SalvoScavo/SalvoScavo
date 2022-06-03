#ifndef BST_H
#define BST_H

#include "BSTNode_H.h"
#include <iostream>
using namespace std;

template <typename T>
/*
    BST : Binary search tree
*/
class BST
{
    private:    
             BSTNode<T>* root;
    
    public:
            BST()
            {
                root=nullptr;
            }

            bool isEmpty()
            {
                return root== nullptr;
            }
            
            //TEST
            void insert(T key)
            {
                    root = insert(root,key);

            }

             
            BSTNode<T>* insert(BSTNode<T>* ptr, T key)
            {

                
                    if(ptr==nullptr)
                    {
                        return new BSTNode<T>(key);                      
                    }
                    if(key <= ptr->key)
                    {
                        ptr->left=insert(ptr->left,key);
                    }else 
                    {
                         ptr->right=insert(ptr->right,key);
                    }

            }   //fine test

            void visit(BSTNode<T>* node)
            {
                cout<<*node<<"-";
            }

            void visitInorder(BSTNode<T>*ptr)
            {
                if(ptr==nullptr)  return;

                visitInorder(ptr->left);
                visit(ptr);
                visitInorder(ptr->right);
            }

            void print()
            {
                visitInorder(root);
            }
};

#endif
