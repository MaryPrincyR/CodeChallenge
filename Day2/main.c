/*This code creates a simple linked list with three nodes and prints the data in each node.*/

#include <stdio.h>
#include <stdlib.h>

/*Define the node structure.The Node structure represents a node in the linked list.
Each node has an integer data and a pointer next to the next node in the list.*/

typedef struct node
{
    int data;
    struct node* next;
} node;

/*Function to create a new node.This function creates a new node with the given data.
It allocates memory for the new node using malloc, assigns the data, and sets the
next pointer to NULL.*/

node* create_node(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/*Function to print the list.This function prints the data in each node of the list.
It starts from the head of the list and follows the next pointers to access each node.*/
void print(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    node* head = create_node(1);//creates the first node with data 1 and assigns its address to head.
    head->next = create_node(2);//creates the second node with data 2 and links it to the first node.
    head->next->next = create_node(3);//creates the third node with data 3 and links it to the second node.
    print(head);//prints the data in each node.
    return 0;
}