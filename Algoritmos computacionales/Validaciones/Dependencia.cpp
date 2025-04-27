//Validacion por Dependencia
//Se asegura que ciertos campos o datos dependan de otros y se llenen solo si se
//cumple una condición.
#include <iostream>
#include <string>
#include <locale.h> // Para habilitar el uso de acentos y ñ en la consola
using namespace std;
int main() {
setlocale(LC_ALL, "Spanish");
string estadoCivil;
string nombreConyuge;
cout << "Formulario de Registro" << endl;
cout << "Seleccione su estado civil (Soltero/Casado): ";
getline(cin, estadoCivil);
// Validación de dependencias basada en el estado civil
if (estadoCivil == "Casado" || estadoCivil == "casado") {
cout << "Ingrese el nombre de su cónyuge: ";
getline(cin, nombreConyuge);
} else if (estadoCivil == "Soltero" || estadoCivil == "soltero") {
cout << "No es necesario ingresar información del cónyuge." << endl;
} else {
cout << "Estado civil no reconocido. Por favor, ingrese 'Soltero' o 'Casado'." << endl;
return 1; // Finaliza el programa si el estado civil no es válido
}
// Mostrar los datos ingresados
cout << "\nRegistro completo:" << endl;
cout << "Estado civil: " << estadoCivil << endl;
if (!nombreConyuge.empty()) {
cout << "Nombre del cónyuge: " << nombreConyuge << endl;
}
return 0;
}