#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <locale>
using namespace std;

// Variables globales para el arreglo y control de estado del programa
int tam = 0;
int* arreglo = nullptr;
bool archivoLeido = false;
bool archivoOrdenado = false;
bool archivoGrabado = false;

// Función para encontrar el valor máximo en el arreglo
int obtenerMaximo(int arr[], int tam) {
    int maximo = arr[0];
    for (int i = 1; i < tam; i++) {
    if (arr[i] > maximo)
    maximo = arr[i];
    
    }
    return maximo;
}

// Función auxiliar de Radix Sort que aplica Counting Sort para un dígito específico
void countingSort(int arr[], int tam, int exp) {
int* salida = new int[tam]; // Arreglo de salida
int conteo[10] = {0}; // Cuenta de dígitos (0 a 9)

// Contar ocurrencias de cada dígito en la posición actual
for (int i = 0; i < tam; i++)
conteo[(arr[i] / exp) % 10]++;

// Calcular posiciones acumuladas para el ordenamiento estable
for (int i = 1; i < 10; i++)
conteo[i] += conteo[i - 1];

// Construir el arreglo de salida
for (int i = tam - 1; i >= 0; i--) {
int idx = (arr[i] / exp) % 10;
salida[conteo[idx] - 1] = arr[i];
conteo[idx]--;
}

// Copiar el arreglo ordenado al arreglo original
for (int i = 0; i < tam; i++)
arr[i] = salida[i];

delete[] salida;
}

// Función principal de Radix Sort
void radixSort(int arr[], int tam) {
    int maximo = obtenerMaximo(arr, tam);
    
    // Aplicar Counting Sort para cada dígito (unidades, decenas,centenas...)
    for (int exp = 1; maximo / exp > 0; exp *= 10)
    countingSort(arr, tam, exp);
    
}

// Leer archivo y llenar el arreglo dinámico
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

// Mostrar los elementos actuales del arreglo
void mostrarArreglo() {
    if (!archivoLeido) {
    cout << "Debe leer un archivo primero.\n";
    return;
    }
    if (archivoGrabado) {
    cout << "Ya se grabo el archivo.\n";
    return;
    }
    
    cout << "Contenido del arreglo: ";
    for (int i = 0; i < tam; i++) {
    cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Aplicar el algoritmo de Radix Sort
void ordenarRadix() {
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
    
    radixSort(arreglo, tam);
    archivoOrdenado = true;
    cout << "Arreglo ordenado exitosamente con Radix Sort.\n";
}

// Guardar los datos ordenados en un nuevo archivo
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
cout << "Ingrese el nombre del archivo para guardar (sin extension): ";
cin >> ws;

getline(cin, nombre);
nombre += ".txt";

ofstream archivo(nombre);
if (!archivo) {
cout << "No se pudo crear el archivo.\n";
return;
}

for (int i = 0; i < tam; i++) archivo << arreglo[i]
<< " ";
archivo.close();
archivoGrabado = true;
cout << "Archivo guardado exitosamente como: " << nombre << endl;
}

// Función para salir correctamente del programa
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

// Función principal con el menú de opciones
int main() {
    setlocale(LC_ALL, ""); // Permite acentos y ñ en consola
    
    int opcion;
    bool continuar = true;
    
    do {
    cout << "\nMenu:\n";
    cout << "1. Leer archivo\n";
    cout << "2. Ordenar (Radix Sort)\n";
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
    ordenarRadix();
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



