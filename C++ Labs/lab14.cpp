// Aadrij Upadya
// December 4th, 2023
// Linked List Programs
// Write a program that manages a linked list with a bunch of functions

#include <iostream>
#include <cstdlib>
using namespace std;

// creating node structure that can hold data and point to next node
struct a_node
{
    int number;
    a_node *next_node;
};

// declaring global linked list for usage

a_node *linked_list = new a_node;

/**
 * Inserts a node with the given data to the head of a list
 *
 * @param num value of the node that goes into the list
 */
void insert_node(int num)
{
    a_node *temp_node = new a_node;     // create a temporary empty node
    temp_node->number = num;            // fill our temporary node with the given value
    temp_node->next_node = linked_list; // point to the next node
    linked_list = temp_node;            // our list now uses this node as a pointer
}

/**
 * Deletes node from head of list
 *
 */
int delete_node()
{
    a_node *ptr_head = linked_list;       // linked list currently points to head node
    int deleted_data = ptr_head->number;  // store the number we are deleting so we can return it
    linked_list = linked_list->next_node; // reassign to next node
    delete ptr_head;
    return deleted_data;
}

/**
 * Traverses a linked list and prints each element
 *
 */
void print_list()
{
    a_node *temp_node = linked_list; // create a temporary head pointer

    while (temp_node != NULL) // while our nodes are not null (meaning there is still more data)
    {
        cout << temp_node->number << " "; // print the stored data
        temp_node = temp_node->next_node; // move on to next element by pointing to next node
    }
    cout << endl;
}

int main()
{
    // initialize our first_node with some data and point it to null
    linked_list->number = 100;
    linked_list->next_node = NULL;

    // second node initialization for testing purpos es

    a_node *second_node = new a_node;
    second_node->number = 150;
    linked_list->next_node = second_node;

    // Printing out of first list (only 2 nodes, should print 100 150)
    cout << "Very First List: ";
    print_list();

    // Printing out our list after inserting three nodes (should print 400 300 200 100 150)

    cout << "Inserted Number List: ";

    insert_node(200);
    insert_node(300);
    insert_node(400);

    print_list();

    // Printing out our list after deleting top two nodes (should print 200 100 150)

    cout << "Deleted Element: " << delete_node() << endl; // returning our deleted element
    cout << "Deleted Element: " << delete_node() << endl;

    cout << "New List (Deleted Elements): ";

    print_list();
}