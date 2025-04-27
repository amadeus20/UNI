#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ofstream archivo;
    archivo.open("datos.txt");
    archivo<<"Primera linea de texto"<<endl;
    archivo<<"Segunda linea de texto"<<endl;
    archivo<<"Ultima linea de texto"<<endl;
    archivo.close();
    return 0;
}

