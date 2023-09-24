//write a c function to delete all the occurance of a particular element from a list

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}nd;
void display(nd *node)
{

    while(node != NULL)
    {
       printf("%d ->",node->data);
       node = node->next;
    }
    printf("NULL\n");
}
void insert(nd **head,int data)
{
    nd* newnode = (nd*)malloc(sizeof(nd));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}
void deleteOccurances(nd **head,int value)
{
    nd* curr = *head;
    nd* prev = NULL;
    while(curr != NULL)
    {
        if(curr->data == value)
        {
            if(prev == NULL)
            {
                *head = curr->next;
                free(curr);
                curr = *head;
            }
            else
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
int main(){

nd *head = NULL;
insert(&head,3);
insert(&head,4);
insert(&head,2);
insert(&head,1);
insert(&head,2);
insert(&head,4);
insert(&head,2);

printf("original list:");
display(head);

printf("Lists after deleting:");
deleteOccurances(&head,2);
display(head);

return 0;
}