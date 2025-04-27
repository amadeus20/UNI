//Validacion por Patron
//Usada para campos donde se necesita que el formato de entrada coincida con un
//patrón específico definido por una expresión regular.
#include <iostream>
#include <regex> // Para el uso de expresiones regulares
#include <string>
#include <locale.h>
using namespace std;
int main() {
setlocale(LC_ALL, "spanish");
string codigoPostal;
regex patronCodigoPostal("^[0-9]{5}$"); // Expresión regular para validar un código postal de 5 dígitos
cout << "Ingrese el código postal (5 dígitos): ";
getline(cin, codigoPostal);
// Validación del código postal usando regex
if (regex_match(codigoPostal, patronCodigoPostal)) {
cout << "El código postal ingresado es válido." << endl;
} else {
cout << "Error: El código postal debe contener exactamente 5 dígitos o ser númerico" << endl;
}
return 0;
}