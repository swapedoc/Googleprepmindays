//1.39nlogn, worst n^2/2, inplace but not stable(for equal elements behaves weird)
#include<bits/stdc++.h>
using namespace std;
int findpivot(int arr[],int low , int high){
	int i=low, j=high+1;
	while(true){
		while(arr[low]>arr[++i]){if(i==high)break;}
		while(arr[--j]>arr[low]){if(j==low)break;}
		if(i>=j)break;
		swap(arr[j],arr[i]);
	}
	swap(arr[low],arr[j]);
	return j;
}
void quicksort(int arr[],int low,int high){

	if(low<high){
		int pivot=findpivot(arr,low,high);
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1,high);
	}
}
int quickselect(int arr[],int k,int n){                //kth smallest element(From index 0)
	unsigned seed=0;
	int low=0,high=n-1;
	shuffle(arr, arr+n, default_random_engine(seed)); 
	while(low<high){
		int j=findpivot(arr,low,high);
		if(j<k)low=j+1;
		else if(j>k)high=j-1;
		else return arr[k];
	}
	return arr[k];
	}
int main(){
	int arr[]={2,3,1,4,5};
	int n=5
	quicksort(arr,0,n-1);
	cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<endl;
	return 0;
	
}


\\Quickselect
\\Find kth largest element in array (o(n) avg but can go n^2 worst

int quickselect(int arr[],int k){
	unsigned seed=0;
	int low=0,high=n-1;
	shuffle(arr.begin(), arr.end(), default_random_engine(seed)); 
	while(low<high){
		int j=findpivot(a,low,high);
		if(j<k)low=j+1;
		else if(j>k)high=j-1;
		else return a[k];
	}
	return a[k];
	}
}