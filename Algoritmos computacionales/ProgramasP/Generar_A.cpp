// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//                       Crea archivo de numeros randon
//
#include <stdlib.h>
#include <stdio.h>
#include <string>       /*añadimos la biblioteca "string.h" */
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

	struct Registro{ // entidad
		int valor; // atributo
    } entrada;  // el registro que tiene 0,0,n ....n representa el número de términales

FILE *archivo1;   // nombre del archivo
int i;
int f;
int v;
int n;
int inicio;
string respuesta="s";
string nombrearchivo;

void abrirarchivo(){
//----------------------------------------Crea un archivo con extencion-----------------------------------------
  	srand (time(NULL));        					 		// initialisa random semilla
	printf("\n Teclea el nombre del archivo, sin extensión:   ");
	cin >> nombrearchivo;
	nombrearchivo+= ".txt";						 		// le agregarmos la extension ".txt"
//-------------------------------------------------------------------------------------------------
//---------------------------Se comprueba que el archivo exista--------------------------------------
	archivo1 = fopen(nombrearchivo.c_str(), "r");		// Abrimos archivo
	    if (archivo1 != NULL) {
        printf("El archivo ya existe. ¿Desea reescribirlo? (S/N): ");
       // scanf(" %c", &respuesta);
       cin>>respuesta;

    }
    fclose(archivo1);

	if(respuesta == "s" ){
        archivo1 = fopen(nombrearchivo.c_str(), "w");		// Abrimos archivo
        printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
	}
	else{

        printf(" No se puede abrir el archivo ");
		exit(1);
    }

//--------------------------------------------------------------
}

void generararchivo( ) {

	do{
		printf ("Valor inicial:  \n");
		scanf("%i",&i);
		inicio=i;
		printf ("Valor final:    \n");
		scanf("%i",&f);
	}while(f-i>=500000);
        printf("Cuantos valores en el archivo  \n");
         scanf("%i", &n);
	for (i=0;i<n;i++){
		v=inicio + rand () %(f+1 - inicio); // la formula puede ser diferente
		entrada.valor=v;
		fprintf(archivo1, "%i\n", entrada.valor);  // es el write que escribe la intancia o registro en el archivo
	}

}

void cerrararchivo() {
	fclose(archivo1);
}
int main (void){

     abrirarchivo();
     generararchivo();
     cerrararchivo();


  	return (0);
}