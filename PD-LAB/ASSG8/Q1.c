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
    if(key>root->data)
    {
        root->left = insert(root->left , key);
    }
    else if (key<root->data)
    {
        root->right = insert(root->right , key);
    }
    return root;
}

void inorder(node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
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

void postorder(node root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int find_min(node root)
{
    node current = root;
    while(current && (current->right) != NULL)
        current = current->right;

    return current->data;
}

int find_max(node root)
{
    node current = root;
    while(current && current->left != NULL)
        current = current->left;

    return current->data;
}

void tree_search(node root , int key)
{
    {
        node temp = root;
        int check = 0;
        while(temp!=NULL)
        {
            if(temp->data > key)
                temp = temp->right;
            else if(temp->data < key)
                temp = temp->left;
            else if(temp->data == key)
            {
                check = 1;
                break;
            }
        }
        if(check==0)
            printf("N\n");
        else
            printf("F\n");
        return ; 
    }
    
}

int main()
{
    char ans;
    node root = NULL;
    scanf("%c",&ans);
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
        
        else if(ans=='s')
        {
            int key;
            scanf("%d" , &key);
            node result;
            if(root!=NULL)
            {
                tree_search(root,key);
            }
        }

        else if(ans=='x')
        {
            if(root!=NULL)
            {
                int max = find_max(root);
                printf("%d\n",max);
            }
        }
        else if(ans=='n')
        {
            if(root!=NULL)
            {
                int min = find_min(root);
                printf("%d\n",min);
            }
        }
        else if(ans=='i')
        {
            if(root!=NULL)
            {
                inorder(root);
                printf("\n");
            }
        }
        else if(ans=='p')
        {
            if(root!=NULL)
            {
                preorder(root);
                printf("\n");
            }
        }
        else if(ans=='t')
        {
            if(root!=NULL)
            {
                postorder(root);
                printf("\n");
            }    

        }
        getchar();
        scanf("%c",&ans);
    }
}

