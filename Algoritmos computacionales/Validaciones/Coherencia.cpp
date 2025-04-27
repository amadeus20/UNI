//Validacion por Coherencia
//Asegura que los datos ingresados tengan sentido lógico en relación con otros datos.

#include <iostream>
#include <limits> // Para std::numeric_limits
#include <locale.h>
using namespace std;
// Función para validar que la edad sea coherente
bool esEdadValida(int edad) {
if (edad < 0 || edad > 150) {
cout << "Error: La edad ingresada (" << edad << ") no es coherente. Debe estar entre 0 y 150 años." << endl;
return false;
}
return true;
}
int main() {
setlocale(LC_ALL, "spanish");
int edad;
// Solicita la edad y valida que sea coherente
do {
cout << "Ingrese su edad: ";
cin >> edad;
// Valida la entrada para evitar errores en caso de entrada no numérica
if (cin.fail()) {
cout << "Error: Ingrese un número válido para la edad." << endl;
cin.clear(); // Limpia el estado de error de cin
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada incorrecta
edad = -1; // Asigna un valor inválido temporal para forzar el bucle
} else if (!esEdadValida(edad)) {
edad = -1; // Fuerza el bucle si la edad es incoherente
}
} while (edad < 0);
// Mensaje de éxito si la edad es válida
cout << "\nEdad ingresada correctamente: " << edad << " años." << endl;
return 0;
}