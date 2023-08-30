#include <iostream>
#include <map>
#include <queue>
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

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
map<int, int> horizontalDistanceToRoot;
queue<pair<TreeNode *, int>> q;

void topView(TreeNode *root)
{
    if (!root)
        return;

    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode *node = q.front().first;
        int distance = q.front().second;
        q.pop();

        horizontalDistanceToRoot[distance] = node->value;
        if (node->left)
        {
            q.push({node->left, distance - 1});
        }
        if (node->right)
        {
            q.push({node->right, distance + 1});
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Top View: ";
    topView(root);
    for(pair i:horizontalDistanceToRoot){
        cout<<i.second<<" ";
    }
    return 0;
}
