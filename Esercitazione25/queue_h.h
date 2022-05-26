
#ifndef queue_h
#define queue_h

#include<iostream> 
#include "ListeDLinkate.h"
using namespace std;


template <typename T>
class Queue: protected DLList<T>
{
    private:
     int size;

    public:

    Queue():DLList<T>(),size(0){}

    void enqueue(T val)
    {
        DLList<T>::insertTail(val);
        size++;
    }

    T dequeue()
    {
    	
//    	cout<<"DEQUEUEEUEeee: ";
        if(isEmpty())
        {
            return -1;
        }
         T tmp= (DLList<T>::head)->getVal();
  //       cout<<tmp<<endl;
        DLList<T>::removeHead();
        size--;
        
        return tmp;
    }


    bool isEmpty()
    {
        return DLList<T>::isEmpty();
    }


    friend ostream& operator<<(ostream& out, Queue<T>& queue) 
    {
        DLNode<T>* tmp= queue.head;
        while(tmp->getNext())
        {
            out<<*tmp<<endl;
            tmp=tmp->getNext();
        }
        out<<"Last element of queue: "<<*tmp<<endl;
        return out;
    } 
};



#endif
