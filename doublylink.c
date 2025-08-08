









#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev; // Added for doubly linked list
}*temp=NULL, *first=NULL, *last=NULL;
void create()
{
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL; // Initialize prev pointer
}
void addfront()
{
    create();
    if(first == NULL) {
        first = temp;
        last = temp;
    } else {
        temp->next = first;
        first->prev = temp; // Set previous pointer of the old first node
        first = temp;   
    }
}
void removefront()
{
    struct node *temp;
    temp=first;
    if(first == NULL) {
        printf("List is empty\n");
    }
    if(temp->next==NULL)
    {
        free(temp);
        first = NULL;
        last = NULL;
    }
    else{
        first=temp->next;
        first->prev = NULL; // Update the new first node's previous pointer
        free(temp);
    }
}
void display()
{
    if(first == NULL) {
        printf("List is empty\n");
    } else {
        temp = first;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");  
    }
}
int main()
{
    int choice;
    while(1) {
        printf("1. Insert at front\n");
        printf("2. Remove from front\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addfront(); break;
            case 2: removefront(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}