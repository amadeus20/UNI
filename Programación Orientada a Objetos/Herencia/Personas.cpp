#include <iostream>

using namespace std;

class Persona{
    private:
        string nombre;
        int edad;
    public:
        Persona(string, int);
        virtual void mostrar();

};

Persona::Persona(string _nombre,int _edad){           //Contructor de la clase persona
    nombre=_nombre;
    edad=_edad;

}

void Persona::mostrar(){                           ///La rutina mostra, de la clase persona
    cout<<"Nombre           :"<<nombre<<endl;
    cout<<"Edad             :"<<edad<<endl;

};
//------------------------clase derivada alumno--------------

class Alumno:public Persona{
    private:
        float notaFinal;
    public: 
        Alumno(string,int,float);
        void mostrar();
};

///-------------------constructor de la clase alumno----------

Alumno::Alumno(string _nombre,int _edad, float _notaFinal):Persona(_nombre,_edad){
    notaFinal=_notaFinal;
};

void Alumno::mostrar(){
    Persona:mostrar();
    cout<<"Nota Final: "<<notaFinal<<endl;
}

////--------------------Clase derivada profesor------

class Profesor:public Persona{
    private:
        string materia;
    public:
        Profesor(string ,int,float);
        void mostrar();

};

//------------------constructor de la clase profesor----------

Profesor::Profesor(string _nombre,int _edad, string _materia):Persona(_nombre,_edad){
    materia=_materia;
}
void Profesor::mostrar(){
    Persona::mostrar();
    cout<<"materia                         :"<<materia<<endl;
}


////--------------------------main----------------------

int main(){
    Persona*vector[4];

    vector[0]=new Alumno("Alejandro",18,18.9);
    vector[1]=new Alumno("Maria",19,15.5);
    vector[2]=new Alumno("Pedro",15,10.5);
    vector[3]=new Alumno("Jose",25,"algoritmos");

}




