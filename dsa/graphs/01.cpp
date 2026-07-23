#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; //number of nodes
  int m; //number of edges

  cout<<"Enter number of vertices: "<<endl;
  cin>>n;
  cout<<"Enter number of edges: "<<endl;
  cin>>m;

  unordered_map<int, list<int>> adjList;
  cout<< "Enter edges (u, v): "<<endl;

  for(int i = 0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  cout<<"Adj List: "<<endl;
  for(auto i : adjList){
    cout<< i.first << "->";
    for(auto j : i.second){
      cout << j << " ";
    }
    cout << endl;
  }
}