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

// Funciones para Merge Sort
void merge(int arr[], int inicio, int medio, int fin) {
    // Calcular tamaños de los subarreglos
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    
    // Crear arreglos temporales para izquierda y derecha
    int* izquierda = new int[n1];
    int* derecha = new int[n2];
    
    // Copiar los datos correspondientes a los subarreglos
    for (int i = 0; i < n1; i++) izquierda[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++) derecha[j] = arr[medio + 1 + j];
    
    // Mezclar los subarreglos en orden
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
    if (izquierda[i] <= derecha[j]) arr[k++] = izquierda[i++];
    else arr[k++] = derecha[j++];
    }
    
    // Copiar los elementos restantes, si hay
    while (i < n1) arr[k++] = izquierda[i++];
    while (j < n2) arr[k++] = derecha[j++];
    
    // Liberar memoria dinámica
    delete[] izquierda;
    delete[] derecha;
    }
    
    void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
    // Calcular punto medio evitando desbordamientos
    int medio = inicio + (fin - inicio) / 2;
    // Llamadas recursivas para ordenar cada mitad
    mergeSort(arr, inicio, medio);
    mergeSort(arr, medio + 1, fin);
    // Mezclar las mitades ordenadas
    merge(arr, inicio, medio, fin);
    }
}

// Leer archivo
void leerArchivo() {
    if (archivoLeido) {
    cout << "Ya se ha leído un archivo.\n";
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
    
    while (archivo >> valor) tam++;
    
    if (tam == 0) {
    cout << "El archivo está vacio.\n";
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
    cout << "Archivo leido correctamente. Total de elementos: " << tam << endl;
}

// Mostrar contenido del arreglo
void mostrarArreglo() {
    if (!archivoLeido) {
    cout << "Debe leer primero un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya fue grabado.\n";
    return;
    }
    
    for (int i = 0; i < tam; i++) cout << arreglo[i] << " ";
    cout << endl;
}

// Aplicar Merge Sort
void ordenarMerge() {
    if (!archivoLeido) {
    cout << "Debe leer primero un archivo.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "El archivo ya fue grabado.\n";
    return;
    }
    
    if (archivoOrdenado) {
    cout << "El arreglo ya esta ordenado.\n";
    return;
    }
    
    mergeSort(arreglo, 0, tam - 1);
    archivoOrdenado = true;
    cout << "Arreglo ordenado exitosamente con Merge Sort.\n";
}

// Guardar en archivo
void guardarArchivo() {
    if (!archivoLeido) {
    cout << "Debe leer primero un archivo.\n";
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
    
    for (int i = 0; i < tam; i++) archivo << arreglo[i]
    << " ";
    archivo.close();
    archivoGrabado = true;
    cout << "Archivo guardado exitosamente como: " << nombre << endl;
}

// Salir
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
    cout << "2. Ordenar (merge)\n";
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
    
    ordenarMerge();
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
    default: cout << "Opción invalida. Intente de nuevo.\n";
    }
    
    } while (continuar);
    
    return 0;
}


