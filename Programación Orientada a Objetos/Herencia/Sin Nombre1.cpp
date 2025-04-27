#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int main(){
    float comp,imp,pretot;
    int a;
    a=1;
    while(a==1){
        printf("Dame el precio de la compra:");
        scanf("%f",&comp);
        
        if (comp<=500)
            imp=comp;
        else 
            if (comp>500 && comp<=1000)
                imp=comp-(comp*0.05);
            else 
                if(comp>1000 && comp<=7000)
                    imp=comp-(comp*0.11);
                else
                    imp=comp-(comp*0.25);
        
        
        printf("\n");
        printf("El precio a pagar es de : %.2f",imp);
        printf("\n\n");
        printf("quieres procesar otra cantidad digita enter, salir <> 1");
        printf("\n");
        printf("%d",&a);
        printf("\n");
        
    }
    system("pause");

}

//1.- 3500
//2.- 6850
//3.- 375.5
//4.- 690.50
//5.- 12350
//6.- 25314.18
//7.- 3750
//8.- 14200
//9.- 895.50
//10.- 131850
