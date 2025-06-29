#include <stdio.h> 
#include <stdlib.h> 
#include "queue.h"
#include "stack.h"

// initial node
typedef struct BTreeNode{
    int data; 
    struct BTreeNode * right; 
    struct BTreeNode * left; 
} BTreeNode; 

BTreeNode * createNode(int data){
    BTreeNode * n = (BTreeNode*)malloc(sizeof(BTreeNode)); 
    if (n == NULL) exit(EXIT_FAILURE); 
    n->data = data; 
    n->right = n->left = NULL; 
    return n; 
}

BTreeNode * insert(BTreeNode * root, int data){
    if (root == NULL) return createNode(data); 
    if (data < root->data) root->left = insert(root->left, data); 
    else root->right = insert(root->right, data); 
    return root; 
}

void inorder(BTreeNode * root){
    if (root != NULL){
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    }
}

void preorder(BTreeNode * root){
    if (root != NULL){
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    }
}

void postorder(BTreeNode * root){
    if (root != NULL){
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    }
}


void levelOrder(BTreeNode * root){
    if (root == NULL) return; 
    Queue * queue = createQ(); 
    enqueue(queue, root); 
    while (!isQueueEmpty(queue)){
        BTreeNode * curr = (BTreeNode*)dequeue(queue);
        printf("%d ", curr->data); 
        if (curr->left != NULL){
            enqueue(queue, curr->left); 
        }
        if (curr ->right != NULL){
            enqueue(queue, curr->right); 
        }
    }
    freeQueue(queue); 
}

void inorderIterative(BTreeNode * root){
    Stack * stack = createS(); 
    BTreeNode * curr = root; 
    while (curr != NULL || !isStackEmpty(stack)){
        while (curr != NULL){
            push(stack, curr); 
            curr = curr->left; 
        }
        curr = (BTreeNode *)pop(stack); 
        printf("%d ", curr->data); 
        curr = curr->right; 
    }
    freeStack(stack); 
}

// Push the root node to the stack.
// 
// Pop the stack and print the node's data.
// 
// Push the right child first (if it exists).
// 
// Push the left child next (if it exists).
// 
// Repeat the above steps until the stack becomes empty.

void preorderIterative(BTreeNode * root){
    if (root ==NULL) return;
    Stack * stack = createS(); 
    push(stack, root); 

    while (!isStackEmpty(stack)){
        BTreeNode * curr = (BTreeNode *)pop(stack); 
        printf("%d ", curr->data);

        if (curr->right != NULL){
            push(stack, curr->right); 
        }
        if (curr->left != NULL){
            push(stack, curr->left); 
        }
    }
    freeStack(stack); 
}

// Push the root node to the first stack.
// 
// Pop the top node from the first stack and push it to the second stack.
// 
// Push the left and right children of the popped node to the first stack.
// 
// Repeat the above steps until the first stack is empty.
// 
// Pop all nodes from the second stack and print them.

void postorderIterative(BTreeNode * root){
    if (root == NULL) return; 
    Stack* stack1 = createS(); 

    Stack* stack2= createS();
    
    push(stack1, root); 

    while (!isStackEmpty(stack1)){
        BTreeNode * curr = (BTreeNode * )pop(stack1); 
        push(stack2, curr); 
        if (curr->left != NULL) push(stack1, curr->left); 
        if (curr->right != NULL) push(stack1, curr->right); 
    }

    while(!isStackEmpty(stack2)){
        BTreeNode*curr = (BTreeNode*)pop(stack2); 
        printf("%d ", curr->data);
    }

    freeStack(stack1); 
    freeStack(stack2); 
}

// extract da inorder successor for before deletion of root node (returned node will be the replacement) 
BTreeNode * findMin(BTreeNode * root){
    while (root && root->left != NULL){
        root = root->left; 
    }
    return root; 
}

BTreeNode * deleteNode(BTreeNode * root, int key){
    if (root == NULL){
        return root; 
    }

    if (key < root->data) root->left = deleteNode(root->left, key); 
    else if (key > root->data) root->right = deleteNode(root->right, key); 
    else {
        // case : 1 node only
        if (root->left == NULL){
            BTreeNode * t = root->right; 
            free(root); 
            return t; 
        }
        else if (root->right == NULL){
            BTreeNode * t = root->left; 
            free(root); 
            return t; 
        }
        BTreeNode * t = findMin(root->right); 
        root->data = t->data; 
        root->right = deleteNode(root->right, t->data); 
    }
    return root; 
}


int main(){
    BTreeNode* root = NULL; 
    int val[] = {50, 30, 20, 40, 70, 60, 80}; 
    int n = sizeof(val)/ sizeof(val[0]); 
    for (int i = 0; i < n; i++){
        root = insert(root, val[i]); 
    }

    printf("Inorder traversal: "); 
    inorder(root); 
    printf("\n"); 

    printf("Preorder traversal: "); 
    preorder(root); 
    printf("\n"); 

    printf("Postorder traversal: ");
    postorder(root); 
    printf("\n"); 

    printf("Level order traversal: "); 
    levelOrder(root); 
    printf("\n"); 


    printf("Iterative preorder traversal: "); 
    preorderIterative(root); 
    printf("\n"); 

    printf("Iterative inorder traversal: "); 
    inorderIterative(root); 
    printf("\n"); 

    printf("Iterative postorder traversal: "); 
    postorderIterative(root); 
    printf("\n"); 


    // printf("Deleting node with value 20\n");
    // root = deleteNode(root, 20);
    // printf("Inorder traversal after deleting 20: ");
    // inorder(root);
    // printf("\n");

    printf("Deleting node with value 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    printf("Deleting node with value 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0; 



}