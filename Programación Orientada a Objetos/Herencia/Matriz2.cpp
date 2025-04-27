#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

void gotoxy(short x, short y);//gotoxy nos permite determinar las coordenadas
main(){
    int x[10],i,y,a,z=0,sum=0,num;
    do{
        system("cls");
        sum=0;
        for(i=0;i<10;i++){
            printf("Teclea el datos para la coordenada %d de vector X: ",i);
            scanf("%d",&x[i]);
            sum=sum+x[i];
        }
        printf("La impresion es: \n");
        printf("\t\t");
        y=14;
        for(i=0;i<10;i++){
            gotoxy(23,y);
            printf("%c \n",'[');

            gotoxy(24,y);
            printf(" %d",x[i]);

            gotoxy(26,y);
            printf(" %c ",']');

            y++;
            printf("\n");
        }
        gotoxy(40,23);
        printf("\n\n\t La suma es: %d\n",sum);
        printf("Digita 0: para salir \n");
        scanf("%d",&z);

    }while(z!=0);


    system("pause");
}
void gotoxy(short x, short y){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}