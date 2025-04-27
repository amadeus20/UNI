#include<iostream>
#include"suma.h"
using namespace std;
void gotoxy(short x, short y);
void bubblesort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size -i -1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>= 0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}


void printArray(int arr[], int size, int s, int t){
    int i=0;
    for (i = 0; i < size; i++)
    {
        //gotoxy(s, i+t);
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl<<endl;
}

void printArray1(int arr[], int size, int s, int t){
    for (int i = 0; i < size; i++)
    {
        //gotoxy(s, i+t);
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[]={54, 37, 81, 12, 95, 6, 23, 68, 47, 76, 29, 42};
    int arr2[]={42, 29, 76, 47, 68, 23, 6, 95, 12, 81, 37, 54};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"             Burbuja             "<<"\n\n";
    cout<<"Lista original: ";
    printArray(arr,size, 20, 5);
    bubblesort(arr,size);
    cout<<"Lista ordenada: ";
    printArray(arr,size, 40, 5);
    cout<<"             Insercion             "<<"\n\n";
    cout<<"Lista original: ";
    printArray1(arr2,size, 20, 24);
    insertionSort(arr2,size);
    cout<<"Lista ordenada: ";
    printArray1(arr2,size, 40, 24);

    cout<<endl<<endl<<endl;
    cout<<"\t\t\t fue una gran prueba";
    return 0;
}
