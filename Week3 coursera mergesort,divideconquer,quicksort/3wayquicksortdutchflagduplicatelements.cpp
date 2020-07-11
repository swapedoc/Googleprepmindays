#include <iostream>
using namespace std;
void sort(int a[],int lo,int hi){
	if(hi<=lo)return;
	int lt=lo,gt=hi;
	int pivot=a[lo];
	int i=lo;
	while(i<=gt){
		if(a[i]<pivot)swap(a[i++],a[lt++]);
		else if(a[i]>pivot)swap(a[i],a[gt--]);
		else i++;
	}
	sort(a,lo,lt-1);
	sort(a,gt+1,hi);
}
int main() {
	int arr[]={3,2,1,4,5};
	sort(arr,0,5);
	for(int i=0;i<5;i++)
	cout<<arr[i]<<" ";
	// your code goes here
	return 0;
}