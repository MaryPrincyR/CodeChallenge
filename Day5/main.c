/*This program deletes node from the end of a singly linked list*/
#include <stdio.h>
#include <stdlib.h>

/*Define the node structure*/
struct node
{
    int data;
    struct node* next;
};

/*Function to insert a node at the end of a linked list*/
void insert_to_end(struct node** head, int new_data)
{
    /*Allocate a new node*/
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    /*If the linked list is empty, then make the new node as head*/
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    /*Else traverse till the last node*/
    struct node* last = *head;
    while (last->next != NULL)
        last = last->next;

    /*Change the next of the last node*/
    last->next = new_node;
    return;
}


/*Function to delete the last node of a linked list*/
void deleteEnd(struct node** head)
{
    /*If the linked list is empty, return*/
    if (*head == NULL)
    {
        return;
    }

    /*If the linked list has only one node, delete it and update head*/
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    /*Else traverse till the second last node*/
    struct node* second_last = *head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    /*Delete the last node and update the 'next' of the second last node*/
    free(second_last->next);
    second_last->next = NULL;
    return;
}

/*Function to print the linked list*/
void printList(struct node* node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    /*Start with the empty list*/
    struct node* head = NULL;

    /*Use the insert_to_end function to add elements to the list*/
    insert_to_end(&head, 1);
    insert_to_end(&head, 2);
    insert_to_end(&head, 3);
    printList(head);  // Prints: 1 2 3

    /*Use the deleteEnd function to delete elements from the list*/
    deleteEnd(&head);
    printList(head);  // Prints: 1 2

    return 0;
}