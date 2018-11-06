// NEREA JIMENEZ GONZALEZ Y FERNANDO BELLOT RODRIGUEZ
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
Este problema lo resolvemos con un entero que indica el tramo más largo (maxTramo), un entero que
indica el tamaño del tramo actual (tramo), la variable i para recorrer el array y un entero auxiliar
para comparar las alturas de las pistas

- Si no hay ningún tramo devuelve 0,
- En otro caso, recorremos un bucle while desde la posición 1 hasta el final:
	Si la pista siguiente es mayor que la actual, actualizamos el maxTramo si es necesario
	porque se ha acabado el tramo y hay que empezar uno nuevo. (Y ponemos tramo a 1)

	Si la pista siguiente es menor o igual, aumenta en 1 tramos y continua.

	Después antes de la siguiente vuelta del bucle actualiza en entero auxiliar con
	el siguiente valor

	Al final actualiza maxTramos si el ultimo tramo es el mayor.
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX=1000;

//ESPECIFICA LA FUNCION QUE RESUELVE EL PROBLEMA
//Precondicion:
//forall k:: 0<=k<v.length() ==> tramos[k]>0 && 0<=n

int pistaMasLarga(int tramos[],int n)
{	
	int maxTramo = 1, tramo = 1;
	int i = 1;
	int aux = tramos[0];
	if (n == 0) {
		maxTramo = 0;
	}
	else {

		while (i < n) {
			if (tramos[i] > aux) {
				if (tramo > maxTramo)
					maxTramo = tramo;
				tramo = 1;
			}
			else {
				tramo++;
			}
			aux = tramos[i];
			i++;
		}
		if (tramo > maxTramo)
			maxTramo = tramo;
	}

    //Implementacion
    //Funcion de cota
	//cota: n-i
    //Invariante
	//I: 1<= i <= tramos.length
	//I: #tramos[j] :: forall j :: 0<=j<i ==> tramos[j] >= tramos[j+1] : max(#tramos[j])
	


    
    return maxTramo;
}
//Postcondicion:
//maxtramo = #tramos[j] :: forall j :: 0<=j<tramos.length()-1 ==> tramos[j] >= tramos[j+1] : max(#tramos[j])
//Analisis del coste y justificacion: O(n) ==> O(n)
//el coste es lineal ya que solo tenemos un bucle while que recorre el array desde la posición 1,
//ya que comenzamos a comparar con el auxiliar que inicializamos en la posición 0.




void resuelve()
{

int tramos[MAX];
int n;
cin>>n;
for (int i=0;i<n;i++) {cin>>tramos[i];}
cout << pistaMasLarga(tramos,n)<<endl;

}




int main() {
	    // ajuste para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("sample2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/


    unsigned int numCasos;
    cin >> numCasos;
    // Resolvemos
    while (numCasos--) {
       resuelve();

    }

    // restablecimiento de cin
/*#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    
#endif*/
	system("pause");
	return 0;
}
