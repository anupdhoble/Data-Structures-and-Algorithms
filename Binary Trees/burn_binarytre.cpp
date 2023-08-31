//Print all nodes at a distance k from target node

#include<bits/stdc++.h>
#include<queue>

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
unordered_map<struct node *,bool>visited;

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

void print_from_target(struct node* root,queue<struct node*> bfs){
    int n=0;
    bfs.push(root);
    visited[root]=true;
    
    while(!bfs.empty()){
        
        int size=bfs.size();
        n++;
        for(int i=0;i<size;i++){
            struct node* top=bfs.front();bfs.pop();
            if(m[top]&&!visited[m[top]]){
                visited[m[top]]=true;
                bfs.push(m[top]);
            }
            if(top->left&&!visited[top->left]){
                visited[top->left]=true;
                bfs.push(top->left);
            }
            if(top->right&&!visited[top->right]){
                visited[top->right]=true;
                bfs.push(top->right);
            }
       
          
        }
        
    }
    cout<<n;
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
    queue<struct node*>bfs;
    print_from_target(p1,bfs);
    return 0;
}