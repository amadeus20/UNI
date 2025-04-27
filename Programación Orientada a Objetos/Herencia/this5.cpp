#include<iostream>
using namespace std;

class personaje
{
private:
    int ataque;
    int defensa;
public:
    personaje(int a, int d){
        ataque = a;
        defensa = d;
    }
    
    void imprimir(){
        cout<<" ataque : "<<ataque<<"\n";
        cout<<" this-> ataque : "<<this->ataque<<"\n";
        cout<<" ()ataque : "<<(*this).ataque<<"\n";
    }
    personaje &setAtaque(int a){
        ataque = a;
        return *this;
    }
    personaje &setDefensa(int d){
        defensa = d;
        return *this;
    }

    void imprimirDatos(){
        cout<<" ataque : "<<ataque<<"\n";
        cout<<" Defensa : "<<defensa<<"\n";
    }
};

int main(int argc, char const *argv[])
{
    personaje alucard(100,90);
    alucard.imprimir();
    alucard.setAtaque(50);
    alucard.setDefensa(40);
    alucard.imprimirDatos();
    return 0;
}
