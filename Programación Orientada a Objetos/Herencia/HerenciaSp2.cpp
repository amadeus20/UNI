//Herencia simple publica
#include <iostream>
using namespace std;
class B{
    int a;
    public:
    int b;
    void get_ab();
    int get_a(void);
    void show_a(void);
};
class D:public B
{
    int c;
    public:
        void mul(void);
        void display(void);
};

//-------------------funciones o metodos de la clase madre

void B::get_ab(void){
    a=5;
    b=10;
}
int B::get_a(){
    return a;
}
void B::show_a(){
    cout<<"a= "<<a<<"\n";

}
void D::mul(){
    c=b*get_a();
}
void D::display(){
    cout<<"a= "<<get_a()<<"\n";
    cout<<"b= "<<b      <<"\n";
    cout<<"c= "<<c      <<"\n";
}

int main(){
    D m;

    m.get_ab();
    m.mul();
    m.show_a();
    m.display();
    cout<<"\n";
    m.b=20;
    m.mul();
    m.display();

    return 0;

}