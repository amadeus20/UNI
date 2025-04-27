#include<iostream>
using namespace std;

class test{
    private:
        int x;
    public:
        void setX (int x){
            this ->x=x;
        }
        void print(){cout <<"x == "<<x<<endl;}
};

int main(int argc, char const *argv[])
{
    test obj;
    int x=20;
    obj.setX(x);
    obj.print();
    return 0;
}
