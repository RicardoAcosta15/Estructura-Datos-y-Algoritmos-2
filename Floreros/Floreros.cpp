/*
 Asignatura: IDS344-01 - ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesus Bido 1105909

 Evidencia: Los floreros de Salvador

 Fecha: 23/11/2022
*/

#include <iostream>

using namespace std;

int main()
{
	int A, B, Mod = 1, x = 1;

	cout << "Hace algun tiempo Salvador compro 100 floreros para venderlos en un mercadillo. La semana pasada, despues de haber vendido algunos de ellos en los dias anteriores, tenia los floreros ordenados en seis filas, con el mismo numero de unidades en cada una de ellas. En esta semana vendio ocho floreros y en la actualidad tiene los que le quedan ordenados en 11 filas, numeros con el mismo numero de floreros en cada una.\n" << endl;

	cout << "¿Cuantos floreros tiene salvador para vender todavia ?\n" << endl;

	for (int i = 1; i < 101; i++)
	{
		A = 100 - i;

		Mod = A % 6;

		if (Mod == 0)
		{
			B = A - 8;

			Mod = B % 11;

			if (Mod == 0)
			{
				cout << "Solucion." << x << endl;
				cout << "Cantidad de floreros vendidos inicialmente: " << i << endl;
				cout << "Ordeno " << A << " floreros en 6 filas." << endl;
				cout << "Ordeno " << B << " floreros en 11 filas." << endl;
				cout << "A Salvador le quedan " << B << " floreros.\n" << endl;
				x++;
			}
		}
	}
}