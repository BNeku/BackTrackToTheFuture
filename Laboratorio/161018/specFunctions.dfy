
function Count<T>(s : seq<T>, p : T -> bool):nat
 reads p.reads;
 decreases s;
 requires forall i:: 0<=i<|s| ==> p.requires(s[i])
 ensures |s| == 0 ==> (Count(s,p)==0)
 ensures (|s|>0 && p(s[|s|-1]) ==> (Count(s,p)==1+Count(s[..|s|-1],p)))
 ensures (|s|>0 && !p(s[|s|-1]) ==> (Count(s,p)==Count(s[..|s|-1],p)))
 {
 if s==[] then 0
 else (if p((s[|s|-1])) then 1 else 0)+Count(s[..|s|-1],p)
}


function CountP1Sec(s : seq<int>, i:int, p : (seq<int>,int) -> bool):nat
reads  p.reads;
decreases i;
requires 0<=i<=|s|
 requires forall k:: 0<=k<|s| ==> p.requires(s,k)
 ensures i==0 ==> CountP1Sec(s,i,p)==0
 ensures i>0 && p(s,i-1) ==> CountP1Sec(s,i,p) == 1+ CountP1Sec(s,i-1,p)
 ensures i>0 && !p(s,i-1) ==> CountP1Sec(s,i,p) == CountP1Sec(s,i-1,p)
 {
  
   if (i==0) then 0
   else if p(s,i-1) then 1+ CountP1Sec(s,i-1,p)
   else CountP1Sec(s,i-1,p)
   }
   


/*
 * Products
 */

function ProdLR(a : nat, b : nat) : nat	 
	decreases b - a
{
	if a > b then 1
	else if a == b then a
	else b * ProdLR(a, b-1)
}


function ProdRL(a : nat, b : nat) : nat
	decreases b - a
{
	if a > b then 1
	else if a == b then a 
	else a * ProdRL(a+1, b)
}

lemma ProdEquiv(a : nat, b : nat)
	decreases b - a
	ensures ProdLR(a, b) == ProdRL(a, b)


function Prod(a : nat, b : nat) : nat
	ensures ProdLR(a, b) == ProdRL(a, b)
{
	ProdEquiv(a, b); 
	ProdLR(a, b)
}

/*
 * Sums
 */


function SumV(v:array<int>,c:int,f:int):int
  requires 0<=c<=f<=v.Length
  reads v
{Sum(multiset(v[c..f]))}

function SumS(s:seq<int>):int
//decreases s
 {Sum(multiset(s))}


function Sum(s : multiset<int>) : int
decreases s
{
	if s == multiset{} then 0 else var x :| x in s; x + Sum(s - multiset{x})
}

lemma SumOne(a : multiset<int>, x : int)
    decreases a;
	requires x in a

	ensures Sum(a) == x + Sum(a - multiset{x})


lemma SumByParts(a : multiset<int>, b : multiset<int>)
	decreases a,b;
	ensures Sum(a + b) == Sum(a) + Sum(b)



/*
 * Lemmas
 */

lemma ArrayFacts<T>()
	ensures forall v : array<T>  :: v[..v.Length] == v[..];
	ensures forall v : array<T>  :: v[0..] == v[..];
    ensures forall v : array<T> :: v[0..v.Length] == v[..];

	ensures forall v : array<T>  :: |v[0..v.Length]|==v.Length;
	ensures forall v : array<T>  :: forall k : nat | k < v.Length ::
		v[..k+1][..k] == v[..k]

{

}

lemma ArrayFactsOn<T>(v : array<T>)

	ensures v[..v.Length] == v[..];
	ensures forall k : nat | k < v.Length ::
		v[..k+1][..k] == v[..k]
{

}

lemma SumProps(v : array<int>)
	ensures forall i : nat | i < v.Length :: Sum(multiset(v[..i+1])) == Sum(multiset(v[..i])) + v[i]
	ensures forall i : nat | i < v.Length :: Sum(multiset(v[i..])) == v[i] + Sum(multiset(v[i+1..]))
{
	forall i : nat | i < v.Length
		ensures Sum(multiset(v[..i+1])) == Sum(multiset(v[..i])) + v[i]
	{
		assert multiset(v[..i+1]) == multiset(v[..i]) + multiset{v[i]};
		SumByParts(multiset(v[..i]), multiset{v[i]});
	}


	forall i : nat | i < v.Length
		ensures Sum(multiset(v[i..])) == v[i] + Sum(multiset(v[i+1..]))
	{
		assert [v[i]] + v[i+1..] == v[i..];
		assert multiset(v[i..]) == multiset{v[i]} + multiset(v[i+1..]);
		SumByParts(multiset{v[i]}, multiset(v[i+1..]));
	}
}

/*Suma de elementos que cumplen una propiedad sobre la secuencia*/
function SumP1Sec(s : seq<int>, i:int, p : (seq<int>,int) -> bool):int
reads  p.reads;
decreases i;
requires 0<=i<=|s|
 requires forall k:: 0<=k<|s| ==> p.requires(s,k)
 ensures i==0 ==> SumP1Sec(s,i,p)==0
 ensures i>0 && p(s,i-1) ==> SumP1Sec(s,i,p) == s[i-1]+ SumP1Sec(s,i-1,p)
 ensures i>0 && !p(s,i-1) ==> SumP1Sec(s,i,p) == SumP1Sec(s,i-1,p)
 {
  
   if (i==0) then 0
   else if p(s,i-1) then s[i-1]+ SumP1Sec(s,i-1,p)
   else SumP1Sec(s,i-1,p)
   }
   


/*
 * Power
 */

function Pow (x : int , n : nat ) : int
    decreases n;
	ensures x >= 0 ==> Pow (x , n ) >= 0
{
	if n == 0 then 1 else x * Pow (x , n - 1)
}

lemma {:induction n} PowProdLemma(x : int, n : nat, m : nat)
	decreases n

	ensures Pow(x, n) * Pow(x, m) == Pow(x, n + m)
{
}
