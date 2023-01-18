#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node*ptr){
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
    head=insertion(head,68);
    printf("After Insertion: \n");
    linkedlisttraversal(head); 
    
    return 0;
}