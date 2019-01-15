
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
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casosTLE.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	ofstream salida;
	salida.open("salida2.xls");

	int n;
	std::cin >> n;
	salida << "Entrada\tTiempo" << endl;
	// Resolvemos
	while(n != 0){
		clock_t start = clock();
		resuelveCaso(n);

		float time = ((double)(clock() - start) / CLOCKS_PER_SEC);
		salida << n << "\t" << time << endl;
		cout << "Execution Time: " << time << endl;
		std::cin >> n;
	}

	salida.close();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}