


//----------------------------
//DEFINICION DE PREDICADOS
//-----------------------------

//1-Predicado que indica si un entero positivo es par 
predicate esPar(i:int) 
requires i>=0
{i%2==0}

// Comprueba si el predicado es cierto para algunos enteros
// Este test es util para poder identificar errores del predicado 

method testPar(){
	//assert esPar(2);
	//assert esPar(5);
	//assert esPar(-2);
	//assert esPar(1000000);
}

//2. Predicado que indica si todos los elementos de una secuencia son positivos.

predicate positivos(s:seq<int>)
{forall u::0<=u<|s| ==> s[u]>=0}

method TestPositivos()
{
	//assert positivos([1,2,3]);
	//assert positivos([1,-3,7,8]);
    //assert positivos([0,9]);
	//assert positivos([44,2,3,4,5,6,7,8,9]);

}

//Predicado que indica si todos los elementos de un array son positivos.

predicate positivosA(a:array<int>)
reads a;
{positivos(a[0..a.Length])}

// 3-Predicado que indica que todos los elementos de una secuencia son 
// iguales

predicate iguales(s : seq<int>) {
      forall u, w :: 0 <= u <= w < |s| ==> s[u] == s[w]

}


predicate igualesA( a: array<int>)
	reads a;
{
	forall k,j:: 0 <= k <=j < a.Length  ==> a[k] == a[j] 
}



// Comprueba si el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado 

method TestIguales() 
{
	//assert iguales([1,1,1,1,1]);
	//assert iguales([2]);
	//var s : seq<int>;
	//s := [];
	//assert iguales(s);
	//assert iguales([1,1,1,1,2]); 


	//Comprueba que los elementos de un array son iguales
	//var v:array<int> := new int[4];
	//v[0]:=6; v[1]:=6; v[2]:=6; v[3]:=6;
	//assert iguales(v[0..v.Length]);
	//assert igualesA(v);

}



// ------------------------------------------

//4- Predicado que indica que los elementos de una secuencia son todos distintos de un elemento dado


predicate distintosDe(s : seq<int>, x :int) {

     forall u :: 0 <= u < |s| ==> s[u] != x
}


predicate distintosDeA ( a: array<int>, x:int)
	reads a;
{
	forall k:: 0 <= k < a.Length  ==> a[k] != x 
		
}


// Comprueba si el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado

method TestDistintosDe() 
{
    //assert distintosDe([1,4,2,8],0);
	//assert distintosDe([6,3,1,9,2],8);
	//assert distintosDe([2],3);
	//var s : seq<int>;
	//s := [];
	//assert distintosDe(s,7);
	//assert distintosDe([3,4,3,6],3); // Este assert debe fallar

	//var v:array<int> := new int[4];
	//v[0]:=6; v[1]:=7; v[2]:=8; v[3]:=-2;
	//assert distintosDe(v[0..v.Length],0);
	//assert distintosDeA(v,0);
}


// 5. Escribir un predicado que indique que los elementos de una secuencia son todos distintos entre si


predicate distintos(s : seq<int>) {
    // Escribir aqui el predicado

}


predicate distintosA ( a: array<int>)
	reads a;
{
  //Escribir aqui el predicado 		
}


// Comprueba si el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado 

method TestDistintos() 
{
  	//assert distintos([1,4,2,8]);
	//assert distintos([6,3,1,9,2]);
	//assert distintos([2]);
	//var s : seq<int>;
	//s := [];
	//assert distintos(s);
	//assert distintos([3,4,3,6]); 
	//assert distintos([6,3,3,1,5]);  

	//var v:array<int> := new int[4];
	//v[0]:=6; v[1]:=7; v[2]:=8; v[3]:=-2;
	//assert distintos(v[0..v.Length]);
	//assert distintosA(v);
}


// 6. Escribir un predicado que indique que los elementos contiguos de una secuencia son distintos


predicate contiguosDistintos(s : seq<int>) 
{
 //Escribe aqui el predicado

}



// Comprueba si el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado

method TestContiguosDistintos() 
{
   // assert contiguosDistintos([1,4,2,8]);
   //assert contiguosDistintos([6,3,1,9,2]);
   //assert contiguosDistintos([2]);
	//var s:seq<int>;
	//s:=[];
	//assert contiguosDistintos(s);
	//assert contiguosDistintos([3,4,3,6]);
	//assert contiguosDistintos([6,3,3,1,5]);
	//var v:array<int> := new int[4];
	//v[0]:=6; v[1]:=7; v[2]:=6; v[3]:=-2;
	//assert contiguosDistintos(v[0..v.Length]);

}


// 7. Escribir un predicado que indique que una secuencia esta ordenada de manera no decreciente

predicate ordenado(s : seq<int>) {
    // Escribir aqui el predicado

}

// Comprueba si el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado 

method TestOrdenado()
{
 //assert ordenado([]);
 //assert ordenado([5]);
 //assert ordenado([1,6,8,9]);

 //assert ordenado([3,10,10,28]);
 //assert ordenado([3,6,1,9,10]);


}



// 8. Escribir un predicado que indique que una secuencia esta ordenada de manera estrictamente creciente

predicate ordenadoEstricto(s : seq<int>) {
    // Escribir aqui el predicado

}

// Comprueba si el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado 

method TestOrdenadoEstricto()
{
 //assert ordenadoEstricto([]);
 //assert ordenadoEstricto([5]);
 //assert ordenadoEstricto([1,6,8,9]);

 //assert ordenadoEstricto([3,10,10,28]); 
 //assert ordenadoEstricto([3,6,1,9,10]);//Este test debe fallar
}



//Los existenciales son dificiles de demostrar
//9. Este predicado indica que hay un elemento en la secuencia igual a uno dado


predicate igual(s : seq<int>, x :int) {
   // exists u:int :: 0 <= u < |s| && s[u] == x //prueba con este
   x in s
}


// Comprueba que el predicado es cierto para algunas secuencias
// Este test es util para poder identificar errores del predicado (secuencias que no lo cumplen)
// y corregirlo cuando el test anterior falla.
method TestIgual() 
{  	var s : seq<int>;
 
    s := [1,7,0,5];
   // assert s[2]==0; //sin esta ayuda  no es capaz de demostrarlo
  	assert igual(s,0);
	s:=[];
	//assert igual(s,0); //este caso falla 
}

// ------------------------------------------


//10. Escribir un predicado que indique si una posicion de una secuencia es la primera posicion de la 
//secuencia (desde la izquierda) en la que aparece un cero o su longitud en caso de no haber ningun
//cero en la secuencia

predicate esPrimerCero(s : seq<int>, k : int) 
{
   //Escribe aqui el predicado
}

method TestEsPrimerCero() 
{  //	var s : seq<int>;
   // s := [1,7,0,5];
   // assert esPrimerCero(s,2);
	//assert esPrimerCero(s,1);
	//s:= [1,7,4,5];
	//assert esPrimerCero(s,4);
	//s:=[];
	//assert esPrimerCero(s,0);

}

//11. Este predicado determina si una secuencia es permutacion de otra
predicate esPermutacion(s:seq<int>, t:seq<int>)
{multiset(s)==multiset(t)}

method TestEsPerm()
{
  // assert esPermutacion([1,4,2,5], [5,2,4,1]);
  // assert esPermutacion([1,1],[1]);

}

