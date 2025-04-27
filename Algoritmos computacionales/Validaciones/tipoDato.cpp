//Validación por tipo de dato
//Esta validación asegura que los datos ingresados corresponden al tipo esperado
#include <iostream>
#include <ctype.h>
using namespace std;
bool esEntero(const char* entrada) {
for (int i = 0; entrada[i] != '\0'; ++i) { // el valor de fin de string o carro es \0
if (!isdigit(entrada[i])) {
return false;
}
}
return true;
}
int main() {
char entrada[9];
cout<<"Valor de entrada: ";
cin>>entrada;
if (esEntero(entrada)) {
cout << "Es un entero válido." << endl;
} else {
cout << "No es un entero válido." << endl;
}
return 0;
}