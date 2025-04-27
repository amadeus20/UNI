#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ofstream fich("ejemplo.txt");
    if(!fich){
        cout <<"Error al abrir el ejemplo.dat\n";
        exit(1);
    }
    for(int i=0;i<10;++i){
        fich<<i<<"uno"<<endl;
    }
    
}