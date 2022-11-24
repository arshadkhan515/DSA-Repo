#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  unordered_map<int, vector<int>> m;

  void insert(int src, int des, int graphType)
  {
    m[src].push_back(des);

    if (!graphType)
    {
      m[des].push_back(src);
    }
  }

  void print()
  {
    for (auto i : m)
    {
      auto list = i.second;
      cout << i.first << " - ";
      for (auto j : list)
      {
        cout << j << "->";
      }
      cout << endl;
    }
  }
};

void printList(vector<vector<int>> graph)
{
  for (int i = 0; i < graph.size(); i++)
  {
    auto list = graph[i];
    cout << i << " - ";
    for (auto j : list)
    {
      cout << j << "->";
    }
    cout << endl;
  }
}

int main()
{

  int nodes;
  cout << "Enter Total Nodes(vertices)" << endl;
  cin >> nodes;

  int edges;
  cout << "Enter Total Edges" << endl;
  cin >> edges;

  //***************************** Adjacent Matrix
  // vector<vector<bool>> graph(nodes, vector<bool>(nodes, 0));
  // for (int i = 0; i < edges; i++)
  // {
  //   int src, des;
  //   cout << "Enter Source and Destination" << endl;
  //   cin >> src >> des;

  //   graph[src][des] = 1;
  //   graph[des][src] = 1;
  // }

  //***************************** Adjacent List
  // vector<vector<int>> graph(nodes);
  // for (int i = 0; i < edges; i++)
  // {
  //   int src, des;
  //   // cout << "Enter Source and Destination" << endl;
  //   cin >> src >> des;

  //   graph[src].push_back(des);
  //   graph[des].push_back(src);
  // }
  // printList(graph);

  //***************************** Adjacent List Using Map
  Graph g;
  for (int i = 0; i < edges; i++)
  {
    int src, des;
    cin >> src >> des;
    g.insert(src, des, 0);
  }
  g.print();

  return 0;
}