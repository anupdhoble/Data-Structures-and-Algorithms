#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge between two vertices
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the adjacency list representation of the graph
void printGraph(vector<int> adj[], int V) {
    for (int i = 0; i < V; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
bool dfs(vector<int>adj[],int i,int parent,vector<bool>&visited){

    
    visited[i]=true;
    for(auto it:adj[i]){
        if(it != parent){
            if(visited[it]==true){
                return true;
            }
          if(dfs(adj,it,i,visited)){
            return true;
          }
        }
    }
    return false;

}
bool isCycle(vector<int>adj[],int V){
    
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(adj,i,-1,visited)){
                return true;
            }
        }
    }
    return false;
}
int main() {
    int V = 5; // Number of vertices

    // Create an array of vectors to represent the adjacency list
    vector<int> adj[V];

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);

    // Print the adjacency list representation of the graph
    printGraph(adj, V);

    if(isCycle(adj,V)){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }
    return 0;
}