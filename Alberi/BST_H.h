#ifndef BST_H
#define BST_H

#include BSTNode_h
#include <iostream>
using namespace std;

template <typename T>

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

            void insert(T key)
            {
                if(this->isEmpty())
                {
                    root = new BSTNode<T>(key);
                    return;
                }

                insert(root,key);

            }


            void insert(BSTNode<T>* ptr, T key)
            {
                //sistemare l'inserimento
                    if(ptr==nullptr)
                    {
                        ptr= new BSTNode<T>(key);   //dobbiamo metterer prt->left = ...
                        return;
                    }
                    if(key <= ptr->key)
                    {
                        insert(ptr->left,key);
                    }else 
                    {
                         insert(ptr->right,key);
                    }

            }

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