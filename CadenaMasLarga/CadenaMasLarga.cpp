/*
 Asignatura: IDS344-01 - LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean G�ichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert Le�n 1105634
 - Sebastian Peralta 1105487
 - Jorge Cruz 1105612

 Evidencia: Cadena M�s Larga

 Fecha: 24/11/2022
*/

#include <iostream>
#include <locale.h>

using namespace std;

//Prototipo de funciones
void CreacionCadenas(int i);
void CadenaMasLarga(int a);

int Cont[98], Max, Pos = 0;

int main()
{
	for (int i = 1; i < 100; i++) // Se eval�an los num del 1 al 99
	{
		CreacionCadenas(i);
		//TodasLasCadenas(i);
	}

	Max = Cont[0];  // Max toma la primera pos del array

	for (int a = 0; a < 99; a++)  //Expl�came ah� w pls
	{
		if (Cont[a] > Max) { Max = Cont[a]; Pos = a; }
	}

	cout << "La cadena mas larga es la del " << (Pos + 1) << ".\n" << endl;

	CadenaMasLarga(Pos + 1);
	cout << "Contador de Cadena: " << Max << endl;

	return 0;
}

void CreacionCadenas(int i) // Creamos las cadenas
{
	int num = 0, cont = 0, mod;
	bool confirmar = false;

	num = i;

	while (confirmar != true)
	{
		mod = num % 2; // Usamos el m�dulo para saber si es par

		(mod == 0) ? num /= 2 : num = (num * 3) + 1;  // Si el mod es 0 significa que el num es par

		if (num == 4) { confirmar = true; }  // Si num llega a 4 paramos la cadena

		cont++;  // Cuenta las repeticiones
	}
	Cont[i - 1] = cont;  //Guarda el total de repeticiones del num en un array
}

void CadenaMasLarga(int a)  // Determina la cadena m�s larga
{
	int num = 0, mod;
	bool confirmar = false;
	num = a;
	cout << num << " = ";

	while (confirmar != true)
	{
		mod = num % 2;

		(mod == 0) ? num /= 2 : num = (num * 3) + 1;

		(num != 4) ? cout << num << " - " : cout << num << "\n" << endl; //Mientras num no sea 4, imprime un gui�n

		if (num == 4) { confirmar = true; }
	}
	cout << "Contador de Cadena: " << C << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}