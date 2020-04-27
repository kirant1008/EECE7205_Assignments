//Name : Kiran Tulsulkar NUID : 001057882
#include <iostream>
#include <stdexcept>
#include<stdlib.h>
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

# define INF 0x3f3f3f3f                                                 

typedef pair<int, int> iPair;

//ifstream is used to read text file
ifstream inf;
 //Global variables                                                              
int cnt =0;                                                             
int j = 0;                                                                
int temp;
int ver1[100];                                                               
int ver2[100];
int dst[100];
//List to store the vertex and weights
int lst[1000];                                                             

 //USed to read inputs and store it in the list
void read_Input()                                                                 
{
  inf.open("plot.txt");
  if (inf.fail())
  {
    cerr << "Error: Could not open input file\n";
    exit(1);
  }
  //100897 marks EOF
  while (temp != 100897)                                                              
  {
    try
    {
        inf >> temp;
    }
    catch (std::ifstream::failure e)
    {
        break;
    }
    if(temp < 999)
    {

      lst[cnt++] = temp;
    }
  }
inf.close(); //Close the file
}

void input_Matrix(int list[])
{
    //loop for storing vertex 1
    for(int i = 0; i < cnt; i=i+3)                                               
    {
        ver1[j] = lst[i];
        j++;
    }

    //loop for storing vertex 2
    j=0;
    for(int i = 1; i < cnt; i=i+3)                                              
    {
        ver2[j] = lst[i];
        j++;
    }

    //loop for storing Distance
    j=0;
    for(int i = 2; i < cnt; i=i+3)                                              
    {
        dst[j] = lst[i];
        j++;
    }

}


//Convert the integer to string to display in strings
string integerToString(int j)                                            //Convert the integer version to string for printing
{
    if(j==11)
        return "23a";
    if(j==12)
        return "23b";
    if(j==13)
        return "23c";
    if(j==15)
        return "23e";
    if(j==16)
        return "23f";
    if(j==17)
        return "23g";
    if(j==18)
        return "23h";
    else
        return to_string(j);

}

//Convert the string to integer to store in the integers
string stringToInteger(string a)                                        
{	
	//Convert the string version to integer for storing
    if(a=="23a")
        return "11";
    if(a=="23b")
        return "12";
    if(a=="23c")
        return "13";
    if(a=="23e")
        return "15";
    if(a=="23f")
        return "16";
    if(a=="23g")
        return "17";
    if(a=="23h")
        return "18";
    else
        return a;
}





// adjacency list To add an edge
//Add an edge to the container
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)                 
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

//print_Path function to get the path 
void print_Path(int parent[], int j)                                                    
{
    if (parent[j] == 0)
       return;
   	//recursively calling printPath
	//Recursive function
    print_Path(parent, parent[j]);                                                       
    string location = integerToString(j);
    //Printing Path
    cout << " >>>> " << location;                              
}

void shortest_Path(vector<pair<int,int> > adj[], int V, int src,int dest)
{

	//Priority queue is used to take in the locations which are not yet visited
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;                         

    //Assigning infinity to all vertices
    vector<int> dist(V, INF);                                                           
    int parent[100] = {-1};
    parent[0] = -1;

    //Source distance assigned to zero
    pq.push(make_pair(0, src));                                                         
    dist[src] = 0;


    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        // For loop to get all adjacent of vertex
        for (auto x : adj[u])                                                          
        {

            int v = x.first;
            int weight = x.second;

            // If condition to find is shorted path to v through u
            if (dist[v] > dist[u] + weight)                                           
            {
            	// Updating distance of v
                parent[v] = u;                                                        
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    if(dist[dest] > 10000) 
    {
        cout<< "Point entered not available on Map";
    }
    else
    {  
        string destination = integerToString(dest);
        //Printing Distance in meters
        cout << "Distance from "<< src << " to " << destination << " is: "<<dist[dest] << " meters \n";      
        float x = dist[dest] * 0.000621371;
        float y = ceil(x*10);
        y = y/10;
        //Printing Distance in miles
        cout << "Distance from "<< src << " to " << destination << " is: "<<y<< " miles \n";                                                  
        cout << "\nPath for the shortest distance \n";
        cout << integerToString(src);
        //printPath to get the Path
        print_Path(parent,dest);                                                                    
        cout << "\n";
    }
}


// Driver code
int main()
{
    read_Input();
    input_Matrix(lst);
    string start,end;
    int V = 100;
    vector<iPair > adj[V];
    //For loop to add edges 
    for(int i =0;i<100;i++)                                                                     
    {
        addEdge(adj,ver1[i],ver2[i],dst[i]);
    }
    cout << "Enter the Start Location: ";                                                              
    cin >> start;
    cout << "Enter the End Location: ";                                                         
    cin >> end;
    cout << "\n";
    start = stringToInteger(start);
    end = stringToInteger(end);
    shortest_Path(adj, V,stoi(start),stoi(end));                                      
	return 0;
}