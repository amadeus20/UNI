#include<iostream>
using namespace std;

class Prueba
{
private:
    int x;
public:
    explicit Prueba(int = 0);
    void imprimir() const;
};

Prueba::Prueba(int valor):x(valor)
{
}

void Prueba::imprimir() const
{
    cout<<endl;
    cout<<"         x = "<<x;
    cout<<"\n this-> x = "<<this->x;
    cout<<"\n (*this).x = "<<(*this).x<<endl;
}

int main(int argc, char const *argv[])
{
    Prueba objetoprueba(12);
    objetoprueba.imprimir();
    return 0;
}
