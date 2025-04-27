//Validacion por Unicidad
//Asegura que el dato ingresado no se repita en la base de datos o en un contexto
//donde debe ser único.

#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
using namespace std;
// Función para verificar si el nombre de usuario ya está registrado
bool esUnico(const string& nombreUsuario, const vector<string>& usuariosRegistrados) {
for (const string& usuario : usuariosRegistrados) {
if (usuario == nombreUsuario) {
return false; // El nombre de usuario ya existe
}
}
return true; // El nombre de usuario es único
}
int main() {
setlocale(LC_ALL,"spanish");
vector<string> usuariosRegistrados;
string nombreUsuario;
char opcion;
cout << "Sistema de Registro de Usuarios Únicos" << endl;
do {
cout << "Ingrese un nombre de usuario: ";
cin >> nombreUsuario;
// Validación de unicidad
if (esUnico(nombreUsuario, usuariosRegistrados)) {
usuariosRegistrados.push_back(nombreUsuario);
cout << "Usuario registrado correctamente: " << nombreUsuario << endl;
} else {
cout << "Error: El nombre de usuario '" << nombreUsuario << "' ya está registrado. Intente con otro." << endl;
}
cout << "¿Desea registrar otro usuario? (s/n): ";
cin >> opcion;
} while (opcion == 's' || opcion == 'S');
// Muestra la lista de usuarios registrados
cout << "\nLista de usuarios registrados:" << endl;
for (const string& usuario : usuariosRegistrados) {
cout << usuario << endl;
}
return 0;
}