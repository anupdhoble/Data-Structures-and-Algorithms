#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node* head= NULL;
struct node *createnode(int ele){
    struct node *neww =(struct node *)malloc(sizeof(struct node));
    neww->data=ele;
    neww->next=NULL;
    return neww;
}

int main(){
    
    return 0;
}