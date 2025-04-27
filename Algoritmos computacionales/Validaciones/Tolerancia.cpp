//Validacion por Tolerancia 
//Esta validación permite establecer márgenes de error o tolerancia en los datos
//ingresados para aceptar ciertas desviaciones, por ejemplo, en campos de entrada
//numérica.

#include <iostream>
#include <cmath> // Para std::abs
#include <locale.h>
using namespace std;
bool validarTolerancia(float valorIngresado, float valorEsperado, float tolerancia) {
// Verifica si el valor ingresado está dentro del rango de tolerancia
return abs(valorIngresado - valorEsperado) <= tolerancia;
}
int main() {
setlocale(LC_ALL, "spanish");
float temperaturaObjetivo = 37.5; // Valor exacto esperado, por ejemplo, temperatura promedio del cuerpo
float tolerancia = 0.5; // Rango de tolerancia de ±0.5 grados
float temperaturaIngresada;
cout << "Validación de temperatura con tolerancia de ±" << tolerancia << " grados" << endl;
cout << "Temperatura objetivo: " << temperaturaObjetivo << " grados" << endl;
cout << "Ingrese la temperatura medida: ";
cin >> temperaturaIngresada;
// Validación de la temperatura con tolerancia
if (validarTolerancia(temperaturaIngresada, temperaturaObjetivo, tolerancia)) {
cout << "La temperatura ingresada " << temperaturaIngresada << " está dentro del rango de tolerancia." << endl;
} else {
cout << "La temperatura ingresada " << temperaturaIngresada << " está fuera del rango de tolerancia." << endl;
}
return 0;
}