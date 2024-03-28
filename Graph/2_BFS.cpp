//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends











// *****************love babbar*************************
// using adjlist
void prepareAdjList(unordered_map<int, set<int> > &adjList,
    vector<pair<int, int>> &edges) {
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;

            adjList[u].insert(v);
            adjList[v].insert(u);
        }
}

void bfs(unordered_map<int, set<int>> &adjList,
    unordered_map<int, bool> &visited, vector<int> &ans,
    int node){
        queue<int> q;
        q.push(node);
        visited[node] =1;
        while(!q.empty()){
            int frontNode= q.front();
            q.pop();

            //store frontNode into ans
            ans.push_back(frontNode);

            //traverse all neighbours of frontNode
            for(auto i: adjList[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }

        }
    }

vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components of graph
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

}