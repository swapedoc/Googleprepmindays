#include <iostream>
using namespace std;

void swimmax(int arr[],int k,int N){                             
	while(k>0 && arr[k/2]<arr[k]){
		swap(arr[k],arr[k/2]);
		k=k/2;
	}
}
void sinkmax(int arr[],int k,int N){   
	   
	while(2*k<N){
		int j=2*k+1;
		if(j<N && arr[j]<arr[j+1])j++;
		if(arr[k]>=arr[j])break;
		swap(arr[k],arr[j]);
		k=j;
	}
}
void sinkmin(int arr[],int k,int N){   
	   
	while(2*k<N){
		int j=2*k+1;
		if(j<N && arr[j]>arr[j+1])j++;
		if(arr[k]<arr[j])break;
		swap(arr[k],arr[j]);
		k=j;
	}
}

void buildmaxheap(int arr[],int N){
	for(int k=N/2-1;k>=0;k--)
	sinkmax(arr,k,N);
}
void buildminheap(int arr[],int N){
	for(int k=N/2-1;k>=0;k--)
	sinkmin(arr,k,N);
}
void printheap(int *,int);
void heapascendingsort(int arr[],int N){
	int last=N-1;
	buildmaxheap(arr,N);
	while(last>0){
	swap(arr[0],arr[last]);
	sinkmax(arr,0,--last);
	}
}
void heapdescendingsort(int arr[],int N){
	int last=N-1;
	buildminheap(arr,N);
	while(last>0){
		swap(arr[0],arr[last]);
		sinkmin(arr,0,--last);
	}
}
void printheap(int arr[],int N){
	for(int i=0;i<N;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
int main() {
	// your code goes here
	int arr[]={2,3,1,4,5,6,7};
	int N=7;
	heapascendingsort(arr,N);
	printheap(arr,N);
	heapdescendingsort(arr,N);
	printheap(arr,N);
	//for insert etc operation just create heap class and insert ele into new array int *arr;arr=new int[cap];
//	buildmaxheap(arr,N);
//	printheap(arr,N);
//	buildminheap(arr,N);
//	printheap(arr,N);
	return 0;
}