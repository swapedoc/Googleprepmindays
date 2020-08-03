manacher is used to find longest palindromic substring in linear time

brute force solution is n^3
ok i am done i will use n^2 , not for my brain to comprehend , ukkonen you got a new match 

not doing z algo , kmp is enough

heavy light decomposition sum from one node to another , update quereies
, so we break parts in several components ie find chains and we use segment tree for it, basically we are moving in same chain as lca
during update operation the segment tree values need to be updated ,we go to start of chain , then jump to anotehr chain etc, so each chain is like an interval in segment tree
attach as many paths as possible in segment tree so we dont need to jump( better make heavy edge)

XXXX
given n people ,if we start by killing every kth people then:
#include <iostream> 
using namespace std; 
  
int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else
        /* The position returned by josephus(n - 1, k) 
        is adjusted because the recursive call  
        josephus(n - 1, k) considers the  
        original position k % n + 1 as position 1 */
        return (josephus(n - 1, k) + k-1) % n + 1; 
} 
if person are from 1 to n (or 1 based indexing)
for k=2 simple solution exist but for other values eqn is not found and we have only recursive structure
  
// Driver Program to test above function 
int main() 
{ 
    int n = 14; 
    int k = 2; 
    cout << "The chosen place is " << josephus(n, k); 
    return 0; 
} 