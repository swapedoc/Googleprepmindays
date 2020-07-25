bfs computes shortest path in time proportional to O(E+v) better than dfs
it traverses minimum edges.
usually bfs requires a source vertex and it is not advisable to use recursion on bfs
vector<int>adj[n];
int n,s;
//s is source vertex

queue<int>q;
bool visited[n];
vector<int>d(n),p(n);


void bfs(int s,int n){
queue<int>q;
q.push(s);
visited[s]=true;
p[s]=-1;
visited[s]=true;
while(!q.empty()){
int v=q.front();
q.pop()
for(int u:adj[v]){
if(!visited[u]){
visited[u]=true;
q.push(u);
d[u]=d[v]+1; //path length
p[u]=v;    //parent
}
}


//if we want to restore path
if(!used[u]){
cout<<"no path";}
else
{
vector<int>path;
for(int v=u;v!=-1;v=p[v])
path.push_back(v);
reverse(path.begin(),path.end())

print (path);
}

}



}




void initialize(){
for(int i=0;i<10;i++)
visited[i]=false;
}
 int main(){
 int nodes,edges,x,y,connectedcomponents=0;
 cin>>nodes;
 cin>>edges;
 for(int i=0;i<edges;i++)
 cin>>x>>y;
 adj[x].push_back(y);
 adj[y].push_back(x);
 
}
bfs(0,nodes);
 initialize();
 
 connectedcomponents++;
 }
 }
 cout<<"total connected component"<<connectedcomponents<<endl;}
 