#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LinkedList{
 int data;
 struct LinkedList *right;
 struct LinkedList *left;
};

typedef struct LinkedList *node;

node createNode(int key) 
{
    node temp; // declare a node
    temp = (node ) malloc (sizeof(struct LinkedList));
    // allocate memory using malloc()
    if(temp == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }

    temp->data = key;
    temp->right = NULL;
    temp->left = NULL; // make right and left point to null
    return temp; //return the new node
}

node insert(node root , int key)
{
    if(root==NULL)
        return createNode(key);
    if(key<root->data)
    {
        root->left = insert(root->left , key);
    }
    else if (key>root->data)
    {
        root->right = insert(root->right , key);
    }

    return root;
}

void print_bst(node root)
{
    if(root==NULL)
    {
        printf("( )");
        return;
    }

    printf("( %d",root->data);
    print_bst(root->left);
    printf("( )");
    print_bst(root->right);
    printf("( )");
    printf(" )");
}

void preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    node root = NULL;
    char ans;
    scanf("%c" , &ans);
    while(ans!='e')
    {
        if(ans=='a')
        {
            int key;
            scanf("%d" , &key);
            if(root==NULL)
            {
                root = insert(root,key);
            }
            else
            {
                node temp;
                temp = insert(root,key);
            }
        }
        else if(ans=='p')
        {
            print_bst(root);
            printf("\n");
        }
        else if (ans=='t')
        {
            preorder(root);
        }

        getchar();
        scanf("%c" , &ans);
    }

}
