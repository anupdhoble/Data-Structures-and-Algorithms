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
int isBST(struct node* root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL&&root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node* search(struct node* root,int key){
    if(root==NULL)
        return NULL;
    if(root->data>key)
        return search(root->left,key);
    else if(root->data==key)
            return root;
        else
            return search(root->right,key);
}
int main()
{
    cout<<"By Anup Dhoble..."<<'\a';
     
   struct node* p=createNode(6);
   struct node* p1=createNode(3);
   struct node* p3=createNode(1);
   struct node* p4=createNode(4);
   struct node* p2=createNode(8);

     // Finally The BST tree looks like this:
    //      6
    //     / \
    //    3   8
    //   / \
    //  1   4 
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    cout<<"\nInorder: ";
    printInorder(p);
    //If Inorder is in ascending order then BT is BST.
    if(isBST(p)){
        cout<<"\nIt is a Binary Search Tree..";
    }
    else{
        cout<<"\nIt is not a Binary Search Tree..";
    }
    int key;
    cout<<"\nEnter key to be searched: ";
    cin>>key;
    struct node* n=search(p,key);
    if(n!=NULL)
        cout<<"\n"<<n->data<<" is found at address :"<<n;
    else
        cout<<"\nElement not found..\n";

    return 0;
}