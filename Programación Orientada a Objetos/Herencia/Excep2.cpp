#include <iostream>
using namespace std;

int produto (int a, int b);

int main(){
    try{
        int valor=producto(3,-5);
        cout <<"El valor es: "<<valor<< endl;
    }
    catch(const char*dato){
        cout <<"-------->: "<<dato<<endl;
    }

    return 0;
}

int producto(int a, int b){
    if(a<0||b<0)
        throw "Error, numero negativo";
    return a*b;
}
