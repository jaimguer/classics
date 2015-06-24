#include<stdio.h>
#include<stdlib.h>

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
 * findSmallest(struct node* root) finds the smallest element in a BST
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
 * findLargest(struct node* root) finds the largest element in a BST
 */

int findLargest(struct node* root)
{
    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

void printData(struct node* n)
{
    printf("%d ", n->data);
}

/*
 * preorderPrint :: Node* -> IO
 * preorderPrint(struct node* root) prints the tree represented by root in
 * a preorder fashion
 */
void preorderPrint(struct node* root)
{
    if(root == NULL) {
        return;
    }
    else {
        printData(root);
        preorderPrint(root->left);
        preorderPrint(root->right);
    }

}

/*
 * inorderPrint :: Node* -> IO
 * inorderPrint(struct node* root) prints the BST elements represented by root in order
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

int nodeCount(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
}

int longestPath(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftLength = 1 + longestPath(root->left);
        int rightLength = 1 + longestPath(root->right);
        return leftLength > rightLength ? leftLength : rightLength;
    }
}

int main()
{
    struct node* tree = makeTree();
    int smallest = findSmallest(tree);
    int largest = findLargest(tree);
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
    printf("\n");
    printf("The number of nodes in the tree tree is %d\n", nodeCount(tree));
    printf("The longest path is of length %d\n", longestPath(tree));

    return 0;

}



