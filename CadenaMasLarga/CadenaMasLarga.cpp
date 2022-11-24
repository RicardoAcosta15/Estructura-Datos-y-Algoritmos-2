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

void CreacionCadenas(int i);
void CadenaMasLarga(int i);
void TodasLasCadenas(int i);

int Cont[98], Max, Pos = 0;

int main()
{
	setlocale(LC_ALL, "");
	cout << "La cadena m�s larga\n" << endl;
	cout << "En una fiesta hay 99 invitados, a cada una de ellos se le ha dado un n�mero entero comprendido entre 1 y 99, acompa�ados a unos instrucciones. Si su n�mero es Par divide por 2, si es impar se multiplica por 3 y al resultado se suma 1. Repitiendo hasta que llega a 4.\n" << endl;

	for (int i = 1; i < 100; i++) // Se eval�an los num del 1 al 99
	{
		CreacionCadenas(i);
		//TodasLasCadenas(i);
	}

	Max = Cont[0];  // Max toma la primera pos del array

	for (int a = 0; a < 99; a++)  // Busca el contador m�s grande
	{
		if (Cont[a] > Max) { Max = Cont[a];Pos = a; }  //Si el contador es mayor que Max, Max toma la siguiente pos del array
	}

	CadenaMasLarga(Pos + 1);  //Toma el num con m�s repeticiones
	cout << "Contador de Cadena: " << Max << endl;

	return 0;
}

void CreacionCadenas(int i) // Obtenemos el numero de repeticiones de cada numero del rango
{
	int num = i, cont = 0, mod;
	bool Conf = true;

	while (Conf != false)
	{
		mod = num % 2; // Usamos el m�dulo para saber si es par
		(mod == 0) ? num = (num / 2) : num = (num * 3) + 1;  // Si el mod es 0 significa que el num es par
		if (num == 4) { Conf = false; }  // Si num llega a 4 paramos el bucle
		cont++; // Cuenta las repeticiones
	}
	Cont[i - 1] = cont;  //Guarda el total de repeticiones del num en un array
}

void CadenaMasLarga(int a)  // Imprime la cadena del num con m�s repeticiones
{
	int num = a, mod;
	bool Conf = true;
	cout << num << " = ";

	while (Conf != false)
	{
		mod = num % 2;
		(mod == 0) ? num = (num / 2) : num = (num * 3) + 1;
		(num != 4) ? cout << num << " - " : cout << num << "\n" << endl; //Mientras num no sea 4, imprime un gui�n
		if (num == 4) { Conf = false; }
	}
}

void TodasLasCadenas(int i)  //Imprime las cadenas de todos los numeros
{
	int num = i, cont = 0, mod;
	bool Conf = true;

	cout << num << " = ";

	while (Conf != false)
	{
		mod = num % 2;
		(mod == 0) ? num = (num / 2) : num = (num * 3) + 1;
		(num != 4) ? cout << num << " - " : cout << num << "\n" << endl;
		if (num == 4) { Conf = false; }
		cont++;
	}
	cout << "Contador de Cadena: " << cont << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}
