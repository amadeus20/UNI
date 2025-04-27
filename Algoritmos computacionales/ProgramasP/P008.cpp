//P008
//Manejo de archivos
#include <stdlib.h>
#include <stdio.h>
#include <string>       /*añadimos la biblioteca "string.h" */
#include <iostream>
#include <fstream>   //manejo de archivo
#include <ctime>      // crear en base a la hora los numero aleatorios
#include <cstdlib>

using namespace std;

    int num,b, n, i, j, k, e;
    int p, d;
    int a[1000000];  // declara el arreglo
    int digitos[10];
    int numero;
    bool bandera;
    bool bandera1;
    int contador;
    int residuo;
        string nombrearchivo;
struct Entrada {
		int valor;
} entrada;

void eliminar(){
    numero=num;
    cout<<endl<<"los digitos son: ";
    for(k=0;k<10;k++){
        residuo=numero%10;        // obtengo el residuo
        digitos[k]=residuo;       // salva en el arreglo digitos el residuo
        numero /=10;              // cociente

        cout<<digitos[k]<<", ";  // muestra los digitos
    }

    if(digitos[p]==d){    // comparo digito en la posicion indicada
        bandera1=false;   // indica que voy a eliminar
        cout<<num<< ", ";
    }
    else{
        bandera1=true;
    }

}
int corrimiento(int*arr,int &tam,int&i){
    for(int j=i; j<tam-1; j++){
        arr[j]=arr[j+1]; //corrimiento a la izquierda
    }
    tam--; //disminuye el tamaño del arreglo
    return(0);
} 

void obtener()
{
    FILE *archivo1;
   // string valorInt;

    printf("\n Teclea el nombre del archivo de entrada:   ");
	cin >> nombrearchivo;
	nombrearchivo+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo1 = fopen(nombrearchivo.c_str(), "r");		        // Abrimos archivo

	if(archivo1== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
    }

     cout<<"Indica la posición del digito a validar, recuerda que la posición es 876543210 :";
     cin>>p;   // la posicion
     cout<<endl<<"Valor del digito (0 a 9) a validar: ";
     cin>>d;  // valor del digito que voy a validar
     cout<<endl;
     cout<<"Los valores eliminados son: ";
     j=0;
     for (int i=0; !feof(archivo1); i++) {
        fscanf (archivo1, "%i", &entrada.valor);  //lee archivo
        num=entrada.valor;    //Salva el entero
        bandera1=false;        // apaga bandera
        eliminar();                  // llama a la función eliminar
        if (bandera1== true){       //verifica que la bandera este prendida
            a[j]=num;                       //se almacena en el arreglo el entero leido por que es un valor a no eliminar
     //       cout<<a[j]<< ", ";          //se muestra el valor para pode buscarlo
            j++;                                //incrementa el indice
        }

    }
    cout<<endl;    // salto de linea para separar el parrafo de elementos no eliminados
    n=j;   // corrijo el tamaño del arreglo con el contador j que representa el indice de los valores que se movieron al arreglo a
    cout<<"Los valores en el arreglo son: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<", ";
    }

}


void buscar(){
    printf("\n dame el valor a buscar: ");
    scanf("%d,&b", &b);
    bandera=false;
    contador=0;
    for(i=0; i<n; i++){
        if (a[i]==b){
            bandera=true;
            contador++;
        }
    }


}

void mostrar(){
    if (bandera){
        cout<<"Encontre el valor buscado " << b << " tantas veces "<< contador<<endl;
    }
    else{
        printf("\n no existe el valor buscado");
    }

}
int main()
{
    obtener(); //esta es mi función de entrada, lee el archivo y
               //determinar si eliminar un valor cumple con la
               // posción y valor de digito, no lo pasa al arreglo
   for(i=0; i<1;){
       buscar();  //esta funcion busca en la serie un valor determinado
                  //sirve para comprobar que no existe o extiste un valor
       mostrar(); //esta funcion muestra si encontro o no
       printf("\n quiere buscar otro, si=0, no=1:");
       scanf("%d,&i", &i);
      }
}

