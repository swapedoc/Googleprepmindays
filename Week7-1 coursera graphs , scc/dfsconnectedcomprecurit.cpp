//Recursive and iterative dfs using adjacency list
    #include <bits/stdc++.h>
	using namespace std;
	vector<int>adj[10];
	bool visited[10];
	//recursive
	void dfs(int v){
	visited[v]=true;
	for(int i=0;i<adj[v].size();i++){
	if(!visited[adj[v][i]])
	dfs(adj[v][i]);
	}
	}

//iterative
    void dfs(int v){
	stack<int>st;
	st.push(v);
	while(!st.empty()){
	 v=st.top();
	 st.pop();
	 if(!visited[v]){
	 visited[v]=true;
	 }
	 for(auto i=adj[v].begin();i!=adj[v].end();i++){
	 if(!visited[*i])
	 st.push(*i);
	 }
	}
void initialize(){
for(int i=0;i<10;i++)
visited[i]=false;
}
 vector<int>adj[10];
 int main(){
 int nodes,edges,x,y,connectedcomponents=0;
 cin>>nodes;
 cin>>edges;
 for(int i=0;i<edges;i++)
 cin>>x>>y;
 adj[x].push_back(y);
 adj[y].push_back(x);
 
}
 initialize();
 for(int i=1;i<=nodes;i++){
 if(visited[i]==false){
 dfs(i);
 connectedcomponents++;
 }
 }
 cout<<"total connected component"<<connectedcomponents<<endl;