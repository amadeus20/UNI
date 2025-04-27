#include <stdio.h>
#include <stdlib.h>

main(){
    int n,z;
    long sum;
    printf("Teclea un numero");
    scanf("%d",&n);
    sum=0;
    z=1;

    while(z<=n){
        printf("-->%d",sum);
        sum=sum+z*z;

        z=z+4;


    }
    printf("\nSolucion %d",sum);
    printf("\n\n");
    system("PAUSE");
    
}