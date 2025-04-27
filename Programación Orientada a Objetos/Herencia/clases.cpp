#include<iostream>
#include<conio.h>
using namespace std;

void imprimir(int a){
    cout<<a <<endl;
}

void imprimir(double a){
    cout<<a <<endl;
}

void imprimir(string a){
    cout<<a <<endl;
}

void imprimir(bool &a){
    cout<<a <<endl;
}
int main(int argc, char const *argv[])
{
    imprimir("10");
    imprimir("10.15");
    imprimir("Goodbye to a world");
    imprimir("true");
    return 0;
}
