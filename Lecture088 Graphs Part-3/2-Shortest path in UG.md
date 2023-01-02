# Shortest path in Undirected Graph having unit distance

## Article Link: https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/

## Using BFS

### Time Complexity: O(N+2M)

### Space Complexity: O(N+M) ... N = no of nodes, M = no of edges

```cpp
class Solution {
  private:
    void bfs(vector<int> adjList[],vector<bool>&visi,vector<int>&dist,int node){
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            auto front = q.front();//getting the front node
            q.pop();
            for(auto it:adjList[front]){
                int distanceFromParentToNode = dist[front]+1;//getting the distance from the parent
                if(distanceFromParentToNode < dist[it]){
                    dist[it] = distanceFromParentToNode;//updating the distance
                    q.push(it);//pushing the child
                }
            }
        }
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adjList[N];
        // Step 2: For each edge (src, des, wt) in edges, do:
        for(int i=0;i<M;i++){
            int src = edges[i][0];
            int des = edges[i][1];

            // Step 2a: Add the edge (des, wt) to adjList[src]
            adjList[src].push_back(des);
            adjList[des].push_back(src);
        }
        
        vector<bool> visi(N,false);
        vector<int> dist(N,1e9);
        dist[src] = 0;
        bfs(adjList,visi,dist,src);
        
        //using a vector to store the answers
        vector<int> ans(N, -1);
        //looping through all the nodes
        for(int i = 0;i<N;i++) {
            //if the node is reachable
            if(dist[i] != 1e9) {
                //store the distance from the source to the node in the answer vector
                ans[i] = dist[i]; 
            }
        }
        
        return ans; 

    }
};
```
