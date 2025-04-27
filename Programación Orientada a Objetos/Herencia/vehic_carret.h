#ifndef vehic_carret_H
#define vehic_carret_H
#include<string>

class vehic_carret
{
    int ruedas;
    int pasajeros;
    public:
        void esc_ruedas(int num);
        int preg_ruedas(void);
        void esc_pass(int num);
        int preg_pas(void);
};
#endif