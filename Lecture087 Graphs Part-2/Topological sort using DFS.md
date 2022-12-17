# Topological sort

## Article Link: https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/

## Using DFS

### Time Complexity: O(V+E)

### Space Complexity: O(V)

```cpp
class Solution
{
    void dfs(vector<int> adj[],vector<bool>&vis,stack<int>& sortEle,int node){
        vis[node] = true; // mark the node as visited
        for(auto neg:adj[node]){ // traverse all the neighbors of the node
            if(!vis[neg]) dfs(adj,vis,sortEle,neg); // if the neighbors is not visited then visit it
        }
        sortEle.push(node); // push the node in the stack
    }
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    vector<bool> vis(V,false); // visited array to keep track of vertices that are visited
        stack<int> sortEle; // stack to store the topological order
        for(int i=0;i<V;i++){
            if(!vis[i]){ // if vertex is not visited
                dfs(adj,vis,sortEle,i); // call dfs on that vertex
            }
        }

        vector<int> ans; // vector to store the topological order
        while(!sortEle.empty()){ // pop elements from stack and add them to vector
            ans.push_back(sortEle.top());
            sortEle.pop();
        }
        return ans;
	}
};
```
