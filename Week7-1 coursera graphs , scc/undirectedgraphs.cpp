euler tour -> cycle that uses each edge exactly once
hamilton tour->cycle that uses each vertex exactly once
mst-best way to connect all vertices
connectivity->is there way to connect all vertices of graph
biconnectivity->>is there a vertex whose remove disconnect graph
planarity->draw graph without crossing edges
graph isomerism->do two adjacency lists represent same graph
in undirected graphs the "is connected" relation is reflexive , symmetric and transitive

Graph representations:-
1)Adjacency Matrix
2)Adjacency list
3)Edge lists

1)Adjacency Matrix
4  
4
1 2  
2 4  
3 1  
3 4  
input

0110
1001
1001
0110
output


 #include <iostream>

    using namespace std;

    bool A[10][10];

    void initialize()
    {
        for(int i = 0;i < 10;++i)
            for(int j = 0;j < 10;++j)
                A[i][j] = false;
    }

    int main()
    {
        int x, y, nodes, edges;
        initialize();       //Since there is no edge initially
        cin >> nodes;       //Number of nodes
        cin >> edges;       //Number of edges
		//in undirected graph nodes and edges will be same
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
            x--,y--;
            A[x][y] = true;
            A[y][x] = true;              
       }
       for(int i=0;i<nodes;i++){
       for(int j=0;j<edges;j++){
       cout<<A[i][j];}
       	cout<<endl;
       }
      return 0;
    }
	
	Adjacency matrix provides constant time access (O(1) ) to determine if there is an edge between two nodes. Space complexity of the adjacency matrix is O(V^2).
	
2)Adjacency list
for sparse matrix this is better,space is O(v+E) , to determine edge O(|v|)
**
Concept : array of vectors
vector is dynamic , array static
we use clockwise rule while reading , start from variable and start going clockwise
so vector<int>adj[V], means adj ->[] >vector<int> adj array of vector<int>s
advantage is , here row is fixed but column is not , so we can extend sizes because of advantage of vector


// A simple representation of graph using STL 
#include<bits/stdc++.h> 
using namespace std; 
  
// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// A utility function to print the adjacency list 
// representation of graph 
void printGraph(vector<int> adj[], int V) 
{ 

    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n;
    cin>>n;
    int t=n;
    int x,y;
    vector<int> adj[n]; 
    while(n--){
    	cin>>x>>y;
    	addEdge(adj,x,y);
    }
    printGraph(adj, t); 
    return 0; 
} 


3) edge list representation:
The input itself is edge list


Degree of a graph:-
first calculate adjacency list

int degree(vector<int>adj[],int vertex){
	int degree=0;
	for(auto x:adj[vertex])degree++;
	return degree;
}

int maxdegree(vector<int>adj[],int V){
	int max=0;
	for(int v=0;v<V;v++){
		if(degree(vector<int>adj[],v)>maxi)
			maxi=degree(vector<int>adj[],v);
		return maxi;
	}
}
int avgdegree(vector<int>adj[],int edges,int vertices){
	return 2*edges/vertices;
}

int selfloops(vector<int> adj[], int V) 
{  
    int count=0;

    for (int v = 0; v < V; ++v) 
    { 
        for (auto x : adj[v]) 
          if(x==v)count++;
      
    } 
	return count/2; (each edge counted twice)
} 
  