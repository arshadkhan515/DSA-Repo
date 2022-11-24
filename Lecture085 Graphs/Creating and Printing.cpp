// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
vector < vector < int >> printAdjacency(int nodes, int edges, vector < vector < int >> & edgesValue) {

    vector<int> ans[nodes];
    for (int i = 0; i < edges; i++)
    {
        int src = edgesValue[i][0]; 
        int des = edgesValue[i][1];

        ans[src].push_back(des);
        ans[des].push_back(src);
    }
    
    vector < vector < int >> graph(nodes);
    for(int i=0;i<nodes;i++){
        graph[i].push_back(i);
        
        for(int j=0;j<ans[i].size();j++){
            graph[i].push_back(ans[i][j]);
        }
    }
    return graph;
}