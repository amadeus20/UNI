#include <iostream>
#include <string.h>
using namespace std;

class DiaAnyo{
    public: 
        int mes;
        int dia;
        void visualizar();
};
void DiaAnyo::visualizar(){
    char nommes [80];
    if(mes==01)strcpy(nommes, "Enero");
    if(mes==02)strcpy(nommes, "Febrero");
    if(mes==03)strcpy(nommes, "Marzo");
    if(mes==04)strcpy(nommes, "Abril");
    if(mes==05)strcpy(nommes, "Mayo");
    if(mes==06)strcpy(nommes, "Junio");
    if(mes==07)strcpy(nommes, "Julio");
    if(mes==8)strcpy(nommes, "Agosto");
    if(mes==9)strcpy(nommes, "Septiembre");
    if(mes==10)strcpy(nommes, "Octubre");
    if(mes==11)strcpy(nommes, "Noviembre");
    if(mes==12)strcpy(nommes, "Diciembre");

    if(mes==00 && mes>12)strcpy(nommes, "no valido");
    cout<<dia<<":"<<nommes<<"\n";


}
main(){
    DiaAnyo hoy, FechIndep;

    cout<<"INTRODUSCA LA FECHA DEL DIA DE HOY \n\n";
    cout<<"introdusca el numero del mes: ";
    cin>>hoy.mes;

    cout<<"introdusca el numero del dia: ";
    cin>>hoy.dia;
//--------------------------------------------

    cout<<"\nINTRODUSCA LA FECHA DEL DIA DE LA INDEPENDENCIA\n\n";
    cout<<"introdusca el numero del mes: ";
    cin>>FechIndep.mes;
    cout<<"introdusca el numero del dia: ";
    cin>>FechIndep.dia;


//////---------------------------------------------------------
//Fechas introducidas
    cout<<" \nLa fecha de hoy es: ";
    hoy.visualizar();
    cout<<" \nLa fecha introducida fue: ";
    FechIndep.visualizar();

//Cuanto falta para fecha independencia
    if(hoy.mes>12 or hoy.dia>31)
    {
        cout<<"El mes o dia de la fecha estan fuera de rango, lo siento";
    }
    else{
        if(FechIndep.mes>12 or FechIndep.dia>31)
            cout<<"El mes o dia estan fuera de rango, lo siento";
        else 
            if(hoy.mes==FechIndep.mes && hoy.dia==FechIndep.dia)
                cout<<"\n ¡FELIZ DIA DE LA INDEPENDENCIA \n\n";
            else{
                cout<<"\nLo siento hoy no es el dia de la independencia \n";
                cout<<"              Feliz dia\n\n";
                cout<<"\n mejor suerte para la proxima\n";
                
                
            } 
    }
    system("pause");

///Campos Abad Dante Amadeus


}
