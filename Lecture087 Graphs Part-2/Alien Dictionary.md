# Alien Dictionary

## Article Link: https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/

## Using Topological Sort

### Time Complexity: O(N*len)+O(K+E)

### Space Complexity: O(V)

```cpp
class Solution{
    public:
    void bfs(vector<int> adj[],vector<int>&inComingEgde,int node,vector<int>&topoSort){
       queue<int> q;
       // push all node with inComingEgde == 0 to queue
       for(int i=0;i<inComingEgde.size();i++){
           if(inComingEgde[i] == 0){
               q.push(i);
           } 
       }
       
       while(!q.empty()){
           // pop the front of queue
           auto front = q.front();
           q.pop();
           // add it to topo sort
           topoSort.push_back(front);
           // for each of its neighbour
           for(auto ne:adj[front]){
               // reduce their inComingEgde
               inComingEgde[ne]--;
               // if inComingEgde == 0 add to queue
               if(inComingEgde[ne] == 0){
                   q.push(ne);
               }
           }
           
       }
    }
    string findOrder(string dict[], int N, int K) {
      
      // making Directed Graph
       vector<int> graph[K];
       
       for(int i=0;i<N-1;i++){
           auto s1 = dict[i];
           auto s2 = dict[i+1];
           int len = min(s1.size(), s2.size());
           
           // Step 1: Find the first different character in the two strings
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					
					// Step 2: Add an edge in the graph
					graph[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					break;
				}
			}
       }
       // topSort algo staring here
        //Create a vector to store the number of incoming edges for each node
        vector<int> inComingEgde(K,0);
        //Create a vector to store the sorted nodes
	    vector<int> topoSort;
	    for(int i=0;i<K;i++){
	        for(auto ne:graph[i]){
	            inComingEgde[ne]++;
	        }
	    }
	    
        bfs(graph,inComingEgde,0,topoSort); //Find the order of the characters
        string ans;
        for(auto it:topoSort){
            ans += it+'a'; //Add the characters to the answer string
        }
        return ans;
    }
};
```
