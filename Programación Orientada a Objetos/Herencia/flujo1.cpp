//Flujos

#include <iostream>

using namespace std;

main(void){
    char c1[80];
    char c2[4];

    cout <<"Introduce una cadena: ";
    cin.getline(c1,80);
    fflush(stdin); //fflush de entrada (limpia el campo)

    cout <<"Introduce una segunda cadena: ";
    cin.get(c2,4);

    cout<<"\n-"<<c1<<"-\n-"<<c2<<"-\n";

}
