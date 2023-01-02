
# is Bipartite

## Article Link: https://takeuforward.org/graph/bipartite-graph-bfs-implementation/

## Using BFS

### Time Complexity: O(V+2E)

### Space Complexity: O(V)

```cpp
class Solution {
public:
    bool bfs(vector<int>adj[],vector<int>& colors,int node){
        queue<int> q; //create a queue
        q.push(node); //push the node into the queue
        colors[node] = 0; //color the node with 0
        //color the first node with 0
        
        while(!q.empty()){ //while the queue is not empty
            auto front = q.front(); //get the front of the queue
            q.pop(); //pop the front of the queue
            //get the front of the queue and pop it
            
            for(auto neb:adj[front]){ //for each node in the adjacency list of front
                if(colors[neb] == -1){ //if the color of the node is not colored
                    colors[neb] = !colors[front]; //color the node with the opposite color of front
                    q.push(neb); //push the node into the queue
                }else if(colors[neb] == colors[front]){ //if the node is colored and the color is the same as front
                    return false; //return false
                }
                //if the node is colored with the same color as front, return false
            }
        }
        return true; //return true
    }
	bool isBipartite(int V, vector<int>adj[]){
     // color array to store the color assigned to all the vertices. 
     // Vertex number is used as index in this array. The value '-1' 
     // of  colorArr[i] is used to indicate that no color is assigned 
     // to vertex 'i'. The value 1 is used to indicate first color 
     // is assigned and value 0 indicates second color is assigned. 
     vector<int> colors(V,-1);
      // This code is to handle disconnected graoh 
      for(int i=0;i<V;i++){
        // if the vertex is not assigned any color 
        if (colors[i] == -1) {
            // if the graph is not bipartite, then return false 
            if(bfs(adj,colors,i)==false){
                return false;
            }
        }
      }
      // if the graph is bipartite, then return true 
      return true;
	}

};
```
