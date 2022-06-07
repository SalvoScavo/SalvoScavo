#include <iostream>
#include "BST_H.h"
using namespace std;
int main()
{
    BST<int> tree;

    tree.insert(7);
    tree.insert(4);
    tree.insert(10);
    tree.insert(12);
    tree.insert(9); 
    tree.insert(6);
    tree.insert(3);
    tree.insert(1);
//    tree.insert(3);

    tree.print("Order");


    int max= (tree.findMax())->getKey();
    int min= tree.findMin()->getKey();
    cout<<"Il massimo e' "<<max<<" il minimo e' "<<min<<endl;
/*
    BSTNode<int>* successor=tree.successor(tree.getRoot());
    if(successor)
        cout<<endl<<" SUCCESSORE DELLA ROOT è "<<*successor<<endl;
    else
        cout<<"Non esiste il successore della root";
    int valore;
    cout<<"Inserisci il valore del nodo che vuoi cercare : ";
    cin>>valore;

    BSTNode<int>* ptr= tree.search(valore);

    BSTNode<int>* suc;
    BSTNode<int>* prev;
 /*   if(ptr)
    {
        cout<<"Trovato : "<<*ptr<<endl;
        suc=tree.successor(ptr);
        prev= tree.predecessor(ptr);
        if(prev)
                cout<<"Il suo  predecessore "<<"  ->  "<< *prev;
            else  
                cout<<"Non esiste predecessore "<<endl;
        
        if(suc)
                cout<<"Il suo  succcessore "<<"  ->  "<< *suc;
            else
                cout<<"Non esiste il successore "<<endl;
    }else
    {
        cout<<"Valore non esistende nell'albero "<<endl;
    }
*/

    cout<<"\n Visita post order:\n ";
    tree.print("Post");

    cout<<"\n Visita pre order : \n";
    tree.print("Pre");
}
