# Shortest path in Directed Acyclic Graph

## Article Link: https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/

## Using Topological Sort

### Time Complexity: O(N+M)

### Space Complexity: O(N+M) ... N = no of nodes, M = no of edges

```cpp
class Solution {
  private:
   void topo(vector<pair<int,int>> adjList[],vector<bool>& visi,stack<int>& topoSort,int node){
       visi[node] = true;

       for(auto it:adjList[node]){
           if(!visi[it.first]){
               topo(adjList,visi,topoSort,it.first);
           }
       }

       topoSort.push(node);
   }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Step 1: Create an adjacency list
        vector<pair<int,int>> adjList[N];

        // Step 2: For each edge (src, des, wt) in edges, do:
        for(int i=0;i<M;i++){
            int src = edges[i][0];
            int des = edges[i][1];
            int wt = edges[i][2];

            // Step 2a: Add the edge (des, wt) to adjList[src]
            adjList[src].push_back({des,wt});

        }
        stack<int> topoSort; //create stack for topological sort
        vector<bool> visi(N,false); //create vector to keep track of visited nodes
        for(int i=0;i<N;i++){ //iterate through all nodes
            if(!visi[i]) //if a node has not been visited
              topo(adjList,visi,topoSort,i); //call topo function
        }

        vector<int> dist(N,1e9); // initialize every node with infinity distance from source
        dist[0] = 0; // except the source node, which is at distance 0 from itself

        while(!topoSort.empty()){
            auto top = topoSort.top();
            topoSort.pop();

            for(auto it:adjList[top]){ // for every node adjacent to the top node in the topological sort
                int node = it.first;
                int wt = it.second;

                if(dist[top]+wt < dist[node]){ // if the distance from the source to the top node + the weight of the edge to the adjacent node is less than the current distance to the adjacent node
                    dist[node] = dist[top]+wt; // relax the edge
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;

    }
};
```
