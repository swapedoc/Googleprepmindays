Suffix array:-sorted array of all suffixes of given string
make array of all suffixes
then sort the array
so nlogn then n comparison  so n^2 log n
eg: 
for banana
banana, anana,nana,ana,na,a are suffixes

then sort array
a,ana,anana,banana,na,nana (for our purposes suffix is non empty substring)

suffix aray provides space alternative for suffix tree which itselff is compressed version of trie

suffix array can do everything what suffix tree can

trick to search keywords is : create suffix sort arrray, then use binary search to search for equal  ones, then calculate lcp between adjacent

Its not good with LRS is very long
Longest repeated substring:  Suffix array 
Brute force DN^2

manber myers:-(use this to improve lcp calculation and overall suffix array construction)(n logn)
Cyclic rotations?

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 65536
#define MAXLG 17

char A[MAXN];

struct entry
{
	int nr[2];
	int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int stp, cnt;

int cmp(struct entry a, struct entry b)
{
	return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main()
{
	gets(A);
	for(N=strlen(A), i = 0; i < N; i++)
		P[0][i] = A[i] - 'a';
	
	for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
	{
		for(i=0; i < N; i++)
		{
			L[i].nr[0]=P[stp- 1][i];
			L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
			L[i].p= i;
		}
		sort(L, L+N, cmp);
		for(i=0; i < N; i++)
			P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
	}
	return 0;
}
N log log N

https://discuss.codechef.com/t/a-tutorial-on-suffix-arrays/2950