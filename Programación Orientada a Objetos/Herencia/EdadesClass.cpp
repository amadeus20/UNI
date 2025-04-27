#include<iostream>
using namespace std;

struct Persona{
    string nombre;
    int edad;
    double salario;
    void imprime()const;
    void cambiaEdad(int e)const;
};

int main(){
    Persona juan, pedro, maria;
    juan.nombre="Juan";
    juan.edad=20;
    juan.salario=500.00;
    pedro.nombre="Pedro";
    pedro.edad=30;
    pedro.salario=700.00;
    maria.nombre="Maria";
    maria.edad=35;
    maria.salario=500.00;

    juan.cambiaEdad(100);

    juan.imprime();
    pedro.imprime();
    maria.imprime();
    return 0;

}

void Persona::cambiaEdad()const{
    cout<<"Nombre: "<<nombre<<end;
    cout<<"Edad: "<<edad<<end;
    cout<<"Salario: "<<salario<<end;
}
