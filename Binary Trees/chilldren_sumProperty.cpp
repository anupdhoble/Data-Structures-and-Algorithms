#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
void print_current_level(struct node *root, int i)
{
    if (root == NULL)
        return;
    if (i == 1)
        cout << root->data << " ";
    print_current_level(root->left, i - 1);
    print_current_level(root->right, i - 1);
}
void level_traversal(struct node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_current_level(root, i);
    }
}

struct node *children_sum(struct node *root, int highest)
{
    if (!root)
    {
        return NULL;
    }
    int sumLR = 0;
    if (root->left)
    {
        sumLR += root->left->data;
    }
    if (root->right)
    {
        sumLR += root->right->data;
    }
    if (sumLR > highest)
    {
        highest = sumLR;
        if (root->left)
        {

            root->left = children_sum(root->left, highest);
        }
        if (root->right)
        {

            root->right = children_sum(root->right, highest);
        }
    }

    else
    {
        if (root->left)
        {
            root->left->data = highest;
            root->left = children_sum(root->left, highest);
        }
        if (root->right)
        {
            root->right->data = highest;
            root->right = children_sum(root->right, highest);
        }
    }
    if (root->left || root->right)//For Leaf node dont add as it will result in zero while backtracking the tree
    {
        sumLR = 0;
        if (root->left)
        {
            sumLR += root->left->data;
        }
        if (root->right)
        {
            sumLR += root->right->data;
        }
        root->data = sumLR;
    }
    return root;
}

int main()
{
    cout << "By Anup Dhoble..." << '\a';

    struct node *p = createNode(7);
    struct node *p1 = createNode(6);
    struct node *p3 = createNode(0);
    struct node *p4 = createNode(4);
    struct node *p2 = createNode(1);
    struct node *p5 = createNode(8);

    // Finally The tree looks like this:
    //      7
    //     / \
    //    6   1
    //   / \   \
    //  0   4   8
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    struct node *sum = children_sum(p, p->data);
    level_traversal(sum);
    return 0;
}