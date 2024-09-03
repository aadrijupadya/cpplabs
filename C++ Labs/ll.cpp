#include <cstddef>
#include <iostream>

using namespace std;

// need to declare a node that represents each block of our list

class Node
{
public:
    int data;
    Node *next;
};

void print_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// insert at beginning of linked list
void push(struct Node **head_ptr, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ptr;
    *head_ptr = new_node;
}

void append(struct Node **head_ptr, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    Node *temp = *head_ptr;
    new_node->data = new_data;
    new_node->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertBefore(struct Node **head_node, struct Node *next_node, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    Node *temp = *head_node;
    while (temp->next != next_node)
    {
        temp = temp->next;
    }
    new_node->next = next_node;
    temp->next = new_node;
}

void deleteNode(struct Node *target_node)
{
    if (target_node->next == NULL)
    {
        free(target_node);
        return;
    }

    Node *temp = target_node->next;
    target_node->data = temp->data;
    target_node->next = temp->next;
    free(temp);
}

int findNthLast(struct Node **head_node, int n)
{
    vector<int> a;
    int length = 0;
    Node *temp = *head_node;
    while (temp != NULL)
    {
        a.push_back(temp->data);
        temp = temp->next;
        length++;
    }
    return a[length - n];
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print_list(head);
    push(&head, 0);
    print_list(head);

    append(&head, 4);
    print_list(head);

    insertAfter(third, 3);
    print_list(head);

    insertBefore(&head, second, 1);
    print_list(head);

    deleteNode(third);
    print_list(head);

    cout << findNthLast(&head, 1) << endl;
}
