//Validacion por Redundancia
//Esta validación asegura que no se ingresen datos duplicados innecesarios.
#include <iostream>
#include <unordered_set> // Para la estructura de hash
#include <string>
#include <limits> // Para std::numeric_limits
using namespace std;
int main() {
setlocale(LC_ALL, "Spanish");
unordered_set<string> clientesRegistrados; // Almacena nombres únicos de clientes
string nombreCliente;
char opcion;
cout << "Sistema de Gestión de Clientes (Validación de Duplicados)" << endl;
do {
cout << "\nIngrese el nombre del cliente: ";
getline(cin, nombreCliente);
// Validación de duplicados
if (clientesRegistrados.find(nombreCliente) != clientesRegistrados.end()) {
cout << "Error: El cliente '" << nombreCliente << "' ya está registrado." << endl;
} else {
clientesRegistrados.insert(nombreCliente); // Registrar nuevo cliente
cout << "Cliente registrado correctamente: " << nombreCliente << endl;
}
cout << "\n¿Desea registrar otro cliente? (s/n): ";
cin >> opcion;
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
} while (opcion == 's' || opcion == 'S');
// Mostrar la lista final de clientes registrados
cout << "\nLista de clientes registrados:" << endl;
for (const auto& cliente : clientesRegistrados) {
cout << cliente << endl;
}
return 0;
}