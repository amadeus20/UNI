//Piramide de numeros
// P006

#include <iostream>

using namespace std;

int p=1;

void piramide(){
    int i,n,j;

    cout<<"Introduce el valor de la base del triangulo: "<<endl;
    cin>>n;

    for(i=0;i<=n;i++){ ///Este ciclo va a imprimir la altura 

        /////////2*i-1, Esta es la formula 
        for(j=0;j<2*i-1;j++){ ////Este ciclo va a imprimir los numeros 
            cout<<i;
        }
        cout<<endl;
    }

    
    

}

int main(){
    
    for(;p==1;){
        piramide();
        cout<<"Deseas agregar nuevos valores? si=1/no=0"<<endl;
        cin>>p;
    }
   
    

}