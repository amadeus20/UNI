#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <locale>

using namespace std;

// Variables globales
int* arreglo = nullptr;
int tam = 0;
bool archivoLeido = false;
bool archivoGrabado= false;
bool archivoOrdenado= false;

// Leer valores desde archivo
void leerArchivo() {
    if (archivoLeido) {
    cout << "Ya se leyo el archivo\n";
    return;
    }
    string nombre;
    cout << "Ingrese el nombre del archivo sin extension: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";
    ifstream archivo(nombre);
    if (!archivo) {
    cout << "No se pudo abrir el archivo.\n";
    return;
    }
    
    tam = 0;
    int valor;
    // Primero contamos cuántos elementos hay
    while (archivo >> valor) {
    tam++;
    }
    
    if (tam == 0) {
    cout << "El archivo está vacío.\n";
    return;
    }
    
    // Volver al inicio del archivo
    archivo.clear();
    archivo.seekg(0);
    
    // Reservar memoria y leer valores
    delete[] arreglo;
    arreglo = new int[tam];
    for (int i = 0; i < tam; i++) {
    archivo >> arreglo[i];
    }
    
    archivo.close();
    archivoLeido = true;
    archivoGrabado = false;
    archivoOrdenado = false;
    
    cout << "Archivo leído correctamente. Total de valores: " << tam << endl;
    }

// Mostrar arreglo
void mostrarArreglo() {
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    
    if (archivoGrabado) {
    cout << "Ya se grabo el archivo.\n";
    return;
    }
    
    for (int i = 0; i < tam; i++) {
    cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Ordenamiento burbuja
void burbuja() {
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "Ya se grabo el archivo.\n";
    return;
    }
    if (archivoOrdenado) {
    cout << "Ya se ordeno el archivo.\n";
    return;
    }
    bool cambio = true;
    for (int i = 0; i < tam - 1 && cambio; i++) {
    
    cambio = false;
    for (int j = 0; j < tam - i - 1; j++) {
    if (arreglo[j] > arreglo[j + 1]) {
    swap(arreglo[j], arreglo[j + 1]);
    cambio = true;
    }
    }
    }
    
    archivoOrdenado = true;
    cout << "Arreglo ordenado exitosamente(método burbuja).\n";
}

// Guardar en archivo
void guardarArchivo() {
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "Ya se grabo el archivo.\n";
    return;
    }
    string nombre;
    cout << "Ingrese el nombre del archivo para guardar (sin extension): ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";
    
    ofstream archivo(nombre);
    if (!archivo) {
    cout << "No se pudo crear el archivo.\n";
    return;
    }
    
    for (int i = 0; i < tam; i++) {
    archivo << arreglo[i] << " ";
    }
    archivoGrabado= true;
    archivo.close();
    cout << "Archivo guardado exitosamente como:" << nombre << endl;
}

//Salir del programa
void salir(){
    if (!archivoLeido) {
    cout << "Primero debe leer un archivo.\n";
    return;
    }
    if (!archivoGrabado) {
    cout << "No se a grabo el archivo.\n";
    return;
    }
    cout << "Saliendo del programa.\n";
}

// Menú principal
int main() {
    setlocale(LC_ALL, ""); // Permitir caracteres con acentos y ñ
    
    int opcion;
    
    do {
    cout << "\nMenu:\n";
    cout << "1. Leer archivo\n";
    cout << "2. Ordenar (burbuja)\n";
    cout << "3. Grabar archivo\n";
    cout << "4. Mostrar arreglo\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    
    switch (opcion) {
    case 1:
    leerArchivo();
    break;
    
    case 2:
    burbuja();
    break;
    case 3:
    guardarArchivo();
    break;
    case 4:
    mostrarArreglo();
    break;
    case 5:
    salir();
    break;
    default:
    cout << "Opción inválida. Intente de nuevo.\n";
    }
    } while (opcion != 5);
    delete[] arreglo;
    return 0;
    
}

