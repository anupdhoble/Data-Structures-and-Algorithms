//Print all nodes at a distance k from target node

#include<bits/stdc++.h>
#include<queue>
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

void print_from_target(struct node* root,queue<struct node*> bfs,int k){
    int n=0;
    bfs.push(root);
    while(!bfs.empty()){
        int size=bfs.size();
        for(int i=0;i<size;i++){
            if((visited.find(m[bfs.front()])==visited.end())&&m[bfs.front()]){
                visited.insert(bfs.front());
                bfs.push(bfs.front());
            }
            if((visited.find(m[bfs.front()->left])==visited.end())&&bfs.front()->left){
                visited.insert(m[bfs.front()->left]);
                bfs.push(bfs.front()->left);
            }
            if((visited.find(m[bfs.front()->right])==visited.end())&&bfs.front()->right){
                visited.insert(m[bfs.front()->right]);
                bfs.push(bfs.front()->right);
            }
            n++;
            if(n==k){
                cout << "Nodes at distance " << k << " from target node: ";
                queue<struct node*> tempQueue = bfs;  // Create a temporary queue for iteration
                while (!tempQueue.empty()) {
                    cout << tempQueue.front()->data << " ";
                    tempQueue.pop();
                }
                cout << endl;
            }
        }

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
    print_from_target(p1,bfs,2);
    return 0;
}