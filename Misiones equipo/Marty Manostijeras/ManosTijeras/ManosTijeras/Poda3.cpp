#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include<time.h>
using namespace std;


/*
 por supermercado a lo sumo compra 3 productos
 0 <= productos <= 3*supermercados y super <=20
*/

bool esValido(const std::vector<int> &contador, const std::vector<bool> &marcaProd, int i, int k)
{
	return  !marcaProd[k] && contador[i] < 3;
}


void comprasSemana(std::vector<int> &contador, const std::vector<std::vector<int>> &precio, std::vector<bool> &marcaProd, std::vector<int> &costesMinimoProd,
	int &suma, int &minimo, int k, std::vector<int> &mejores, int &cont)
{
	cont++;
	for (int i = 0; i < contador.size(); i++)
	{
		if (esValido(contador, marcaProd, i, k))
		{
			    suma += precio[i][k];
				contador[i]++;
				marcaProd[k] = true;
				if (k == marcaProd.size() - 1)
				{
					if (suma < minimo)
					{
						minimo = suma;
					}
				}
				else {
					if (mejores[k + 1] + suma < minimo)
					{
						comprasSemana(contador, precio, marcaProd, costesMinimoProd, suma, minimo, k + 1,mejores,cont);
					}
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
	int cont = 0;
	int minimo = INT_MAX;
	std::cin >> super;
	std::cin >> prod;
	std::vector<int> contador(super, 0);
	std::vector<std::vector<int>> precio(super, std::vector<int>(prod));
	std::vector<bool> marcaProd(prod, false);
	std::vector<int> costesMinimosProd(prod,INT_MAX);
	std::vector<int> mejoresAcumulados(prod);
	
	
	for (int i = 0; i < super; i++) {
		for (int j = 0; j < prod; j++) {
			std::cin >> precio[i][j];
			if (precio[i][j] < costesMinimosProd[j])
				costesMinimosProd[j] = precio[i][j];
		}
	}
	mejoresAcumulados.at(prod - 1) = costesMinimosProd.at(prod - 1);
	for (int i = prod - 2; i >=0; i--)
	{
		mejoresAcumulados[i] = mejoresAcumulados[i + 1] + costesMinimosProd[i];
	}
	clock_t t_ini, t_fin;
	double secs;

	t_ini = clock();

	comprasSemana(contador, precio, marcaProd, costesMinimosProd, suma, minimo, 0,mejoresAcumulados,cont);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout << " tiempo " << secs * 1000000.0 << endl;
	out << cont << "\t" << secs*1000000.0 << endl;
	cout << minimo <<"   " << cont<< endl;
}
int main()
{
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	ofstream out;
	out.open("poda3.xls");
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