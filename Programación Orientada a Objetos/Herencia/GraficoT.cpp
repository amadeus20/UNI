#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int i,s=0,a=0,b=0,c=0;
    //Ingresamos los datos a analizar
    int caja[10]={'\0'};
    for (i=0;i<10;i++){
        cout<<"Capture el "<<i<<"er numero"<<endl;
        cin>>caja[i];
    }
    //Se contabilizan los numeros pares totales
    cout<<""<<endl;
    cout<<"Se encontraron los siguientes numeros par: ";
    for(i=0;i<10;i++){
        if (caja[i] % 2 == 0) { 
            cout<<caja[i]<<" , ";
            
            s+=caja[i];
            a=a+1;
        }
        b=b+1;
    }
    cout<<""<<endl;
    cout <<"La suma de los numeros par: "<<s<<endl;
    c=b-a;//asi obtenemos el numero de numeros impares
    //-------------Aqui los graficamos---------------------
    cout<<"-------------------------------------------"<<endl;
    cout<<a<<c<<b<<endl;
    cout<<"Numeros par:   ";
    for(int j=0;j<(a*10); j++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"Numeros impar: ";
    for(int j=0;j<(c*10); j++){
        cout<<"#";
    }

}