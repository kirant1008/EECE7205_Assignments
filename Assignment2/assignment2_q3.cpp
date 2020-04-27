#include <iostream>
#include <random>
using namespace std;


void ProcedureX(int A[],int x)
{
	int c; 
	for (int i = 0; i <=x-1 ; i++)
	{
		for (int j = x-1; j >= i; j--)
		{
			if (A[j]<A[j-1]){

				c=A[j];
				A[j]=A[j-1];
				A[j-1]=c;
			}
		}
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
	
    // int p =0;
    // int r =n-1;
	ProcedureX(A,n);// 0 ,8
    cout<<'\n';
    cout<< "Sorted Numbers are : "<<'\n';
    for (int i = 0; i < n;i++)
	{
		cout << A[i]<<'\t';
	}

	cout<<'\n';
	return 0;

}