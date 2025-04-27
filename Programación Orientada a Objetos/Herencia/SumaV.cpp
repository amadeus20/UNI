#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

void gotoxy(short x, short y){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
main(){
    int x[10],x2[10],i,j,c,y,a,z=0,sum=0,sum2=0,sumv[10],num,sumt;
    do{
        system("cls");
        sum=0;

        for(i=0;i<10;i++){ //Ingreso de los numeros del vector1
            printf("Teclea el datos para la coordenada %d de vector X: ",i);
            scanf("%d",&x[i]);
            sum=sum+x[i];
        }
        for(j=0;j<10;j++){ //Ingreso de los numeros del vector2
            printf("Teclea el datos para la coordenada %d de vector Y: ",j);
            scanf("%d",&x2[j]);
            sum2=sum2+x2[j];
        }

        for(c=0;c<10;c++){ //Suma de los vectores
            sumv[c]=x[c]+x2[c];
        }

        printf("\n");
        printf("La impresion es: \n");
        printf("\t\t");
        y=27;
        sumt=sum+sum2;

        //Mostrar los datos en pantalla

        for(i=0;i<10;i++){ //Muestra el vector 1
            gotoxy(8,y);
            printf("%c \n",'[');

            gotoxy(10,y);
            printf(" %d",x[i]);

            gotoxy(12,y);
            printf(" %c ",']');
            y++;
            printf("\n");
        }
        y=27;
        for(j=0;j<10;j++){ //Muestra el vector 2
            gotoxy(25,y);
            printf("%c \n",'[');

            gotoxy(27,y);
            printf(" %d",x2[i]);

            gotoxy(29,y);
            printf(" %c ",']');
            y++;
            printf("\n");
        }
        y=27;
        for(c=0;c<10;c++){ //Muestra la suma de los vectores
            gotoxy(42,y);
            printf("%c \n",'[');

            gotoxy(44,y);
            printf(" %d",sumv[i]);

            gotoxy(46,y);
            printf(" %c ",']');
            y++;
            printf("\n");
        }

        gotoxy(19,32);
        printf("+");
        gotoxy(19,38);
        printf("+");
        gotoxy(36,32);
        printf("=");
        gotoxy(36,38);
        printf("=");

        gotoxy(10,y);
        printf("%d\n", sum);//muestra el resultado de la suma1

        gotoxy(27,y);
        printf("%d\n", sum2); //muestra el resultado de la suma2
        
        gotoxy(44,y);
        printf("%d\n", sumt);//suma el resultado de la suma total

        printf("Digita 0: para salir \n");
        scanf("%d",&z);

    }while(z!=0);

    system("pause");

}