#include<stdio.h>
#include<stdlib.h>

/*
 * Implementation of Binary Search Trees.  BSTs maintain the invariants that
 * each node has no more than two children, that the left child's data is less
 * than the parent's data, and that the right child's data is greater than the
 * parent's.
 */

/*
 * A node within a binary tree is recursively defined.
 * It is either empty (that is, NULL), or it posseses some data and pointers
 * to left and right children
 */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/*
 * makeTree :: () -> Node*
 * makeTree() creates a tree with 7 nodes
 */
struct node* makeTree()
{
    struct node* root = malloc(sizeof(struct node));
    struct node* l    = malloc(sizeof(struct node));
    struct node* r    = malloc(sizeof(struct node));
    struct node* ll   = malloc(sizeof(struct node));
    struct node* lr   = malloc(sizeof(struct node));
    struct node* rl   = malloc(sizeof(struct node));
    struct node* rr   = malloc(sizeof(struct node));
    struct node* rrr  = malloc(sizeof(struct node));

    root->data  = 4;
    root->left  = l;
    root->right = r;

    l->data     = 2;
    l->left     = ll;
    l->right    = lr;

    r->data     = 6;
    r->left     = rl;
    r->right    = rr;

    ll->data    = 1;
    ll->left    = NULL;
    ll->right   = NULL;

    lr->data    = 3;
    lr->left    = NULL;
    lr->right   = NULL;

    rl->data    = 5;
    rl->left    = NULL;
    rl->right   = NULL;

    rr->data    = 7;
    rr->left    = NULL;
    rr->right   = rrr;

    rrr->data = 8;
    rrr->left = NULL;
    rrr->right = NULL;

    return root;
}

/*
 * findSmallest :: Node* -> Integer
 * findSmallest(struct node* root) finds the smallest element in a BST.  The
 * smallest element is the leftmost node.
 */
int findSmallest(struct node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;

}

/*
 * findLargest :: Node* -> Integer
 * findLargest(struct node* root) finds the largest element in a BST. The
 * largest element is the rightmost node.
 */
int findLargest(struct node* root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

/* printData :: Node* -> IO
 * printData(struct node* n) prints the data member of n.
 */
void printData(struct node* n)
{
    printf("%d ", n->data);
}

/*
 * preorderPrint :: Node* -> IO
 * preorderPrint(struct node* root) prints the tree represented by root in
 * a preorder fashion.  Preorder traversal consists of printing the parent
 * node first, and then printing its children from left to right.
 */
void preorderPrint(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printData(root);
        preorderPrint(root->left);
        preorderPrint(root->right);
    }

}

/*
 * inorderPrint :: Node* -> IO
 * inorderPrint(struct node* root) prints the BST elements represented by root
 * in order.  In order traversals print the left children, the parent, and
 * then the right children.
 */
void inorderPrint(struct node* root)
{
    if(root == NULL) {
        return;
    }
    else {
        inorderPrint(root->left);
        printData(root);
        inorderPrint(root->right);
    }
}

/*
 * postOrderPrint :: Node* -> IO
 * postorderPrint(struct node* root) prints a BST in a postorder fasion.  Post
 * order traversals process all of a node's children before they process the
 * node itself.
 */
void postorderPrint(struct node* root)
{
    if (root == NULL) {
        return;
    }
    else {
        postorderPrint(root->left);
        postorderPrint(root->right);
        printData(root);
    }
}

/*
 * find :: Integer Node* -> IO
 * find(int key, struct node* root) determines if key can be found in the BST
 * represented by root.
 */
void find(int key, struct node* root)
{
    if (root == NULL)
    {
        printf("%d is not in the tree\n", key);
    }
    else if (key < root->data)
    {
        find(key, root->left);
    }
    else if (key > root->data)
    {
        find(key, root->right);
    }
    else
    {
        printf("%d is in the tree\n", key);
    }
}

/*
 * nodeCount :: Node* -> Nat
 * nodeCount(struct node* tree) counts the number of nodes in tree
 */
int nodeCount(struct node* tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nodeCount(tree->left) + nodeCount(tree->right);
    }
}

/*
 * longestPath :: Node* -> Nat
 * longestPath(struct node* tree) finds the longest path from root to leaf
 * within tree.
 */
int longestPath(struct node* tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int leftLength  = 1 + longestPath(tree->left);
        int rightLength = 1 + longestPath(tree->right);
        return leftLength > rightLength ? leftLength : rightLength;
    }
}

/*
 * insert :: Integer Node* -> void
 * insert(int input, struct node* tree) inserts input into the tree,
 * while maintaining the BST invariants.
 * Initially assume a nonempty tree input
 */
void insert(int input, struct node* tree)
{
    if (tree->left == NULL && tree->right == NULL)
    {
        struct node* n = malloc(sizeof(struct node*));
        n->data  = input;
        n->left  = NULL;
        n->right = NULL;
        if (input < tree->data)
        {
            tree->left = n;
        }
        else
        {
            tree->right = n;
        }
    }
    else if (input < tree->data)
    {
        insert(input, tree->left);
    }
    else
    {
        insert(input, tree->right);
    }
}

int main()
{
    struct node* tree = makeTree();
    int smallest      = findSmallest(tree);
    int largest       = findLargest(tree);
    printf("The smallest value in the tree is %d\n", smallest);
    printf("The largest value in the tree is %d\n", largest);

    printf("Preorder traversal:\n");
    preorderPrint(tree);
    printf("\n");

    printf("Inorder traversal:\n");
    inorderPrint(tree);
    printf("\n");

    printf("Postorder traversal:\n");
    postorderPrint(tree);
    printf("\n");

    find(7, tree);
    find(12, tree);

    printf("The number of nodes in the tree tree is %d\n", nodeCount(tree));
    printf("The longest path is of length %d\n", longestPath(tree));

    insert(-1, tree);
    printf("Inserted -1 \n");

    insert(10, tree);
    printf("Inserted 10 \n");


    insert(9, tree);
    printf("Inserted 9 \n");
    inorderPrint(tree);
    printf("\n");

    find(9, tree);
    find(10, tree);

    return 0;

}



