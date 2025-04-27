//Busqueda secuencial, programa de Youtube modificado

#include<iostream>
#include<conio.h>

using namespace std;

int a[20];
int i=0,dato,n;
int bandera=0;

void captura(){
    cout<<"Cuantos datos quieres agregar?"<<endl;
    cin>>n;
    for(int j=0;j<n;j++){
        cout<<"Tecle el "<<j<<" dato: ";
        cin>>a[j];
    }

}

void buscar(){

    while((bandera==0)&&(i<20)){
        if (a[i]==dato){             //Busqueda
            bandera=1;
        }
        i++;
    }

}

int main(){

    captura();

    cout<<"Tecle el valor a buscar: ";
    cin>>dato;

    buscar();
    
    if(bandera==0){
        cout<<"El numero no existe en el arreglo";
        cout<<"\n Valor "<<dato<<" no encontrado, veces "<<bandera<<" , iteraciones "<<i;     
        cout<<"\n Intenta nuevamente"<<endl;

    }
    else if(bandera==1){
        cout<<"El numero fue encontrado en la posicion: "<<i-1;
        cout<<"\n Valor "<<dato<<" encontrado, veces "<<bandera<<" , iteraciones "<<i;     
        cout<<"\n Quiere volver a intentar"<<endl;
    }


}
