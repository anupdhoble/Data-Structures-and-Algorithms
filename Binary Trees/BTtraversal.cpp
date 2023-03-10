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

void printPreorder(struct node* root){
    if(root!=NULL){
        cout<<root->data;
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
void printPostorder(struct node* root){
    if(root!=NULL){
        printPostorder(root->left);
        printPostorder(root->right);
        cout<<root->data;
    }
}

void printInorder(struct node* root){
    if(root!=NULL){
        printInorder(root->left);
        cout<<root->data;
        printInorder(root->right);
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
    
    // cout<<"\nIterative Inorder: ";
    // inorder_iterative(p);
    // cout<<"\nPreorder Iterative: ";
    // preorder_iterative(p);
    cout<<"\nPost order recursion: ";
    printPostorder(p);
    cout<<"\nPre order recursion: ";
    printPreorder(p);
    cout<<"\nInorder recursion: ";
    printInorder(p);
    return 0;
}