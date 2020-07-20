euler tour -> cycle that uses each edge exactly once
hamilton tour->cycle that uses each vertex exactly once
mst-best way to connect all vertices
connectivity->is there way to connect all vertices of graph
biconnectivity->>is there a vertex whose remove disconnect graph
planarity->draw graph without crossing edges
graph isomerism->do two adjacency lists represent same graph

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