//Implement the following operations on a binary search tree (BST) in C: a. Insertion: Insert a given value into the BST. b. Deletion: Remove a given value from the BST. c. Search: Check if a given value exists in the BST.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node* createNode(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}    
struct node* insertNode(struct node* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->left=insertNode(root->left,data);
    }
    else
    {
        root->right=insertNode(root->right,data);
    }
    return root;    
}
struct node* deleteNode(struct node* root,int data) 
{
    if(root==NULL)
    {
        return root;
    }
    if(data<root->data)
    {
        root->left=deleteNode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=deleteNode(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=root->right;
        while(temp&&temp->left!=NULL)
        {
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;    
}
int searchNode(struct node* root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    if(data<root->data)
    {
        return searchNode(root->left,data);
    }
    else if(data>root->data)
    {
        return searchNode(root->right,data);
    }
    else
    {
        return 1;
    }    
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }    
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }    
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }                                   
}   
int main()
{
    struct node* root=NULL;
    int n,data,choice=1;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        root=insertNode(root,data);
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\nEnter the value to be deleted: ");
    scanf("%d",&data);
    root=deleteNode(root,data);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");    
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\nEnter the value to be searched: ");
    scanf("%d",&data);
    if(searchNode(root,data))
    {
        printf("Value found in the BST\n");
    }
    else
    {
        printf("Value not found in the BST\n");
    }
    printf("\nEnter the value to be inserted: ");
    scanf("%d",&data);
    root=insertNode(root,data);
    printf("Inorder Traversal: ");
    inorder(root);    
    printf("\nPreorder Traversal: ");    
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}   