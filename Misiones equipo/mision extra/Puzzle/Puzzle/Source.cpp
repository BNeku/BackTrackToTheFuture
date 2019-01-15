//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime> 

using namespace std;


void resuelveCaso(int& n) {
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado

	int x = sqrt(n);

	while (n % x != 0) {
		x--;
	}

	//cout << n / x << endl;

}

int main() {

	/*
	ofstream casos;
	casos.open("casos.txt");

	for (int i = 0; i < 1000000; i++) {
		casos << i << endl;
	}
	*/

	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	ofstream salida;
	salida.open("salida.txt");

	int n;
	std::cin >> n;

	// Resolvemos
	while(n != 0){
		clock_t start = clock();
		resuelveCaso(n);

		float time = ((double)(clock() - start) / CLOCKS_PER_SEC);
		//cout << "Execution Time: " << time << endl;
		salida << time << endl;

		std::cin >> n;
	}

	salida.close();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}