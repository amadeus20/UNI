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
bool archivoOrdenado = false;
bool archivoGrabado = false;

// Leer archivo y llenar el arreglo
void leerArchivo() {
    if (archivoLeido) {
    cout << "El archivo ya fue leído.\n";
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
    
    tam = 0;
    int valor;
    while (archivo >> valor) {
    tam++;
    }
    
    if (tam == 0) {
    cout << "El archivo está vacío.\n";
    archivo.close();
    return;
    }
    
    archivo.clear();
    archivo.seekg(0);
    
    delete[] arreglo;
    arreglo = new int[tam];
    for (int i = 0; i < tam; i++) {
    archivo >> arreglo[i];
    }
    
    archivo.close();
    archivoLeido = true;
    archivoOrdenado = false;
    archivoGrabado = false;
    
    cout << "Archivo leído correctamente. Total de valores: " << tam << "\n";
}

// Mostrar el contenido del arreglo
void mostrarArreglo() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo primero.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya fue grabado.\n";
    return;
    }
    
    cout << "Contenido del arreglo: ";
    for (int i = 0; i < tam; i++) {
    cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Ordenamiento por selección
void ordenamientoSeleccion() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo primero.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya fue grabado.\n";
    return;
    }
    if (archivoOrdenado) {
    cout << "El arreglo ya está ordenado.\n";
    return;
    }
    
    for (int i = 0; i < tam - 1; i++) {
    
    int min = i;
    for (int j = i + 1; j < tam; j++) {
    if (arreglo[j] < arreglo[min]) {
    min = j;
    }
    }
    int aux = arreglo[min];
    arreglo[min] = arreglo[i];
    arreglo[i] = aux;
    }
    
    archivoOrdenado = true;
    cout << "Ordenamiento por selección completado.\n";
}

// Guardar el arreglo en un archivo
void guardarArchivo() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo primero.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya fue grabado.\n";
    return;
    }
    
    string nombre;
    cout << "Ingrese el nombre del archivo para guardar (sin extensión): ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";
    
    ofstream archivo(nombre);
    if (!archivo.is_open()) {
    cout << "No se pudo crear el archivo.\n";
    return;
    }
    
    for (int i = 0; i < tam; i++) {
    archivo << arreglo[i] << " "<<endl;
    }
    
    archivo.close();
    archivoGrabado = true;
    cout << "Archivo grabado exitosamente como: " << nombre <<
    endl;
}

// Salir del programa
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

// Menú principal
int main() {
    setlocale(LC_ALL, ""); // Permitir caracteres con acentos y ñ
    int opcion;
    bool continuar = true;
    do {
    cout << "\nMenu:\n";
    cout << "1. Leer archivo\n";
    cout << "2. Ordenar (seleccion)\n";
    cout << "3. Grabar archivo\n";
    cout << "4. Mostrar arreglo\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
    leerArchivo();
    system ("pause");
    system("cls");
    break;
    
    case 2:
    ordenamientoSeleccion();
    system ("pause");
    system("cls");
    break;
    case 3:
    guardarArchivo();
    system ("pause");
    system("cls");
    break;
    case 4:
    mostrarArreglo();
    system ("pause");
    system("cls");
    break;
    case 5:
    continuar = !salir();
    system ("pause");
    system("cls");
    break;
    default: cout << "Opcion invalida. Intente de nuevo.\n";
    }
    } while (continuar);
    return 0;
}

