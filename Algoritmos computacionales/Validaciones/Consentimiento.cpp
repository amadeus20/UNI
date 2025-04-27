//Validacion por Consentimiento
//Se usa para verificar que el usuario otorgue un consentimiento explícito antes de
//proceder con ciertas acciones, como el uso de sus datos personales.
#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
int main() {
setlocale(LC_ALL,"spanish");
char consentimiento;
cout << "Bienvenido al sistema de suscripción." << endl;
cout << "Para continuar, por favor lea y acepte los términos y condiciones." << endl;
cout << "\n¿Acepta los términos y condiciones? (s/n): ";
// Solicitar el consentimiento explícito del usuario
cin >> consentimiento;
// Validación de consentimiento
if (consentimiento == 's' || consentimiento == 'S') {
cout << "\nGracias por aceptar los términos y condiciones." << endl;
cout << "Procediendo con su suscripción..." << endl;
// Aquí se colocaría el código para procesar la suscripción
} else if (consentimiento == 'n' || consentimiento == 'N') {
cout << "\nNo ha aceptado los términos y condiciones. No se puede proceder con la suscripción." << endl;
} else {
cout << "\nEntrada inválida. Por favor, ingrese 's' para aceptar o 'n' para rechazar." << endl;
}
return 0;
}