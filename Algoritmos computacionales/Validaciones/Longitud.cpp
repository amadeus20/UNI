//Validacion por Longitud
//Esta validación asegura que la longitud del texto ingresado está dentro de los
//límites permitidos
#include <iostream>
using namespace std;
bool validarLongitud(const char* entrada, int min, int max) {
int longitud = 0;
for (int i = 0; entrada[i] != '\0'; ++i) { // el valor de fin de string o carro es \0
longitud++;
}
return longitud >= min && longitud <= max;
}
int main() {
char entrada[30];
int rango_inf;
int rango_sup;
cout<<"Rango inferior de longitud: ";
cin>>rango_inf;
cout<<endl<<"Rango superior de longitud: ";
cin>>rango_sup;
cout<<endl<<"Entrada: ";
cin>>entrada;
if (validarLongitud(entrada, 8, 16)) {
cout << "Longitud válida." << endl;
} else {
cout << "Longitud inválida." << endl;
}
return 0;
}