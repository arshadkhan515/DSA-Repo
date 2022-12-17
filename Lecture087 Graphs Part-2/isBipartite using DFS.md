# is Bipartite

## Article Link: https://takeuforward.org/graph/bipartite-graph-dfs-implementation/

## Using BFS

### Time Complexity: O(V+2E)

### Space Complexity: O(V)

```cpp
class Solution {
public:
    // This function is used to check for bipartiteness of a graph
    bool dfs(vector<int>adj[],vector<int>& colors,int node,int parentColor){

        colors[node] = parentColor; // color the current node as the parent color

            for(auto neb:adj[node]){
                if(colors[neb] == -1){ // if the color of the neighbour is not assigned
                    bool ans = dfs(adj,colors,neb,!colors[node]); // assign the opposite color to the neighbour
                    if(ans == false)
                     return false;
                }else if(colors[neb] == colors[node]){ // if the color of the neighbour is same as the current node
                    return false;
                }

            }
         return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
     vector<int> colors(V,-1); //colors array is used to store the colors of the vertices. Initially all vertices are uncolored, so we fill the colors array with -1s.
      for(int i=0;i<V;i++){
        if (colors[i] == -1) { //if a vertex is uncolored, then we call the dfs function to color it.
            if(dfs(adj,colors,i,0)==false){ //if the dfs function returns false, then the graph is not bipartite.
                return false;
            }
        }
      }
      return true;
	}

};
```
