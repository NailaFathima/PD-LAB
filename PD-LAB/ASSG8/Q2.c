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

node predecessor(node root , node *pre , node *suc , int key)
{
    if(root==NULL)
        return NULL ;
    if(root->data == key)
    {
        if(root->left != NULL)
        {
            node temp1 = root->left;
            while(temp1->right!= NULL)
                temp1 = temp1->right;
            *pre = temp1;
            return *pre ;
            //printf("%d\n",*pre->data);
        }
        return NULL;
        
    }
    if(root->data > key)
    {
        *suc = root ;
        predecessor(root->right , pre , suc , key);
    }
    else
    {
        *pre = root;
        predecessor(root->right , pre , suc , key);
    }
}

void successor(node root , node pre , node suc , int key)
{
    if(root==NULL)
        return ;
    if(root->data == key)
    {
        if(root->right != NULL)
        {
            node temp1 = root->right;
            while(temp1->left!= NULL)
                temp1 = temp1->left;
            suc = temp1;
            if(temp1!=NULL)
                printf("%d\n",suc->data);
            else
                printf("-1\n");
        }
        return ;
    }
    if(root->data > key)
    {
        suc = root ;
        successor(root->right , pre , suc , key);
    }
    else
    {
        pre = root;
        successor(root->right , pre , suc , key);
    }
}

int main()
{
    char ans;
    node root = NULL;
    node pre = NULL;
    node suc = NULL;
    root = insert(root , 50);
    root = insert(root , 30);
    root = insert(root , 60);
    root = insert(root , 20);
    root = insert(root , 40);
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
        else if(ans=='c')
        {
            int key;
            scanf("%d", &key);
            node pre = NULL;
            node suc = NULL;
            if(root!=NULL)
            {
                successor(root , pre , suc , key);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if(ans=='r')
        {
            int key;
            scanf("%d", &key);
            node pre = NULL;
            node suc = NULL;
            if(root!=NULL)
            {
                node temp = predecessor(root , &pre , &suc , key);
                printf("%d\n" , temp->data);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if(ans=='p')
        {
            if(root!=NULL)
            {
                preorder(root);
                printf("\n");
            }
            else
            {
                printf("-1\n");
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
        getchar();
        scanf("%c",&ans);
    }
}


    