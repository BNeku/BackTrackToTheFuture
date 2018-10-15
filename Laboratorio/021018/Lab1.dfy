include "Neku.dfy" //sustituye aqui por tu fichero
include "specFunctions.dfy"
//2.Especifica un metodo que determine si todos los elementos de un vector de enteros son positivos

method mpositivos(v:array<int>) returns (b:bool)
    requires v.Length > 0
    ensures b==positivosA(v)

//4.Especifica un metodo que determine si todos los elementos de un vector de enteros contenidos entre dos posiciones 
//dadas c (incluida) y f (excluida) son pares. Se considera que el intervalo [c,f) es vacio cuando c=f
//[c,f)

predicate pares(v:array<int>, d:int , g:int )
    reads v;
{ forall u:: 0 <= d <= u < g < v.Length-1 ==> v[u]%2==0}

method mparesEntreA(v:array<int>,c:int,f:int) returns (b:bool)
    requires v.Length > 0 && c!=f
    ensures b == pares(v, c, f)

//6.Especifica un metodo que dado un vector de enteros devuelva la posicion en la que se encuentra el primer elemento
//igual a 0, y el numero de elementos en caso de no haber ninguno 


method mprimerCero(v:array<int>) returns (i:int)
    requires v.Length > 0
    ensures exists i:: esPrimerCero(v[0..v.Length],i) 


//8.Especifica un metodo que calcule una posicion del maximo de un vector de enteros
method mmaximo(v:array<int>) returns (i:int) 
    requires v.Length>0
    ensures forall k :: 0<= k <= i < v.Length-1 ==> v[i] >= v[k]

//10. Especifica un metodo que calcule la posicion de la aparicion mas a la derecha  del maximo de un vector de enteros


method multimoMaximo(v:array<int>) returns (i:int)
      requires v.Length>0
    ensures forall k :: 0<= k <= i < v.Length ==> v[i] >= v[k] && i > k

//12.Especifica un metodo que calcule la raiz entera de un entero positivo
/*
method mraiz(n:int) returns (r:int) 
    requires n >= 0
    ensures Pow(n, r) Marty tiro el cafe encima de mis apuntes sobre raices cuanticas y no pudimos resolverlo
    */

//14.Especifica un metodo que  calcula la suma de los elementos de un array de enteros

method msuma(v:array<int>) returns (suma:int) //de izquierda a derecha
//ensures  suma==SumS(v[0..v.Length])
ensures suma==SumV(v,0,v.Length)

//16.Especifica un metodo que indica si un vector es Gaspariforme (ejercicio 8 de los apuntes)

/*gaspariforme: todas sus sumas parciales son no negativas y la suma total es igual a cero*/
/*suma parcial: toda suma a[0] + .. + a[i] con 0<= i < n */
method mgaspariforme(v:array<int>) returns (b:bool)
    requires v.Length > 0
    ensures forall u, k:: 0 <= u < k <v.Length ==> SumV(v,u,k) >= 0 && SumS(v[0..v.Length])==0 ==> b==true

//18. Especifica un metodo que positiviza un vector de enteros, lo cual consiste en reemplazar los valores
// negativos por cero respetando el resto de valores
method mpositivizar(v:array<int>)
modifies v
ensures forall k::0<=k<v.Length && old(v[k])<0 ==> v[k]==0 &&
        forall k::0<=k<v.Length && old(v[k])>=0 ==> v[k]==old(v[k])

//20. Especifica un metodo que dado un vector v de enteros devuelva otro vector w con su imagen especular 
method mespecular(v:array<int>,w:array<int>)
modifies w
ensures forall k::0<=k<v.Length && 
