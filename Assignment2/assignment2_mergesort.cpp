
// Name : Kiran Tulsukar NuID : 001057882

#include <iostream>
#include <random>
using namespace std;


void Merge(int A[], int min1, int mid1, int max1)
{
    
    int nL = mid1 - min1+1;// Finding Length of Left array
    int nR = max1 - mid1;// Finding Length of Right array 
    int L[nL]; // creating left and right array for sorting
    int R[nR];
    
	// Creating Left array
    for (int i=1 ;i<=nL ;i++) { 
        L[i] = A[min1+i-1];
    }
	// Creating Right array
    for (int j=1;j<=nR ;j++){
        R[j] = A[mid1+j];
    }
    
	// Setting Last value in array as infinity
    L[nL+1] = 1000;
    R[nR+1] = 1000;
    
    int i = 1;
    int j = 1;
    // Sorting the divide arrays
    for (int k = min1;k<=max1;k++){
        if (L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
    
    
}

void MergeSort(int A[],int min , int max){
    if(min<max){
        
    	int mid = (min+max)/2; //Finding Middle Index
    	MergeSort(A,min,mid);// Passing Array, Minimum Index and Middle Index
    	MergeSort(A,mid+1,max);// Passing middle and max value
    	
    	Merge(A,min,mid,max); // Merging the sorted arrays
    	
    }

}

int main(){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 100);//uniform distribution between 1 and 100
	int n;
	cout << "Enter the value of n "; // Entering Value of n
	cin  >> n;
	
	int A[n];
	
	cout<< "Randomly Generated Numbers are : "<<'\n'; // Printing Randomly Generated Numbers
	for(int i = 0; i<n;i++){
	    
	    A[i] = dis(gen);
	    cout<< A[i]<<'\t';
	}
	
    int p =0;
    int r =n-1;
	MergeSort(A,p,r);// 0 ,8
    cout<<'\n';
    cout<< "Sorted Numbers are : "<<'\n'; // Printing Sorted Numbers
    for (int i = 0; i < n;i++)
	{
		cout << A[i]<<'\t';
	}

	cout<<'\n';
	return 0;
    
}


