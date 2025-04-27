#include <iostream>
int const tamalipa=5;
using namespace std;

class Pila{
    public:
        class Desbordamiento{
            public: 
                int valdesborde;
                Desbordamiento(int i):valdesborde(i){
                    
                }
        };
        class Subdesbordamiento{
            public:
                Subdesbordamiento(){}
        };
        Pila(){cima=-1;}
        void meter (int item){
            if (cima<(tamalipa-1))
                lapila[++cima]=item;
            else    
                throw Desbordamiento(item);
        }
        int sacar(){
            if(cima>-1)
                return lapila[cima--];
            else
                throw Subdesbordamiento();
        }
        private:
            int lapila[tamalipa];
            int cima;

};

main (){
    Pila mipila;
    int i=5,j=25,l=30;

    try{
        mipila.meter(i);
        mipila.meter(j);
        mipila.meter(l);
        mipila.meter(12345);
        mipila.meter(9999);
        mipila.meter(100);

        cout <<"Sistema exitoso";
    }
    catch(Pila::Desbordamiento&p){
        cout<<"La pila se ha desbordado tratando de meter: "<<p.valdesborde<<endl;
        cout<<endl;
    }
    catch(Pila::Subdesbordamiento&p){
        cout<<"Se a producido un rebase negatico"<<endl;

    }
}
