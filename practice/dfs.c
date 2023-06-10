#include<stdio.h>
#include<stdlib.h>
int visited[7]={0,0,0,0,0,0,0};
int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
void dfs(int j){
    visited[j]=1;
    printf("%d ",j);
    for(int i=0;i<7;i++){
        if(A[j][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    printf("DFS: ");
    dfs(2);
    return 0;
}