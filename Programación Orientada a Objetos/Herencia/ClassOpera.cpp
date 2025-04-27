//Herencia regulada, operaciones 
#include <iostream>
using namespace std;

class Operacion{
    protected:
        int valor1;
        int valor2;
        int resultado;
    public:
        void cargar1();
        void cargar2();
        void mostrarR();
};

class Suma:public Operacion{
    public:
        void operar();

};

class Resta:public Operacion{
    public:
        void operar();

};

class Multi:public Operacion{
    public:
        void operar();

};

class Div:public Operacion{
    public:
        void operar();

};

///------------------------------------

void Operacion::cargar1(){
    cout<<"Ingrese primer valor: ";
    cin>>valor1;

}
void Operacion::cargar2(){
    cout<<"Ingrese segundo valor: ";
    cin>>valor2;
    
}
void Operacion::mostrarR(){
    cout<<resultado<<"\n";
    
}
///----------------------------------------------
void Suma::operar(){
    resultado=valor1+valor2;
}
void Resta::operar(){
    resultado=valor1-valor2;
}
void Multi::operar(){
    resultado=valor1*valor2;
}
void Div::operar(){
    resultado=valor1/valor2;
}

int main(){
    Suma suma1;
    suma1.cargar1();
    suma1.cargar2();
    suma1.operar();
    cout<<"La suma de los dos valores es: ";
    suma1.mostrarR();
    cout<<endl;

    Resta resta1;
    resta1.cargar1();
    resta1.cargar2();
    resta1.operar();
    cout<<"La resta de los dos valores es: ";
    resta1.mostrarR();
    cout<<endl;

    Multi multi1;
    multi1.cargar1();
    multi1.cargar2();
    multi1.operar();
    cout<<"La multiplicacion de los dos valores es: ";
    multi1.mostrarR();
    cout<<endl;

    Div div1;
    div1.cargar1();
    div1.cargar2();
    div1.operar();
    cout<<"La divicion de los dos valores es: ";
    div1.mostrarR();  

    cout<<endl;

    cout<<"Gracias por tu participacion"<<endl;

    return 0;



}