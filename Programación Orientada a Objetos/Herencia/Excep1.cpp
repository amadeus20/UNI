//Excepciones 
#include <iostream>

using namespace std;

int main(){
    try
    {
        int num=5;
        //int num=0;
        //int num_-2;

        if(num<0)
            throw"error en el sistema";
        if(num==0)
            throw 5;

        cout<<num<<endl;
    }
    catch(const char*dato)
    {
        cout<<dato<<"45"<<endl;
    }
    catch(int dato)
    {
        cout<<"error numero"<<dato<<endl;
    }
    catch(...)
    {
        cout<<"Error"<<endl;
    }

    return 0;
    
}