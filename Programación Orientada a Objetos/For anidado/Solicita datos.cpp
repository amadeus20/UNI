#include <iostream.h>

using namespace std;
int main(){
    int dato,i;
    cout<<"Programa que solicita datos";
    cout<<"hasta que el dato tecleado es mayor a 20\n\n";

    for(i=0;i<1;){
        cout<<"Tecle un numero \n";
        cin>>dato;

        cout<<"numero tecleado: ">>dato<<endl;
        
        if (dato>20){
            cout<<"numero tecleado mayor a 20"<<endl;
            i++;
        }
    }
    system("PAUSE");
}