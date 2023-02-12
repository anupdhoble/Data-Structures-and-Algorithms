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
int main()
{
    struct queue q;
    q.size=400;
    q.front=q.rear=0;
    q.arr=(int*)malloc(sizeof(int)*q.size);

    int node;
    int i=2;//Starting node
    printf("Starting node: %d\n",i);
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("BFS traversal of graph: ");
    printf("%d",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q)){
        int node=dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1&&visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}