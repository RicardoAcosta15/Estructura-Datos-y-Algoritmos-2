/*
 Asignatura: IDS344-01 - ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesus Bido 1105909

 Evidencia: N reinas con backtracking

 Fecha: 05/01/2022
*/

#include <iostream>
#include<stdio.h>
#include <string>
using namespace std;

bool comprobacion(int reinas[], int n, int k);
void Nreinas(int reinas[], int n, int k);
bool Validacion(string c);

int x = 0; // Contador de las soluciones.

int main(int argc, char* argv[]) {

	//Declaracion de variables
	int k = 0; // Representa los niveles del arbol
	int n = 0; //  Representa la cantidad de reinas
	string str;
	bool validar = false;

	do
	{
		system("cls");
		cout << "Ingresar la cantidad de reinas : ";
		cin >> str;

		validar = Validacion(str); // Valida que la entrada sea correcta.

		if (validar == true) // En caso de que sea correcta lo transforma en int.
		{
			n = stoi(str);
		}

	} while (validar == false); // Continua el bucle mientras la validacion sea falsa.


	int* reinas = new int[n]; //Creacion del array reinas del tamaño de la cantidad de reinas.

	for (int i = 0; i < n; i++) { //llena el array de -1.
		reinas[i] = -1;
	}

	Nreinas(reinas, n, k);

	return 0;
}

bool comprobacion(int reinas[], int n, int k)
{
	int i;
	for (i = 0; i < k; i++) {
		// En caso de que esten en una misma fila
		// o que diagonalmente se encuentre bajo ataque
		// de otra reina.
		if ((reinas[i] == reinas[k]) or (abs(k - i) == abs(reinas[k] - reinas[i]))) {
			return false; // En caso de que se cumpla alguna 
			// quiere decir que esa posicion no es valida.
		}
	}
	return true;
}

void Nreinas(int reinas[], int n, int k)
{
	if (k == n) { // Cuando se llegue al nivel que coinside 
		// con la cantidad de reinas se ha encontrado
		// una posible solucion al problema.
		x++;
		cout << "Solucion #" << x << ": ";
		for (int i = 0; i < n; i++) { // Imprime la solucion por pantalla.

			if (i == n - 1)
			{
				cout << reinas[i] << ".";
			}
			else
			{
				cout << reinas[i] << ", ";
			}

		}
		cout << endl;

	}
	else {
		for (reinas[k] = 0; reinas[k] < n; reinas[k]++) { // Para movernos lateralmente en nodos 
			// de una misma rama.
			if (comprobacion(reinas, n, k)) { // Comprueba que la jugada en cuestion es valida.
				Nreinas(reinas, n, k + 1); // Se llama a la funcion nuevamente aumentando
				// el nivel del arbol.
			}
		}
	}
}

bool Validacion(string c)
{
	for (int i = 0; i < c.length(); i++)  // Recorre la cadena completa.
	{
		if (isdigit(c[i]) == false)  // isdigit comprueba si el valor dentro de la cadena es un dígito.
		{
			return false;
		}
	}
	return true; // Devuelve true si es un dígito o false es una letra.
}

