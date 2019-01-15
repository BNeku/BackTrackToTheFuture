#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <time.h>


using namespace std;


void haypuzzle(int &largo,  int &ancho,  int &dif,  int &n)
{
	
	bool exito = true;
	int i = 0;
	 int resto;
	while (i < n && exito)
	{

		resto = n / largo;
		if (n%largo == 0)
		{
			if (abs(largo - resto) <= dif)
			{
				if (largo > resto) { ancho = largo; }
				else {
					ancho = resto;
				}
				dif = abs(largo - resto);
			}
			else exito = false;
		}
		largo++;
		i++;
	}
	
	
}

void resuelve( int n)
{
	int largo = 1;
	int ancho = 1;
	int diferencia = n;
	int dif2 = n;
	int i = 1;
	int k = 1;
	clock_t t0, t1;

	t0 = clock();
	haypuzzle(largo, ancho, diferencia, n);
	t1 = clock();

	int tiempo_duracion = (double)(t1 - t0) / (CLOCKS_PER_SEC)*1000.0;
	//salida << "Execution Time : " << tiempo_duracion << "    resultado " << ancho << endl;
	//salida.close();
	cout << "Execution Time: " << tiempo_duracion << endl;
	cout << ancho << endl;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	//unsigned t0, t1;

	//t0 = clock();

	int n;
	std::cin >> n;

	//ofstream salida;
	//salida.open("salida.txt");
	// Resolvemos
	while (n != 0) {
		resuelve(n);
		std::cin >> n;
	}
	//salida.close();

//	t1 = clock();
	//int tiempo_duracion = (double)(t1 - t0) / (CLOCKS_PER_SEC)*1000.0;
	//double time = (double(t1 - t0) / CLOCKS_PER_SEC * 1000.0);
	//cout << "Execution Time: " << tiempo_duracion << endl;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}