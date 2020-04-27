
// Kiran Tulsulkar Nuid : 001057882
#include <chrono>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <fstream>
#include <stdexcept>
#include <time.h>
using namespace std;

// Initialising Moves and Comps
int moves = 0, comps = 0;

//To verify if the array is sorted 
void verifySort(int A[], int n){
    
	int correct =0;
	int incorrect = 0;
	cout<< '\n';
	for (int i =0; i < n; i++){
	    
	    if(A[i]<=A[i+1]){
	        correct = correct + 1; // Incrmenting the correct order
	    }
	    else{
	        incorrect = incorrect + 1; // Implementing the incorrect order
	    }
	}
	if(incorrect>1){
	    cout<<"Error"<<'\n'; // Printing Error and NOt an error
	}
	else{
	     cout<<"No Error"<<'\n';
	}
}
//writing function for swapByPointer
void swapP(int* n1 ,int* n2)
{
	 if(*n1 != *n2 ){
		moves = moves + 3;
		int w;//making a dummy variable
		w = *n1;
		*n1 = *n2;
		*n2 = w;
	}
}
//for generating array best average and worst
void array_generator(int Avg[], int Bst[], int Wst[], int num){

	for (int i = 0; i < num; i++)
	{
		Avg[i] = rand() % 1000;	 // Generating Random Integers
	}

	Bst[0] = 10;
	Wst[0] = 10000;
	for (int i = 1; i< num; i++){

		Bst[i] = Bst[i-1] + 10;
		Wst[i] = Wst[i-1] - 10;
	}

}

// Insertion Sort Algorithm
void insertion_sort(int grd[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		comps++;
		while (j > 0 and grd[j - 1] > grd[j]) //Comparing the numbers
		{
			comps++;
			swapP(&grd[j],&grd[j-1]);
			j = j - 1;
		}
	}
}


// Implementing Partition for QuickSort
int partition(int A[],int l, int h){
	int pivot = A[h];
	int i = (l-1);

	for (int j = l; j <= h-1; j++)
	{
		if(A[j]<=pivot){
			i++;
			swapP(&A[i],&A[j]);
		}
		comps++;
	}
	swapP(&A[i+1],&A[h]);
	return (i+1);
}

// QuickSort whcih calls partition
void quicksort(int A[],int p, int r){
	if(p<r){
		int q;
		q = partition(A,p,r); // Performing Partition  and get value q position for partition
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
	comps++;
}

// Implementing heapify for heapsort
void heapify(int A[], int n, int i){

	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && A[l] > A[largest]){
        largest = l;
	}
  	comps++;
    // If right child is larger than largest
    if (r < n && A[r] > A[largest]){ 
        largest = r;
    }
  	comps++;
    // If largest is not root 
    if (largest != i) 
    { 
        swapP(&A[i], &A[largest]);  
        heapify(A, n, largest); 
    }
    comps++;
}

//Implementing Heap-Sort usig heapify function 
void heapSort(int A[],int n){
	for(int i = n/2-1;i>=0;i--){
		heapify(A, n, i); // Generating an heap
	}
	for(int i = n-1; i>=0;i--){
		swapP(&A[0], &A[i]);
		heapify(A, i, 0);
	}
}

int main(){

ofstream outf;

srand(time(NULL));  

int num = 1000;
//Defining 9 arrays for average best and worst case
int Avg1[num], Bst1[num], Wst1[num];
int Avg2[num], Bst2[num], Wst2[num];
int Avg3[num], Bst3[num], Wst3[num];

// Generating the arrays required
array_generator(Avg1, Bst1, Wst1, num);
//Duplicating the arrays
for (int i = 0; i < 1000; i++)
{
	Avg2[i] = Avg1[i]; 
	Avg3[i] = Avg1[i];

	Bst2[i] = Bst1[i];
	Bst3[i] = Bst1[i];

	Wst2[i] = Wst1[i];
	Wst3[i] = Wst1[i];
}

//Best Case
// 
outf.open("Sort.txt");

outf<< "Best Case : \n\n";
cout<< "Best Case : \n\n";

moves = 0;
comps = 0;

insertion_sort(Bst1,num);

outf<< "Insertion Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Insertion Sort"<<"\n";
verifySort(Bst1,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";


moves = 0;
comps = 0;

heapSort(Bst2,num);

outf<< "Heap Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Heap Sort"<<"\n";
verifySort(Bst2,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";



moves = 0;
comps = 0;

quicksort(Bst3,0,num-1);

outf<< "Quick Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Quick Sort"<<"\n";
verifySort(Bst3,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";

outf<< "Average Case : \n\n";
cout<< "Average Case : \n\n";


// Average Case
moves = 0;
comps = 0;

insertion_sort(Avg1,num);

outf<< "Insertion Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Insertion Sort"<<"\n";
verifySort(Avg1,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";


moves = 0;
comps = 0;

heapSort(Avg2,num);

outf<< "Heap Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Heap Sort"<<"\n";
verifySort(Avg2,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";



moves = 0;
comps = 0;

quicksort(Avg3,0,num-1);

outf<< "Quick Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Quick Sort"<<"\n";
verifySort(Avg3,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";

outf<< "Worst Case : \n\n";
cout<< "Worst Case : \n\n";

moves = 0;
comps = 0;

insertion_sort(Wst1,num);

outf<< "Insertion Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Insertion Sort"<<"\n";
verifySort(Wst1,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";


moves = 0;
comps = 0;

heapSort(Wst2,num);

outf<< "Heap Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Heap Sort"<<"\n";
verifySort(Wst2,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";



moves = 0;
comps = 0;

quicksort(Wst3,0,num-1);

outf<< "Quick Sort"<<"\n";
outf<< "Moves : " << moves<<"\n";
outf<< "Comparisons : " << comps<<"\n\n";

cout<< "Quick Sort"<<"\n";
verifySort(Wst3,num);
cout<< "Moves : " << moves<<"\n";
cout<< "Comparisons : " << comps<<"\n\n";


moves = 0;
comps = 0;

outf.close();

return 0;

}