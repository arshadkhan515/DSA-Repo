# Bellman Ford Algorithm

# Intuition
why we relax all the edges V-1 times? because given edges are directed edges and random directed edges can form a cycle.so we need to relax all the edges V-1 times to make sure that we have covered all the possible paths.

# Approach
Relax all the edges V-1 times. If after V-1 times, we still get a shorter path, then there is a negative cycle.
That's why we first relax all the edges V-1 times and then check if there is a negative cycle.if there is a negative cycle, then we return {-1}.or else we return the distance array.


# Complexity
- Time complexity:
O(V*E) where V is the number of vertices and E is the number of edges.

- Space complexity:
O(V) for the distance array.

# Code
```c++
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8); //initially all distances are infinity
        dist[S] = 0; //source distance is 0
        for(int i=0;i<V-1;i++){ //for V-1 iterations
            for(auto it:edges){ //for each edge
                int src = it[0]; //source
                int dis = it[1]; //destination
                int weight = it[2]; //weight
                if(dist[src] != 1e9 && dist[src]+weight < dist[dis]){ //if distance of source is not infinity and if the distance of source plus weight is less than the distance of the destination node
                    dist[dis] = dist[src]+weight; //then, update the distance of the destination node
                }
            }
        }
        
        for(auto it:edges){ //for each edge
                int src = it[0]; //source
                int dis = it[1]; //destination
                int weight = it[2]; //weight
                if(dist[src] != 1e9 && dist[src]+weight < dist[dis]){ //if distance of source is not infinity and if the distance of source plus weight is less than the distance of the destination node
                    return {-1}; //then, it means that there is a negative weight cycle
                }
        }
        
        return dist; //return the distance vector
    }
};
```