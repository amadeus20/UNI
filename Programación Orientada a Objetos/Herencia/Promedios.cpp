#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main(){
    int i,n;
    float suma=0.0,promedio,dato;
    cout<<"Ese programa obtiene el promedio de las calificaciones \n";
    cout<<"¿cuantas calificaciones se van a introducir?\n";
    cin>>n;

    if(n>0){
        cout<<"Capture la calificaciones por favor: \n";
        i=1;
        while(i<n){
            cin>>dato;
            suma+=dato;
            i++;

        }
        promedio=suma;
        cout<<"El promedio es de: "<<promedio<<"\n";
        
    }
    else {
        cout<<"No puede sacar promedio de calificiones 0\n";
        cout<<"Oprima cualquier otra terminal\n";
    }
    getch();system("PAUSE");

}