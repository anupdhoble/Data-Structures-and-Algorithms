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
vector<vector<int>> countTriplet(struct node*head,int x){
    struct node* ptr1,*ptr2,*ptr;
    vector<vector<int>>v;
    int a,b,c;
    unordered_map<int,struct node*>s;
    
    for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next){
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next){
            if(s.find(x-ptr1->data-ptr2->data)!=s.end()&&s[x-ptr1->data-ptr2->data]!=ptr1&&s[x-ptr1->data-ptr2->data]!=ptr2){
                a=ptr1->data;b=ptr2->data;c=x - ptr1->data - ptr2->data;
                v.push_back({a,b,c});
            }
            s[ptr1->data]=ptr1;
            s[ptr2->data]=ptr2;
        }
    }
    return v;
}
int main(){
    struct node *head = new struct node;
    struct node *second = new struct node;
    struct node *third = new struct node;
    struct node *fourth = new struct node;
    struct node *fifth = new struct node;
    struct node *sixth = new struct node;
    struct node *seventh = new struct node;

    head->data = 9;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 5;
    fourth->next = fifth;
    fifth->data = 4;
    fifth->next = sixth;
    sixth->data = 4;
    sixth->next = seventh;
    seventh->data = 1;
    seventh->next = NULL;
   
   int x=17;
    
    linkedlisttraversal(head);
    vector<vector<int>>v=countTriplet(head,17);
    cout<<"vector: ";
    for(int i=0;i<v.size();i++){
        for(int j=0;j<3;j++){
            cout<<" "<<v[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
//output:-
// //Element: 9
// Element: 8
// Element: 6
// Element: 5
// Element: 4
// Element: 4
// Element: 1
// Element: 6
// Element: 5
// Element: 4
// Element: 4
// Element: 1
// vector:  9 4 4
//  8 5 4
//  8 4 5
//   8 4 5
//    5 4 8
//     5 4 8
//      4 4 9