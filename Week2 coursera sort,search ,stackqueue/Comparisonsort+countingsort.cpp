Selection sort

void selectionsort(int arr[],int n){
 for(int i=0;i<n;i++){
	 for(int j=i+1;j<n;j++){
		 int temp=arr[i];
		 if(temp>arr[j])swap(arr[i],arr[j]);
	 }
 }	
}

Worst complexity: n^2
Average complexity: n^2
Best complexity: n^2
Space complexity: 1
Method: Selection
Stable: No(equal items dont preserve order)
Doesnt depend on type of input
inplace: Yes (doesnt depend on extra datastructure , or space complexity =1)

Insertion Sort

void insertionSort(int arr[],int n){
	for(int i=1;i<n;i++){
		int temp=arr[i];
		for(int j=i;j>=0;) {
			if(temp<arr[j-1] && j-1>=0){
				arr[j]=arr[j-1];
				j--;
			}
			else {arr[j]=temp;break;}                         
			                                                   
		}
	}
}
Worst complexity: n^2
Average complexity: n^2
Best complexity: n
Space complexity: 1
Method: Insertion
Stable: Yes
Class: Comparison sort

Bubble Sort

void bubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j+1]<arr[j])
				swap(arr[j],arr[j+1]);
	}}
	
Worst complexity: n^2
Average complexity: n^2
Best complexity: n
Space complexity: 1
Method: Exchanging
Stable: Yes
Class: Comparison sort	

Shell sort
insertion sort with h jumps , i++ becomes i+h, j-1 becomes j-h , etc

Cocktail sort
bubblesort from both directions , first get max element to rightmost then do bubble on right to left so min on left most and so on

function cocktailSort(a) {
    var swapped;
    var first_swap;
    var first_swap_new;
    var last_swap;
    var last_swap_new;
    first_swap = 0;
    last_swap = a.length - 1;
    do {
        swapped = false;
        for (var i=first_swap; i<last_swap; i++) {
            // if items are out of order swap them
            if (a[i] > a[i+1]) {
                swap(a, i, i+1);
                last_swap_new = i;
                swapped = true;
            }
        }
        first_swap_new = last_swap_new;
        for (var i=last_swap_new; i>=first_swap; i--) {
            // if items are out of order swap them
            if (a[i] > a[i+1]) {
                swap(a, i, i+1);
                first_swap_new = i;
            }
        }
        last_swap = last_swap_new;
        first_swap = first_swap_new;
    } while(swapped);
    return a;
}



