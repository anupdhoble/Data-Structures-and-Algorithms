//Print all nodes at a distance k from target node

#include<bits/stdc++.h>
#include<windows.h>
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


unordered_map<struct node*,struct node*>m;
unordered_set<struct node *>visited;

void bind_parent(struct node* root){
    if(root==NULL){
        return;
    }
    if(root->left){
        m[root->left]=root;
        bind_parent(root->left);
    }
    if(root->right){
        m[root->right]=root;
        bind_parent(root->right);
    }

}

void print_from_target(struct node* root,queue q){

}

int main()
{
    cout<<"By Anup Dhoble..."<<'\a';
     
   struct node* p=createNode(7);
   struct node* p1=createNode(6);
   struct node* p3=createNode(0);
   struct node* p4=createNode(4);
   struct node* p2=createNode(1);
   struct node* p5=createNode(8);


    // Finally The tree looks like this:
    //      7
    //     / \
    //    6   1
    //   / \   \
    //  0   4   8
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;

    bind_parent(p);
    queue<struct node*>q;

    return 0;
}