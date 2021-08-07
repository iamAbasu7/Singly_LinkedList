#include <stdio.h>
#include<stdlib.h>
// Linked List Node
struct node {
        int info;
        struct node* link;
};
struct node* start = NULL;

// Function to traverse the linked list
void traverse()
{
        struct node* temp;

        // List is empty
        if (start == NULL)
                printf("\nList is empty\n");

        // Else print the LL
        else {
                temp = start;
                while (temp != NULL) {
                        printf(" %d ->",temp->info);
                        temp = temp->link;
                }
        }
}

// Function to insert at the front
// of the linked list
void insertAtFront()
{
        int data;
        struct node* temp;
        temp = malloc(sizeof(struct node));
        printf("\nEnter number to"
                " be inserted : ");
        scanf("%d", &data);
        temp->info = data;

        // Pointer of temp will be
        // assigned to start
        temp->link = start;
        start = temp;
}

// Function to insert at the end of
// the linked list
void insertAtEnd()
{
        int data;
        struct node *temp, *head;
        if(start == NULL)
                printf("Enter the data at the First position\n");
        else{
        temp = malloc(sizeof(struct node));

        // Enter the number
        printf("\nEnter number to"
                " be inserted : ");
        scanf("%d", &data);

        // Changes links
        temp->link = 0;
        temp->info = data;
        head = start;
        while (head->link != NULL) {
                head = head->link;
        }
        head->link = temp;
}
}
// Function to insert at any specified
// position in the linked list
void insertAtPosition()
{
        struct node *temp, *newnode;
        int pos, data, i = 1;
        if(start == NULL)
                printf("Enter the data at the First position\n");
        else{
        newnode = malloc(sizeof(struct node));

        // Enter the position and data
        printf("\nEnter position and data :");
        scanf("%d %d", &pos, &data);
        struct node* temp=start;
        int count=0;
        while(temp != NULL)
        {
                temp=temp -> link;
                count++;
        }
        if(pos>=count+2 || pos==0)
       {
                printf("Invalid Input please insert a valid input");
        }
        else
        {
        // Change Links
        temp = start;
        newnode->info = data;
        newnode->link = 0;
        while (i < pos - 1) {
                temp = temp->link;
                i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
}}
}
// Function to delete from the front
// of the linked list
void deleteFirst()
{
        struct node* temp;
        if (start == NULL)
                printf("\nList is empty please insert some data\n");
        else {
                temp = start;
                start = start->link;
                free(temp);
        }
}

// Function to delete from the end
// of the linked list
void deleteEnd()
{
        struct node *temp, *prevnode;
        if (start == NULL)
                printf("\nList is Empty please insert some data\n");
        else {
                temp = start;
                while (temp->link != 0) {
                        prevnode = temp;
                        temp = temp->link;
                }
                free(temp);
                prevnode->link = 0;
        }
}

// Function to delete from any specified
// position from the linked list
void deletePosition()
{
    struct node *temp=start, *position;
    int i = 1, pos;

                int count=0;
                while(temp != NULL)
                {
                        temp=temp -> link;
                        count++;
                }


    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");


    // Otherwise
    else {
        printf("\nEnter index : ");

        // Position to be deleted
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
        position =start;
        if(pos>count || pos==0)
        {
        printf("Invalid Input");
        }
        else if(pos == 1)
        {
                start=temp->link;
                free (temp);
                temp=NULL;
        }
        else{
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
	// Change Links
        position = temp->link;
        temp->link = position->link;

        // Free memory
        free(position);
    }
}}

// main func
int main()
{
        int choice;
        while (1) {

                printf("\n\t1 To see list\n");
                printf("\t2 For insertion at"
                        " starting\n");
                printf("\t3 For insertion at"
                        " end\n");
                printf("\t4 For insertion at "
                        "any position\n");
                printf("\t5 For deletion of "
                        "first element\n");
                printf("\t6 For deletion of "
                        "last element\n");
                printf("\t7 For deletion of "
                        "element at any position\n");
                printf("\t8 To exit\n");
                printf("\nEnter Choice :\n");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                        traverse();
                        break;
                case 2:
                        insertAtFront();
                        break;
                case 3:
                        insertAtEnd();
                        break;
                case 4:
                        insertAtPosition();
                        break;
                case 5:
                        deleteFirst();
                        break;
                case 6:
                        deleteEnd();
                        break;
                case 7:
                        deletePosition();
                        break;
                case 8:
                        exit(1);
                        break;
                default:
                        printf("Incorrect Choice\n");
                }
        }
        return 0;
}
