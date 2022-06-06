#ifndef BST_H
#define BST_H

#include "BSTNode_h.h"
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

            
            BSTNode<T>* getRoot()const
            {
                return this->root;
            }

                //Soluzione professore
            void insert(T key)
            {
                if(this->isEmpty() )
                {
                    root=new BSTNode<T>(key);
                    return;
                }
                insert(root,key);
            }

             
            void insert(BSTNode<T>* ptr, T key)
            {

                
                    if(ptr->right==nullptr && key>ptr->key)
                    {
                        ptr->right = new BSTNode<T>(key);
                        ptr->right->setParent(ptr);
                        return;              
                    }
                    if(ptr->left == nullptr && key <= ptr->key)
                    {
                        ptr->left = new BSTNode<T>(key);
                        ptr->left->setParent(ptr);
                        return;
                    }

                    if(key <= ptr->key)
                    {
                        insert(ptr->left,key);
                    }else 
                    {
                        insert(ptr->right,key);
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



            BSTNode<T>* search(T key)
            {
                return search(root,key);
            }



            BSTNode<T>* search(BSTNode<T>* ptr,T key)
            {
                if(ptr== nullptr)  return nullptr;

                if(ptr->key == key )
                    return ptr;
                

                if(key < ptr->key)
                    return search(ptr->left, key);

                if( key > ptr->key)
                     return search(ptr->right,key);
                
                return nullptr;

            }


            BSTNode<T>* findMax()
            {
                return findMax(root);
            }

            BSTNode<T>* findMax(BSTNode<T>* from)
            {
                
                if(this->isEmpty())
                {
                    cout<<"Empty list! return null";
                    return nullptr;
                }


                BSTNode<T>* ptr= from;
                while(ptr->right !=nullptr)
                {
                    ptr= ptr->right;
                }

                return ptr;
            
            
            
            }

            BSTNode<T>* findMin()
            {
                return findMin(root);
            }





            BSTNode<T>* findMin(BSTNode<T>* from)
            {
                if(this->isEmpty())
                {
                    cout<<"Empty list! return null";
                    return nullptr;
                }


                BSTNode<T>* ptr= from;
                while(ptr->left !=nullptr )
                {
                    ptr= ptr->left;
                }

                return ptr;

            }

            BSTNode<T>* successor(BSTNode<T>* x)
            {
                if(this->isEmpty())
                {
                    return nullptr;
                }

                //caso 1 (esiste un sottoalbero)
                if(x->right)
                {
                    return this->findMin(x->right);
                }

                //caso 2

                BSTNode<T>* y = x->parent;

                while(x!= nullptr && x==y->right)
                {
                    x=y;
                    y=y->parent;
                }

                return y;
            }


            BSTNode<T>* predecessor(BSTNode<T>* x)
            {
                if(this->isEmpty())
                {
                    return nullptr;
                }

                if(x->left)
                {
                    return this->findMax(x->left);
                }


                 BSTNode<T>* y = x->parent;

                while(x!= nullptr && x==y->left)
                {
                    x=y;
                    y=y->parent;
                }

                return y;

                
            }
};

/*Dato un nodo x il suo successore è :
    se esiste un sottoalbero destro  -> il minimo di esso
    se non esiste il sottoalbero destro -> l'antenato più prossimo di x il cui figlio sinitro è anche antenato di x
                                            in pratica risalgo l'albero finche il parent non è un figlio sinistro

Per il predecessore è l'opposto
*/
#endif
