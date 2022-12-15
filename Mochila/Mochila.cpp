/*
 Asignatura: IDS344-01 - LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesús Bidó 1105909

 Evidencia: Mochila cargada

 Fecha: 15/12/2022
*/

#include <iostream>

using namespace std;

int max(int a, int b);
int mochila(int umbral, int pesoPaquetes[], int beneficio[], int paquetes);

int main()
{
	int pesoPaquetes[] = { 10, 20, 30, 40, 50 };
	int beneficio[] = { 20, 30, 65, 40, 60 };

	int umbral = 100;

	int paquetes = 5;

	cout << "El beneficio maximo sin sobrepasar el umbral es: " << mochila(umbral, pesoPaquetes, beneficio, paquetes) << endl;

	return 0;
}


int max(int a, int b) {
	return (a > b) ? a : b;
}  //devuelve el beneficio maximo

int mochila(int umbral, int pesoPaquetes[], int beneficio[], int paquetes)
{
	// Si el umbral es 0 o la cantidad de paquetes es 0, devolvera un 0
	if (paquetes == 0 || umbral == 0)
		return 0;

	// Si el peso de uno de los paquetes es superior a al umbral de la mochila
	// Entonces este paquete no puede ser incluido en la solucion del beneficio maximo
	if (pesoPaquetes[paquetes - 1] > umbral) {
		return mochila(umbral, pesoPaquetes, beneficio, paquetes - 1);
	}
	// Retorna el mayor beneficio de la combinacion de valores
	else {
		return max(beneficio[paquetes - 1] + mochila(umbral - pesoPaquetes[paquetes - 1], pesoPaquetes, beneficio, paquetes - 1), mochila(umbral, pesoPaquetes, beneficio, paquetes - 1));
	}
}