# Detect cycle in a directed graph
## Article Link: https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
## Using DFS
### Time Complexity:  O(V+E)
### Space Complexity: O(V)
```cpp
class Solution {
  private:
    bool dfs(vector<int> adj[],vector<bool>&vis,vector<bool>&path,int node){
        vis[node] = true;  // Mark the current node as visited.
        path[node] = true; // Mark the current node in the recursion stack.
        
        for(auto neg:adj[node]){
            if(!vis[neg]){
                if(dfs(adj,vis,path,neg)){
                    return true;
                }
            }else if(path[neg]){ // If an adjacent node is visited and is also present in the recursion stack, then there is a cycle.
                return true;
            }
        }
        path[node] = false; // Remove the current node from the recursion stack.
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false); // mark all the vertices as not visited.
        vector<bool> path(V,false); 
        
        for(int i=0;i<V;i++){
            if(!vis[i]){ // if the vertex is not visited, then call the dfs function
                if(dfs(adj,vis,path,i)) // if dfs returns true, then there is a cycle
                 return true;
            }
        }
        return false;
    }
};
```
