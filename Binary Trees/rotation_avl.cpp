#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};
int getheight(struct node * n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
struct node* createnode(int key){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
int getBalanceFactor(struct node* n){
    if(n==NULL){
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
   //       y                         x
    //     / \                      /  \ 
    //    x   T3    ---->>        T1   y
    //   / \                         /  \ 
    //  T1  T2                    T2    T3
struct node* rightrotate(struct node* y){
    struct node* x=y->left;
    struct node* T2=x->right;
    
    x->right=y;
    y->left=T2;
    
    y->height= max(getheight(y->right),getheight(y->left))+1;
    x->height= max(getheight(x->right),getheight(x->left))+1;
    return x;
}
struct node* leftrotate(struct node* x){
    struct node* y=x->right;
    struct node* T2=y->left;
    
    x->right=T2;
    y->left=x;
    
    y->height= max(getheight(y->right),getheight(y->left))+1;
    x->height= max(getheight(x->right),getheight(x->left))+1;
    return y;
}
struct node* insert(struct node*node,int key){
    if(node==NULL)
        return (createnode(key));
    if(key<node->key)
        node->left=insert(node->left,key);
    else if(key > node->key)
        node->right=insert(node->right,key);

    node->height=1+max(getheight(node->left),getheight(node->right));
    int bf=getBalanceFactor(node);

    //Left Left Case
        if(bf>1&&key<node->left->key){
           return rightrotate(node);
        }
    //Right Right Case
    if(bf<-1&&key>node->right->key){
          return leftrotate(node);
        }
    //Left Right Case
    if(bf>1&&key>node->left->key){
        node->left=leftrotate(node->left);
        return rightrotate(node);

    }
    //Right Left Case
    if(bf<-1&&key<node->right->key){
        node->right=rightrotate(node->right);
        return leftrotate(node);

    }
    return node;
}
void printPreorder(struct node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
int main(){
    struct node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    cout<<"Preorder after insertions:\n";
    printPreorder(root);
    return 0;
}