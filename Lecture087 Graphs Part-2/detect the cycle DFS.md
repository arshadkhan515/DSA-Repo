# Detect the cycle in a undirected graph
## Article Link: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/
## Using DFS
### Time Complexity: O(V+2E) = O(V+E)
### Space Complexity: O(V)
```cpp
class Solution {
  private:
 bool dfs(vector<int> adj[],vector<bool> vis,int node,int parent){
     //mark current node as visited
     vis[node] = true;
     
     bool ans = false;
     //iterate through all the neighbors of the node
     for(auto neighbor:adj[node]){
         //if the neighbor is not visited
         if(!vis[neighbor]){
             //mark the neighbor as visited
             vis[neighbor] = true;
             //call dfs for the neighbor
            ans = dfs(adj,vis,neighbor,node);
             //if the neighbor returns true, it means there is a cycle
             if(ans)
              return ans;
         }else if(neighbor != parent){
             //if the neighbor is visited and it is not the parent of the node, it means there is a cycle
             return  true;
         }
     }
     
      return ans;
 }
  public:
    // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[]) {
       vector<bool> vis(V,false); // mark all the vertices as not visited.
        
        for(int i=0;i<V;i++){
            if(!vis[i]){ // if the vertex is not visited, call the bfs function to check if there is a cycle in the graph.
                if(dfs(adj,vis,i,-1))
                 return true;
            }
        }
        return false;
    }
};
```
