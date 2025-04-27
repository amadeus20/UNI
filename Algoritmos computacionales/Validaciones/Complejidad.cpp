//Validacion por Complejidad (contaseñas)
//Comúnmente usada en contraseñas, esta validación verifica que el valor ingresado
//cumpla con ciertos criterios de seguridad

#include <iostream>
#include <string>
#include <cctype> // Para std::isdigit y std::isupper
#include <locale.h>
using namespace std;
// Función para validar la complejidad de la contraseña
bool validarComplejidad(const string& contrasena) {
bool tieneMayuscula = false;
bool tieneNumero = false;
bool tieneCaracterEspecial = false;
// Verificar la longitud mínima de la contraseña
if (contrasena.length() < 8) {
cout << "Error: La contraseña debe tener al menos 8 caracteres." << endl;
return false;
}
// Recorrer la contraseña para verificar los requisitos de complejidad
for (char c : contrasena) {
if (isupper(c)) tieneMayuscula = true; // Verificar si tiene mayúsculas
if (isdigit(c)) tieneNumero = true; // Verificar si tiene números
if (ispunct(c)) tieneCaracterEspecial = true; // Verificar si tiene caracteres especiales
}
// Verificar si cumple con todos los criterios
if (!tieneMayuscula) {
cout << "Error: La contraseña debe contener al menos una letra mayúscula." << endl;
}
if (!tieneNumero) {
cout << "Error: La contraseña debe contener al menos un número." << endl;
}
if (!tieneCaracterEspecial) {
cout << "Error: La contraseña debe contener al menos un carácter especial." << endl;
}
// Retornar true si cumple con todos los criterios de complejidad
return tieneMayuscula && tieneNumero && tieneCaracterEspecial;
}
int main() {
setlocale(LC_ALL, "spanish");
string contrasena;
string sigue;
cout<< "Longitud mínima: Al menos 8 caracteres"<<endl;
cout<< "Mayúsculas: Al menos una letra mayúscula"<<endl;
cout<< "Números: Al menos un número"<<endl;
cout<< "Carácter especial: Al menos un carácter especial (como !, @, #, etc.)"<<endl;
do {
cout << "Ingrese una contraseña: ";
//getline(cin, contrasena);
cin>> contrasena;
// Validación de la complejidad de la contraseña
if (validarComplejidad(contrasena)) {
cout << "Contraseña válida y segura." << endl;
} else {
cout << "Contraseña no cumple con los requisitos de seguridad." << endl;
}
cout<<"Quiere validar otra contraseña (S o N)?";
cin>>sigue;
} while (sigue == "S" || sigue == "s");
return 0;
}