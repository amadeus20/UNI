#include <iostream>
using namespace std;

int main(){
    int option, k;
    for (k=0;k<1;){
        system("cls");
        cout<<"Menu\n";
        cout<<"1--Opcion 1\n";
        cout<<"2--Opcion 2\n";
        cout<<"3--Salir\n";
        cin>>option;
        switch(option){
            case(1):
                cout<<"Proceso en caso de elegir opcion 1\n";
                break;
            case(2):
                cout<<"Proceso en caso de elegir opcion 2\n";
                break;
            case(3):
                cout<<"Finaliza el proceso\n";
                break;
            default:
                cout<<"Opcion invalida\n";
                break;
        }
        system("pause");
    }
    
}