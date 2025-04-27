#ifndef automovil_H
#define automovil_H
#include "vehic_carret.h"
#include<string>

enum tipo{coche,furgoneta,ranchera};

class automovil:public vehic_carret
{
    enum tipo tipo_coche;
    public:
        void esc_tipo(enum tipo t);
        enum tipo preg_tipo(void);
        void mostrar(void);
};

#endif
