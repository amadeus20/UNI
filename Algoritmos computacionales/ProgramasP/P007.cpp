//algoritmo que lea un archivo de enteros ordenados y
//le solicite al usuario las siguientes opciones:
//1.Valor a agregar
//2 Valor a eliminar
//P007

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int* leerArchivo(const string& nombreArchivo, int& tam) {
    
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }
    
    tam = 0;
    int temp;
    
    while (archivo >> temp) {
        tam++;
    }
    
    if (tam == 0) {
        cout << "El archivo está vacío.\n";
        archivo.close();
        return nullptr;
    }

    archivo.clear();
    archivo.seekg(0, ios::beg);

    int* arreglo = new int[tam];
    for (int i = 0; i < tam; i++) {
        archivo >> arreglo[i];
    }

    archivo.close();
    return arreglo;
}

void mostrarArreglo(int* arr, int tam) {
    if (arr == nullptr || tam == 0) {
        cout << "El arreglo está vacío." << endl;
        return;
    }
    cout << "Arreglo actual: ";

    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* agregarValor(int* arr, int& tam,int valor) {
        int* nuevoArr = new int[tam + 1];
        int i = 0, j = 0;
    
        while (i < tam && arr[i] < valor){
            nuevoArr[j++] = arr[i++];
        }
    
        nuevoArr[j++] = valor;
        while (i < tam) {
            nuevoArr[j++] = arr[i++];
        }

        tam++;
        delete[] arr;
        return nuevoArr;
    }

int* eliminarValor(int* arr, int& tam, int valor) {
        if (arr == nullptr || tam == 0) {
        cout << "No hay elementos en el arreglo.\n";
        return arr;
        }
        
        int pos = -1;
        
        for (int i = 0; i < tam; i++) {
            if (arr[i] == valor) {
                pos = i;
                break;
            }
        }
        
        if (pos == -1) {
            cout << "El valor no existe en el arreglo." << endl;
            return arr;
        }
    
        int* nuevoArr = new int[tam - 1];
        for (int i = 0, j = 0; i < tam; i++) {
            if (i != pos) {
                nuevoArr[j++] = arr[i];
            }
        }
    
        tam--;
        delete[] arr;
        return nuevoArr;
    }

int main() {
        string nombreArchivo;
        int tam = 0;
        int* arreglo = nullptr;
        
        int opcion, valor;
        do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Leer archivo\n";
        cout << "2. Agregar un valor\n";
        cout << "3. Eliminar un valor\n";
        cout << "4. Mostrar arreglo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            cout << "Ingrese el nombre del archivo sin extension: ";
            
            cin >> nombreArchivo;
            nombreArchivo += ".txt";
            
            if (arreglo) {
            delete[] arreglo;
            }
            
            arreglo = leerArchivo(nombreArchivo, tam);
            mostrarArreglo(arreglo, tam);
            break;
            case 2:

                if (arreglo == nullptr) {
                    cout << "Primero debe leer un archivo.\n";
                    break;  
                }
                cin >> valor;
                arreglo = agregarValor(arreglo, tam, valor);
                break;
            case 3:
                if (arreglo == nullptr) {
                    cout << "Primero debe leer un archivo.\n";
                    break;
                }
                cin >> valor;
                arreglo = eliminarValor(arreglo, tam, valor);
                break;
            case 4:
                mostrarArreglo(arreglo, tam);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
                }
        } while (opcion != 5);
                
        delete[] arreglo;
        return (opcion);


    }

