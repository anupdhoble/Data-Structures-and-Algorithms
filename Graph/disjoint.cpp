#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    vector<int>rank,parent,Size;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        Size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int find_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void unionByRank(int u,int v){ //unions set containing u and v
        int ultimateParent_u = find_parent(u);
        int ultimateParent_v = find_parent(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(rank[ultimateParent_u]<rank[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
        }
        else if(rank[ultimateParent_v]<rank[ultimateParent_u]){
            parent[ultimateParent_v] = ultimateParent_u;
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
    void unionBySize(int u,int v){ //unions set containing u and v
        int ultimateParent_u = find_parent(u);
        int ultimateParent_v = find_parent(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(Size[ultimateParent_u]<Size[ultimateParent_v]){
            parent[ultimateParent_u] = ultimateParent_v;
            Size[ultimateParent_v]+=Size[ultimateParent_u];
        }
        else if(Size[ultimateParent_v]<Size[ultimateParent_u]){
            parent[ultimateParent_v] = ultimateParent_u;
            Size[ultimateParent_u]+=Size[ultimateParent_v];
        }
        else{
            parent[ultimateParent_v] = ultimateParent_u;
            Size[ultimateParent_u]+=Size[ultimateParent_v];
        }
    }
};