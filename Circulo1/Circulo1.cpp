/*
 Asignatura: IDS344-01 - ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesus Bido 1105909

 Evidencia: Hacer un Círculo en c++

 Fecha: 05/01/2022
*/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

bool Validacion(string c);

int main()
{
    int radio = 0;
    string r;
    bool validar = false;
    int i, j;
    do
    {
        system("cls");
        cout << "Ingresar el radio : ";
        cin >> r;

        validar = Validacion(r); // Valida que la entrada sea correcta.
        if (validar == true) // En caso de que sea correcta lo transforma en int.
        {
            radio = stoi(r);
        }
    } while (validar == false); // Continua el bucle mientras la validacion sea falsa.

    for (i = 0; i <= 2 * radio; i++)
    {
        for (j = 0; j <= 2 * radio; j++)
        {
            double distancia = sqrt((double)(i - radio) * (i - radio) + (j - radio) * (j - radio));
            if (distancia > radio - 0.65 && distancia < radio + 0.2)
            {
                cout << "**";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;

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
