#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>
//     1
//    / \
//   2   3
//    \
//     4
//      \
//       5
//        \
//         6

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};


TreeNode* maketree(vector<int>&arr,int l,int r){
    if(l==r){
        TreeNode* p =new TreeNode(arr[l]);
        return p;
    }
    int mid=(l+r)/2;
    TreeNode * neww=new TreeNode(arr[mid]);
    if(mid-1>=l){
        neww->left=maketree(arr,l,mid-1);
    }
    if(mid+1<=r){
        neww->right=maketree(arr,mid+1,r);
    }
    return neww;
}
void printInorder(TreeNode* root){
    if(root!=NULL){
        printInorder(root->left);
        cout<<root->value;
        printInorder(root->right);
    }
}

int main()
{
    int arr[] = {-10, -3, 0, 5, 9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    TreeNode* ans=maketree(v,0,v.size()-1);
    printInorder(ans);

    
    return 0;
}
