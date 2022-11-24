// Dfs -- Depth First Search
// Article -- https://takeuforward.org/data-structure/depth-first-search-dfs/
//** time complexity --- of dfs in undirected graph is O(V)+O(2E) = O(V+E) where V is the number of vertices and E is the number of edges
//** time complexity ----- of dfs in directed graph is O(V)+O(E) = O(V+E) where V is the number of vertices and E is the number of edges
//** space complexity of dfs is O(V) where V is the number of vertices


class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],vector<bool>& visited,vector<int>& ans,int node){
        ans.push_back(node); //adding node to answer
        visited[node] = true; //marking as visited
        
        for(auto i:adj[node]){ //for each node of current node
            if(!visited[i]){ //if not visited
                dfs(adj,visited,ans,i); //call dfs on that node
            }
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans; //answer vector
        vector<bool> visited(V,false); //visited vector
        
        for(int i=0;i<V;i++){ //for each node
            if(!visited[i]){ //if not visited
                dfs(adj,visited,ans,i); //call dfs on that node
            }
        }
        
        return ans;
    }
};