#include<iostream>
using namespace std;

class fraccion
{
private:
    int numerador;
    int denominador;
    int MCD(int, int);
public:
    fraccion(int n=0, int d=0): numerador(n), denominador(d){
        Simplificar();
    }
    void Simplificar();
    void Mostrar();
};

void fraccion::Simplificar()
{
    int mcd=MCD(numerador, denominador);
    numerador /= mcd;
    denominador /= mcd;
}

void fraccion::Mostrar()
{
    cout<<numerador<<"/"<<denominador<<endl;
}

void fraccion::MCD(int a, int b)
{
    if(a<b) return MCD(b,a);
    if(b==0) return a;
}
