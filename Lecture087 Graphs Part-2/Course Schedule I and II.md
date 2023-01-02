# Course Schedule I and II | Pre-requisite Tasks | Topological Sort

## Article Link: https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

## Using Topological Sort

### Time Complexity: O(V+E)

### Space Complexity: O(V)


## Prerequisite Tasks
```cpp
class Solution
{
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
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> inComingEgde(V,0);
	    vector<int> topoSort;
	    for(int i=0;i<V;i++){
	        for(auto ne:adj[i]){
	            inComingEgde[ne]++;
	        }
	    }
	    
        bfs(adj,inComingEgde,0,topoSort);
        return topoSort;
	}
};
```
## Course Schedule
```cpp
class Solution
{
    private:
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
public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
         vector<int> adjList[V];
	    
	    for(auto it:prerequisites){
	        adjList[it[1]].push_back(it[0]);
	    }
	    
	    vector<int> inComingEgde(V,0);
	    vector<int> topoSort;
	    for(int i=0;i<V;i++){
	        for(auto ne:adjList[i]){
	            inComingEgde[ne]++;
	        }
	    }
	    
        bfs(adjList,inComingEgde,0,topoSort);
        
        if(topoSort.size()==V){
            return topoSort;
        }
        return {};
    }
};
```
