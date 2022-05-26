//liste doppiamente linkate
#ifndef ListeDLinkate
#define ListeDLinkate
#include <iostream>
using namespace std;

template<typename T>
class DLNode
{
    private:
        T val;
        DLNode<T> *next;
        DLNode<T> *prev;

        template <typename U>  
        friend class DLList;

    public:

    DLNode(T val): val(val),next(nullptr),prev(nullptr){}

    DLNode<T>* getNext() const
    {
        return this->next;
    }

    DLNode<T>* getPrev()const
    {
        return this->prev;
    }
    
    T getVal() const
    {
        return this->val;
    }



    friend ostream& operator<<(ostream& out, const DLNode<T> & node)
    {
        out<<"node val= "<<node.getVal() <<"-next= "<<node.getNext()<<"-prev= "<<node.getPrev();
        return out;
    }
};


template<typename T>
class DLList
{

    protected:
        DLNode<T> *head;
        DLNode<T>  *tail;
    
    public:

        DLList(){
            this->head=nullptr;
            this->tail=nullptr;
        }

        bool isEmpty()
        {
            return ( (head==nullptr) && (tail==nullptr) );
        }

        void insertHead(T val)
        {
            if(this->isEmpty())
            {
                head= new DLNode<T>(val);
                tail=head;
                return;
            }

            DLNode<T>* toInsert= new DLNode<T>(val);
            toInsert->prev=toInsert;
            head=toInsert;
        }

        void insertTail(T val)
        {
            if(this->isEmpty())
            {
                this->insertHead(val);
                return;
            }

            DLNode<T> *toInsert= new DLNode<T>(val);
            toInsert->prev=tail;
            tail->next=toInsert;
            tail=toInsert;
        }

        //fare inserimento ordinato


        void removeHead()
        {
            if(this->isEmpty())
            {
                cout<<"Empty list!"<<endl;
                return;
            }

            if(head == tail)  //vuol dire che c'è un solo elemento
            {
                DLNode<T>* ptr= head;
                head= nullptr;
                tail= nullptr;
                delete ptr;
				return;
            }

            DLNode<T>* ptr= head;
            (ptr->next )->prev = nullptr;  //vai al nodo successivo alla testa e metti il precedente a null
            head=ptr->next;
            delete ptr;
        }


        void removeTail()
        {
             if(this->isEmpty())
            {
                cout<<"Empty list!"<<endl;
                return;
            }

            if(head == tail)  //vuol dire che c'è un solo elemento
            {
                DLNode<T>* ptr= head;
                head= nullptr;
                tail= nullptr;
                delete ptr;

            }

            DLNode<T> *ptr=tail;
            ptr->prev->next=nullptr;  //il precedente della coda avrà il next a null diventando ultima
            tail= ptr->prev;  //la coda diventa il penultimo
            delete ptr;  //elimino la vecchia coda


        }

        //fare la cancellazione di un elemento




        friend ostream& operator<<(ostream& out,const DLList<T> list)
        {
           out<<"List head="<< list.head <<endl;
           DLNode<T> *ptr= list.head;
           while(ptr!=nullptr)
            {
                out<<"\t"<<*ptr<<endl;
                ptr= ptr->getNext();
            }

            out<<"List tail= "<<list.tail<<endl;
            return out;
        }
};


#endif
