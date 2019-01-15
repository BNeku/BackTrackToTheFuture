#include <iostream>
#include <iomanip>
#include<math.h>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
 por supermercado a lo sumo compra 3 productos
 0 <= productos <= 3*supermercados y super <=20
*/
const int MAX_SUPER = 20;
const int MAX_PROD = 3 * MAX_SUPER;

bool esValido(const std::vector<int> &contador, const std::vector<bool> &marcaProd, int i, int k)
{
	return  !marcaProd[k] && contador[i] < 3;
}


void comprasSemana(std::vector<int> &contador, const std::vector<std::vector<int>> &precio, std::vector<bool> &marcaProd, 
	int &suma, int &minimo, int k, int &cont, const std::vector<int> &estimacion, int &precio_estimado, const int &minimoTotal)
{
	cont++;

	for (int i = 0; i < contador.size(); i++)
	{
		if (esValido(contador, marcaProd, i, k))
		{
			suma += precio[i][k];
			contador[i]++;
			marcaProd[k] = true;
			precio_estimado = suma +( minimoTotal * (marcaProd.size()-1 - k));
			if (precio_estimado < minimo)
			{
				if (k == marcaProd.size() - 1)
				{
					minimo = precio_estimado;
				}
				else comprasSemana(contador, precio, marcaProd, suma, minimo, k + 1, cont, estimacion, precio_estimado,minimoTotal);
			}

			suma -= precio[i][k];
			contador[i]--;
			marcaProd[k] = false;
		}
	}
}

void resuelveCaso(ofstream &out)
{
	int prod, super;
	int suma = 0;
	int minimo = INT_MAX;
	std::cin >> super;
	std::cin >> prod;
	std::vector<int> contador(super, 0);
	std::vector<std::vector<int>> precio(super, std::vector<int>(prod));
	std::vector<bool> marcaProd(prod, false);
	std::vector<int> estimacion(prod);
	int precio_estimado = 0;
	int minimoTodo = INT_MAX;
	int cont = 0;
	for (int i = 0; i < super; i++) {
		for (int j = 0; j < prod; j++) {
			std::cin >> precio[i][j];
			if (precio[i][j] < minimoTodo)
			{
				minimoTodo = precio[i][j];
			}

		}
	}

	clock_t t_ini, t_fin;
	double secs;

	t_ini = clock();
	comprasSemana(contador, precio, marcaProd, suma, minimo, 0, cont, estimacion,precio_estimado,minimoTodo);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout << " tiempo " << secs * 1000000.0 << endl;
	out << cont << "\t" << secs*1000000.0 << endl;
	cout << minimo << "   " << cont << endl;
}
int main()
{
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	ofstream out;
	out.open("poda2.xls");
	unsigned int n;
	std::cin >> n;

	// Resolvemos
	for (int i = 0; i < n; ++i) {
		resuelveCaso(out);
	}
	out.close();
	system("PAUSE");
	return 0;

}