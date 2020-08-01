small extension to Dijkstra that builds in heuristic to tell we are getting a bit closer
for each node we have distance to a node and distance to reach target(this is the heuristic , here we can take euclidean distance as one of the sensible heuristic){part of informed search or heuristic}
fn= gn+hn {euclidean+greedy path cost}
O(V+e)

Maths
No of factors of number , divide it into prime with powers p1, p2, p3 etc -> (p1+1)*(p2+1)....etc
sum of factors of number-> p^a *q^b -> (p^(a+1)-1/(p-1) ) * (q^(b+1) -1 /q-1)
product of factors of number-> say 84 is 84^(no of factors/2)

A number n is called a perfect number if n Æ ¾(n)¡n, i.e., n equals the sum
of its factors between 1 and n¡1. For example, 28 is a perfect number, because
28 =1+2+4+7+14

approximation on number of primes between 1 to n = n/ ln n (ln is log base e)

factors
vector<int> factors(int n) {
vector<int> f;
for (int x = 2; x*x <= n; x++) {
while (n%x == 0) {
f.push_back(x);
n /= x;
}
}
if (n > 1) f.push_back(n);
return f;
}

prime sieve
#include <bits/stdc++.h>
using namespace std;
void sieve(int n){
	int count=0;
	vector<bool>prime(n,true);
	for(int i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
    }
    for(int i=2;i<=n;i++){
    	if(prime[i])cout<<i<<" ";
    }
}
int main() {
	int n;
	cin>>n;
	sieve(n);
	// your code goes here
	return 0;
}

gcd
int gcd(int a, int b) {
if (b == 0) return a;
return gcd(b, a%b);
} 
works in log n, to find complexity notice that reduction due to mod is mmore than 25% x-x/4 =3/4x 
(4/3)^S <= A+B

2 numbers are coprime if gcd between them is 1
number of coprime to n = euler totient of n
eg totient of 12 => factors of 12 is 2^2* 3 so 2^(2-1)*3^(1-1)*(3-1)=4
for prime n totient is n-1

mod 
x^n mod m = ((x mod m)^n)mod m , also for plus minus and multiply

mod exponentiation
for numbmer B= x*x*x* ..n times
B= x[n/2 times ] * x[n/2 times] *x(if B is odd)
again x[n/2 can be divided into x[n/4] *x[n/4] etc

int modpow(int x, int n, int m) {
if (n == 0) return 1%m;
long long u = modpow(x,n/2,m);
u = (u*u)%m;
if (n%2 == 1) u = (u*x)%m;
return u;
}


euler's theorem

(anynumber)^p modq =1 if p is euler totient of q-1


Modular inverse
if x* x^-1 mod m=1 
so for x=6 and m=17 ,inverse is 3
but inverse not always exists

only when x and m are coprime then inverse exists
x inverse mod m=  x ^(euler totient -1) mod m

Diophantine solution  for ax+by=c where c is div by gcd of (a,b)
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g!=0) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
int main(){
	int a,b,c,x1,y1,g;
	cin>>a>>b>>c;
	if(find_any_solution(a,b,c,x1,y1,g))cout<<x1<<" "<<y1;
	
}
input 39 15 12
output 8,-20
If a pair (x, y) is a solution,
then also all pairs
(x+kb/gcd(a,b), y-ka/gcd(a,b) are also solution

)
are solutions, where k is any integer.
eg 8,-20 is soln for 39x +15y=12
hence 8+1*(15/3),-20-1(39/3)) => 13,-33 are also solution 

Lagrenge:
every positive number can be represented as sum of square of 4 numbers

pythagorean triples:
(n^2-m^2,2nm,n2+m^2), where n,m are coprime and atleast one of m,n is even

wilson theorem
if n is prime , then (n-1)! mod n =n-1
eg 5 is prime, then 4! mod 5=4 or 24 mod 5=4


-----------------------------------------
Combinatorics

nCk
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
pascal triangle
const int maxn = ...;
int C[maxn + 1][maxn + 1];
C[0][0] = 1;
for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
}


