//Name : Kiran Tulsulkar NUID : 001057882
#include <stdio.h>
#include <cstdlib>
#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;

int rodCut_dynamic(int price[], int n) 
{ 
   int val_str[n+1]; 
   val_str[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val_str[i-j-1]); 
       val_str[i] = max_val; 
   } 
  
   return val_str[n]; 
} 

int rodCut(int price[], int n)
{
    // base case
    if (n == 0)
        return 0;

    int maxValue = 0;

    for (int i = 1; i <= n; i++)
    {
        // rod of length i has a cost price[i-1]
        int cost = price[i - 1] + rodCut(price, n - i);

        if (cost > maxValue)
            maxValue = cost;
    }

    return maxValue;
}

//array to get_Price function
void get_Price(int price_cuts[],int num_cuts)                                
{
    int j = 1;
    //Storing in price array
    for(int i = 0;i < num_cuts ; i++)
    {

        if(j == 1)
        {
            price_cuts[i] = 2;                                    
            
        }
        if(j < num_cuts && j > 1)
        {
            price_cuts[i] = floor(2.5 * j);                       
        }

        if(j == num_cuts)
        {
            price_cuts[i] = ((2.5 * j) - 1);                    
        }
        
        j++;
    }
    cout<<"Price Array : ";
    for(int i=0; i<num_cuts;i++){
    // Printing the price array
        cout << price_cuts[i]<<" ";                              
    }
}

int main()
{
    int num_cuts ;
    
     //Entering rod size
    cout << "Enter Rod Size: ";                        
    cin >> num_cuts;
    
    int price_cuts[num_cuts];
    //Function call to get the prices
    get_Price(price_cuts,num_cuts);                              
    
    cout<< "\nRecursive Aproach";
    //clock_t - start the clock
    clock_t timeProf = clock();
    //maximum revenue
    cout << "\nMaximum Possible Revenue is: " << rodCut(price_cuts, num_cuts);   
     //Stop the clock
    timeProf = clock() - timeProf;
    //time taken for cutting of rod
    cout << "\nTime taken for execution : " << (((float)timeProf)/CLOCKS_PER_SEC) << endl; 
    
    cout<< "\nDynamic Programming Aproach";
     //clock_t - start the clock
    clock_t timeProf1 = clock();
    //maximum revenue
    cout << "\nMaximum Possible Revenue is: " << rodCut_dynamic(price_cuts, num_cuts);   
     //Stop the clock
    timeProf1 = clock() - timeProf1;
    //time taken for cutting of rod
    cout << "\nTime taken for execution : " << (((float)timeProf1)/CLOCKS_PER_SEC) << endl; 
   
    return 0;
}