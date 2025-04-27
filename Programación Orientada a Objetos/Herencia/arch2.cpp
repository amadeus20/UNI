#include <fstream>
#include <stdlib.h>
///---------------------Crea un archivo de texto 
using namespace std;

int main(){
    ofstream archivo;

    archivo.open("datos.txt");

    archivo<<"Primera linea de texto"<<endl;
    archivo<<"Segunda linea de texto"<<endl;
    archivo<<"Ultima linea de texto"<<endl;

    archivo.close();
    return 0;

}
