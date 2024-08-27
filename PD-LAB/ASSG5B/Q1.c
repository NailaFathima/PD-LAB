#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList{
 int data;
 struct LinkedList *next;
};

typedef struct LinkedList *node;

node createNode() {
 node temp; // declare a node
 temp = (node ) malloc (sizeof(struct LinkedList));
 // allocate memory using malloc()
 if(temp == NULL)
    { 
        printf("Error creating a new node.\n");
        exit(0); 
    }
 temp->next = NULL; // make next point to NULL
 return temp; //return the new node
}

node list_search(node head , int key)  //function to search for a node
{   
    node p;
    p = head;
    if(head!=NULL)
    {
        while(p != NULL)
        {
            if(p->data == key)
            {   
                printf("1\n");
                return p;
            }
            else
                p = p->next;
        }
        printf("-1\n");
        return head;
    }
    else //empty list
    {
        printf("1\n");
        return head;
    }
}

node list_search_func(node head , int key) //similar to the above function but wont print anything
{   
    node p;
    p = head;
    if(head!=NULL)
    {
        while(p != NULL)
        {
            if(p->data == key)
            {   
                return p;
            }
            else
                p = p->next;
        }
        return NULL;
    }
    else //empty list
    {
        return NULL;
    }
}

node list_insert_front( node first, int data) //function to insert at the beginning
{
    node new_head;
    node new_node =createNode();
    new_node->data = data;
    new_node->next = first;
    new_head = new_node;
    return new_head;
}
node list_insert_tail( node first , int data) //function to insert at the end
{
    node temp,p; 
    temp = createNode();
    temp->data = data;
    temp->next=NULL; 
    if(first == NULL) //when the linked list is empty
        first = temp;  
    else 
    {
      p = first; 
      while(p->next != NULL) 
        p = p->next; 
      p->next = temp; 
    }
    return first;
}
node list_delete_first(node head) //function to insert at the beginning
{
    if(head != NULL)
    {   
        if(head->next != NULL)
        {
            node temp;
            temp = head->next;
            printf("%d\n",head->data);
            free(head);
            head = temp;
            return head;
        }
        else //linked list contains only one node
        {
            printf("%d\n" , head->data);
            free(head);
            head = NULL;
            return head;
        }
    }
    else
    {
        printf("-1\n");
        return head;
    }
}

node list_delete_last(node head) //function to insert at the end
{   
    node temp,temp2;
    if(head!=NULL)
    {
        if(head->next != NULL)
        {
            temp = head;
            while(temp->next->next != NULL)
            {   
                temp = temp->next;
            }
            printf("%d\n", temp->next->data);
            free(temp->next);
            temp->next = NULL;
            return head;
        }
        else //thelinked list contains only one node
        {
            printf("%d\n" , head->data);
            free(head);
            head = NULL;
            return head;
        }
    }
    else
    {
        printf("-1\n");
        return head;
    }
}

node list_delete(node head , int key) //function to delete a particular node
{
    node temp;
    temp = list_search_func(head , key);
    node p = head;
    if(temp!=NULL)
    {
        if(temp == head) //if the node to be deleted is the first node
        {
            head = list_delete_first(temp);
            return head;
        }
        else if(temp->next == NULL) //if the node to be deleted is the last node
        {
            head = list_delete_last(head);
            return head;
        }
        else
        {
            while(p->next != temp)
                p = p->next;
            node temp2;
            temp2 = p->next->next;
            printf("%d\n",p->next->data);
            free(p->next);
            p->next = temp2;
            return head;
        }
    }
    else
    {
        printf("-1");
        return head;
    }
}

