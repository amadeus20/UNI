#include <iostream>

using namespace std;
int main(){
    int i,j;
    int tabla[5][3]={'\0'};
    
    //Se capturan los datos mediante dos ciclos for

    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
        cout<<"Capture el numero "<<i<<endl;
        cin>>tabla[i][j];
        }
    }
    //Se imprimen los datos usando nuevamente 
    //dos ciclos for
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
        cout<<tabla[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");

}