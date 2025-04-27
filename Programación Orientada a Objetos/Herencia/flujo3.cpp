//fulos 3

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int suma;
class inventario{
    char nombre[10];
    int codigo;
    float coste;

    public:
        void reddata(void);
        void writedata(void);
        void reportdata(void);
};

void inventario::reddata(void){
    cout<<"introdusca nombre: ";cin>>nombre;
    cout<<"introdusca codigo: ";cin>>codigo;
    cout<<"introdusca precio: ";cin>>coste;
}
void inventario::writedata(void){
    cout<<setiosflags(ios::right)
        <<setw(10)<<nombre
        <<setiosflags(ios::right)
        <<setw(10)<<codigo
        <<setw(10)<<coste
        <<endl;
}
void inventario::reportdata(void){
    cout<<"\t\t\t\t";
    cout<<setiosflags(ios::right)
        <<setw(10)<<nombre
        <<setiosflags(ios::right)
        <<setw(10)<<codigo
        <<setw(11)<<coste
        <<endl;

    suma=suma+coste;
}
int main(){
    inventario articulo[3];
    fstream archivo;
    archivo.open("STOCK.DAT",ios::in|ios::out);

    cout<<"Introdusca detalles de tres articulos \n";
    for(int i;i<3;i++){
        articulo[i].reddata();
        archivo.write((char*)& articulo[i],sizeof(articulo[i]));
    }
    archivo.seekg(0);

    cout<<"\n SALIDA \n\n";
    for(int i;i<3;i++){
        
        archivo.read((char*)& articulo[i],sizeof(articulo[i]));
        articulo[i].writedata();
    }

    archivo.seekg(0);
    system("cls");
    cout<<"\n\t\t\t\t     Las tortas locas CDMX            \n";
    cout<<"\n\t\t\t\t       Sucursal Polanco               \n";
    cout<<"\n";
    cout<<"\t\t\t\t     Nombre    Codigo     Precio        \n";

    for(int i;i<3;i++){
        archivo.read((char*)& articulo[i],sizeof(articulo[i]));
        articulo[i].reportdata();
    }

    cout<<"\t\t\t\t                Total:       "<<suma;

    archivo.close();
    cout<<"\n\n\n";
    return 0;

    


}

