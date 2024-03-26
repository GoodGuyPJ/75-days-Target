//two methord
// 1 adjacency Matrix
// #include<bits/stdc++.h>
// using namespace std;
 
 
// int main(){
//     // 1 adjacency Matrix
//     int n, m;
//     cin>>n>>m;
//     int adj[n+1][m+1];
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(adj[i][j] == 1){
//             cout<<adj[i][j]<<" ";
//             }
//             else{
//                 cout<<0<<" ";
//             }
//         }
//         cout<<endl;
//     }

//     //adjacency list
//     vector<int> adj[n+1];
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         // if there is edge / is directed graph
//         // only use adj[u].push_back(v);  tc- o(E)
//     }
 
//   return 0;
// }



/************************************************************/
#include<bits/stdc++.h>
using namespace std;
 template <typename T>
 class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        //direction = 0 -> undirected
        //direction = 1 -> directed graph

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<< "-> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
 };
 
int main(){
    int n;
    cout<<"Ener the number of nodes "<<endl;
    cin>>n;
    
    int m;
    cout<<"Ener the number of edges "<<endl;
    cin>>m;

    graph g;
    for(int i=0; i<m; i++){
        int u, v;
        cin>> u>> v;
        //creating an undirected graph
        g.addEdge(u, v, 0);
    }

    //printing graph
    g.printAdjList();
 
  return 0;
}




vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int> > adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);
        //entering neighbours
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return  adj;
}