//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime> 
#include<stdio.h>

using namespace std;


void resuelveCaso(int& n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	clock_t start = clock();
	int x = sqrt(n);

	
	while (n % x != 0) {
		x--;
	}

	printf("Tiempo transcurrido: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	cout << n / x << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	//unsigned t0, t1;

	//t0 = clock();
//DateTime inicio = DateTime.Now; 
	
	int n;
	std::cin >> n;

	// Resolvemos
	while (n != 0) {
		clock_t t0, t1;

		t0 = clock();
		resuelveCaso(n);
		t1 = clock();

		int tiempo_duracion = (double)((t1 - t0) * 1000 / (CLOCKS_PER_SEC));


		//cout << "Execution Time: " << tiempo_duracion << endl;
		std::cin >> n;
	}
	/*ofstream a;
	a.open("caso1.txt");
	for (int i = 0; i < 999000; i++)
	{
		a << i << " ";
	}
	a.close();*/
	//t1 = clock();

	//double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	//cout << "Execution Time: " << time << endl;
	//for (int i = 1000000; i < 9900000; i++)
	//
	//cout << i << " ";

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}