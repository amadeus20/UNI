#include <iostream>
using namespace std;
int main() {
setlocale(LC_ALL, ""); // Permite acentos y ñ en consola
// 1. Declaración de una variable entera
int numero = 42;
cout << "Declaración de variable entera con valor de " << numero << endl;
// 2. Declaración de un apuntador a entero (inicializado como nullptr por seguridad)
int* ptr = nullptr;
// 3. Asignación de la dirección de 'numero' al apuntador 'ptr'
ptr = &numero;
// 4. Mostrar la dirección de memoria almacenada en el apuntador
cout << "Dirección almacenada en ptr (&numero): " << ptr << endl;
// 5. Mostrar el valor almacenado en la variable 'numero' usando el apuntador
cout << "Valor apuntado por ptr (*ptr): " << *ptr << endl;
// 6. Modificar el valor de 'numero' usando el apuntador
*ptr = 100;
// 7. Mostrar el nuevo valor de 'numero' después de modificarlo a través del apuntador
cout << "Nuevo valor de numero (modificado con *ptr): " << numero <<
endl;
// 8. Reservar memoria dinámica para un entero usando new
int* ptr_dinamico = new int;

// 9. Asignar valor al entero creado dinámicamente
*ptr_dinamico = 55;
// 10. Mostrar el valor y la dirección de memoria del entero dinámico
cout << "Valor en memoria dinámica: " << *ptr_dinamico << endl;
cout << "Dirección de memoria dinámica: " << ptr_dinamico << endl;
// 11. Liberar la memoria reservada dinámicamente
delete ptr_dinamico;
// 12. Prevenir errores posteriores (colgantes) asignando nullptr
ptr_dinamico = nullptr;
// 13. Arreglo de enteros y apuntadores a su inicio
int arreglo[3] = {10, 20, 30};
int* parreglo = arreglo; // No se usa & porque el nombre del arreglo ya
representa su dirección
// 14. Recorrer el arreglo usando el apuntador
cout << "Recorriendo arreglo con apuntadores:" << endl;
for (int i = 0; i < 3; i++) {
cout << "Elemento " << i << ": " << *(parreglo + i) << endl;
}
return 0;
}