#include <iostream>
#include "BST_H.h"
using namespace std;
int main()
{
    BST<int> tree;

    tree.insert(10);
    tree.insert(4);
    tree.insert(6);
    tree.insert(12);
    tree.insert(7); 
    tree.insert(14);
    tree.insert(5);
    tree.insert(18);
    tree.insert(3);

    tree.print();


    int max= (tree.findMax())->getKey();
    int min= tree.findMin()->getKey();
    cout<<"Il massimo e' "<<max<<" il minimo e' "<<min<<endl;

    cout<<endl<<" SUCCESSORE DELLA ROOT è "<<*tree.successor(tree.getRoot())<<endl;

    int valore;
    cout<<"Inserisci il valore del nodo che vuoi cercare : ";
    cin>>valore;

    BSTNode<int>* ptr= tree.search(valore);

    BSTNode<int>* suc;
    BSTNode<int>* prev;
    if(ptr)
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

  
}
