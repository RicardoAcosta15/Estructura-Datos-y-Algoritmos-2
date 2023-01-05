/*
 Asignatura: IDS344-01 - LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesús Bidó 1105909

 Evidencia: Triangulo de Sierpinski

 Fecha: 22/12/2022
*/

#include <iostream>
#include <cstdlib>

using namespace std;



int main()
{
	const int tam = 37; //Tamaño de la matriz
	char triangulo[tam][tam];  //Matriz cuadrada
	
	int num, x = tam, y = tam, rep = 0;

	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			triangulo[j][i] = ' ';  //Inicializamos la matriz con el caracter nulo
		}
	}

	while (rep < 1000)  //Se repetirá el proceso 1000 veces
	{
		rep++;
		num = rand() % 3; //num toma valores aleatorios entre 0, 1 y 2

		switch (num)
		{
		case 0:
			triangulo[(x + tam - 1) / 2][(y + tam - 1) / 2] = '.';  //Se coloca un punto hacia el punto der
			x = (x + tam - 1) / 2;  //x , y toman la posición de ese nuevo punto
			y = (y + tam - 1) / 2;
			break;

		case 1:
			triangulo[x / 2][(y + tam - 1) / 2] = '.';  //Se coloca un punto hacia el punto izq
			x = x / 2;
			y = (y + tam - 1) / 2;  //x , y toman la posición de ese nuevo punto
			break;

		case 2:
			triangulo[(x + tam / 2) / 2][y / 2] = '.';  //Se coloca un punto hacia el punto superior
			x = (x + tam / 2) / 2;  //x , y toman la posición de ese nuevo punto
			y = y / 2;
			break;
		}

		system("cls");
		for (int i = 0; i < tam; i++)  // Visualizar el proceso
		{
			for (int j = 0; j < tam; j++)
			{
				cout << " ";
				cout << triangulo[j][i];
			}
			cout << "\n";
		}
	}
	return 0;
}



