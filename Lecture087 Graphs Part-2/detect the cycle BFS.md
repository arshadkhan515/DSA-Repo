# Detect the cycle in a undirected graph
## Article Link: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/
## Using BFS
### Time Complexity: O(V+2E) = O(V+E)
### Space Complexity: O(V)
```cpp
class Solution {
    private:
    bool bfs(vector<int> adj[],vector<bool>& vis,int src){
        // use a queue to store the nodes and the parent of each node
        queue<pair<int,int>> q;
        vis[src] = true;
        q.push({src,-1});
        
        while(!q.empty()){
            // get the front node and its parent
            auto front = q.front();
            auto node = front.first;
            auto parent = front.second;
            q.pop();
            // check all the neighbours of the node
            for(auto i:adj[node]){
                // if the neighbour is not visited, then mark it visited and push it to the queue
                if(!vis[i]){
                    q.push({i,node});
                    vis[i] = true;
                }else{
                    // if the neighbour is already visited and it is not the parent of the current node, then there is a cycle
                    if(i != parent) return true;
                }
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool> vis(V,false); // mark all the vertices as not visited.
        
        for(int i=0;i<V;i++){
            if(!vis[i]){ // if the vertex is not visited, call the bfs function to check if there is a cycle in the graph.
                if(bfs(adj,vis,i))
                 return true;
            }
        }
        return false;
    }
};
```
