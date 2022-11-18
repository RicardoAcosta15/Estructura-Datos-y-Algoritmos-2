/*
 Asignatura: IDS344-01 - ESTRUCTURAS DE DATOS Y ALGORITMOS II

 Docente: CASIMIRO GILBERTO CORDERO RAMIREZ

 Estudiantes:

 - Jean Güichardo 1105491
 - Ricardo Acosta 1104082
 - Wilbert León 1105634
 - Sebastian Peralta 1105487
 - Jesus Bido 1105909

 Evidencia: Convertir número a palabra

 Descripcion: Realizar un programa C++ que lea un número real (correspondiente a un monto) y convertir este monto a palabra.

 Fecha: 16/11/2022
*/

#include <iostream>
#include <string>
using namespace std;

string TransformarDigito(int n);
string TransformarCent(int n);
void AgruparDigitos(string d, int gd[]);
bool Validar(string c);

// Programa que conviente un numero de n digitos a palabras
int main(int argc, const char* argv[]) {
	int i = 1;
	int dg[8] = { 0,-1,-1,-1,-1,-1,-1,-1 };
	bool validar = true;
	string dig = "";
	string num = "", k = "", copia, centavos;
	string deno[6] = { "","mil","millones","mil millones","billones","mil billones"};

	do
	{
		system("cls");
		cout << "Introduzca la cantidad a convertir a Palabra: ";
		cin >> k;
		validar = Validar(k);  //Verifica si se ingresó un número

	} while (validar == false);  //Repite mientras el valor no sea un número

	AgruparDigitos(k, dg);

	while (dg[i] != -1) {
		copia = TransformarDigito(dg[i]); // retorna un numero de 3 digitos en palabras
		if (copia == "un" && i == 2) copia = ""; // para que sea mil y no un mil
		if (copia == "" && dg[2] != 1) 
		{ 
			num = copia + num;
		}
		else
		{ 
			num = copia + " " + deno[i - 1] + " " + num;
		}
		i++;
	}

	centavos = TransformarCent(dg[0]);

	cout << num << "pesos con " << centavos << " centavos" << endl;
	return 0;
}

// Convierte a palabra el caso base de un numero de 3 digitos
string TransformarDigito(int n)
{
	string palabra[34] = { "","cien","doscientos ","trescientos ","cuatrocientos ","quinientos ","seiscientos","setecientos ","ochocientos ","novecientos","diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa","once","doce","trece","catorce","quince","","un","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
	string cadena = "";
	int c, r, d = 100, pos = 0;
	c = n / d; // Para tomar el digito de la centena
	r = n % d; // residuo de la division para tomar los digitos que restan
	cadena = cadena + palabra[pos + c]; //se toma la palabra correspondiente a las centenas
	if (c == 1 && r > 0) cadena = cadena + "to"; // Para los casos entre 100 < x < 200
	d = d / 10; n = r; pos = 9; // posicion de las decenas
	c = n / d; r = n % d; // digitos de las decenas y unidad
	if (c == 1 && (r >= 1 && r <= 5)) { cadena = cadena + " " + palabra[pos * (c + 1) + r]; c = 0; r = 0; } // casi de los numerales especiales once al quince
	if (c == 1 && r == 0) cadena = cadena + " " + palabra[pos + c]; // primera decena sin residuo (diez)
	if (c == 1 && r > 5) cadena = cadena + " dieci"; // agregar palabra dieci a numerales
	else if (c > 1) cadena = cadena + " " + palabra[pos + c]; // agregar palabra de la decena
	n = r; pos = 24; // agregan las unidades
	(c > 1 && r > 0) ? cadena = cadena + " y " + palabra[pos + n] : cadena = cadena + palabra[pos + n];
	return cadena;
}

string TransformarCent(int n)
{
	string palabra[34] = { "","cien","doscientos ","trescientos ","cuatrocientos ","quinientos ","seiscientos","setecientos ","ochocientos ","novecientos","diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa","once","doce","trece","catorce","quince","","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve" };
	string cadena = "";
	int c, r, d = 10, pos = 9;
	c = n / d; r = n % d; // digitos de las decenas y unidad
	if (c == 1 && (r >= 1 && r <= 5)) { cadena = cadena + " " + palabra[pos * (c + 1) + r]; c = 0; r = 0; } // casi de los numerales especiales once al quince
	if (c == 1 && r == 0) cadena = cadena + " " + palabra[pos + c]; // primera decena sin residuo (diez)
	if (c == 1 && r > 5) cadena = cadena + " dieci"; // agregar palabra dieci a numerales
	else if (c > 1) cadena = cadena + " " + palabra[pos + c]; // agregar palabra de la decena
	n = r; pos = 24; // agregan las unidades
	(c > 1 && r > 0) ? cadena = cadena + " y " + palabra[pos + n] : cadena = cadena + palabra[pos + n];
	if (cadena == "") { cadena = "cero"; }
	return cadena;
}

	//Separa en grupo de 3 digitos el numero dado para realizar la conversion
void AgruparDigitos(string d, int gd[])
{
	int i, k = 0, j = 0, n = 1, s = 0;
	bool t = false;
	string dig = "", num = "";
	while (d[k] != '\0') 
	{	k++; 
		if (d[k] == '.') 
		{ t = true; 
		s = k; } 
	} // para determinar la posicion de los centavos
	if (t) 
	{
		for (i = s; i < k; i++) {
		dig = dig + d[i]; 
		}

	} // para tomar los digitos de los centavos
	(k > s + 1 && t == true) ? gd[0] = stof(dig) * 100 : gd[0] = 0;
	if (s == 0) s = k;
	for (i = s - 1; i >= 0; i--) {
		dig = d[i] + dig;
		j++;
		if (j == 3) {
			if (i != 0)num = "," + dig + num;
			else num = dig + num;
			gd[n] = stoi(dig);
			dig = "";
			n++;
			j = 0;
		}
	}
	if (dig != "") gd[n] = stoi(dig);
	num = dig + num;
	cout << "El numero introducido fue: " << num << endl;
}

// Validacion de la entrada
bool Validar(string c) // Devuelve true si se ingresa un dígito y/o un punto o false si se ingresa una letra
{
	bool q = true;
	int p = 0, i = 0;

	while(i < c.length())
	{
		if (isdigit(c[i]) == false && c[i] != '.')  // isdigit comprueba si el valor dentro de la cadena es un dígito
		{
			q = false;
		}
		
		if (c[i] == '.') { // En caso de que haya mas de un punto 
			p++;
			if (p > 1)
			{
				q = false;
			}
		}
		i++;
	}

	return q;
}