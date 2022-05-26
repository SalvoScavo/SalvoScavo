#ifndef List_h
#define List_h

#include "Node_h.h"
#include <iostream>
template <typename T>
class List
{

    protected: 
            //visto le modifiche fare tutto in un nuovo file
            //aggiungere un contatore della lista quindi una dimensione
            //aggiungere un puntatore alla coda
            //aggiungere l'operatore []
             Node<T>* head;

    public:
                
                List(){
                    head=nullptr;
                }

                Node<T>* getHead() const
                {
                    return this->head;
                } 

                bool isEmpty()
                {
                    return head==nullptr;
                }


        //INSERIMENTO

                void insert(T* val)
                {
                    if(this->isEmpty())     //se la lista è vuota mettiamo come head un nuovo nodo
                    {
                        head= new Node<T>(val);
                        return;
                    }
                }
                
                void insertHead(T* val)   //costa o(1) 
                {

                    if(this->isEmpty())
                    {
                        this->insert(val);
                        return;
                    }
                    Node<T>* temp= new Node<T>(val);
                    temp->next = head;
                    this->head=temp;
                }


                void insertTail(T* val )  // o(n)
                {
                    if(this->isEmpty())
                    {
                        this->insertHead(val);
                            return;
                    }

                    Node<T>* ptr= head;

                    while (ptr->getNext()!=nullptr)
                    {
                            ptr=ptr->getNext();
                    }

                    Node<T> * tmp= new Node<T>(val);
                    ptr->next=tmp;
                }

                /*void insertInOrder(T val, char order)
                {
                    if(order=='A')
                    {
                       this-> insertInOrderAscending(val);
                        return;
                    }

                    if(order=='D')
                    {
                        this->insertInOrderDescending(val);
                    }
                }

                void insertInOrderAscending(T val)
                {
                    if(this->isEmpty())
                    {
                        this->insertHead(val);
                        return;
                    }

                    //se la lista è vuota sarebbe NULL e quindi darebbe una eccezione , controllo se il valore da inserire è minore della testa
                    if(val <= this->head->val)
                    {
                        this->insertHead(val);
                        return;
                    }

                    Node<T>* ptr=this->head; //puntatore alla testa

                    while(ptr->getNext() && (val>=ptr->val) )  //stessa  cosa di (ptr->getNext()!=nullptr)
                    {    
                        ptr=ptr->getNext();
                    }

                    if(ptr->getNext()==nullptr)
                    {
                        this->insertTail(val);
                        return;
                    }


                    Node<T>* toInsert= new Node<T>(val);
                    toInsert->next=ptr->getNext();
                    ptr->next=toInsert;

                }


                void insertInOrderDescending(T val)
                {
                     if(this->isEmpty())
                    {
                        this->insertHead(val);
                        return;
                    }

                    
                    if(val >= (this->head)->val)
                    {
                        this->insertHead(val);
                        return;
                    }



                    Node<T> *cur=head;
                    Node<T> *prev=nullptr;
                    while(cur->next && (val<=cur->val) )  //arrivamo al penultimo
                    {
                        prev=cur;
                        cur=cur->getNext();
                    }



                    if(cur->getNext()==nullptr)
                    {
                        this->insertTail(val);
                        return;
                    }


                    Node<T>* toInsert= new Node<T>(val);
                    
                    prev->next=toInsert;
                    toInsert->next=cur;
                    
                }

*/


                //cancellazione


                void removeHead()
                {
                    if(this->isEmpty())
                    {
                        cout<<"You cant delete an Empty list! "<<endl;
                        return;
                    }
                    Node<T> *temp= head;
                    head=head->next;  //sposto la testa un elemento in avanti
                    delete temp;
                }

                void removeTail()
                {
                    if(this->isEmpty())
                    {
                        cout<<"You cant delete an Empty list! "<<endl;
                        return;
                    }
                    
                    Node<T> *cur=head;
                    Node<T> *prev=nullptr;
                    while(cur->next)  //arrivamo al penultimo
                    {
                        prev=cur;
                        cur=cur->getNext();
                    }

                    prev->next=nullptr;  //il penultimo diventa ultimo
                    delete cur;  //l'ultimo viene eliminato
                }


                void removeElement(T* val)
                {
        
                    /*
                          prev -> cur --> nextcur 
                          prev -> nextCur
                          delete cur;
                    */

                    if(this->isEmpty())
                    {
                        cout<<"You cant delete an Empty list! "<<endl;
                        return;
                    }

                    if(head->val==val)
                    {
                        this->removeHead();
                        return;
                    }

                    Node<T> *cur=head;
                    Node<T> *prev=nullptr;

                    while(cur->next && cur->val!=val)  //arrivamo al penultimo oppure fino a quando il current è il valore cercato
                    {
                        prev=cur;
                        cur=cur->getNext();    
                    }

                    if(!(cur->next) && cur->val!=val)  //se siamo arrivati alla fine e non troviamo il valore 
                    {
                        cout<<"Element with value "<<val<<" not foud!";
                        return;
                    }

                    //eliminazione elemento
                    prev->next= cur->getNext();  //se è l'utlimo elemento prev.next punterà a null e quindi l'ultimo viene eliminato
                    delete cur;
                }

                friend ostream& operator<<(ostream& out,const List<T> list)
                {
                    out<<"List head="<< list.head <<endl;
                    Node<T> *ptr= list.head;
                    while(ptr!=nullptr)
                    {
                        out<<"\t"<<*ptr<<endl;
                        ptr= ptr->getNext();
                    }
                    return out;
                }
};
#endif