#include<iostream>
using namespace std;

class Tiempo{
    private:
        int hrs;
        int mins;
        int segs;
    public:
    Tiempo(){ //Se inicia el tiempo en 00:00:00
        segs=0;
        mins=0;
        hrs=0;
    }

    void VerHora(void){
        cout<<hrs<<":"<<mins<<":"<<segs;
    }
    void LeerTiempo(void){ //Lee la hora del teclado
        cout<<"\nDame la hora: ";
        cin>>hrs;
        cout<<"\nDame los minutos: ";
        cin>>mins;
        cout<<"\nDame los segundos: ";
        cin>>segs;


        cout<<hrs<<":"<<mins<<":"<<segs;
    }
    Tiempo & operator ++(){
        segs++;
        if(segs>59){
            segs-=60;
            ++mins;
        }
        if(mins>59){
            mins-60;
            ++hrs;
        }
        return*this;
    }


};

int main(){
    Tiempo t1;
    cout<<"\nIntrodusca hora (hh:mm:ss): ";
    t1.LeerTiempo();
    for (int i = 0; i<=10; i++)
    {
        cout<<"\n Visualizar t1: ";
        t1.VerHora();
        ++t1;
        cout<<"\n Despues de incrementar, t1= ";
        t1.VerHora();
    }
    
    
    return 0;
    
}