#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *createnode(int ele)
{
    struct node *neww = (struct node *)malloc(sizeof(struct node));
    neww->data = ele;
    neww->next = NULL;
    return neww;
}
int lengthll()
{
    int len = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void insert_beg(int ele)
{
    struct node *neww = createnode(ele);
    if (head == NULL)
    {
        head = neww;
        return;
    }
    neww->next = head;
    head = neww;
}
void createll()
{
    int n, data;
    printf("\nEnter no of elements: ");
    scanf("%d", &n);
    while (n--)
    {
        int d;
        printf("Enter data: ");
        scanf("%d", &data);
        insert_beg(data);
    }
}

void insert_end(int ele)
{
    struct node *temp = head;
    struct node *neww = createnode(ele);
    if (head == NULL)
    {
        head = neww;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = neww;
}
void display()
{
    struct node *temp = head;
    printf("\nLinked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void insert_pos(int pos, int ele)
{
    struct node *temp = head;
    int len = lengthll();
    int ndx = 0;
    struct node *neww = createnode(ele);
    if (pos > len)
        insert_end(ele);
    else if (pos == 1)
    {
        neww->next = head;
        head = neww;
    }
    else
    {

        while (ndx < pos - 2)
        {
            ndx++;
            temp = temp->next;
        }
        neww->next = temp->next;
        temp->next = neww;
    }
}
int delete_beg(){
    int a;
    if(head->next==NULL){
        a=head->data;
        free(head);
        head=NULL;
    }
    else{
        struct node* temp=head->next;
        a=head->data;
        free(head);
        head=temp;
    }
    return a;
}
int delete_end(){
    int a;
    if(head==NULL) {printf("\nLinked list empty : Operation aborted wrong answer generated"); return -999;}
    else if(head->next==NULL){
        a=head->data;
        free(head);
        return a;
    }
    else{
        struct node* temp=head;
        while(temp->next->next!= NULL){
            temp=temp->next;
        }
            a=temp->next->data;
            free(temp->next);
            temp->next=NULL;
            return a;
    }
}
int delete_pos(int pos){
    int l=lengthll();
    if(pos<1||pos>l){
        printf("\nOperation Aborted: Enter pos range that is available (1 - %d)",l);
        return -999;
    }
    else if(pos==1){
        return delete_beg();
    }
    else if(pos==l){
        return delete_end();
    }
    else{
        int k=pos-2;
        struct node * temp= head;
        while(k--){
            temp=temp->next;
        }
        int a=temp->next->data;
        struct node*temp1=temp->next;
        temp->next=temp->next->next;
        free(temp1);
        return a;
    }
    
}
int main()
{

    int c, e, pos,a;
    struct node *n = NULL;
    while (1)
    {
        printf("\nMenu:-\n1. Create ll\n2. Insert at beginning\n3. Insert at end  \n4. Insert at position\n5. Delete from beginning\n6. Delete from end\n7. Delete from a position\n8. Calculate length \n9. Display\n10. Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            createll();
            display();
            break;
        case 2:
            printf("Enter element to insert at beginning: ");
            scanf("%d", &e);
            insert_beg(e);
            display();
            break;
        case 3:
            printf("Enter element to insert at end: ");
            scanf("%d", &e);
            insert_end(e);
            display();
            break;
        case 4:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &e);
            printf("\nEnter postion at which to be inserted: ");
            scanf("%d", &pos);
            insert_pos(pos, e);
            display();
            break;
        case 5:
            a = delete_beg();
            printf("\nDeleted node data: %d",a);
            display();
            break;
        case 6:
            a=delete_end();
            printf("\nDeleted node data: %d",a);
            display();
            break;
        case 7:
            printf("\nEnter position number: ");
            scanf("%d",&pos);
            a=delete_pos(pos);
            printf("\nDeleted number: %d",a);
            display();
            break;
        case 8:
            printf("\nLength of Linked list is: %d",lengthll());
            break;
        case 9:
            display();
            break;
        case 10:
            printf("\nMission Abort ...Exiting........");
            exit(0);
        default:
            printf("\nInvalid entry:");
        }
    }
    return 0;
}