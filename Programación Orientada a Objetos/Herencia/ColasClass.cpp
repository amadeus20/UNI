#include<iostream>
using namespace std;

class cola{                     //clase cola
    int c[100];
    int posf,posp;
    public:
        cola(void);             ///constructor
        ~cola(void);            //destructor
        void ponc(int i);
        int quitac (void);

};

cola::cola(void){               //Constructor sirve para inicializar los atributos
    posp=posf=0;
    cout<<"\n La cola ya tiene valores iniciales"<<posp<<endl;

};

cola::~cola(void){          //Este es el destructor de los contructores
    cout<<"La cola ha sido destruida\n";

};

void cola::ponc(int i){                //con esta funcion incluimos elementos en la cola 
    
    if(posp==100){
        cout<<"La cola esta llena";
        return;
    }
    else{
        posf++;
        c[posf]=i;
        cout<<"El elemento "<<c[posf]<<" esta es la cola \n";
    }
}

int cola::quitac(void){
    
    if(posp==posf){
        cout<<"La cola esta vacia";
        return 0;
    }
    else{
        posp++;
        return c[posp];
    }
}

main(){
    cola a,b;               //Se crean dos objetos del tipo cola

    a.ponc(10);
    b.ponc(19);

    a.ponc(20);
    b.ponc(1);

    cout<<endl;

    cout<<"El elemento eliminado es: "<<a.quitac()<<"\n";
    cout<<"El elemento eliminado es: "<<a.quitac()<<"\n";
    cout<<"El elemento eliminado es: "<<b.quitac()<<"\n";
    cout<<"El elemento eliminado es: "<<b.quitac()<<"\n\n";
    return 0;
}