.................
to get multiplicative inverse trick is to write m mod i = m- (m/i)mod i then reach i inverse by multiplying with some numbers on rhs and lhs(using also the property n* inverse of n =1)
m mod i=m−floor(m/i) *i
Taking both sides modulo m yields:
mmodi≡−⌊mi⌋⋅i mod m
Multiply both sides by i−1⋅(mmodi)−1 yields
(mmodi)⋅i−1⋅(mmodi)−1≡−⌊mi⌋⋅i⋅i−1⋅(mmodi)−1modm,
which simplifies to:
i^−1≡−⌊mi⌋⋅(m mod i)^−1 mod m
also use property inverse of 1 is 1 , so start looping from 2
inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = (m - (m/i) * inv[m%i] % m) % m;
........................


another method to calculate nCk
nCk= n!inv(k!) *inv((n-k)!)

to cal:= n! mod m%
factorial[0] = 1;
for (int i = 1; i <= n; i++) {
    factorial[i] = factorial[i - 1] * i % m;
}

factorial n will store n! value_comp
now inverse
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k]) % m * inverse(factorial[n - k]) % m;
}
where inverse
inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = (m - (m/i) * inv[m%i] % m) % m;

-------------
catalan numbers=total no of valid parenthesis=n nodes , total number of binary trees
2n C n ways to construct all parenthesis,(n right , n left parenthesis)
if parenthesis not valid then either left more or right more so 2n Cn+1 are invalid
so valid =  2n Cn - 2n C (n+1)  also known as catalan number  = (1/(n+1)) * 2n Cn
anotehr application in n*n lattice where you want to go only in top part and not below diagonal


Burnside lemma or polya enumeration
n pearl , m colors ->find total necklaces;
total = sum i=0 to n-1  m^(gcd(i,n) /n 

so for 4 pearl , 3 color necklaces
 3^(0)/4+ 3/4+3^2/4+3^(gcd(4,4))/ 24
 
 cayley formula- for labelled trees for n nodes
 
total trees= n^(n-2) so for 4 node labels 1,2,3,4 there are 4^(4-2)=16 trees


..................................................
probability

Expected value
The expected value E[X] indicates the average value of a random variable X.
The expected value can be calculated as the sum
X
x
P(X Æ x)x,
where x goes through all possible values of X.
For example, when throwing a dice, the expected outcome is
1/6*1+1/6*2+1/6*3...  =7/2

uniform distribution for dice 
(1+6)/2
binomial distribution
eg throwing dice 10 times probabilyt of throwing a six exactly 3 times is 
(1/6)^3(5/6)^7 10C3
expected value =pn


Markov chain: dp based method which maintain probability distribution
complexity: O(n^3 log m) {m steps n floor}


Order statistics: quick select (already done)
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


Game theory

Finder's keepers
a and b playing game , if each player can pick atleast x coins and at max y coins 
then for strategy where last coin wins:
1)Finders-winner-> reduce opponent to state of (x+y)*k(player who picks last coin wins)
2)keepers-loses-> player who picks last coin loses (x+y)*k +l  where  1<=l<=x

game of nim
iN this game n heaps are given and 2 players alternatively pick sticks,finders keepers
so losing state is where xor of all numbers is 0 , if player a goes first and for him xor is not 0,
try to remove y sticks such that after removal of y from one of the heap , the new xor is 0

misere game:
player who removes last stick loses ,
play normally , however in end choose a move so that there is odd number of heaps with 1 stick


Sprague Grundy theorem
grundy number of losing state is 0 , and winning state is positive
they use term called mex 
say 4 coins , a and b can chose 1,2,3 coins , a goes first
G(4)= 0
G(3)=mex(G(2),G(1),G(0))
G(0) =0,G(1)=1,G(2)={0,1} (2)
G(3)=mex(1,2,0)  so minimum exclusive number missing is 3
G(3)=3

trick is to reach a 0 state and give it to other 
might need to combine mex with xor if games are independent (becomes nim)
