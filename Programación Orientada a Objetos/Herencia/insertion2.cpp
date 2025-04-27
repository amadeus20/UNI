//insercion 2
#include <iostream>
using namespace std;


void insertionSort(int arr[],int size){
    for(int i=1;i<size; ++i){

        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    }
}

void printArray(int arr[],int size){
    for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
    }

    cout<<endl;
}

int main(){
    int arr[]={54,37,81,12,95,6,23,68,47,76,29,42};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout <<"             insercion                  "<<"\n\n";
    cout<<"Lista original: ";
    printArray(arr,size);

    insertionSort(arr,size);

    cout<<"Lista ordenada: ";
    printArray(arr,size);

    return 0;
}
