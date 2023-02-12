#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
struct node{
    struct node* left;
    struct node* right;
    int data;
};

struct node* createNode(int data){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
void print_current_level(struct node* root,int i){
    if(root==NULL) return;
    if(i==1) cout<<root->data<<" ";
    print_current_level(root->left,i-1);
    print_current_level(root->right,i-1);
}
void level_traversal(struct node* root){
    int h= height(root);
    for(int i=1;i<=h;i++){
        print_current_level(root,i);
    }

}

int main()
{
    cout<<"By Anup Dhoble..."<<'\a';
     
   struct node* p=createNode(7);
   struct node* p1=createNode(6);
   struct node* p3=createNode(0);
   struct node* p4=createNode(4);
   struct node* p2=createNode(1);

     // Finally The tree looks like this:
    //      7
    //     / \
    //    6   1
    //   / \
    //  0   4 
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    cout<<"Level order traversal: ";
    level_traversal(p);
    return 0;
}