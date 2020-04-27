
// Name : Kiran Tulsukar NuID : 001057882

#include <iostream>
#include <random>
using namespace std;

int date_random(int day, int month, int year){

    string d,m,y,date;
    
    d= to_string(day); //Converting integer to string
    m= to_string(month);
    y= to_string(year);
    if(day<10 && month<10){
        date = '0' + d + '0'+ m +'0'+y;
    }
    else if(day<10){
        date = '0'+d+m+'0'+y;
    }
    else if(month<10){
        date = d +'0'+ m +'0'+y;
    }
    else{
        date =  d + m +'0'+y;
    }
    int new_date = stoi(date);
    return new_date;
}


int main(){

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> day(1, 28);//Generation of days between 1 and 28
    std::uniform_int_distribution<> month(1, 12);//Generation of months between 1 and 12
    std::uniform_int_distribution<> year(0, 4);//Generation of year between 2000 an 2004

    //generating and storing 1000 random dates

    int birthday_keys_n = 1000;
    int birthday_keys[birthday_keys_n];

    for (int i = 0; i < birthday_keys_n;i++)
    {
        int d = day(gen);
        int m = month(gen);
        int y = year(gen);

        //Generating Random date using date_random

        int z = date_random(d,m,y);

        //Stroring randomly generated dates in birthday_keys

        birthday_keys[i] = z;

    }
    int size_table = 0;
    //Size of Hash Table
    cout << "Enter Size m = [97, 98, 100 , 101 ] of Hash table = ";
    cin >> size_table;

    int table[size_table];
    //Initiating all the values in hash table as 0
    for (int i = 0; i < size_table;i++)
    {
        table[i] = 0;
    }


    //Storing the count according to the index of keys mod the size of hash table
    for (int i = 0; i < birthday_keys_n; i++)
    {
        int index = birthday_keys[i] % size_table;
        if (table[index] == 0)
        {
            table[index] = 1;
        }
        else{
            
             table[index] = table[index]+ 1;
        
         }
    }

    //Sorting the array in ascending order
   for(int i=0; i<size_table;i++)
    {
        
        for(int j=0;j<size_table-1;j++)
        {
            int temp;
            
            if(table[j]>table[j+1])
            {
                temp=table[j];
                table[j]=table[j+1];
                table[j+1]=temp;
            }
        }
        
    }

    int max = table[size_table-1]-1;

    //Printing the minimum value
    for (int i = 0; i < size_table; i++)
    {
        if(table[i] !=0 && table[i] !=1){
            cout<< "Minimum collisions = "<< table[i]-1<<'\n';
            break;
        }
        
    }
    
    //Printing the Maximum value
    cout<< "Maximum collisions = "<< max<<'\n';

    //Calculating the mean and printing it
    float total = 0;
    for (int i = 0; i < size_table; i++)
    {
        if(table[i] !=0){
            total = total + (table[i]-1);
        }
    }
    
    float mean = total/size_table;

    cout<< "Mean of collisions = "<<mean<<'\n';

    // Calculating the variance and printing it
    float variance = 0;

    for (int i = 0; i < size_table; i++)
    {
        if(table[i] !=0){
            variance = variance + ((table[i]-1-mean)*(table[i]-1-mean));
        }
    }

    variance= variance/size_table;
    cout<< "Variance of collisions = "<<variance<<'\n';

}