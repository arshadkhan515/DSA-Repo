# Implementing Dijkstra Algorithm

<!-- add the article link here -->

[Article Link](https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/)

# Intuition

- why we need priority queue in dijkstra algorithm? because minimum priority queue will always return the node with minimum distance from source. So, we can use this property to find the shortest path from source to all other nodes.
- In case of normal queue, we have to traverse through all the nodes to find the node with minimum distance from source. But, in case of priority queue, we can always return the node with minimum distance from source in O(1) time. [Link Of Video](https://www.youtube.com/watch?v=3dINsjyfooY&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21)

# Approach

Using BFS, we can find the shortest path from a source node to all other nodes in a graph. But, what if we want to find the shortest path from a source node to a particular node? In that case, we can use Dijkstra’s algorithm.

this algorithm is similar to BFS, but instead of using a queue, we use a priority queue. The priority queue will always return the node with minimum distance from source. So, we can use this property to find the shortest path from source to all other nodes.

this algorithm not work for negative weight and negative cycle. for that we have to use bellman ford algorithm.

# Complexity

- Time complexity: O(E log(V)), Where E = Number of edges and V = Number of Nodes.

- Space complexity: O( |E| + |V| ), for the distance array and the priority queue.

# Code

```cpp
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // minP is priority queue which will store the pair of node and its distance from source
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minP;
        // dist is the vector which will store the distance of each node from source
        // and will be returned by dijkstra function
        vector<int> dist(V,1e9);
        dist[S] = 0;
        minP.push({0,S});

        while(!minP.empty()){
             // front is the pair of node and its distance from source
             auto front = minP.top();
             // node is the node from which we will find the adjacent node
             int node = front.second;
             // nodeWei is the weight of the node from which we will find the adjacent node
             int nodeWei = front.first;
             minP.pop();
             // loop through the adjacent nodes of the node
             for(auto it:adj[node]){
                 // adjNode is the adjacent node
                 int adjNode = it[0];
                 // edgeWei is the weight of the edge from node to adjNode
                 int edgeWei = it[1];

                 // if the distance of node + weight of the edge from node to adjNode is less than the distance of adjNode
                 // then update the distance of adjNode
                 if(dist[node]+edgeWei < dist[adjNode]){
                     dist[adjNode] = dist[node]+edgeWei;
                     minP.push({dist[node]+edgeWei,adjNode});
                 }
             }
        }
        return dist;
    }
};
```
