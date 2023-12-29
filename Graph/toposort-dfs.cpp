#include<bits/stdc++.h>

using namespace std;

void performDfs(stack<int>&s,vector<int>adj[],int current,int visited[]){
    visited[current]=1;
    for(auto it:adj[current]){
        if(visited[it]==0){
            performDfs(s,adj,it,visited);
        }
    }
    s.push(current);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    stack<int>s;
    int visited[V]={0};
    vector<int>ans;
    

    for(int i=0;i<V;i++){
        if(visited[i]==0){
            performDfs(s,adj,i,visited);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();

    }
 
    return ans;
}

int main() {
    int V = 6;  // Number of vertices
    vector<int> adj[V];

    // Adding edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topoSort(V, adj);

    // Displaying the result
    cout << "Topological order: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
