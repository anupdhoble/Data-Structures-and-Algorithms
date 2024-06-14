#include <iostream>
#include <queue>
#include <climits> // Include the <climits> header for INT_MIN
#include <unordered_set>
#include <unordered_map>
#include <vector> // Add the missing header for the vector class

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to create a binary tree from an array
TreeNode* createBinaryTree(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (nums[i] != INT_MIN) { // Check for INT_MIN instead of -1
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nums.size() && nums[i] != INT_MIN) { // Check for INT_MIN instead of -1
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int count=0;
void pathSum(TreeNode* root, int targetSum,unordered_map<int,int>&s,int sum) {
    if(!root) return ;
    sum+=root->val;
    if(s.find(targetSum-sum)!=s.end()){
        count+=s[targetSum-sum];
    }
    s[sum]++;



    pathSum(root->left,targetSum,s,sum);
    pathSum(root->right,targetSum,s,sum);
    s[sum]--;
    return ;
}

int main() {
    // Example usage
    vector<int> nums = {10,5,-3,3,2,INT_MIN,11,3,-2,INT_MIN,1};
    TreeNode* root = createBinaryTree(nums);
    inorder(root);
    int targetSum = 8;
    unordered_map<int,int>s;
    // Perform operations on the binary tree
    pathSum(root, targetSum,s,0);
    cout << "Path Sum: " << count;

    return 0;
}