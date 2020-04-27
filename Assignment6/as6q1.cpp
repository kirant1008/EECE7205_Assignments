//Name : Kiran Tulsulkar NUID : 001057882
#include <iostream>
#include<ctime>
using namespace std;

int A[100];

int fib_rec(int n) 
{ 
    if (n <= 1) // if n = 0 or n = 1 return 1
        return n; 
    return fib_rec(n-1) + fib_rec(n-2); 
}
int fib_dynamic(int n) 
{ 
  int result;
  if (A[n] != -1){
      return A[n];
  }
  if (n==1 or n==2){
      result = 1;
  }
  else{
      result = fib_dynamic(n-1)+fib_dynamic(n-2);
  }
  A[n] = result;
  return result;
} 
  

int main(){
    int n ;
    cout << "Enter value of n = ";
    cin >> n;
    clock_t timeProf = clock();
    cout << "Recursive Aproach : "<<fib_rec(n)<<'\n';
    timeProf = clock() - timeProf;
    //time taken for cutting of rod
    cout << "Time taken for execution : " << (((float)timeProf)/CLOCKS_PER_SEC) << endl; 
    for(int i=0;i<100;i++){
        A[i] = -1;
    }

    clock_t timeProf1 = clock();
    cout << "Dynamic Aproach : "<< fib_dynamic(n)<<'\n';
    timeProf1 = clock() - timeProf1;
    cout << "Time taken for execution : " << (((float)timeProf1)/CLOCKS_PER_SEC) << endl;

}