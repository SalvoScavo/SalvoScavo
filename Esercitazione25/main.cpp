#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "OperazioneAritmetica_H.h"

#include "DStack_h.h"
#include "queue_h.h"

int main()
{
    srand(time(0));
       int N;

    do
    {
       cout<<"Inserisci il numero di operazioni: ";
       cin>>N;
    }while(N<1);

    Stack<OperazioneAritmetica> operazioni;

    int rnd;
    for(int i=0;i<N;i++)
    {
        rnd=rand()%400;

        if(rnd<100)
        {
            Addizione* a=new Addizione();
            operazioni.push(a);
        }else if(rnd<200)
        {
            Sottrazione* s=new Sottrazione();
            operazioni.push(s);
        }else if(rnd<300)
        {
            Moltiplicazione* m=new Moltiplicazione();
            operazioni.push(m);
        }else{
            Divisione *d = new Divisione();
            operazioni.push(d);
        }
    }

    cout<<"Pila di operazioni creata:\n "<<operazioni<<endl;


        Queue<double> numeri;

        double f;
        for(int i=0;i<2*N;i++)
        {
            f=(double)rand() / RAND_MAX;
            f= 1+f*(1000-1);
            numeri.enqueue(f);
        }

        cout<<numeri<<endl;


        cout<<"Estrazione numeri\n";
        OperazioneAritmetica* op;
        double sx,dx;
        int dim=operazioni.getSize();
        for(int i=0;i<=dim;i++)
        {
            
            sx=numeri.dequeue();
            dx=numeri.dequeue();
            
            
            op=operazioni.pop();
         
            op->setOpSinitro(sx);
            op->setOpDestro(dx);
            //cout<<op<<"= "<<op->eseguiCalcolo();
            //cout<<operazioni.pop();
            if(typeid( *op )==typeid(Addizione))
            {
                Addizione* add=(Addizione*) op;
                cout<<*add<<" = "<<add->eseguiCalcolo()<<endl;

            }else if( typeid( *op )==typeid(Sottrazione))
            {

                Sottrazione* sot=(Sottrazione*) op;
                cout<<*sot<<" = "<<sot->eseguiCalcolo()<<endl;

            }else if(typeid( *op )==typeid(Moltiplicazione))
            {
                
                Moltiplicazione* mol=(Moltiplicazione*) op;
                cout<<*mol<<" = "<<mol->eseguiCalcolo()<<endl;
            
            }else if(typeid( *op )==typeid(Divisione))
            {

                Divisione* div=(Divisione*) op;
                cout<<*div<<" = "<<div->eseguiCalcolo()<<endl;
            
            }
            
        }

}
