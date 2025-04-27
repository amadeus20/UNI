#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream asalida;
    asalida.open("pais.txt");
    asalida<<"Estados unidos de America"<<endl;
    asalida<<"Reino Unido"<<endl;
    asalida<<"Corea del Sur";

    asalida.close();

    asalida<<"Washington \n";
    asalida<<"Londres \n";
    asalida<<"Seul \n";

    asalida.close();

    //Lectura de archivos

    const int N=80;
    char linea[80];
    ifstream aentrada;
    aentrada.open("pais.txt");

    cout<<"Contenido del archivo pais\n";

    while(aentrada){
        aentrada.getline(linea,N);

        cout<<linea<<endl;
    }

    aentrada.close();

    aentrada.open("capital.txt");
    cout<<"\n";
    cout<<"\nContenido del archivo capital";

    while(aentrada){
        aentrada.getline(linea,N);

        cout<<"\n"<<endl;

        cout<<linea<<"soy la capital amiga"<<endl;
    }
    aentrada.close();

    return 0;
     

}