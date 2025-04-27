#include <iostream>
#include <string.h>

using namespace std;

class DiaAño{
    public:
        int mes;
        int dia;
        void visualizar();

};

void DiaAño::visualizar(){
    char nommes[80];
    if(mes==01) strcpy(nommes, "Enero");
    if(mes==02) strcpy(nommes, "Febrero");
    if(mes==03) strcpy(nommes, "Marzo");
    if(mes==04) strcpy(nommes, "Abril");
    if(mes==05) strcpy(nommes, "Mayo");
    if(mes==06) strcpy(nommes, "Junio");
    if(mes==07) strcpy(nommes, "Julio");
    if(mes==8) strcpy(nommes, "Agosto");
    if(mes==9) strcpy(nommes, "Septiembre");
    if(mes==10) strcpy(nommes, "Octubre");
    if(mes==11) strcpy(nommes, "Noviembre");
    if(mes==12) strcpy(nommes, "Diciembre");
    cout<<dia<<":"<<nommes<<"\n";


}

main(){
    DiaAño hoy, cumpleaños;
    cout<<"Introdusca la fecha del dia de hoy \n\n";
    cout<<"Introdusca el numero del mes: ";
    cin>>hoy.mes;
    cout<<"Introdusca el numero del dia: ";
    cin>>hoy.dia;

    cout<<"Introdusca la fecha de nacimiento \n\n";
    cout<<"Introdusca el numero del dia: ";
    cin>>cumpleaños.dia;
    cout<<"Introdusca el numero del mes: ";
    cin>>cumpleaños.mes;
///Imprimir
    cout<<" \nLa fecha de hoy es: ";
    hoy.visualizar();
    cout<<" \nSu fecha de naciemiento es: ";
    cumpleaños.visualizar();
//Decide cuanto falta para el cumpleños
    if(hoy.mes>12 or hoy.dia>31)
        cout<<"El mes o dia de la fecha estan fuera de rango, lo siento";
    else
        if(cumpleaños.mes>12 or cumpleaños.dia>31)
            cout<<"El mes o dia del cumpleños estan fuera de rango, lo siento";
        else 
            if(hoy.mes==cumpleaños.mes && hoy.dia==cumpleaños.dia)
                cout<<"\n FELIZ CUMPLEÑOS \n\n";
            else{
                cout<<"\nLo siento hoy no es tu cumpleaños \n";
                cout<<"              Feliz dia\n\n";
            }  
    system("pause");

}