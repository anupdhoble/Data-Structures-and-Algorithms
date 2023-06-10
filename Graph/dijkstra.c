#include<stdio.h>
#include<stdlib.h>
#define V 6

int minDistance(int dist[],int visited[]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void printSolution(int dist[]) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t %d\n", i, dist[i]);
    }
}
void dijkstra(int graph[V][V],int source){
    int dist[V];
    int visited[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[source]=0;
    int u;
    for(int i=0;i<V-1;i++){
        u=minDistance(dist,visited);
        visited[u]=1;
        for(int v=0;v<V;v++){
            if(!visited[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }

    }  
    
    printSolution(dist);
}

    int main(){
    int graph[V][V] = {
        {0, 2, 0, 1, 0, 0},
        {2, 0, 4, 4, 3, 0},
        {0, 4, 0, 2, 0, 0},
        {1, 4, 2, 0, 5, 3},
        {0, 3, 0, 5, 0, 1},
        {0, 0, 0, 3, 1, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
    