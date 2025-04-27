//Validacion por Formato
//Se utiliza para validar si el formato de la entrada es correcto, generalmente se 
//aplica
//a campos como correos electrónicos, fechas o números de teléfono, que tienen un
//formato específico.
#include <iostream>
using namespace std;
bool esCorreoValido(const char* correo) {
bool arroba = false, punto = false, domi=false;
int j=0;
char dominio[]={'y','a', 'h','o','o'};
for (int i = 0; correo[i] != '\0'; ++i) { // el valor de fin de string o carro es \0
if (correo[i] == '@') {
arroba = true;
j=i+1; //salva la posición de el @
} else if (arroba && correo[i] == '.') {
punto = true;
}
}
int i=0;
if (arroba){
while (dominio[i] != '\0'&& correo[j]==dominio[i]){
cout<< " el correo "<< correo [j]<< " dominio "<< dominio[i]<<endl;
i++;
j++;
}
if (correo[j]=='.' ){
domi=true;
}
}
return arroba && punto && domi;
}
int main() {
char correo[50];
cout<< "Teclee un correo con la sigiente: usuario@dominio.com ";
cin>> correo;
if (esCorreoValido(correo)) {
cout << "Correo válido." << endl;
} else {
cout << "Correo inválido." << endl;
}
return 0;
}
