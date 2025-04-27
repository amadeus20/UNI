#include <iostream>

class Animal{
    public:
        virtual void come(){std::cout <<"Yo como, como un animal generico.\n";}
        virtual ~Animal(){}


};

class Lobo: public Animal{
    public:
        void come(){std::cout<<"¡Yo como como un lobo.\n";}
        virtual~Lobo(){}

};

class Pez:public Animal{
    public:
        void come(){std::cout<<"¡Yo como com un pez.\n";}
        virtual~Pez(){
        }
};

class OtroAnimal:public Animal{
    virtual~OtroAnimal(){}
};

int main(){
    Animal*unAnimal[4];
    unAnimal[0]=new Animal();
    unAnimal[1]=new Lobo();
    unAnimal[2]=new Pez();
    unAnimal[3]=new OtroAnimal();

    for(int i=0;i<4;i++){
        unAnimal[i]->come();
    }
    for(int i=0;i<4;i++){
        delete unAnimal[i];
    }

    return 0;

}
