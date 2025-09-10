#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int key) {
   
    if (root == NULL) 
        return newNode(key);
    
    if (key < root->data)
        root->left = insert(root->left, key);
   
    else if (key > root->data)
        root->right = insert(root->right, key);
 
    
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    
    int key = 4;
    root = insert(root, key);
    
    printf("Inorder traversal after insertion: ");
    inorder(root); 
    printf("\n");
    
    return 0;
}
