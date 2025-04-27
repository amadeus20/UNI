#include<iostream>
#include<conio.h>
using namespace std;

template <typename tipo> class contenedor{
public:
    tipo obtiene(int pos){
        return arreglo[pos];
    }
    void establece(tipo valor, int pos){
        arreglo[pos]=valor;
    }
    void imprime() const;
private:
    tipo arreglo[5];
};

template<typename tipo> void contenedor<tipo>::imprime() const{
    for (int i = 0; i < 5; i++)
    {
        cout<<"\tEl elemento ["<<i<<"]"<<" es "<<arreglo[i]<<endl;
        cout<<endl;
    }
    
}
int main(int argc, char const *argv[])
{
    contenedor<int> c1;
    contenedor<float> c2;
    contenedor<double> c3;


    c1.establece(1,0);
    c1.establece(50,1);
    c1.establece(-23,2);
    c1.establece(600,3);
    c1.establece(1000,4);

    c2.establece(2.3f,0);
    c2.establece(9.4f,1);
    c2.establece(10.25f,2);
    c2.establece(-100.01f,3);
    c2.establece(20.01f,4);

    c3.establece(1,0);
    c3.establece(100.45,1);
    c3.establece(-20000,2);
    c3.establece(1000000,3);
    c3.establece(3001.0,4);

    c1.imprime();
    c2.imprime();
    c3.imprime();
    return 0;
}
