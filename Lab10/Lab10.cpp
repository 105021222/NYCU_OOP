#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
 
void heapify(int *a ,int root, int n) {
    int parent = root;
    int child = parent * 2 + 1;
        while (child <= n) {
            if (child < n && a[child] < a[child + 1]) child++;
            if (a[parent] >= a[child]) return;
            swap(a[parent], a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
}
 
 void heap_sort(int *a ,int num) {
    for (int i = (num / 2) - 1; i >= 0; i--) {
        heapify(a,i, num - 1);
    }
    for (int i = num - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a,0, i - 1);
    }
}

void bubble_sort(int* a,int num) {
    int n = num;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void selection_sort(int* a,int num) {
    int n = num;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index!= i) {
            swap(a[min_index], a[i]);
        }
    }
}
void insertion_sort(int* a,int num) {
    int n = num;
    for (int i = 1, j, key; i < n; i++) {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

void merge(int array[], int const left, int const mid, int const right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
 
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
 
    
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


//quickSort
int partition (int* a, int low, int high)
{
    int pivot = a[high]; 
    int i = (low -1);
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}


 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(a, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
 
/* Function to print an array */


 int main(){
 	fstream file;
 	file.open("input.txt");
 	int num=0;
 	file>>num;

	
 	int a[num];
 	for(int i=0;i<num;i++){
 		file>>a[i];
	}
	heap_sort(a , num);
	//bubble_sort(a , num);
	//selection_sort(a , num);
	//insertion_sort(a , num);
	//mergeSort(a,0,num-1);
	//quickSort(a, 0, num-1);
	for(int i=0;i<num;i++){
 		cout<<a[i]<<endl;
	}
	
	
 }
