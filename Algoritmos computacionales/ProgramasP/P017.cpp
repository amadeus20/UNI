#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

// Variables globales
int* arreglo = nullptr;
int tam = 0;
bool archivoLeido = false;
bool archivoOrdenado = false;
bool archivoGrabado = false;
// Función auxiliar para mantener la propiedad del heap
void heapify(int arr[], int n, int i) {
int mayor = i; // Inicialmente seasume que el nodo actual es el mayor
int izquierda = 2 * i + 1; // Hijo izquierdo
int derecha = 2 * i + 2; // Hijo derecho

// Comparar hijo izquierdo con el nodoctual
if (izquierda < n && arr[izquierda] >
arr[mayor]) {
mayor = izquierda;
}

// Comparar hijo derecho con el mayor hasta ahora
if (derecha < n && arr[derecha] >
arr[mayor]) {
mayor = derecha;
}

// Si el mayor no es el nodo actual,intercambiar y aplicar heapifyrecursivamente
if (mayor != i) {
swap(arr[i], arr[mayor]);
heapify(arr, n, mayor);
}
}

// Función principal para realizar el ordenamiento heap sort
void heapSort(int arr[], int n) {
    // Construcción del heap (reorganización del arreglo)
    for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
    }
    
    // Extraer uno por uno los elementos del heap
    for (int i = n - 1; i > 0; i--) {
    // Mover el elemento raíz al final
    swap(arr[0], arr[i]);
    // Llamar heapify sobre el heap reducido
    heapify(arr, i, 0);
    }
}

// función principal
void leerArchivo();
void mostrarArreglo();
void ordenarHeapSort();
void guardarArchivo();
bool salir();
int main() {
setlocale(LC_ALL, "");
int opcion;
bool continuar = true;

do {
cout << "\nMenú:\n";
cout << "1. Leer archivo\n";
cout << "2. Ordenar (heap sort)\n";
cout << "3. Grabar archivo\n";
cout << "4. Mostrar arreglo\n";
cout << "5. Salir\n";
cout << "Seleccione una opción: ";
cin >> opcion;
switch (opcion) {

case 1:
leerArchivo();
break;
case 2:
ordenarHeapSort();
break;
case 3:
guardarArchivo();
break;
case 4:
mostrarArreglo();
break;
case 5:
continuar = !salir();
break;
default: cout << "Opción inválida. Intente de nuevo.\n";
}
} while (continuar);

return 0;
}

// Implementación de las funcion leer
void leerArchivo() {
    if (archivoLeido) {
    cout << "El archivo ya ha sido leído.\n";
    return;
    }
    
    string nombre;
    cout << "Ingrese el nombre del archivo sin extensión: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";
    
    ifstream archivo(nombre);
    if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo.\n";
    return;
    }
    
    int valor;
    tam = 0;
    
    while (archivo >> valor) tam++;
    if (tam == 0) {
    cout << "El archivo está vacío.\n";
    archivo.close();
    return;
    }
    
    archivo.clear(); archivo.seekg(0);
    delete[] arreglo;
    arreglo = new int[tam];
    for (int i = 0; i < tam; i++) archivo >> arreglo[i];
    
    archivo.close();
    archivoLeido = true;
    archivoOrdenado = false;
    archivoGrabado = false;
    cout << "Archivo leído correctamente. Total de valores: " << tam << endl;
}

void mostrarArreglo() {
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya ha sido grabado.\n";
    return;
    }
    
    cout << "Contenido del arreglo: ";
    for (int i = 0; i < tam; i++) cout << arreglo[i] << " ";
    cout << endl;
}

void ordenarHeapSort() {
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya ha sido grabado.\n";
    return;
    }
    if (archivoOrdenado) {
    cout << "El arreglo ya ha sido ordenado.\n";
    return;
    }
    
    heapSort(arreglo, tam);
    archivoOrdenado = true;
    cout << "Ordenamiento por heap sort completado exitosamente.\n";
}

bool salir() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo antes de salir.\n";
    return false;
    }
    if (!archivoGrabado) {
    cout << "Debe grabar el archivo antes de salir.\n";
    return false;
    }
    delete[] arreglo;
    cout << "Gracias por usar este programa creado por mí.\n";
    return true;
}

// Guardar en archivo
void guardarArchivo() {
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya ha sido grabado.\n";
    return;
    }
    
    string nombre;
    cout << "Ingrese el nombre del archivo sin extensión: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";
    
    ofstream archivo(nombre);
    if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo para grabar.\n";
    return;
    }
}
