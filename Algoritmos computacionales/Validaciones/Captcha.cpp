//Validacion de Captcha
//Se utiliza para asegurar que el usuario que realiza una operación es humano y no
//un programa automatizado (bot).

#include <iostream>
#include <cstdlib> // Para std::rand y std::srand
#include <ctime> // Para std::time
#include <string>
#include <locale.h>
using namespace std;
// Función para generar un código captcha aleatorio
string generarCaptcha(int longitud) {
string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
string captcha = "";
for (int i = 0; i < longitud; ++i) {
captcha += caracteres[rand() % caracteres.size()];
}
return captcha;
}
// Función para validar si el usuario ingresó correctamente el captcha
bool validarCaptcha(const string& captchaGenerado, const string& captchaIngresado) {
return captchaGenerado == captchaIngresado;
}
int main() {
setlocale(LC_ALL, "spanish");
// Inicializar la semilla para generación de números aleatorios
srand(static_cast<unsigned int>(time(0)));
// Generar un captcha de 6 caracteres
string captchaGenerado = generarCaptcha(6);
string captchaIngresado;
cout << "Por favor, ingrese el siguiente código captcha para verificar que no es un robot:" << endl;
cout << "Captcha: " << captchaGenerado << endl;
cout << "Ingrese el captcha: ";
cin >> captchaIngresado;
// Validar el captcha ingresado
if (validarCaptcha(captchaGenerado, captchaIngresado)) {
cout << "Verificación exitosa. ¡No eres un robot!" << endl;
} else {
cout << "Error: Captcha incorrecto. Intente de nuevo." << endl;
}
return 0;
}