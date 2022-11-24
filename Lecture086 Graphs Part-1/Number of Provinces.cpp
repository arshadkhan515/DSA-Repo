// Number of Provinces 
// problem: https://practice.geeksforgeeks.org/problems/number-of-provinces/1
//article: https://takeuforward.org/data-structure/number-of-provinces/

/** Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 

Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.*/

class Solution {

  public:
    void dfs(vector<int> adj[], vector<bool>& visited, vector<int>& ans, int node) {
      // push current node to the answer
      ans.push_back(node);
      // mark current node as visited
      visited[node] = true;

      for (auto i : adj[node]) {
        if (!visited[i]) {
          // if node i is not visited, call dfs on it
          dfs(adj, visited, ans, i);
        }
      }
      return;
    }
    int numProvinces(vector<vector<int>> adjM, int V) {

    // Create a vector of vectors to represent an adjacency list
   vector<int> adj[V];
   // Loop through each row of the adjacency matrix
   for (int i = 0; i < V; i++) {
      // Loop through each column of the adjacency matrix
      for (int j = 0; j < adjM[i].size(); j++) {
         // If the element is 1 and the indices are not the same, add the index to the adjacency list
         if (adjM[i][j] == 1 && i != j) {
            adj[i].push_back(j);
            adj[j].push_back(i);
         }
      }
   }

      vector<int> ans; // vector to store the final answer
      vector<bool> visited(V, false); // vector to keep track of visited nodes
      int provinces = 0; // variable to store the number of provinces

      for (int i = 0; i < V; i++) { // iterate over all the nodes
        if (!visited[i]) { // if the node is not visited, run dfs
          provinces++; // increment the number of provinces
          dfs(adj, visited, ans, i); // run dfs on the node
        }
      }

      return provinces; // return the number of provinces
    }
};