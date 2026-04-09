#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(int value, int pos)
{
    if (pos == 1)
    {
        insertAtFirst(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    for (int i = 1; pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid psotion\n");
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL)
    {
        tail = newNode;
    }
}

void display()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void search(int key)
{
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Key Fount at the pos %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Key not found\n");
}

void count()
{
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    printf("Count is : %d\n", count);
}

void deleteAtFirst()
{

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head == NULL)
    {
        tail = NULL;
    }

    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = tail = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    tail = temp;
}

void deleteByValue(int value)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->data == value)
    {
        deleteAtFirst();
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("value not fount\n");
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == tail)
    {
        tail = temp;
    }

    free(delNode);
}

int main()
{

    display();

    insertAtFirst(10);
    insertAtEnd(120);
    insertAtEnd(50);
    insertAtFirst(30);
    insertAtFirst(50);
    insertAtEnd(111);

    search(30);
    search(111);
    search(1111);

    display();

    count();

    deleteAtFirst();
    deleteAtEnd();

    display();

    deleteByValue(10);

    display();

    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(int value, int pos)
{
    if (pos == 1)
    {
        insertAtFirst(value);
        return;
    }

    Node *newNode = createNode(value);
    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL)
        tail = newNode;
}

void display()
{
    Node *temp = head;

    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int key)
{
    Node *temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Key found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Key not found\n");
}

void deleteAtFirst()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head == NULL)
        tail = NULL;

    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = tail = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    tail = temp;
}

void deleteByValue(int value)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->data == value)
    {
        deleteAtFirst();
        return;
    }

    Node *temp = head;

    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Value not found\n");
        return;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == tail)
        tail = temp;

    free(delNode);
}

int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtFirst(5);
    insertAtFirst(50);

    display();

    deleteByValue(30);
    display();

    return 0;
}

*/