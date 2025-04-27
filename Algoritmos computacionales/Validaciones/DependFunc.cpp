//Validacion por Dependencia Funcional
//Esta validación garantiza las funciones tengan un orden determinado de ejecución.
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
using namespace std;
int opcion=0;
int banderadepen=0; // bandera de dependencia inicia con 0, cuando se ejecuta funcion 1 cambia a 1, cuandose ejecuta la funcion 4, cambia a 2
int infinito=0; // controla el ciclo infinito para mostrar el menú hasta que se llega que se realiza la función 5 salir

int imprimeMenu (){
cout<<"\n1. Funcion 1 con validacion que permite ejecutarse solo una vez \n ";
cout<<"\n2. Funcion 2 \n";
cout<<"\n3. Funcion 3 \n";
cout<<"\n4. Funcion 4 que una vez ejecutada solo permite solo salir\n";
cout<<"\n5. Salir \n";
cout<<"\n Seleccione la opcion ";
cin>>opcion;
cout<<"\n\n";
return (opcion);
}
void funcion1 ()
{
if (banderadepen==0) // se verifica que no se haya ejecutado esta función
{
printf("Funcion uno con chequeo de ejecucion\n");
banderadepen=1; // Indica que ya se ejecuto esta funcion
}
else
{
if(banderadepen==1){
printf("Error: ya se leyo el archivo\n");
}
else{
printf("Error: ya se creo el archivo de salida\n");
}
}
// desarrollo de la funcion
}
void funcion2 ()
{
if (banderadepen==1){ // se verifica que ya se haya ejecutado la funcion 1
printf("Funcion dos\n");
}
else
if (banderadepen==0){
printf("Error: no se ha leido el archivo\n");
}
else {
printf("Error: ya se creo archivo de salida\n");
}
// desarrollo de la funcion
}
void funcion3 ()
{
if (banderadepen==1) // se verifica que ya se haya ejecutado la funcion 1
printf("Funcion tres\n");
else
if (banderadepen==0){
printf("Error: no se ha leido el archivo\n");
}
else {
if (banderadepen==1){
printf("Error: no se ha leido el archivo\n");
}
else {
printf(" Error: ya se creo archivo de salida\n");
}
}
// desarrollo de la funcion
}
void funcion4()
{
if (banderadepen==1) // se verifica que ya se haya ejecutado la funcion 1
{
printf("Funcion cuatro grabar\n");
banderadepen=2; // Indica que la funcion de grabar archivo de salida ya se ejecuto y evita realizar otras funciones que no sea salir
}
else
if (banderadepen==0){
printf("Error: no se ha leido el archivo\n");
}
else {
printf(" Error: ya se creo archivo de salida\n");
}
// desarrollo de la funcion
}
void funcion5()
{
if (banderadepen==2) // se verifica que ya se haya ejecutado la funcion 4
{
printf("Funcion salir\n");
infinito=2; // rompe el ciclo infinito del menu
}
else
if (banderadepen==0){
printf("no se ha leido el archivo\n");
}
else {
printf("no se ha creado el archivo de salida\n");
}
// desarrollo de la funcion
}
int main(){
cout<<"\n";
banderadepen=0; // se inicializa la bande de dependencia
for (infinito=0; infinito==0; ){ // controla el ciclo infinito, ya que inicia en cero, mienta sea cero, se rompe en opción 5

opcion = imprimeMenu(); // muestra el menu
switch (opcion){
case 1:

funcion1();

system ("pause");

system("cls");

break;
case 2:
funcion2();
system ("pause");

system("cls");

break;
case 3:
funcion3();
system ("pause");
system("cls");
break;
case 4:
funcion4();
system ("pause");

system("cls");

break;

case 5:

funcion5();
system ("pause");
system("cls");
break;

default:

printf("\n\n\tSeleccion valida, intente nuevamente\n");
system ("pause");
system("cls");
break;

}
}
system("PAUSE");
}