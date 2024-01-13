#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX


vector<int> bellmanFord(int V,vector<vector<int>>&edges,int S){


    vector<int>dist(V,INF);
    dist[S]=0;
    while(V--){
        for(auto edge: edges){
            if(dist[0]!= 1e8 && dist[edge[0]]+edge[2]<dist[edge[1]])
            dist[edge[1]]=dist[edge[0]]+edge[2];
        }
    }
    for(auto edge: edges){
        if(dist[0]!= 1e8 && dist[edge[0]]+edge[2]<dist[edge[1]]){
            return {-1};
        }
    }
    return dist;
}





int main()
{
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int source = 0; // Source vertex

    vector<int> result = bellmanFord(V, edges, source);

    // Print the result
    if (result[0] == -1) {
        cout << "Negative cycle detected. No shortest paths exist." << endl;
    } else {
        cout << "Shortest distances from source " << source << " are: ";
        for (int i = 0; i < V; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}