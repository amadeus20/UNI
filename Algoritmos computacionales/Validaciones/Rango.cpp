//Validacion por Rango
//La validación de rango asegura que los valores ingresados caen dentro de un rango
//específico de valores.
#include <iostream>
using namespace std;
bool validarRango(int valor, int minimo, int maximo) {
return valor >= minimo && valor <= maximo;
}
int main() {
int valor;
int rango_inf;
int rango_sup;
cout<<"Rango inferior: ";
cin>>rango_inf;
cout<<endl<<"Rango superior: ";
cin>>rango_sup;
cout<<endl<<"Valor: ";
cin>>valor;
if (validarRango(valor, rango_inf, rango_sup)) {
cout << "Valor dentro del rango." << endl;
} else {
cout << "Valor fuera del rango." << endl;
}
return 0;
}