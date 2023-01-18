#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void linkedtraversal(struct node*ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node * deleteNvalue(struct node *head,int data){
        struct node* p=head,*q=p->next;
        while(q->data!=data && q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        if(q->data==data){
        p->next=q->next;
            free(q);
        }
        return head;
    }
int main(){
    struct node *head =(struct node*) malloc(sizeof(struct node));
    struct node *second =(struct node*) malloc(sizeof(struct node));
    struct node *third =(struct node*) malloc(sizeof(struct node));
    struct node *fourth =(struct node*) malloc(sizeof(struct node));
    struct node *fifth =(struct node*) malloc(sizeof(struct node));
    struct node *sixth =(struct node*) malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 25;
    third->next = fourth;
    fourth->data = 63;
    fourth->next = fifth;
    fifth->data = 74;
    fifth->next = sixth;
    sixth->data = 61;
    sixth->next = NULL;

    linkedtraversal(head);
    head=deleteNvalue(head,63);
    printf("\nAfter Deletion:\n");
    linkedtraversal(head);

}