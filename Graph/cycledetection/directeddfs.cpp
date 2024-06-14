#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include<bits/stdc++.h>

bool dfs(vector<int> &adj, int i, int parent, int V, vector<int> &visited, vector<int> &currvisited)
{

    visited[i] = true;
    currvisited[i] = true;
    for (auto it : adj[i])
    {
        if (it != parent)
        {
            if (currvisited[it])
            {
                return true;
            }
            if (!visited[it])
            {
                if (dfs(adj, it, i, V, visited, currvisited))
                {
                    
                    return true;
                }
            }
        }
    }
    return false;
}
bool isCycle(vector<int> &adj, int V)
{
    vector<bool> visited(false, V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, i, parent,V, visited,currvisited))
            {
            }
        }
    }
}

int main()
{
    int V = 4;

    vector<int> adj[V];
    return 0;
}