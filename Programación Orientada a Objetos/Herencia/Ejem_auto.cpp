#include <iostream>
#include "vehic_carret.h"
#include "automovil.h"

using namespace std;

void vehic_carret::esc_ruedas(int num)
{
    ruedas=num;
}
int vehic_carret::preg_ruedas(void)
{
    return ruedas;
}
void vehic_carret::esc_pass(int num)
{
    pasajeros=num;
}
int vehic_carret::preg_pas(void)
{
    return pasajeros;
}

////----------------------------automovil

void automovil::esc_tipo(enum tipo t)
{
    tipo_coche=t;
}
enum tipo automovil::preg_tipo(void)
{
    return tipo_coche;
}

void auotmovil::mostrar(void)
{
    cout<<"\t ruedas      : "<<preg_ruedas()<<"\n";
    cout<<"\t pasajeros   : "<<preg_ruedas()<<"\n";
    cout<<"\t tipo        : ";
    switch (preg_tipo())
    {
        case furgoneta: cout<<"furgoneta \n";
                break;
        case coche: cout<<"coche  \n";
                break;
        case ranchera: cout<<"ranchera  \n";
    }

}

main()
{
    automovil c;

    c.esc_ruedas(4);
    c.esc_pass(6);
    c.esc_tipo(furgoneta);
    c.mostrar();

    return 0;
}