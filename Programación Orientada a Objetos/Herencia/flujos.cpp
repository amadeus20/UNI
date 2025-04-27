#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ofstream fich("ejemplo.txt");
    if (!fich)
    {
        cout<<"Error al abrir ejemplo.dat\n";
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        fich<<i<<" uno"<<endl;
    }
    return 0;
}

