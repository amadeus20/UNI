#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,c,sum, valorBuscado;
    
    // Ingresar el tamaño de la lista
    cout << "Ingrese el número de elementos de la lista: ";
    cin >> n;
    
    // Verificar si la lista está vacía
    if(n <= 0) {
        cout << "La lista está vacía." << endl;
        return 0;
    }
    
    // Ingresar los elementos de la lista
    vector<int> lista(n);
    for(int i=0;i<n;i++){
        cout<<"Teclea el datos para la coordenada %d de vector X: ",i;
        cin>>lista[i];
        sum=sum+lista[i];
    }
    
    // Ingresar el valor a buscar
    cout << "Ingrese el valor a buscar: ";
    cin >> valorBuscado;
    
    // Búsqueda lineal
    bool encontrado = false;
    for (int i = 0; i < n && valorBuscado>=lista[i]; i++) {
        c++;
        if(lista[i] == valorBuscado) {
            encontrado = true;
            break;
        }
    }
    
    // Mostrar el resultado
    if(encontrado)
        cout << "\n Encontre el valor %i, veces %i, iteraciones %i"<< endl;
    else
        cout << "Valor no encontrado." << endl;
    
    return 0;
}
