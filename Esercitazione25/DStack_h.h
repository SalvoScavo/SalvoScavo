#ifndef DStack_h
#define DStack_h

#include "List_h.h"


template<typename T>
class Stack : protected List<T>
{

    //ridefinire l'overload di << per fare una visualizzazione stile lista
    private:
            int size=0;
    
    public:

        Stack():List<T>(){}

        Node<T>*getTop()
        {
             if(List<T>::isEmpty()) 
                    return nullptr;
            return List<T>::getHead();
        }

        void push(T* val)
        {
            List<T>::insertHead(val);
            size++;

        }
        T* pop()
        {
            
            if(List<T>::isEmpty()) 
                    return nullptr;
            T* ptr= getTop()->getVal();
            List<T>::removeHead();
            size--;
            return ptr;
        }


        int getSize()
        {
            return this->size;
        }

        friend ostream& operator<<(ostream& out, Stack<T>& s)
        {
            //sistemare
             out<<"Top value: "<<*(s.getTop())->getVal()<<"- top address:  "<<s.getTop()<<endl;

             Node<T>* ptr=s.getTop()->getNext();
             while(ptr)
             {
                 out<<*ptr<<endl;
                 ptr=ptr->getNext();
             }

             return out;
        }
};
#endif
