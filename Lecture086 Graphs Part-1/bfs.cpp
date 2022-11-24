// bfs -- breadth first search
// Article -- https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/

//** problem 1:
// Problem on codingNinja https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
#include <bits/stdc++.h> 
void preparList(vector<pair<int, int>> &edges,unordered_map<int,set<int>> &adjList){
    
    for(int i=0;i<edges.size();i++){
        int src = edges[i].first;
        int des = edges[i].second;
        
        adjList[src].insert(des); 
        adjList[des].insert(src);
    }
}
void bfs(unordered_map<int,set<int>> &adjList,vector<bool>&visited,vector<int>&ans,int node){
    
    queue<int> qu;
    qu.push(node);
    visited[node] = true;
    
    while(!qu.empty()){
        auto getNode = qu.front();
        qu.pop();
        
        
        ans.push_back(getNode);
        
        for(auto i:adjList[getNode]){
            if(!visited[i]){
                qu.push(i);
                visited[i] = true;
            }
        }
    }
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
//     vector<int> adjList[vertex];
//     unordered_map<int,bool> visited;
    vector<bool> visited(vertex,false);
    vector<int> ans;
    preparList(edges,adjList);
    
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    
    return ans;
}


//** problem 2:
// Problem on gfg -- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
     //** this is bfs function complexity is O(V+E) **//
    // time complexity O(V)+O(E) = O(V+E) 
    // space complexity = O(V)
    void bfs(vector<int> adj[],vector<bool> &visited,vector<int>& ans,int node){
        
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty()){
            auto getNode = q.front();
            q.pop();
            
            ans.push_back(getNode);
            
            for(auto i:adj[getNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(adj,visited,ans,i);
            }
        }
        
        
        return ans;
    }
};








