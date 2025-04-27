#include <iostream>
using namespace std;

class obj_geom{

    public:
        obj_geom(float x=0, floaty=0):xC(x),yC(x){}
        void imprimir() const{
            cout<<xC<<"  "<<yC<<endl;
        }
    protected:
        float xC, yC;

};

const float PI=3.14159265;

class circulo: public obj_geom{

    public:
        circulo(float x_C, float y_C, float r):obj_geom(x_C,y_C){
            radio=r;
        }
        float
    

};

class cuadrado:public obj_geom{
    public:
        cuadrado(float x_C,y_C)
}

