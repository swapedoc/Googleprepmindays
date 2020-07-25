strongly connnected->if there is directed path from v to w and w to v
its an equivalence relation
note that when we talk of strong components we talk usually of Direct acyclic 
graph, so that means v and w cant be in same strong component otherwise v-w and w-v path will exist

Connected components= when v-w are connected

constructor processers graph in linear time assigns unique id to each strongly connected component.
then we check if scc[v]==scc[w], same like in undirected graph

tarjan ->linear algortithm , very hard
kosaraju-sharir- >easy to implement



Kosaraju :
Reverse graph:-strong components in G are same as in G reverse
Kernel DAG:connect each strong component into single vertex

Idea:compute topological order in kernel dag
run dfs, considering vertices in reverse topo order

1)Run dfs reverse postorder in G reverse
2)use reverse order to do dfs ,mark them with a number for each component if they are not marked so scc will be the value

In kosaraju first phase is crucial -> never use bfs to code , for second phase bfs, dfs any will do

Shortest Directed cycle->run bfs from each vertex
,
hamilitonian path in dag- >in general it is hard problem , however in dag its easy
REachable vertex:->
1)DAG:-a vertex reachable from all otehr vertex, calculate outdegree
2)digraph:-compute scc and look at kernel dag(digraph in step two for each scc)
#include <bits/stdc++.h>
using namespace std;

vector<int>mylist,nodes;
int parent=0;
bool visited[100];
vector<int>sccarray[100];
int leader[100];
vector<int>adj[100],revadj[100];
void dfs_reverse(vector<int>revadj[],int v){
	visited[v]=true;
	for(auto u:revadj[v]){
		if(!visited[u])dfs_reverse(revadj,u);
	}
	mylist.push_back(v);
}
void dfs(vector<int>adj[],int v){
	visited[v]=true;
	leader[v]=parent;
	nodes.push_back(v);
	for(auto u:adj[v]){
		if(!visited[u])dfs(adj,u);
	}
}
bool scc(int u, int v){
	return leader[u]==leader[v];
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	int b=t;
	while(t--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		revadj[y].push_back(x);
	}
	cout<<"Original graph";
	for(int i=0;i<b;i++){
	for(auto u:adj[i]){
		cout<<u<<" ";               ///1->0  0->2-3 2->1 3->4 
	}}
	cout<<"Reverse graph";
	for(int i=0;i<b;i++){
	for(auto u:revadj[i]){         //0->1 2->0 1->2 3->0 4->3
		cout<<u<<" ";
	}}
	memset(visited,false,b*sizeof(bool));
	//visite reverse graph
	for(int i=0;i<b;i++){
		if(!visited[i])dfs_reverse(revadj,i);
	}

    memset(visited,false,b*sizeof(bool));
    //visit original in reverse postorder
    int totalscc=0;
    for(int i=b-1;i>=0;i--)
		if(!visited[mylist[i]]){nodes.clear();parent=mylist[i];dfs(adj,mylist[i]);sccarray[totalscc]=nodes;totalscc++;}
	cout<<"total strongly connected components are "<<totalscc<<endl;
	cout<<"strongly components are "<<endl;
	for(int i=0;i<totalscc;i++){
		for(int j=0;j<sccarray[i].size();j++){
			cout<<sccarray[i][j];
		}
		cout<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		scc(x,y)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}