#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

const char * nombrearchivo = "BINARIO";

int main(int argc, char const *argv[])
{
    float altura[4]={175.5, 153.0, 167.25, 160.70};

    ofstream archivosalida;
    archivosalida.open(nombrearchivo);

    archivosalida.write((char *) & altura, sizeof(altura));
    archivosalida.close();

    for (int i = 0; i < 4; i++)
    {
        altura[i]=0;
    }
    
    ifstream archivoentrada;

    archivoentrada.open(nombrearchivo);
    archivoentrada.read((char *) & altura, sizeof(altura));

    for (int i = 0; i < 4; i++)
    {
        cout.setf(ios::showpoint);
        cout<<setw(20)<<altura[i];
    }
    archivoentrada.close();
    return 0;
}

