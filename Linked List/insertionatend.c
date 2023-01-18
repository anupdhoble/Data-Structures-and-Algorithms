#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node*ptr)
{
    while(ptr!= NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
        
    }
}
struct node * insertion(struct node *head,int data){
        struct node *ptr =(struct node*) malloc(sizeof(struct node));
        ptr->next=head;
        ptr->data= data;
        
        return ptr;
    }
struct node * insertatbetween(struct node *head,int data,int index){

    struct node * ptr =(struct node* )malloc(sizeof(struct node));
    struct node *p = head;
    int i=0;
    while (i!=index - 1){
        p=p->next;
        i++;
        
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return head;

}
struct node * insertatend(struct node *head,int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    
        ptr->next=NULL;
        ptr->data=data;
        p->next=ptr;
        
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
   
    
    linkedlisttraversal(head);

    printf("After Insertion: \n");
    
    head=insertatend(head,66);
    linkedlisttraversal(head); 
    
    return 0;
}