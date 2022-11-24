// CadenaMasLarga.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void CreacionCadenas(int i);
void CadenaMasLarga(int i);

int Cont[98], Max, Pos = 0;

int main()
{

	for (int i = 1; i < 100; i++)
	{
		CreacionCadenas(i);
	}

	Max = Cont[0];

	for (int a = 0; a < 99; a++)
	{
		if (Cont[a] > Max)
		{
			Max = Cont[a];
			Pos = a;
		}
	}

	CadenaMasLarga(Pos + 1);
	cout << "Contador de Cadena: " << Cont[Pos] << endl;

	return 0;
}

void CreacionCadenas(int i)
{
	int N = 0, C = 0, M;
	bool Conf = true;

	Conf = true;
	N = i;
	C = 0;

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
	int N = 0, M;
	bool Conf = true;
	N = a;
	cout << N << " = ";

	while (Conf != false)
	{
		M = N % 2;

		(M == 0) ? N = (N / 2) : N = (N * 3) + 1;

		(N != 4) ? cout << N << " - " : cout << N << "\n" << endl;

		if (N == 4) { Conf = false; }
	}
}
