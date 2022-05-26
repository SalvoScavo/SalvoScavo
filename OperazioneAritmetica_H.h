#ifndef OperazioneAritmetica_H
#define OperazioneAritmetica_H
#include <typeinfo>

class OperazioneAritmetica
{
    private:
        double opSinistro;
        double opDestro;
    public:
        OperazioneAritmetica()
        {
            this->opSinistro=0;
            this->opDestro=0;
        }

        virtual double eseguiCalcolo()=0;

        void setOpSinitro(double op)
        {
            this->opSinistro=op;
        }
        

        void setOpDestro(double op)
        {
            this->opDestro=op;
        }        

        double getOpSinistro()
        {
            return this->opSinistro;
        }
        double getOpDestro()
        {
            return this->opDestro;
        }
    
        virtual ostream& print(ostream& out)
        {
            out<<"Operazione= "<<typeid(*this).name()<<endl;
            return out;
        }
};

class Addizione: public OperazioneAritmetica
{
    public:
    Addizione() :OperazioneAritmetica(){}

    double eseguiCalcolo()
    {
        return OperazioneAritmetica::getOpSinistro() + OperazioneAritmetica::getOpDestro();
    }

    ostream& print(ostream& out)
    {
        OperazioneAritmetica::print(out);
        out<<this->getOpSinistro() <<" + "<<this->getOpDestro()<<endl;

        return out;
        
    }
};
class Sottrazione: public OperazioneAritmetica
{
    public:
    Sottrazione() :OperazioneAritmetica(){}

    double eseguiCalcolo()
    {
        return OperazioneAritmetica::getOpSinistro() - OperazioneAritmetica::getOpDestro();
    }

     ostream& print(ostream& out)
    {
          OperazioneAritmetica::print(out);
        out<<this->getOpSinistro() <<" - "<<this->getOpDestro()<<endl;
        return out;
    }
};

class Moltiplicazione: public OperazioneAritmetica
{
    public:
    Moltiplicazione() :OperazioneAritmetica(){}

    double eseguiCalcolo()
    {
        return OperazioneAritmetica::getOpSinistro() * OperazioneAritmetica::getOpDestro();
    }

    ostream& print(ostream& out)
    {
          OperazioneAritmetica::print(out);
        out<<this->getOpSinistro() <<" * "<<this->getOpDestro()<<endl;
        return out;
    }
};


class Divisione: public OperazioneAritmetica
{
    public:
    Divisione() :OperazioneAritmetica(){}

    double eseguiCalcolo()
    {
        if(OperazioneAritmetica::getOpDestro()==0)
        {
            cout<<"\nImpossibile dividere per zero, valore ritornato 0.0"<<endl;
            return 0.0;
        }
        return OperazioneAritmetica::getOpSinistro() / OperazioneAritmetica::getOpDestro();
    }

    ostream& print(ostream& out)
    {
          OperazioneAritmetica::print(out);
        out<<this->getOpSinistro() <<" / "<<this->getOpDestro()<<endl;

        return out;
        
    }
};


ostream& operator<<(ostream& out,OperazioneAritmetica& obj)
{
    return obj.print(out);
}


#endif
