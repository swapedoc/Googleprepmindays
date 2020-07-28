Kruskal
They can only be done for undirected graph

build pq complexity -E 
delete min Log E
union    log * v
connected Lov*V

total time ELog E
if edges are sorted Elog* V(almost linear) {log * V =5 in universe)

Kruskal
 put edges in priorty queue by weight(can use array with same complexity but this is elegent_
 count=0;
  while(count<n-1)do
  get next edge(v,w)
   if(component(v)!=component(w))(else it contains cylce)
	   add to Tkruskal
        merge v and w
		
here we are using basic algo without pq
#include <bits/stdc++.h>
using namespace std;
const int MAX=1e+5;
int id[MAX],nodes,edges;
pair<long long,pair<int,int>>p[MAX];
void initialise(){
	for(int i=0;i<MAX;i++)
	id[i]=i;
}
int root(int x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void union1(int x, int y){
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}
long long kruskal(pair<long long,pair<int,int>>p[]){
	int x,y;
	long long weight,minval=0;
	for(int i=0;i<edges;i++){
		x=p[i].second.first;
		y=p[i].second.second;
		weight=p[i].first;
		if(root(x)!=root(y)){
			minval+=weight;
			union1(x,y);
		}
	}
	return minval;
}
int main() {
	int x,y;
	long long wt,mincost;
	initialise();
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>x>>y>>wt;
        p[i]=make_pair(wt,make_pair(x,y));	
	}
	sort(p,p+edges);//dont need to write comparator as it sorts based on first element
	mincost=kruskal(p);
	cout<<mincost<<endl;
	// your code goes here
	return 0;
}

ElogE

minimum-weight feedback-edge set (MWFES).-do kruskal on max weights instead(maximum spanning tree, basically sort edges in decreasing order)

prims:
start with vertex 0 and greedily grow tree
att to T min weight edge with exactly one endpoint
repeat until v-1 edges
for lazy propagation(using priorty queue with edges): delete min e -> bin heap log e ,
                     insert  e -> log e    so Eloge
Extra space using E

forearly propagation(using priorty queue with vertices)

prims 
array 1 v 1 v^2(dense graph)
bin heap log v log v log v elog v-1


Prims algo (early propagation too hard to implement)
start from 1, explore adjacent (maintain wt array along with list ) , if not visited push in pq, top element pop it out use its value in mincost , mark it as visited , make it source 
#include <bits/stdc++.h>

using namespace std;
int marked[1000];
vector<int>adj[1000];
vector<int>wt[1000];
struct data{
	int v,w;
	bool operator <(data p)const{        //used to implement reverse priorty queu(min priorty)
		return w>p.w;
	}
};

long long prim(int src,int nodes)
{
    memset(marked,0,sizeof(marked));   
    priority_queue<data>pq;
    int u,v,temp=0;
    long long minimumCost = 0;
    
    for(int i=0;i<nodes-1;i++){
    	u=src;
    	marked[u]=1;
    	for(int j=0;j<adj[u].size();j++){      
    		v=adj[u][j];
    		if(marked[v]==0){
    			data obj;
    			obj.v=v;
    			obj.w=wt[u][j];
    			pq.push(obj);
    		}
    	}
    	while(marked[src]){
    		data T=pq.top();
    		pq.pop();
    		src=T.v;
    		temp=T.w;
    	}
    	minimumCost+=temp;
    }
    return minimumCost;
}
    

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(y);
        adj[y].push_back(x);
        wt[x].push_back(weight);
        wt[y].push_back(weight);
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1,nodes);
    cout << minimumCost << endl;
    return 0;
}