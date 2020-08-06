first method is sqrt decomposition
we divide array into (int)sqrt+1 size blocks and calculate value for range
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
vector<int> a (n);
for(int i=0;i<n;i++)
cin>>a[i];
// preprocessing
int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
vector<int> b (len);
for (int i=0; i<n; ++i)
    b[i / len] += a[i];


// answering the queries
for (;;) {
    int l, r;
    cin>>l>>r;
  // read input data for the next query
    int sum = 0;
    for (int i=l; i<=r; )
        if (i % len == 0 && i + len - 1 <= r) {
            // if the whole block starting at i belongs to [l, r]
            sum += b[i / len];
            i += len;
        }
        else {
            sum += a[i];
            ++i;
        }
        cout<<sum<<endl;
        break;
}

return 0;
}

//not doing mo's algorithm might see later

Binary index tree: only advantage is it takes less memory compared to segment tree , however tehre is no point to use BIT when you can simply do using segment trees since all BIT has some restrictions but segment tree can do everything what BIT can

BIT as name suggest depends on binary index
the trick is to go till set bit position eg for 4 or binary 100 first set bit position is 2nd positions from left(if 0 indexed)
so 4 will store 2^2=4 element sum , similarly 8 1000 =2^3=8 position sum , 
0000
0001
0010
0011
0100
0101
to calculate sum of say [1,5] or 101 we have to keep removing set bits one by one 
so sum of 1 to 5 , first 5 or 101 is responsible for itself

then remove the lowet set bit 101& -101 or 101*001= 1from 101
so now 101-1 =100 so this we update to sum and try unset more

we cant so we stop

This is sum implementation
int sum(int k) {
int s = 0;
while (k >= 1) {
s += tree[k];
k -= k&-k;
}
return s;
}

update operation : to sum say 9 or 1001 , we will need to update numbers above 9 that can reach use
numbers will be 1010, 1100 and 10000 

when you add 1 to lowest set bit ie 9 you get 10 , when you do on lowest set bit of 10 you get 12 , then 16

void update(int k,int x){
	while(k<=n){
		tree[k]+=x;
		k+=k&-k;
	}
}
 complexity of both )(log n)

just like interval tree , all nodes in base and save queries in parent  like range minimum, range sum etc
update take care of parents
while storing in array do level order traversal from top


Segment tree stores intervals, and optimized for "which of these intervals contains a given point" queries.
Interval tree stores intervals as well, but optimized for "which of these intervals overlap with a given interval" queries. It can also be used for point queries - similar to segment tree.
Range tree stores points, and optimized for "which points fall within a given interval" queries.
Binary indexed tree stores items-count per index, and optimized for "how many items are there between index m and n" queries.
Performance / Space consumption for one dimension:

Segment tree - O(n logn) preprocessing time, O(k+logn) query time, O(n logn) space
Interval tree - O(n logn) preprocessing time, O(k+logn) query time, O(n) space
Range tree - O(n logn) preprocessing time, O(k+logn) query time, O(n) space
Binary Indexed tree - O(n logn) preprocessing time, O(logn) query time, O(n) space

XXXXXXXXXXXXXXXXXXX
