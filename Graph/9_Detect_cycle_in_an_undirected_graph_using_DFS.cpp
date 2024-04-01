#include<bits/stdc++.h>
 class Solution {
     bool dfs(int node, int parent,int vis[], vector<int> adj[]) {
      vis[node] = 1; 
      //visit adjacent nodes
      for(auto adjacentNode: adj[node]){
        
        if(dfs(adjacentNode, node, vis, adj) == true)
            return true;
      }
      //visited node but not a parent node
      else if(adjacentNode != parent) return true;
      
      return false; 
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(dfs(i, -1, vis, adj)) return true; 
            }
        }
        return false; 
    }
};