//Validacion por Existencia
//Esta validación asegura que ciertos campos obligatorios no queden vacíos y que se
//proporcionen los datos necesarios.
#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
// Función para validar que un campo no esté vacío
bool campoNoVacio(const string& campo, const string& valor) {
if (valor.empty()) {
cout << "Error: El campo '" << campo << "' es obligatorio y no puede estar vacío." << endl;
return false;
}
return true;
}
int main() {
setlocale(LC_ALL, "spanish");
string nombre, correo;
// Solicita el nombre y valida que no esté vacío
do {
cout << "Ingrese su nombre: ";
getline(cin, nombre);
} while (!campoNoVacio("nombre", nombre));
// Solicita el correo y valida que no esté vacío
do {
cout << "Ingrese su correo electrónico: ";
getline(cin, correo);
} while (!campoNoVacio("correo electrónico", correo));
// Si ambos campos son válidos, muestra un mensaje de éxito
cout << "\nRegistro exitoso." << endl;
cout << "Nombre: " << nombre << endl;
cout << "Correo electrónico: " << correo << endl;
return 0;
}