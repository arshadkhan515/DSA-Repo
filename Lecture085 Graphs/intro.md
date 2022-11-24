# what is a graph?
<!-- link of article -->
## link of article
- [takeuforword](https://takeuforward.org/graph/introduction-to-graph/)
<!-- point -->
- a graph is a collection of nodes(vertices) and edges(links)
- nodes are connected by edges
- edges can be directed or undirected
- edges can have weights or costs associated with them (e.g. distance)
<!-- important terms -->
## important terms
- **node**: a vertex in a graph
- **edge**: a link between two nodes
- **directed graph**: a graph where edges have a direction
- **undirected graph**: a graph where edges do not have a direction
- **adjacent**: two nodes are adjacent if they are connected by an edge
- **degree**: the number of edges connected to a node
- **path**: a sequence of nodes connected by edges
- **cycle**: a path that starts and ends at the same node
- **connected**: a graph is connected if there is a path between every pair of nodes
- **component**: a connected subgraph of a graph
<!-- image of graphs from gfg -->
## image of undirected graphs
![image of undirected graphs](https://media.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png)
## image of directed graphs
![image of directed graphs](https://media.geeksforgeeks.org/wp-content/uploads/20200521130949/UndirectedGraph3.jpg)

# graph representations
<!-- point -->
- there are many ways to represent a graph
- we will look at two ways: **adjacency matrix** and **adjacency list**
<!-- important terms -->
## important terms
- **adjacency matrix**: a 2D array where a 1 indicates an edge between two nodes and a 0 indicates no edge between two nodes (i.e. a 1 in the matrix indicates an edge)```c++ adjlist[0][1] = 1; // edge between node 0 and node 1```

![image of adjacency matrix](https://wat-images.s3.ap-south-1.amazonaws.com/images/ps/edges-to-adjacency-matrix.svg)
- **adjacency list**: a list of lists where each list represents a node and contains the nodes that are adjacent to it

![image of adjacency list](https://cdn.codespeedy.com/wp-content/uploads/2020/04/Background.png)

# time complexity and space complexity
<!-- point -->
- the time complexity of an adjacency matrix is O(1) for adding and removing edges and O(n) for adding and removing nodes
- the space complexity of an adjacency matrix is O(n^2) 
- the time complexity of an adjacency list is O(1) for adding and removing nodes and O(n) for adding and removing edges
- the space complexity of an adjacency list is O(2E) in undirected graphs and O(E) in directed graphs where E is the number of edges

# how to represent a weighted graph
<!-- point -->
- we can represent a weighted graph by adding weights to the edges in the adjacency matrix or adjacency list
- Small change in code ,instead of 1 or 0 we can add weight of edge between two nodes in adjacency matrix like this
- Adjacency matrix for weighted graph ```c++ adj[u][v] = w;``` instead of ```c++ adj[u][v] = 1;```  where u and v are nodes and w is weight of edge between u and v
- Adjacency list for weighted graph ```c++ adj[u].push_back({v,w});``` instead of ```c++ adj[u].push_back(v);``` where u and v are nodes and w is weight of edge between u and v





