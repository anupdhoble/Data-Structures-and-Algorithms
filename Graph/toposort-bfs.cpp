#include<bits/stdc++.h>

using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }
    vector<int> ans;

    queue<int> q;

    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int i = 0; i < adj[node].size(); i++){
            if(indegree[adj[node][i]] != 0){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
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
