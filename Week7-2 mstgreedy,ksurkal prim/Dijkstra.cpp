//Dijkstra -greedy approach , for n vertices in complete graaph complexity n^2 , otherwise eloge(V) ,
//it can be used only for positive edges
//algorithm basically is used to find shortest path from single source to all points,it asks to relax reachable
//edges as relaxed and rest of the edges not reachable infinity, we keep on relaxin and selecting min edge based on greedy approach, if a particular vertex is not reachable it will remain infinity
//dijkstra is very similar to prims , only that it is used for directed graph , however in undirected edge u-vwe can use trick u-> v && u<-v ie adding edges in both directions thus making it ideal for dijkstra
//reason why edges can be negativeis that they are weights//other values and not distances so weights can be anything

#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int>cost[100];
#define max 2000
const int infinity=1000000000;
struct data{
	int city,distance;
	bool operator <(const data &d)const{
		return distance>d.distance;
	}
};
int Dijkstra(vector<int>adj[],int source,int destination){
	int d[max];
	for(int i=0;i<max;i++)d[i]=infinity;
	data u,v;
	priority_queue<data>pq;
	u.city=source,u.distance=0;
	pq.push(u);
	d[source]=0;
	while(!pq.empty()){
		u=pq.top();
		pq.pop();
		int ucost=d[u.city];
		for(int i=0;i<adj[u.city].size();i++ ){
		v.city=adj[u.city][i],v.distance=cost[u.city][i]+ucost;
		if(d[v.city]>v.distance){
		d[v.city]=v.distance;
		pq.push(v);}
		}
	}
	return d[destination];
}
			

int main() {
	// your code goes here
	int n,e,wt,src,dest;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y>>wt;
		adj[x].push_back(y);  //for unidirectional
		cost[x].push_back(wt);
	}
	cin>>src>>dest;
	int ans=Dijkstra(adj,src,dest);
	cout<<ans<<endl;
	return 0;
}


6 8
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
5 4 2
5 6 5
4 6 1
1 4