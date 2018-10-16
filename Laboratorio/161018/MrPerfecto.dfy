include "specFunctions.dfy"
include "LovelacePred.dfy"


//1.Copia tu especificación, y añade invariante y cota al bucle 
// que resuelve el problema de determinar si todos los elementos de v son distintos de x
//Indica y justifica el coste 
/*
method mdistintosDe(v:array<int>, x:int) returns (b:bool)
//Copia aqui tu especificacion
   requires true
   ensures b==positivosA(v)
{
var i:int;
i:=0;
while i<v.Length && v[i]!=x
 decreases //funcion de cota
 invariant //invariante
{
   i:=i+1;
}

b:=(i==v.Length);
}
*/
//Coste y justificación:

//2. Copia tu especificación, y añade invariante y cota al bucle 
// que resuelve el problema de determinar si todos los elementos de v son positivos
//Indica y justifica el coste 
//coste: O(n)==> O(i)
method mpositivos(v:array<int>) returns (b:bool)
//Copia aqui tu especificacion
  requires true
  ensures b==positivosA(v)
{
  var i:int;
  b:=true;
  i:=0;
  while i<v.Length && b
   invariant 0 <= i <= v.Length
   invariant b == forall k:: 0 <= k < i  ==> v[k]>=0
   decreases v.Length-i//funcion de cota
  {
   b:=(v[i]>=0);
   i:=i+1;
  }
}

//Coste y justificación:

//3. Copia tu especificación, y añade invariante y cota al bucle 
// que resuelve el problema de devolver la posicion de la aparicion mas a la izquierda 
// del maximo de un vector de enteros
//Indica y justifica el coste 
/*
method mprimerMaximo(v:array<int>) returns (i:int)
//Copia aqui tu especificacion
{
i:=0;
var j:=1;
while (j<v.Length)
 decreases //funcion de cota
 invariant //invariante
 {
  if (v[j]>v[i]) {i:=j;} 
  j:=j+1;
 }

}
*/
//Coste y justificación:

//4. Copia tu especificación, y añade invariante y cota al bucle 
// que resuelve el problema de devolver la posicion de la aparicion mas a la derecha 
// del maximo de un vector de enteros
//Indica y justifica el coste 
//coste: O(n)==> O(j)
method multimoMaximo(v:array<int>) returns (i:int)
//Copia aqui tu especificacion
      requires true
      ensures 0<=i<v.Length
      ensures forall u:: 0 <=u < v.Length ==> v[u] <= v[i]
      ensures forall k:: i < k < v.Length ==> v[k] < v[i]
{
i:=v.Length-1;
var j:=v.Length-2;
while (j>=0)
 decreases j//funcion de cota
 invariant 0 <= j <= v.Length
 invariant 0 <= i <= j
 invariant forall k:: 0 <= k < j ==> (v[k] <= v[j])
 invariant forall u:: j <= u < v.Length-2 ==> (v[u] < v[j] )
 {
  if (v[j]>v[i]) {i:=j;}
  j:=j-1;
 }
 
}

//Coste y justificación:

//5.Copia tu especificación, y añade invariante y cota al bucle 
// que resuelve el problema de determinar si en un array de enteros posittivos hay la misma cantidad de pares que de impares.
//Indica y justifica el coste 
/*
function ContarPares(s : seq<int>):nat
 decreases s;
 requires forall i:: 0<=i<|s| ==> s[i]>=0
 {
 if s==[] then 0
 else (if esPar((s[|s|-1])) then 1 else 0)+ContarPares(s[..|s|-1])
}

method mmismaParidad(v:array<int>) returns (b:bool)
//Copia aqui tu especificacion
{
  var i:=0;
  var dif:int;
  dif := 0;
  while (i<v.Length)
    decreases //funcion de cota
    invariant //invariante
  {  ArrayFacts<int>(); 

    if (v[i]%2==0) { dif := dif+1;}
    else {dif := dif-1;}
    i := i+1;
  }
  b:=(dif==0);
}
*/
//Coste y justificación:

//6. Copia tu especificación e implementa un metodo que devuelva la posición en la que se encuentra el primer elemento
//igual a 0, y en caso de no haber ninguno devuelva la longitud del array. Añade invariante y cota al bucle que permita verificar su correccion.
//Indica y justifica el coste 

method mprimerCero(v:array<int>) returns (i:int)
//Copia aqui tu especificacion
    requires true 
    ensures 0 <= i <= v.Length 
    ensures esPrimerCero(v[0..v.Length], i) 
  { var k:= 0;
 //Implementa
    while(v[k]!=0 && k < v.Length-1)
    decreases v.Length-k
    invariant 0 <= k <= v.Length
    invariant forall j:: 0 <= j < v.Length ==> v[j]==0 

  {
    k:=k+1;
  }
   i:=k;
 
}

//Coste y justificación:

//7.Copia tu especificación e implementa un metodo que determine si todos los elementos de un vector de enteros contenidos entre dos posiciones 
//dadas c (incluida) y f (excluida) son pares. Añade invariante y cota al bucle que permita verificar su correccion.
//Se considera que el intervalo [c,f) es vacio cuando c=f
//Indica y justifica el coste 



method mparesEntreA(v:array<int>,c:int,f:int) returns (b:bool)
//Copia aqui tu especificacion
{
 //Implementa
}

//Coste y justificación:

//8.Copia tu especificación e implementa un metodo que determine si un array es  Gaspariforme (según la definición dada en el ejercicio 8 de los apuntes del Tema 2).
//Añade invariante y cota al bucle que permita verificar su correccion. 
//Recuerda utiliza
//  ArrayFacts<int>();  
//  SumProps(v);
////Indica y justifica el coste 

method mgaspariforme(v:array<int>) returns (b:bool)
//Copia aqui tu especificacion
{
  ArrayFacts<int>();  
  SumProps(v);

  //Implementa

}

//Coste y justificación:
