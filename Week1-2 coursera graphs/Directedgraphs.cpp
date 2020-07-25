For V vertices there are V^2 possible edges(when self loops) ,so 2^(v^2) digraph possible
some problems:
path:does path exist from source to target
shortest path from source to target in directed graph
topo sort: draw digraph so all edges point upwards
strong connectivity:for any vertices is there directed path from u to v and v to u
Transitive close :for v and w is there a path from v to w
page rank: importance of web page,more links to web page more imp it is

Adjaceny matrix:
cin >> x >> y;
            x--,y--;
            A[x][y] = true; 
			
			only this not a[y][x]
			
			

adjacency list:
cin>>nodes;
 cin>>edges;
 for(int i=0;i<edges;i++)
 cin>>x>>y;
 adj[x].push_back(y);
 not adjy.pushx
 
 Search
 code is same for dfs and bfs, only construction needs to be taken care
 
 uses:
 every program is diagraph,vertex:block of instruction
 edge:jump
 so dead code elimination
 infinite loop detection
 
 Reachability:-
 Mark sweep algorithm- >when object created marked bit set to off, we do dfs on all and if we can see set bit off we unset it , if some of bits are still unset that means they cant be reached 
 
 
 bfs dfs similar like in undirected
 
 
 Problem:
 
 Mulitple source shortest path:
 put sources in queu, then use bfs
 
 web crawler:
 root web page as source s,
 maintain queue of websites to expore
 basically bfs
 (not ideal to use dfs as they can have loop traps)
 