//Examen
///P010 

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int opcion=0, banderadepen, infinito=0, valor=0, tam, menor, mayor, medio;

int* arreglo = nullptr;  // Inicializar el puntero a nullptr para evitar acceso a memoria no válida
vector<int> valores; // Vector para almacenar los valores leídos del archivo


int imprimeMenu(){
    cout << "\n\n\t\t\tMenu de opciones\n\n";
    cout << "\t1. Leer archivo\n";
    cout << "\t2. Mostrar arreglo\n";
    cout << "\t3. Agregar un valor\n";
    cout << "\t4. Calcular\n";
    cout << "\t5. Eliminar un valor\n";
    cout << "\t6. Guardar\n";
    cout << "\t7. Salir\n";
    cout << "\n\tSelecciona una opcion: ";
    
    cin >> opcion;
    
    return opcion;
}
int* leer(const string& nombreArchivo, int& tam) {
    
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
//-----------------------------------------------------
int LeerArchivo (string& nombreArchivo, int& tam){ // Llamar a la función leer para obtener el tamaño del arreglo
     // Llamar a la función leer para obtener el tamaño del arreglo
    if (banderadepen==0){
        cout << "Ingrese el nombre del archivo sin extension: ";
            
            cin >> nombreArchivo;
            nombreArchivo += ".txt";
            
            if (arreglo) {
            delete[]arreglo;
            }
            
            arreglo = leer(nombreArchivo, tam);
            valores.resize(tam); // Redimensionar el vector para que tenga el tamaño correcto
            for (int i = 0; i < tam; i++) {
                valores[i] = arreglo[i]; // Copiar los valores leídos al vector
            }
            banderadepen=1; // Cambiar el estado de la bandera a 1 después de leer el archivo
    }
    else{
        if(banderadepen==1){
            printf("Error: ya se leyo el archivo\n");
            return (0);
        }
        else{
            printf("Error: ya se creo el archivo de salida\n");
            return (0);
        }
    
        return 0; // Ensure the function always returns a value
    }
    return (0);
}

//---------------------------------------------------------

int Mostrar(int* arr, int tam){
    if (banderadepen==1){ 
        if (arr == nullptr || tam == 0) {
            cout << "El arreglo está vacío." << endl;
            return 0;
        }
        cout << "Arreglo actual: ";
    
        for (int i = 0; i < tam; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }
    else{
        if (banderadepen==0){
            printf("Error: no se ha leido el archivo\n");
            return(0);
        }
        else {
            printf("Error: ya se creo archivo de salida\n");
            return(0);
        }
        return 0;
    }
}


int* Agregar (int* arr, int& tam, int valor, int* nuevoArr = nullptr){
    if (banderadepen == 1){ 
        nuevoArr = new int[tam + 1];
        int i = 0, j = 0;
    
        while (i < tam && arr[i] < valor) {
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
    else {
        if (banderadepen == 0){
            printf("Error: no se ha leido el archivo\n");
        }
        else {
            printf("Error: ya se creo archivo de salida\n");
        }
        return nullptr;
    }
}


int Calcular (int* arr, int &menor, int &mayor, int &medio){
    
    if(banderadepen==1){
        if (valores.empty()) { 
            return 0;
            }
            menor = arreglo[0];
            mayor = arreglo[tam - 1];
            medio = arreglo [tam/2];
            cout << "Menor: " << menor << endl;
            cout << "Mayor: " << mayor << endl;
            cout << "Medio: " << medio << endl;
    }
    else
        if (banderadepen==0){
            printf("Error: no se ha leido el archivo\n");
            return(0);
        }
        else {
            if (banderadepen==1){
                printf("Error: no se ha leido el archivo\n");
                return(0);
            }
            else {
                printf(" Error: ya se creo archivo de salida\n");
                return(0);
            }
        }
        return (0);
}

int* Eliminar (int* arr, int& tam, int valor, int* nuevoArr = nullptr){
    if (banderadepen==1){
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
    else{
        if (banderadepen==0){
            printf("Error: no se ha leido el archivo\n");
            return(0);
        }
        else {
            printf(" Error: ya se creo archivo de salida\n");
            return(0);
        }
    }
        return (0);
    
}

int Guardar(){
    if (banderadepen==1) {
        printf("Guardar\n");
        banderadepen=2; 
    }
    else
        if (banderadepen==0){
            printf("Error: no se ha leido el archivo\n");
            return(0);
        }
        else {
            printf(" Error: ya se creo archivo de salida\n");
            return(0);
        }
        return (0);

}

int Salir(){
    if (banderadepen==2) {
        printf("Salir\n");
        delete[] arreglo; // Liberar la memoria del arreglo

        infinito=2;
    }
    else
        if (banderadepen==0){
            printf("no se ha leido el archivo\n");
            return(0);
        }
        else {
            printf("no se ha creado el archivo de salida\n");
            return(0);
        }

    return (0);
}

int main(){
    string nombreArchivo;
     // se inicializa el tamaño del arreglo
    cout<<"\n";
    banderadepen=0; // se inicializa la bande de dependencia
    for (infinito=0; infinito==0; ){
    
        opcion = imprimeMenu(); // muestra el menu
    switch (opcion){
        case 1:
            LeerArchivo(nombreArchivo, tam);
            leer(nombreArchivo, tam);
             // Llamar a la función leer para obtener el tamaño del arreglo
             // Llamar a la función leer para obtener el tamaño del arreglo
            system ("pause");
            system("cls");
            break;
        case 2:
            Mostrar(arreglo, tam);
            system ("pause");
            system("cls");
            break;
        case 3:
            cout << "Ingrese el valor a agregar: ";
            cin >> valor;
            banderadepen=1; // Cambiar el estado de la bandera a 1 después de leer el archivo
            arreglo = Agregar(arreglo, tam, valor);
            system ("pause");
            system("cls");
            break;
        case 4:
            Calcular(arreglo, menor, mayor, medio);
            system ("pause");
            system("cls");
            break;
        case 5:
            cout << "Ingrese el valor a eliminar: ";
            cin >> valor;
            arreglo = Eliminar(arreglo, tam, valor);
            system ("pause");
            system("cls");
            break;
            
        case 6:
            Guardar();
            system ("pause");
            system("cls");
            break;
            
        case 7:
            
            Salir();
            system ("pause");
            
            system("cls");
            break;
            
        default:
            
            printf("\n\n\tSeleccion valida, intente nuevamente\n");
            
            system ("pause");
            system("cls");
            break;
        }
            
    }
            system("PAUSE");

}