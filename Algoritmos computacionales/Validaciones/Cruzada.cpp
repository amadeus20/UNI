//Validacion Cruzada o Relacional
//Se asegura que los valores de varios campos relacionados sean consistentes entre
//sí.
#include <iostream>
#include <locale.h>
using namespace std;
// Estructura para representar una fecha
struct Fecha {
int dia;
int mes;
int anio;
};
// Función para validar que la fecha ingresada es correcta
bool validarFecha(const Fecha& fecha) {
if (fecha.anio < 1) {
cout << "Año inválido. Debe ser mayor que 0." << endl;
return false;
}
if (fecha.mes < 1 || fecha.mes > 12) {
cout << "Mes inválido. Debe estar entre 1 y 12." << endl;
return false;
}
// Determinar el número de días del mes
int diasMes;
if (fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) {
diasMes = 30;
} else if (fecha.mes == 2) {
// Verificación de año bisiesto para febrero
if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0)) {
diasMes = 29; // Año bisiesto
} else {
diasMes = 28;
}
} else {
diasMes = 31;
}
if (fecha.dia < 1 || fecha.dia > diasMes) {
cout << "Día inválido para el mes y año ingresados." << endl;
return false;
}
return true;
}
// Función para validar si la fecha de fin es posterior a la fecha de inicio
bool esFechaPosterior(const Fecha& inicio, const Fecha& fin) {
if (fin.anio > inicio.anio) {
return true;
} else if (fin.anio == inicio.anio) {
if (fin.mes > inicio.mes) {
return true;
} else if (fin.mes == inicio.mes) {
if (fin.dia > inicio.dia) {
return true;
}
}
}
return false; // La fecha de fin no es posterior a la de inicio
}
int main() {
setlocale(LC_ALL, "spanish");
Fecha inicio, fin;
cout << "Ingrese la fecha de inicio:" << endl;
do {
cout << "Día: ";
cin >> inicio.dia;
cout << "Mes: ";
cin >> inicio.mes;
cout << "Año: ";
cin >> inicio.anio;
} while (!validarFecha(inicio)); // Repite hasta que la fecha sea válida
cout << "\nIngrese la fecha de fin:" << endl;
do {
cout << "Día: ";
cin >> fin.dia;
cout << "Mes: ";
cin >> fin.mes;
cout << "Año: ";
cin >> fin.anio;
} while (!validarFecha(fin)); // Repite hasta que la fecha sea válida
// Validación cruzada de fechas
if (esFechaPosterior(inicio, fin)) {
cout << "\nLa fecha de fin es válida y posterior a la fecha de inicio." << endl;
} else {
cout << "\nError: La fecha de fin debe ser posterior a la fecha de inicio." << endl;
}
return 0;
}