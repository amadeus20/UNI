#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char data[100];

    ofstream outfile;
    outfile.open("gfg.txt");
    cout<<"writing to the file"<<endl;
    cout<<"Enter your name: ";
    
    cin.getline(data, 100);

    outfile<<data<<endl;

    outfile.close();

    ifstream infile;
    infile.open("gfg.txt");

    cout<<"Reading from the file"<<endl;
    infile>>data;

    cout<<data<<endl;

    infile.close();

    return 0;
}

