topo sort
proof
cycle in directed graph-circular refernce
code:-

Graph should not contain cycle and should be directed. 
Topo sort: sorting in such a way that for u->v , u comes before v;
Every dag will have atleast 1 topological sorting
we use kahn algorithm
first find element with indegree 0 , do bfs onthis and keep decreasing indegree of elements beside this element,once this element indegree becomes 0 , push it also into q, also maintain result array accordingly
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10];
void toposort(int n){
	vector<int>indegree(n,0);
	for(int k=0;k<n;k++){
	for(auto u:adj[k])
		indegree[u]++;}
	int cnt=0;
	queue<int>q;
	for(int i=0;i<n;i++){
	if(indegree[i]==0)q.push(i);}
	vector<int>top_order;
	while(!q.empty()){                     
		int u=q.front();
		q.pop();
		top_order.push_back(u);
		for(auto p:adj[u]){
			if(--indegree[p]==0)
			q.push(p);
		}
		cnt++;
	}
	if(cnt!=n){cout<<"Cycle in graph";return;}
	for(int i=0;i<top_order.size();i++)
	cout<<top_order[i]<<" ";
	cout<<endl;
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
	}
	toposort(b);
	return 0;
}
time complexity: based on adjacency list , or matrices so here O(v+E)