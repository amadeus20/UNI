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

// Funciones para Quick Sort
int particion(int arr[], int inicio, int fin)
{
int pivote = arr[fin];
int i = inicio - 1;

for (int j = inicio; j < fin; j++) {
if (arr[j] <= pivote) {
i++;
swap(arr[i], arr[j]);
}
}

swap(arr[i + 1], arr[fin]);
return i + 1;
}

void quickSort(int arr[], int inicio, int fin) {
if (inicio < fin) {
int pi = particion(arr, inicio, fin);
quickSort(arr, inicio, pi - 1);
quickSort(arr, pi + 1, fin);
}
}

// Leer archivo de texto
void leerArchivo() {
    if (archivoLeido) {
    cout << "Ya se ha leído un archivo anteriormente.\n";
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
    while (archivo >> valor) tam++;
    
    if (tam == 0) {
    cout << "El archivo está vacío.\n";
    archivo.close();
    return;
    }
    archivo.clear();
    archivo.seekg(0);
    delete[] arreglo;
    arreglo = new int[tam];
    for (int i = 0; i < tam; i++) archivo >> arreglo[i];
    archivo.close();
    archivoLeido = true;
    archivoOrdenado = false;
    archivoGrabado = false;
    cout << "Archivo leído correctamente. Total de elementos: " << tam << endl;
    }

// Mostrar arreglo
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
    for (int i = 0; i < tam; i++) cout << arreglo[i] << " ";
    cout << endl;
}

// Ordenamiento Quick Sort
void ordenarQuickSort() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo antes de ordenar.\n";
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
    
    quickSort(arreglo, 0, tam - 1);
    archivoOrdenado = true;
    cout << "Ordenamiento Quick Sort realizado exitosamente.\n";
}

// Guardar en archivo
void guardarArchivo() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo antes de grabar.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya fue grabado.\n";
    return;
    }
    
    string nombre;
    cout << "Ingrese el nombre del archivo para guardar (sin extension): ";
    cin >> ws;
    getline(cin, nombre);
    
    nombre += ".txt";
    
    ofstream archivo(nombre);
    if (!archivo.is_open()) {
    cout << "No se pudo crear el archivo.\n";
    return;
    }
    
    for (int i = 0; i < tam; i++) archivo << arreglo[i] << " ";
    
    archivo.close();
    archivoGrabado = true;
    cout << "Archivo grabado exitosamente como: " <<
    nombre << endl;
}

// Salida segura
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
    cout << "Gracias por usar este programa creado por mi.\n";
    return true;
}

// Menú principal
int main() {
    setlocale(LC_ALL, "");
    int opcion;
    bool continuar = true;
    
    do {
    cout << "\nMenu:\n";
    cout << "1. Leer archivo\n";
    cout << "2. Ordenar (Quick Sort)\n";
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
    ordenarQuickSort();
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
    default:
    cout << "Opcion invalida. Intente de nuevo.\n";
    }
    } while (continuar);
    
    return 0;
}



