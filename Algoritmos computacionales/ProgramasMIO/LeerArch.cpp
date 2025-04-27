//Narrativa 5
//Leer un archivo existente y hacer calculos 

#include <iostream>
#include <fstream>

using namespace std;

void leer(){
    
    ifstream archivo; // le indica al Sistema operativo que va usar un recurso
    archivo.open("datos.txt"); // Se abre el archivo de manera explícita

    if (!archivo) { // Alternativamente: if (!archivo.is_open())
        cout << "Error al abrir el archivo." << endl;
        exit(1);
    }
    

}

int main() {
    leer();
}