
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int suma;
float imp=0.33;
class datos{
    char nombre[10];
    int ID;
    float sueldo;
    char puesto[15];
    float impuesto;
    float pago;

    public:
        void reddata(void);
        void writedata(ofstream &archivo);
        void reportdata(ofstream &archivo);
};

void datos::reddata(void){
    cout<<"introdusca ID: ";cin>>ID;
    cout<<"introdusca nombre: ";cin>>nombre;
    cout<<"introdusca puesto: ";cin>>puesto;
    cout<<"introdusca sueldo: ";cin>>sueldo;
    impuesto=sueldo*imp;
    pago=sueldo-impuesto;

}

void datos::writedata(ofstream &archivo){
    cout<<setiosflags(ios::right)
        <<setw(10)<<ID
        <<setw(10)<<nombre
        <<setiosflags(ios::right)
        <<setw(10)<<puesto
        <<setw(11)<<sueldo
        <<setiosflags(ios::right)
        <<setw(10)<<impuesto
        <<setw(10)<<pago
        <<endl;
}

void datos::reportdata(ofstream &archivo){
    cout<<"\t\t\t\t";
    cout<<setiosflags(ios::right)
        <<setw(10)<<ID
        <<setw(10)<<nombre
        <<setiosflags(ios::right)
        <<setw(10)<<puesto
        <<setw(11)<<sueldo
        <<setiosflags(ios::right)
        <<setw(10)<<impuesto
        <<setw(10)<<pago
        <<endl;

}

int main(){
    datos articulo[10];
    ofstream archivo;

    archivo.open("REPORTE.txt",ios::in|ios::out);

    cout<<"Introdusca 10 registros \n";
    for(int i;i<10;i++){
        articulo[i].reddata();
        archivo.write((char*)& articulo[i],sizeof(articulo[i]));
    }
    archivo.seekg(0);

    cout<<"\n SALIDA \n\n";
    for(int i;i<10;i++){
        
        archivo.read((char*)& articulo[i],sizeof(articulo[i]));
        articulo[i].writedata();
    }

    archivo.seekg(0);
    system("cls");
    archivo<<"\n\t\t\t\t     Reportes de empleados           \n"<<endl;
    archivo<<"\n"<<endl;
    archivo<<"\t\t\t\t     ID       Nombre     Puesto    Sueldo    Impuesto   Pago    \n"<<endl;

    for(int i;i<10;i++){
        archivo.read((char*)& articulo[i],sizeof(articulo[i]));
        articulo[i].reportdata();
    }
    

    archivo.close();
    cout<<"\n\n\n";
    return 0;

    


}