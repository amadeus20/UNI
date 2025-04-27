#include <iostream>
using namespace std;

class Primera{
    protected:
        int i,j;
    public: 
        Primera(){
            i=j=0;

        }
Primera(int a, int b){
    i=a,j=b;
}
void Entra_ij(int a, int b){
    i=a,j=b;
}
void Muestra_ij(void){
    cout<<"\nP"<<i<<"  "<<j;
}
};


class Segunda: public Primera{
    int k;
    public:
        void Entra_k(int a){
            k=a;
        }
        void Muestra_k(void){
            cout<<"\nS"<<k;
        }

};

class Tercera:public Segunda{
    public:
        void f(void){
            i=j=2;
            cout<<"\nT hola el valor "<<i<<" "<<j<<"\n";
        }
};

int main(void){
    Primera P(1,2);
    Segunda S;
    Tercera T;

    S.Entra_ij(3,4);        //Entrada de la clase primera
    S.Entra_k(5);           //Entrada de la clase segunda
    S.Entra_ij(8,8);            //Saca 3,4 de la clase primera
    P.Muestra_ij();             //Saca 1,2 de la clase segunda 
    
    S.Muestra_k();              //Saca 5 de la clase segunda 
    T.Muestra_ij();                 //Saca 2 2
    T.Entra_k(3);                   //Entrada de la clase segunda
    T.Muestra_k();                   //Saca 3
    S.Muestra_k();                     //Saca 5
    T.Entra_ij(5,6);
    T.Muestra_ij();                 //Saca 5,6
    P.Muestra_ij();                 //Saca 1,2

return 0;

}
