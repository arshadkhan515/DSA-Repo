// Detect a Cycle in an Undirected Graph using BFS
// Article Link: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/
// Time Complexity: O(V+2E) = O(V+E) 
// Space Complexity: O(V) 
class Solution {
    private:
    bool bfs(vector<int> adj[],vector<bool>& vis,int src){
        queue<pair<int,int>> q;
        vis[src] = true;
        q.push({src,-1});
        
        while(!q.empty()){
            auto front = q.front();
            auto node = front.first;
            auto parent = front.second;
            q.pop();
            for(auto i:adj[node]){
                if(!vis[i]){
                    q.push({i,node});
                    vis[i] = true;
                }else{
                    if(i != parent) return true;
                }
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(adj,vis,i))
                 return true;
            }
        }
        return false;
    }
};