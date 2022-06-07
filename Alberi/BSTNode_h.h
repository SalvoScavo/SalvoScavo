#ifndef BSTNode_H
#define BSTNode_H

#include <iostream>
using namespace std;



template <typename T>
class BSTNode
{  
    
    private:
             
             T key;
             BSTNode<T>* left;
             BSTNode<T>* right;
             BSTNode<T>* parent;
             template <typename U>   //siccome ancora lista non esiste non sa che List sarà una classe template
             friend class BST;   //ci sarà una clsse list (ancora non definito) che sarà friend di Node  
    public: 
            BSTNode(T key):key(key)
            {
                left= nullptr;
                right= nullptr;
                parent= nullptr;
            }


            void setParent(BSTNode<T>* par)
            {
                this->parent=par;
            }

            BSTNode<T>* getParent() const
            {
                return this->parent;
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

            friend ostream& operator<<(ostream& out, const BSTNode<T> & node)
            {
                out<<"Key="<<node.key;
                 out <<"- parent= ";
                if(node.parent)
                {
                   out<<(node.parent)->key;
                }  else
                {
                       out<<"NULL"; 
                }
                 out<<"- left= ";
                if(node.left)
                {
                    out<<(node.left)->key;
                }else
                {
                    out<<"NULL";
                }

                out<<"- right= ";
                if(node.right)
                {
                    out<<(node.right)->key;
                }else
                {
                    out<<"NULL";
                }

                out<<endl;
                    
                  //   " - right= "<<*node.right<<endl;
              //  out<<"BSTNode@"<<&node<<" key="<<(node.key)<<"- parent= "<<node.parent <<"- left= "<<node.left<<" - right= "<<node.right<<endl;
                return out;
            }

            /*DISTRUTTORE  
            ~BSTNode()
            {
                delete left;
                delete right;
            }*/

};
    

#endif
