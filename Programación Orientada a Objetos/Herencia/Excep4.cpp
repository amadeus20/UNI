#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a,b,c;

    bool variable=false;

    while (variable==false){
        try{
            cout<<"ingrese el primer lado p.f: ";
            cin>>a;
            if(a<=0)
                throw 20;
            else
                variable=true;
        }
        catch(int e){
            cout <<"Oye usuario estas ingresando un valor igual a 0 o negativo, intentalo otra vez";
        }
    }

    variable=false;
    while(variable==false){
        try{
            cout<<"ingrese el segundo lado p.f: ";
            cin>>b;
            if(b<=0)
                throw 30;
            else    
                variable=true;
        }
        catch(int e){
            cout<<"Oye usuario estas ingresando un valor igual a 0 o negativo, intentalo otra vez";
        }
    }
    while(variable==false){
        try{
            cout<<"ingrese el tercer lado p.f: ";
            cin>>c;
            if(c<=0)
                throw 40;
            else    
                variable=true;
        }
        catch(int e){
            cout<<"Oye usuario estas ingresando un valor igual a 0 o negativo, intentalo otra vez";
        }
    }

    if (a<=b+c && b<=a+c && c<=a+b && a>=abs(b-c) && b>=abs(a-c) && c>=abs(a-b)){
        cout <<"con los valores ingresados, si puede construir un triangulo"<<endl;
    }
    else
        cout<<"con los valores ingresados, no puede construir un triangulo"<<endl;

}