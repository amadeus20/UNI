#include<iostream>
using namespace std;

int main(){
    int i;
    int arreglo[10]={'\0'};
    for(i=0;i<10;i++){
        cout<<"Capture el numero "<<i<<endl;
        cin>>arreglo[i];
        
    }
    cout<<"Los datos capturados son"<<endl;
    
    for(i=0;i<10;i++){
        cout<<arreglo[i]<<"";
    }
    cout<<endl;
    system("pause");
}