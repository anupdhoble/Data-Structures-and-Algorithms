#include <bits/stdc++.h>
#include <malloc.h>

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
void printInorder(struct node *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        cout << root->data;
        printInorder(root->right);
    }
}
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

void insert_bst(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "Error:- Insertion failed,value already exist in BST..";
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *n = createNode(key);
    if (key < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}
struct node* inorderPredecessor(struct node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node* delete_bst(struct node * root,int key){
    struct node* ipre;
    if(root==NULL){//base condition
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){ //i.e. it is a leaf node
        //base condition
        free(root);
        return NULL;
    }
    //search for node to be deleted
    if(key<root->data){
        root->left=delete_bst(root->left,key);
    }
    else if(key>root->data){
        root->right=delete_bst(root->right,key);
    }
    else{//key node found if key==root->data
        ipre=inorderPredecessor(root);
        root->data=ipre->data;
        root->left=delete_bst(root->left,ipre->data);
    }
    return root;
}
int main()
{
    cout << "By Anup Dhoble..." << '\a';

    struct node *p = createNode(6);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(8);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Finally The BST tree looks like this:
    //      6
    //     / \
    //    3   8
    //   / \
    //  1   4
    // Eg. After insertion of 2 BST looks like
    //      6
    //     / \
    //    3   8
    //   / \
    //  1   4
    // / \
    //[]  2
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    cout << "\nInorder: ";
    printInorder(p);
    // If Inorder is in ascending order then BT is BST.
    if (isBST(p))
    {
        cout << "\nIt is a Binary Search Tree..";
    }
    else
    {
        cout << "\nIt is not a Binary Search Tree..";
    }
    
    insert_bst(p, 2);
    cout << "\n"<< p->left->left->right->data<<"\n";
    printInorder(p);
    delete_bst(p,2);
    cout<<endl;
    printInorder(p);
    

    return 0;
}