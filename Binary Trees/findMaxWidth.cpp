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
int max_width_of_binary_tree(struct node* root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    queue<pair<struct node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int indx_of_first_in_queue= q.front().second;
        int low,high;

        for(int i=0;i<size;i++){
            struct node* current= q.front().first;
            int curr_index=q.front().second-indx_of_first_in_queue;
            q.pop();
            if(i==0){
                low=curr_index;
            }
            if(i==size-1){
                high=curr_index;
            }
            if(current->left){
                q.push({current->left,2*curr_index+1});
            }
            if(current->right){
                q.push({current->right,2*curr_index+2});
            }
        }
        ans=max(ans,high-low+1);
    }
    return ans;
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
    cout<<"Max width of given binery tree: "<<max_width_of_binary_tree(p);

    return 0;
}