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

int resuelve(int n, int &tiempo)
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

	tiempo= (double)(t1 - t0) / (CLOCKS_PER_SEC)*1000.0;

	return ancho;
}


int main() {
	// Para la entrada por fichero.
	
#ifndef DOMJUDGE
	ifstream in("casosTLE.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	ofstream salida("salida.xls");
	int n, ancho, tiempo;
	cin >> n;
	salida << "Entrada\tTiempo" << endl;
	// Resolvemos
	while (n != 0) {
		ancho=resuelve(n, tiempo);
		
		salida << n <<"\t"<<tiempo << endl;
		cout << "Execution Time: " << tiempo << endl;
		cout << ancho << endl;

		cin >> n;
	}
	salida.close();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}