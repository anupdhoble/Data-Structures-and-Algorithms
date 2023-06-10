#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};
int isEmpty(struct queue *q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}
int isFull(struct queue *q){
    if(q->rear==q->size-1){
        return 1; 
    }
    return 0;
}
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("This queue is full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}
int dequeue(struct queue*q){
    int a=-1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->front++;
        a=q->arr[q->front];
    }
    return a;
}
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

int main(){
    int i=2;
    struct queue q;
    q.size=400;
    q.front=q.rear=0;
    q.arr=(int*)malloc(sizeof(int)*q.size);
    printf("Bfs: ");
    visited[i]=1;0
    enqueue(&q,i);
    while(!isEmpty(&q)){
        int node=dequeue(&q);
        
        printf("%d ",node);
        for(int j=0;j<7;j++){
            if(A[node][j]==1&&!visited[j]){
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
}