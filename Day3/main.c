#include <stdio.h>
#include <stdlib.h>/*the standard library for memory allocation*/

/*Define the structure of a node*/
struct node
{
    int data; // Data 
    struct node* next; /*Pointer to the next node*/
};

/*Declare a global variable to store the head of the list*/
struct node* head = NULL;

/*Function to create a new node and insert it at the beginning of the list*/
void insert_at_start(int data)
{
    /*Allocate memory for the new node*/
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    /*Check if memory allocation was successful*/
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    /*Assign the data and the next pointer of the new node*/
    new_node->data = data;
    new_node->next = head;

    /*Make the new node as the head of the list*/
    head = new_node;
    printf("Inserted %d at the start of the list.\n", data);
}


/*Function to delete the first node of the list*/
void delete_from_start()
{
    /*Check if the list is empty*/
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;/*Store the head node in a temporary variable*/
    head = head->next;/*Make the head point to the next node*/

    printf("Deleted %d from the start of the list.\n", temp->data);
    free(temp);/*Free the memory of the deleted node*/
}


/*Function to display the data of all the nodes in the list*/
void display_list()
{
    /*Check if the list is empty*/
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    /*Traverse the list and print the data of each node*/
    struct node* temp = head;
    printf("The list contains: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    /*Insert some nodes at the start of the list*/
    insert_at_start(10);
    insert_at_start(20);
    insert_at_start(30);
    insert_at_start(40);

    display_list();/*Display the list*/

    /* Delete some nodes from the start of the list*/
    delete_from_start();
    delete_from_start();

    display_list();/* Display the list again*/
    return 0;
}