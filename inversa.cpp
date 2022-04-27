#include <iostream>
using namespace std;
//alumno: Bryan Suca Jaramillo
int mul_inv(int a, int b)

{
    //definiendo variables que ayudaran a crear el inverso
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;

    // Si b es igual 1 ahi acaba
	if (b == 1){
        return 1;}
    //bucle hasta que se cumpla la condicion para salir
	while (a > 1) {
		q = a / b; // Encontramos la division de los numeros 
        
		t = b; // reemplazamos en una variable temporal t a b 
        b = a % b; // b viene a convertirse en un nuevo resultado del modulo de a y b 
        a = t; // La variable temporal se convierte a a            

		t = x0; // convertimos a la variable temporal nuevamente en 0
        //condicion para evuluar el inverso multiplicativo
        x0 = x1 - q * x0; 
        x1 = t;
    }
    // cuando sale del bucle evaluara dicha informacion para retonar el inverso multiplicativo
	if (x1 < 0){

        x1 += b0;
        cout << "La respuesta es: " ;
        return x1;
    }
    
}
// Funcional principal que evalua si el numero b es positivo e imprime la funcion creada.
int main(void) {
    int a, b;
    //Pedimos los numeros para evaluar el Inverso Multiplicativo
    cout << "Escribe el primer numero a: " <<endl;
    cin >> a;
    cout << "Escribe el segundo numero b: " <<endl;
    cin >> b; 

    if (b > 0){
	    cout << mul_inv(a, b) << endl;
    }
    if (b < 0){
        cout << "Escriba el segundo numero como positivo" <<endl;
    }

	return 0;
}