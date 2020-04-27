#include <iostream>
#include <random>
using namespace std;


void Merge(int A[], int min1, int mid1, int max1)
{
    
    int nL = mid1 - min1+1;
    int nR = max1 - mid1;
    int L[nL];
    int R[nR];
    
    for (int i=1 ;i<=nL ;i++) {
        L[i] = A[min1+i-1];
    }
    for (int j=1;j<=nR ;j++){
        R[j] = A[mid1+j];
    }
    
    int i = 1;
    int j = 1;
    int k = min1;
    
    while(i<=nL and j<=nR){

        if (L[i]<=R[j])
        {
            A[k] = L[i];
            i=i+1;
        }
        else
        {
            A[k] = R[j];
            j=j+1;
        }
        k=k+1;
    }
    while(i<=nL)
    {
        A[k] = L[i];
        i=i+1;
        k=k+1;
    }
    while(j<=nR)
    {
        A[k] = R[j];
        j=j+1;
        k=k+1;
    }
        
}

void MergeSort(int A[],int min , int max){
    if(min<max){
        
        int mid = {(min+max)/2};//4
        MergeSort(A,min,mid);// 0,4
        MergeSort(A,mid+1,max);
        
        Merge(A,min,mid,max);
        
    }

}

int main(){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 100);//uniform distribution between 1 and 100
    int n;
    cout << "Enter the value of n ";
    cin  >> n;
    
    int A[n];
    
    cout<< "Randomly Generated Numbers are : "<<'\n';
    for(int i = 0; i<n;i++){
        
        A[i] = dis(gen);
        cout<< A[i]<<'\t';
    }
    
    int p =0;
    int r =n-1;
    MergeSort(A,p,r);// 0 ,8
    cout<<'\n';
    cout<< "Sorted Numbers are : "<<'\n';
    for (int i = 0; i < n;i++)
    {
        cout << A[i]<<'\t';
    }

    cout<<'\n';
    return 0;
    
}


