#include <iostream>
#include <string>
using namespace std;

string Convierte(int n, int i);
void SeparaGruposDigitos(string d, int gd[]);
bool Validar(string c);

// Programa que conviente un numero de n digitos a palabras
int main(int argc, const char* argv[]) {
	int i = 1, j = 0, len = 0, Cant = 0;
	int dg[10] = { 0,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	bool validar = true;
	string dig = "", c;
	string num = "", k = "", copia;
	string deno[8] = { "","mil","millones","millardos","billones","mil billones","trillones","mil trillones" };

	do
	{
		system("cls");
		cout << "Introduzca la cantidad a convertir a Palabra: ";
		cin >> k;
		validar = Validar(c);  //Verifica si se ingresó un número

	} while (validar == false);  //Repite mientras el valor no sea un número

	SeparaGruposDigitos(k, dg);

	while (dg[i] != -1) {
		copia = Convierte(dg[i], i); // retorna un numero de 3 digitos en palabras
		if (copia == "uno" && i > 1) copia = "un";
		if (copia == "un" && i == 2) copia = "";
		(copia == "" && dg[3] == 1) ? num = copia + " " + num : num = copia + " " + deno[i - 1] + " " + num;
		i++;
	}

	cout << num << "pesos con " << dg[0] << " centavos" << endl;
	return 0;
}

// Convierte a palabra el caso base de un numero de 3 digitos
string Convierte(int n, int ciclo)
{
	string palabra[34] = { "","cien","doscientos ","trescientos ","cuatrocientos ","quinientos ","seiscientos","setecientos ","ochocientos ","novecientos","diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa","once","doce","trece","catorce","quince","","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
	string cadena = "";
	int c, r, d = 100, pos = 0;
	if (ciclo > 1) palabra[25] = "un";
	c = n / d; // cociente entero para tomar el primer digito (centena)
	r = n % d; // residuo de la division para tomar los digitos que restan
	cadena = cadena + palabra[pos + c]; //se toma la palabra correspondiente a las centenas
	if (c == 1 && r > 0) cadena = cadena + "to"; // ciento en el caso de que sea > 100
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

	//Separa en grupo de 3 digitos el numero dado para realizar la conversion
void SeparaGruposDigitos(string d, int gd[])
{
	int i, k = 0, j = 0, n = 1, s = 0;
	bool t = false;
	string dig = "", num = "";
	while (d[k] != '\0') 
	{	k++; 
		if (d[k] == '.') 
		{ t = true; 
		s = k; } 
	} // para determinar donde se encuentra el punto delos centavos
	if (t) 
	{
		for (i = s; i < k; i++) {
		dig = dig + d[i]; 
		}

	} // toma los digitos de los centavos
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

// Valida la entrada de un valor numerico
bool Validar(string c) // Devuelve true si se ingresa un dígito o false si se ingresa una letra
{
	bool q = true;

	for (int i = 0; i < c.length(); i++)
	{
		if (isdigit(c[i]) == false)  // isdigit comprueba si el valor dentro de la cadena es un dígito
		{
			q = false;
		}
	}

	return q;
}