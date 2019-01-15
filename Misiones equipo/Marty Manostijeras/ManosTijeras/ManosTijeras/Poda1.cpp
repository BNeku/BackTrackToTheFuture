#include <iostream>
#include <time.h>
#include <fstream>
#include <climits>
#include <vector>
using namespace std;




/*
 por supermercado a lo sumo compra 3 productos
 0 <= productos <= 3*supermercados y super <=20
*/

void inicializaCompras(std::vector<std::vector<int>> &precio, std::vector<int>&costesMinimosProd,const int&super, const int &prod)
{
	int k;
	for (int i = 0; i < super; i++)
	{
		for (int j = 0; j < prod; j++)
		{
			std::cin >> k;
			if (costesMinimosProd[j] > k) { costesMinimosProd[j] = k; }
			precio[i][j] = k;
		}
	}
}


bool esValido(const std::vector<int> &contador, const std::vector<bool> marcaProd,const  int &i , const int &k)
{
	return  !marcaProd[k] && contador[i] < 3;
}


void comprasSemana(const std::vector<std::vector<int>> &precio, std::vector<bool> &marcaProd, std::vector<int> &contador,
	int k , const int &super, const int &prod, int &suma, int &minimo, int &cont, const std::vector<int> &costesMinimosProd)
{
	cont++;
	for (int i = 0; i < super; i++)
	{
		if (esValido(contador,marcaProd,i,k))
		{
			suma += precio[i][k];
			contador[i]++;
			marcaProd[k] = true;
			if (k == prod - 1)
			{
				if (suma < minimo)
				{
					minimo = suma;
				}
			}
			else {
				if (costesMinimosProd[k + 1] + suma < minimo)
				{
					comprasSemana(precio, marcaProd, contador, k + 1, super, prod, suma, minimo, cont, costesMinimosProd);
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
	int cont = 0;
	int suma = 0;
	int minimo = INT_MAX;
	clock_t t_ini, t_fin;
	double secs;
	

	std::cin >> super;
	std::cin >> prod;
	std::vector<int> contador(super, 0);
	std::vector<std::vector<int>> precio(super, std::vector<int>(prod));
	std::vector<bool> marcaProd(prod, false);
	std::vector<int>costesMinimosProd(prod, INT_MAX);
	inicializaCompras(precio, costesMinimosProd, super, prod);



	t_ini = clock();
	comprasSemana(precio, marcaProd, contador, 0, super, prod, suma, minimo, cont, costesMinimosProd);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	out << cont << "\t" << secs*1000000.0 << endl;
	cout << " tiempo " << secs*1000000.0 << endl;
	cout << minimo << "  " <<cont <<endl;
	
}
int main()
{
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	ofstream out;
	out.open("poda1.xls");
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