node list_insert_after(node head , int key , int after) //function to insert after particular node
{
    node temp,find,p ;
    
    find = list_search_func(head , after);
    if(find!=NULL)
    {   
        temp = createNode();
        temp->data = key;
        if(find->next!=NULL)
        {   
            p = head;
            while(p!=find)
                p=p->next;
            node temp2;
            temp2 = p->next;
            temp->next = temp2;
            p->next = temp;
            return head;
        }
        else //node to be inserted is after the last node
        {
            head = list_insert_tail(head , key);
            return head;
        }
    }
    else
        return head;
}

node list_insert_before(node head , int key , int before) //function to insert before a particular node
{
    node temp , find , p;
    find = list_search_func(head,before);
    if(find!=NULL)
    {
        temp = createNode();
        temp->data = key;
        if(find!=head)
        {
            p = head;
            while(p->next!=find)
                p=p->next;
            node temp2;
            temp2 = p->next;
            temp->next = temp2;
            p->next = temp;
            return head;
        }
        else //node to be inserted is before the first node i.e. same as insertion at beginning
        {
            head = list_insert_front(head , key);
            return head;
        }
    }
    else
        return head;
}

node list_reverse(node head) //function to reverse the LL
{
    node prev , current , next;
    current = head;
    prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void list_reverse_even(node head) //function to reverse only the even positioned nodes
{
    if (head == NULL || head->next == NULL)
        return;

    node odd = head;
    node even = NULL;

    while (odd && odd->next) 
    {
        node temp = odd->next; 
        odd->next = temp->next;
        temp->next = even;
        even = temp ;
        odd = odd->next;
    }

    odd = head;

    while (even)
    {
        node temp = even->next;
        even->next = odd->next;
        odd->next = even;
        odd = odd->next->next;
        even = temp;
    }
}

void printlist(node head) //function to print the LL
{
  if(head==NULL)
    printf("\n");
  else
  {
    while(head->next!=NULL)
    {
      printf("%d ",head->data);
      head=head->next;
    }
    printf("%d\n",head->data);
  }
}

#include <stdio.h>
int main()
{
    char ans[100];
    node head = NULL;
    /*MENU

    f -> insertion at the front
    t -> insrtion at the last
    a -> insertion after a particular node
    b -> insertion before a particular node
    d -> deletion of node and deleted node's key is printed
    i -> deletion of the first node and deleted node's key is printed
    l -> deletion of last node and deleted node's key is printed
    s -> searching for a node
    r -> reversal of the linked list
    ds -> print the list
    re -> reversal of elements in the even positions only
    e -> exit

    */

   scanf("%s" , ans);
   while((strcmp(ans,"e")!=0))
   {
    if ((strcmp(ans,"f")==0))
    {
        int key;
        scanf("%d",&key);
        head = list_insert_front(head , key);
    }
    else if ((strcmp(ans,"t")==0))
    {
        int key;
        scanf("%d",&key);
        head = list_insert_tail(head , key);
    }
    else if ((strcmp(ans,"a")==0))
    {
        int key , after;
        scanf("%d %d",&key , &after);
        head = list_insert_after(head , key , after);
    }
    else if ((strcmp(ans,"b")==0))
    {
        int key , before;
        scanf("%d %d",&key , &before);
        head = list_insert_before(head , key , before);
    }
    else if ((strcmp(ans,"d")==0))
    {
        int key;
        scanf("%d",&key);
        head = list_delete(head , key);
    }
    else if ((strcmp(ans,"i")==0))
    {
        head = list_delete_first(head);
    }
    else if ((strcmp(ans,"l")==0))
    {
        head = list_delete_last(head);
    }
    else if ((strcmp(ans,"s")==0))
    {
        int key;
        scanf("%d",&key);
        head = list_search(head , key);
    }
    else if ((strcmp(ans,"r")==0))
    {
        head = list_reverse(head);
        printlist(head);
    }
    else if ((strcmp(ans,"ds")==0))
    {
        printlist(head);
    }
    else if ((strcmp(ans,"re")==0))
    {
        list_reverse_even(head);
        printlist(head);
    }
    scanf("%s",ans);
    }
    return 0; 
}