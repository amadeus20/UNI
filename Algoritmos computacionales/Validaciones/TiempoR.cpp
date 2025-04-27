//Validacion en tiempo
//Se realiza mientras el usuario ingresa los datos, brindando retroalimentación
//inmediata sobre los errores. Es común en formularios web modernos.
#include <iostream>
#include <regex>
#include <string>
#include <conio.h> // Para _getch() (requiere Windows) o usa std::cin si no está disponible
#include <locale.h>
using namespace std;
// Función para validar el formato del correo electrónico
bool esCorreoValido(const string& correo) {
regex patronCorreo("^[\\w\\.]+@[\\w\\.]+\\.[a-z]{2,3}$", regex::icase); // Patrón básico para correo
return regex_match(correo, patronCorreo);
}
int main() {
setlocale(LC_ALL,"spanish");
string correo;
char caracter;
cout << "Ingrese su correo electrónico (validación en tiempo real):" << endl;
// Validación en tiempo real del correo electrónico
while (true) {
caracter = _getch(); // Obtiene un carácter sin necesidad de presionar Enter
if (caracter == '\r') { // Finaliza la entrada si se presiona Enter
break;
} else if (caracter == '\b') { // Retroceso
if (!correo.empty()) {
correo.pop_back(); // Elimina el último carácter de la cadena
}
} else {
correo += caracter; // Agrega el nuevo carácter a la cadena
}
// Validación en tiempo real
system("CLS"); // Limpia la pantalla (requiere Windows)
cout << "Ingrese su correo electrónico (validación en tiempo real):" << endl;
cout << correo << endl;
if (esCorreoValido(correo)) {
cout << "Formato de correo válido hasta ahora." << endl;
} else {
cout << "Formato de correo incorrecto." << endl;
}
}
// Validación final después de presionar Enter
if (esCorreoValido(correo)) {
cout << "\nCorreo válido: " << correo << endl;
} else {
cout << "\nError: El correo ingresado no tiene el formato correcto." << endl;
}
return 0;
}