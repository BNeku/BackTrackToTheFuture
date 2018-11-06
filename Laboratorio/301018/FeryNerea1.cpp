// NEREA JIMENEZ GONZALEZ Y FERNANDO BELLOT RODRÍGUEZ
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
Recorremos el vector una sola vez:
- Desde 0 hasta p buscamos el valor más grande (auxM)
- Desde p + 1 hasta el final del vector comparamos auxM con cada valor del array
y si auxM es mayor o igual que alguno de los valores, sale del bucle y devuelve false.
Si no simplemente devuelve true.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdlib>


//ESPECIFICA la funcion que resuelve el problema
//Precondicion:
//v.size() > 0 && 0 <= p < v.size() && forall k:: 0<=k<v.size() ==> v[k] pertenece Z

bool resolver(std::vector<int> const& v, size_t p) {
	bool menor = true;
	int auxM = v[0];
	int i = 0, j = p+1;
    //Implementacion
    //Funcion/es de cota
	//cota: v.size() - i - j
    //Invariante/s
	//I: 1 <= i <= v.size()
	//I: forall k,j:: 0<=k<=p < j < i ==> v[k] < v[j]
	while (i <= p) {
		if (v[i] > auxM)
			auxM = v[i];
		i++;
	}
	while (j < v.size() && menor) {
		if (v[j] <= auxM)
			menor = false;
		j++;
	}

	return menor;
}

//Postcondicion:
//menor=true ==> forall i,j:: 0<=i<=p < j < v.size() ==> v[i] < v[j]
//menor=false e.o.c.


//Analisis y justificacion del coste: O(n) ==> O(i) + O(j)
//el vector sólo se va a recorrer una vez, a pesar de que haya dos bucles, ya que el primero va hasta la posición p 
// y el segundo hasta el final del array, por lo que sería como un bucle de 0 al final. Por lo que el coste es lineal, 
//siendo la suma de los dos while.





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numElems = 0; size_t p;
    std::cin >> numElems >> p;
    std::vector<int> v(numElems);
    for (int& i : v) std::cin >> i;
    bool sol = resolver(v,p);
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("sample1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
 #endif
*/
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
    
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
*/    
    return 0;
}
