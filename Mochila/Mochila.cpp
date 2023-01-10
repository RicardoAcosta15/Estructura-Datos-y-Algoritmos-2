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

struct objeto  //estrutura con los atributos de cada elemento
{
	float beneficio;
	float peso;
	float indice;  //valor del beneficio por unidad de peso
};

float mochila(int k, float umbral, objeto elemento[], float sol);

int main()
{

	int n = 5, k = 0, max;
	float umbral = 100, sol = 0;
	objeto elemento[5], aux;
	float peso[5] = { 10, 20, 30, 40, 50 };
	float beneficio[5] = { 20, 30, 65, 40, 60 };

	for (int i = 0; i < n; i++)  //Asignamos los valores establecidos a la estructura
	{
		elemento[i].peso = peso[i];
		elemento[i].beneficio = beneficio[i];
		elemento[i].indice = elemento[i].beneficio / elemento[i].peso;
	}

	for (int i = 0; i < n; i++) //Ordenamos por indice de mayor a menor con selection sort
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (elemento[j].indice > elemento[max].indice)
			{
				max = j;
			}
		}
		aux = elemento[i];
		elemento[i] = elemento[max];
		elemento[max] = aux;
	}

	cout << "El beneficio maximo sin sobrepasar el umbral es: " << mochila(k, umbral, elemento, sol) << endl;

	return 0;
}

float mochila(int k, float umbral, objeto elemento[], float sol)
{
	while (umbral > 0)  //Mientras la mochila tenga espacio
	{
		if (umbral > elemento[k].peso) //Si el peso completo del elemento cabe
		{
			umbral -= elemento[k].peso; //Resta al peso disponible
			sol += elemento[k].beneficio;  //Suma el beneficio de dicho peso a la solucion
		}
		else  //Si el peso completo del elemento no cabe
		{
			sol += elemento[k].beneficio * (umbral / elemento[k].peso);  //Suma la fraccion de beneficio correspondiente
			umbral = 0; // La mochila ya no tiene espacio disponible
		}
		k++; //Suma k para recorrer el array
	}
	return sol;  // retorna la sumatoria de los beneficios
}