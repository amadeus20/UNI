#include <iostream>
#include <string>

using namespace std;

class LibroCalificaciones{

    public:

    void MostrarMensaje(string nombreCurso) const{
        cout<<endl;
        cout<<"Bienvenido al libro de calificaciones para: "<<nombreCurso<<"!"<<endl;
        cout<<endl;

    }

};

int main(){
    string nombredelCurso;
    LibroCalificaciones miLibroCalificaciones;

    cout <<"Escribe el nombre del curso como entrada"<<endl;
    getline(cin,nombredelCurso);

    cout<<endl;

    miLibroCalificaciones.MostrarMensaje(nombredelCurso);
    
}