Bipartite (2 colors)

1)Easy 
Dfs:
#include <bits/stdc++.h> 
using namespace std; 
  
// function to store the connected nodes 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// function to check whether a graph is bipartite or not 
bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for(auto u:adj[v]){
    if(!visited[u]){
    	visited[u]=true;color[u]=!color[v];
  		if(!isBipartite(adj,v,visited,color))return false;}
  	else
  		{
         if(color[u]==color[v])return false;
  		}
    }
    return true;
} 
  
// Driver Code 
int main() 
{ 
    // no of nodes 
    int N = 6; 
  
    // to maintain the adjacency list of graph 
    vector<int> adj[N + 1]; 
  
    // to keep a check on whether 
    // a node is discovered or not 
    vector<bool> visited(N + 1); 
  
    // to color the vertices 
    // of graph with 2 color 
    vector<int> color(N + 1); 
  
    // adding edges to the graph 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    addEdge(adj, 4, 5); 
    addEdge(adj, 5, 6); 
    addEdge(adj, 6, 1); 
  
    // marking the source node as visited 
    visited[1] = true; 
  
    // marking the source node with a color 
    color[1] = 0; 
  
    // Function to check if the graph 
    // is Bipartite or not 
    if (isBipartite(adj, 1, visited, color)) { 
        cout << "Graph is Bipartite"; 
    } 
    else { 
        cout << "Graph is not Bipartite"; 
    } 
  
    return 0; 
} 

2)Find cycle in graph
easy
#include <iostream>
#include <vector>
using namespace std;
vector<bool>visited(100,false);
	vector<int>color(100,0);
	vector<int>adj[100];
	vector<int>parent(100,-1);
	bool flag=false;
	int cycle_start,cycle_end;
void addedge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
bool dfs(vector<int>adj[],int v){
	color[v]=1;
	for(auto u:adj[v]){
		if(color[u]==0){
			parent[u]=v;
			if(dfs(adj,u))return true;
		}
		else if(color[u]==1 && u!=parent[v]){
			
			cycle_end=v;
			cycle_end=u;
			return true;
		}
	}
	color[v]=2;
	return false;
}
int main() {
	// your code goes here

	int n;
	cin>>n;
	
	
	int x,y;
	while(n--){
		cin>>x>>y;
		addedge(x,y);
	}
    
    if(dfs(adj,1))cout<<"cycle exists";
    else cout<<"no cycle";
	return 0;
}

Seven bridges of konigsberg-eulerian graph
soln: check degree of every vertex, if all have even degree then connected graph is eulerian( use edge once)
if 2 have odd degree then semi eulerian,check connectivity
3)Find cycle that uses every edge exactly once(eulerian tour)
medium easy
eulerian cyle-connected component,all even degree
eulerian path-connected component, all except 2 even degree ,

to check connected component , find adjacent list with degreee non zero , traverse using that point,initially set visited array false , when traversing ,set visited [point] true , then traverse adjacency list of that poitn and send that list in recursion of dfs.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, E;
vector<int>adj[100];

void addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}

void DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

bool isConnected()
{
    // Mark all the vertices as not visited
    bool visited[N];
    int i;
    for(i = 0; i < N; i++)
        visited[i] = false;

    // Find a vertex with non-zero degree
    for(i = 0; i<N; i++)
        if(adj[i].size()!=0)
            break;
    // If there are no edges in the graph, return true
    if(i == N)
        return true;

    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);

    // Check if all non-zero degree vertices are visited
    for(i = 0; i < N; i++)
        if(visited[i] == false && adj[i].size() > 0)
            return false;
    return true;
}

   // The function returns one of the following values
   // 0 --> If graph is not Eulerian
   // 1 --> If graph has an Euler path (Semi-Eulerian)
   // 2 --> If graph has an Euler Circuit (Eulerian) 
int isEulerian()
{
    // Check is all non-zero degree vertices are connected
    if(isConnected() == false)
        return 0;
    // Count vertices with odd degree
    int odd = 0;
    for(int i = 0; i < N; i++)
        if(adj[i].size() & 1)
        odd++;
    // If count is more than 2, then graph is not Eulerian
    if(odd > 2)
        return 0;
    // If odd count is 2, then semi-eulerian
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)? 1 : 2;
}


int main()
{
    int u, v;
    cin>>N>>E;
    int res = isEulerian();

    for(int i = 0; i < E; i++){
        cin>>u>>v;
        addEdge(u, v);
    }

    if(res == 0)
        cout << "Graph is not Eulerian" << endl;
    if(res == 1)
        cout << "Graph has an Euler path" << endl;
    else
        cout << "Graph has an Euler Cycle" << endl;
}
4)Find cycle that uses every vertex exactly once(tsp problem,hamiltonian problem , np complete)
super hard

5)are two graphs identical except for vertex names-graph isomorphism
no one knows , how to even classify

6)lay out a graph without crossing edges- linear time dfs (tarjan:complex)

Diameter of a tree: pick vertex do dfs, then run dfs from vertex farthest from soln

center of tree: consider vertices on longest path(ie diamter path , mid vertex is center)