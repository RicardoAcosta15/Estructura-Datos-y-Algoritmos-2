/*
 Asignatura: IDS344-01 - ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesus Bido 1105909

 Evidencia: La cadena mas larga

 Fecha: 23/11/2022
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
	cout << "La cadena más larga\n" << endl;
	cout << "En una fiesta hay 99 invitados, a cada una de ellos se le ha dado un número entero comprendido entre 1 y 99, acompañados a unos instrucciones. Si su número es Par divide por 2, si es impar se multiplica por 3 y al resultado se suma 1. Repitiendo hasta que llega a 4.\n" << endl;

	for (int i = 1; i < 100; i++)
	{
		CreacionCadenas(i);
		//TodasLasCadenas(i);
	}

	Max = Cont[0];

	for (int a = 0; a < 99; a++)
	{
		if (Cont[a] > Max) { Max = Cont[a]; Pos = a; }
	}

	cout << "La cadena mas larga es la del " << (Pos + 1) << ".\n" << endl;

	CadenaMasLarga(Pos + 1);
	cout << "Contador de Cadena: " << Max << endl;

	return 0;
}

void CreacionCadenas(int i)
{
	int N = i, C = 0, M;
	bool Conf = true;

	while (Conf != false)
	{
		M = N % 2;
		(M == 0) ? N = (N / 2) : N = (N * 3) + 1;
		if (N == 4) { Conf = false; }
		C++;
	}
	Cont[i - 1] = C;
}

void CadenaMasLarga(int a)
{
	int N = a, M;
	bool Conf = true;
	cout << N << " = ";

	while (Conf != false)
	{
		M = N % 2;
		(M == 0) ? N = (N / 2) : N = (N * 3) + 1;
		(N != 4) ? cout << N << " - " : cout << N << "\n" << endl;
		if (N == 4) { Conf = false; }
	}
}

void TodasLasCadenas(int i)
{
	int N = i, C = 0, M;
	bool Conf = true;

	cout << N << " = ";

	while (Conf != false)
	{
		M = N % 2;
		(M == 0) ? N = (N / 2) : N = (N * 3) + 1;
		(N != 4) ? cout << N << " - " : cout << N << "\n" << endl;
		if (N == 4) { Conf = false; }
		C++;
	}
	cout << "Contador de Cadena: " << C << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}