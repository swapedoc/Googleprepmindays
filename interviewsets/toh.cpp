//3 towers source,helper ,destination
//move n-1 plates from source to helper using destination as helping fn
//move last plate from source to destination
//move n-1 plate from helper to destination using source as helping fn

#include <iostream>
using namespace std;
void toh(int n,int s,int h, int d){
	if(n>0){
		toh(n-1,s,d,h);
		cout<<"moved  from "<<s<<" to "<<d<<endl;
		toh(n-1,h,s,d);
	}
}
int main() {
	int n=3;
	int s=1,h=2,d=3;
	toh(n,s,h,d);
	// your code goes here
	return 0;
}