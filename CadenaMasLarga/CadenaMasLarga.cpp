/*
 Asignatura: IDS344-01 - ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesus Bido 1105909

 Evidencia: Cadena Más Larga

 Fecha: 24/11/2022
*/

#include <iostream>

using namespace std;

#include <iostream>
#include <locale.h>

using namespace std;

// Prototipo de funciones
void CreacionCadenas(int i);
void CadenaMasLarga(int i);
void TodasLasCadenas(int i);

int Cont[98], Max, Pos = 0;

int main()
{
	setlocale(LC_ALL, "");
	cout << "La cadena más larga\n" << endl;
	cout << "En una fiesta hay 99 invitados, a cada una de ellos se le ha dado un número entero comprendido entre 1 y 99, acompañados a unos instrucciones. Si su número es Par divide por 2, si es impar se multiplica por 3 y al resultado se suma 1. Repitiendo hasta que llega a 4.\n" << endl;

	for (int i = 1; i < 100; i++) // Se evalúan los num del 1 al 99
	{
		CreacionCadenas(i);
		//TodasLasCadenas(i);
	}

	Max = Cont[0];  // Max toma la primera pos del array

	for (int a = 0; a < 99; a++) //Encuentra el cont más grande
	{
		if (Cont[a] > Max) { Max = Cont[a];Pos = a; }  //Si Max es menor, Max pasa a la siguiente pos del array
	}

	CadenaMasLarga(Pos + 1); //Imprimimos el num con el mayor contador
	cout << "Contador de Cadena: " << Max << endl;

	return 0;
}

void CreacionCadenas(int i) // Determina las veces que se repite el proceso para cada numero
{
	int num = i, cont = 0, mod;
	bool confirmar = true;

	while (confirmar != false)
	{
		mod = num % 2; // Usamos el módulo para saber si es par
		(mod == 0) ? num /= 2 : num = (num * 3) + 1;  // Si el mod es 0 significa que el num es par
		if (num == 4) { confirmar = false; }  // Si num llega a 4 paramos el bucle
		cont++;  // Cuenta las repeticiones
	}
	Cont[i - 1] = cont;  //Guarda el total de repeticiones del num en un array
}

void CadenaMasLarga(int a)  // Imprime la cadena del num con más repeticiones
{
	int num = a, mod;
	bool confirmar = true;
	cout << num << " = ";

	while (confirmar != false)
	{
		mod = num % 2;
		(mod == 0) ? num /= 2 : num = (num * 3) + 1;
		(num != 4) ? cout << num << " - " : cout << num << "\n" << endl;  //Mientras num no sea 4, imprime un guión
		if (num == 4) { confirmar = false; }
	}
}

void TodasLasCadenas(int i)  // Imprime todas las cadenas del 1 al 99
{
	int num = i, cont = 0, mod;
	bool confirmar = true;

	cout << num << " = ";

	while (confirmar != false)
	{
		mod = num % 2;
		(mod == 0) ? num /= 2 : num = (num * 3) + 1;
		(num != 4) ? cout << num << " - " : cout << num << "\n" << endl; 
		if (num == 4) { confirmar = false; }
		cont++;
	}
	cout << "Contador de Cadena: " << cont << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}