#include<iostream>
using namespace std;

class Test{
    private:
        int x;
    public:
        Test(int x=0){this ->x=x;}
        void change(Test *t){this->x=x;}
        void print(){cout <<"x == "<<x<<endl;}
};

int main(int argc, char const *argv[])
{
    Test obj(15);
    Test *ptr = new Test(10);
    obj.change(ptr);
    obj.print();
    return 0;
}
