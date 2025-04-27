//Validacion por Dominio
//Este tipo de validación comprueba si el valor ingresado está dentro de un conjunto
//de valores válidos o permitidos.

#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
bool validarGenero(const string& genero) {
// Verifica si el valor ingresado está dentro del conjunto de valores válidos
return (genero == "Masculino" || genero == "Femenino" || genero == "Otro");
}
int main() {
setlocale(LC_ALL, "spanish");
string genero;
// Solicita al usuario que ingrese un género válido hasta que lo haga correctamente
do {
cout << "Ingrese su género (Masculino, Femenino, Otro): ";
cin >> genero;
if (!validarGenero(genero)) {
cout << "Entrada inválida. Por favor ingrese 'Masculino', 'Femenino' o 'Otro'." << endl;
}
} while (!validarGenero(genero));
// Muestra un mensaje de éxito si la entrada es válida
cout << "Género ingresado correctamente: " << genero << endl;
return 0;
}