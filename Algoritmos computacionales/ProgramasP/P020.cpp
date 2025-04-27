#include <iostream>
using namespace std;
// Función que intercambia los valores de dos variables usando apuntadores
void intercambiar(int* a, int* b) {
// Se muestra lo que se recibe como dirección
cout << "\n[intercambiar] Dirección de a: " << a << ", valor: " << *a << endl;
cout << "[intercambiar] Dirección de b: " << b << ", valor: " << *b << endl;
int temp = *a; // Se guarda el valor apuntado por a
*a = *b; // Se copia el valor apuntado por b en la dirección apuntada por a
*b = temp; // Se copia el valor guardado en temp a la dirección apuntada por b
cout << "[intercambiar] Valores intercambiados dentro de la función." << endl;
}
// Función que eleva al cuadrado un número usando apuntador
void elevarAlCuadrado(int* numero) {
*numero = (*numero) * (*numero); // Se modifica directamente el valor apuntado
}

int main() {
    setlocale(LC_ALL, ""); // Para mostrar acentos correctamente
    int x = 5;
    int y = 10;
    cout << "Valores iniciales:\n";
    cout << "x = " << x << ", y = " << y << endl;
    // Se llama a la función con las direcciones de x e y
    intercambiar(&x, &y);
    cout << "\nValores después de llamar a intercambiar:\n";
    cout << "x = " << x << ", y = " << y << endl;
    // Elevar x al cuadrado
    elevarAlCuadrado(&x);
    cout << "\nx elevado al cuadrado: " << x << endl;
    // Elevar y al cuadrado
    elevarAlCuadrado(&y);
    cout << "y elevado al cuadrado: " << y << endl;
    return 0;
}