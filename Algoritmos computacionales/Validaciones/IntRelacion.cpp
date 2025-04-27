//Validacion por Integridad Relacional
//En bases de datos relacionales, la validación de integridad referencial asegura que
//las claves foráneas referencien registros existentes en las tablas 
//correspondientes.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale.h>
using namespace std;
// Estructura para representar un Cliente
struct Cliente {
int id;
string nombre;
};
// Estructura para representar una Orden
struct Orden {
int id;
int clienteId; // ID del cliente que realizó la orden
string descripcion;
};
// Función para verificar si un cliente tiene órdenes asociadas
bool tieneOrdenesAsociadas(int clienteId, const vector<Orden>& ordenes) {
for (const auto& orden : ordenes) {
if (orden.clienteId == clienteId) {
return true; // Se encontró una orden vinculada al cliente
}
}
return false; // No hay órdenes asociadas al cliente
}
// Función para mostrar las órdenes asociadas a un cliente
void mostrarOrdenesCliente(int clienteId, const vector<Orden>& ordenes) {
bool tieneOrdenes = false;
for (const auto& orden : ordenes) {
if (orden.clienteId == clienteId) {
cout << " Orden ID: " << orden.id << ", Descripción: " << orden.descripcion << endl;
tieneOrdenes = true;
}
}
if (!tieneOrdenes) {
cout << " No hay órdenes asociadas." << endl;
}
}
// Función para eliminar un cliente con validación de integridad referencial
bool eliminarCliente(int clienteId, vector<Cliente>& clientes, vector<Orden>& ordenes) {
if (tieneOrdenesAsociadas(clienteId, ordenes)) {
cout << "Error: No se puede eliminar el cliente con ID " << clienteId
<< " porque tiene órdenes asociadas." << endl;
return false;
}
// Eliminar cliente si no tiene órdenes asociadas
auto it = remove_if(clientes.begin(), clientes.end(),
[clienteId](const Cliente& cliente) { return cliente.id == clienteId; });
if (it != clientes.end()) {
clientes.erase(it, clientes.end());
cout << "Cliente con ID " << clienteId << " eliminado exitosamente." << endl;
return true;
} else {
cout << "Cliente con ID " << clienteId << " no encontrado." << endl;
return false;
}
}
int main() {
setlocale(LC_ALL,"spanish");
vector<Cliente> clientes = {
{1, "Juan Pérez"},
{2, "Maria López"},
{3, "Carlos Ruiz"}
};
vector<Orden> ordenes = {
{1, 1, "Orden de productos electrónicos"},
{2, 3, "Orden de artículos de oficina"}
};
int clienteId;
// Mostrar clientes actuales con sus órdenes
cout << "Clientes actuales:" << endl;
for (const auto& cliente : clientes) {
cout << "ID: " << cliente.id << ", Nombre: " << cliente.nombre << endl;
mostrarOrdenesCliente(cliente.id, ordenes);
}
cout << "\nIngrese el ID del cliente que desea eliminar: ";
cin >> clienteId;
// Intentar eliminar el cliente con validación de integridad referencial
eliminarCliente(clienteId, clientes, ordenes);
// Mostrar lista de clientes después del intento de eliminación
cout << "\nClientes después de la operación:" << endl;
for (const auto& cliente : clientes) {
cout << "ID: " << cliente.id << ", Nombre: " << cliente.nombre << endl;
mostrarOrdenesCliente(cliente.id, ordenes);
}
return 0;
}