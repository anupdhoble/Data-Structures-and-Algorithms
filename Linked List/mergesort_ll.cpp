#include<bits/stdc++.h>
using namespace std;
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
struct node* findmid(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node* fast=head->next,*slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}
struct node * merge(struct node*a,struct node* b){
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    struct node * result;
    if(a->data<=b->data){
        result=a;
        a->next=merge(a->next,b);
    }
    else{
        result = b;
        b->next=merge(a,b->next);
    }
    return result;
}
struct node * mergesort(struct node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct node* mid=findmid(head);
    struct node* midnxt=mid->next;
    mid->next=NULL;
    struct node* left= mergesort(head);
    struct node *right=mergesort(midnxt);
    return merge(left,right);
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
    struct node* ans=mergesort(head);
    cout<<"Sorted Linkedlist: ";
    linkedlisttraversal(ans);
  
    return 0;
}