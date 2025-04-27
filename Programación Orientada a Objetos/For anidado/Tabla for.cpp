#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,x,aux,tope=10;
    
    int tabla[10];
    int tau[tope];
    printf("Dame el numero de interacciones");
    scanf("%d",&tope);
    
    for(i=0;i<tope;i++){
        scanf("%d",&x);
        tabla[i]=x;

    }
    for(i=0;i<tope;i++){
        printf("\n\t\t\t\t\t%d", i);
        //tabla[i]=i
        //i=i+1
        printf("\t%d", tabla[i]);
    }
    i=0;
    
    //while (i<=tope)
   // {
       // aux=tau[i];
     //   tabla[i]
    //}
    

}