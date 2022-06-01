#ifndef BSTNode_h
#define BSTNode_h

#include <iostream>
using namespace std;



template <typename T>
class BSTNode
{  
    
    private:
             
             T key;
             BSTNode<T>* left;
             BSTNode<T>* right
             template <typename U>   //siccome ancora lista non esiste non sa che List sarà una classe template
             friend class BST;   //ci sarà una clsse list (ancora non definito) che sarà friend di Node  
    public: 
            BSTNode(T key):key(key)
            {
                left= nullptr;
                right= nullptr;
            }

            void setLeft(BSTNode<T>* lf)
            {
                this->left=left;
            }

            void setRight(BSTNode<T>*rg)
            {
                this->right=right;
            }


            T getKey() const
            {
                return key;
            }

            void setKey(T key)
            {
                this->key=key;
            }
            
            BSTNode<T>* getLeft() const
            {
                return this->left;
            }

            BSTNode<T>* getRight() const
            {
                return this->right;
            }

            friend ostream& operator<<(ostream& out, const Node<T> & node)
            {
                out<<"BSTNode@"<<&node<<" key="<<*(node.key) <<"- left= "<<node.left<<" - right= "<<node.right;
                return out;
            }

            /*DISTRUTTORE  DEPRECATED
            ~BSTNode()
            {
                delete left;
                delete right;
            }*/

};
    

#endif
