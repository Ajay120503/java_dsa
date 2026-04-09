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
        tail->next = head; // 🔁 CHANGE: circular link
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head; // 🔁 CHANGE
    }
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
        tail->next = head; // 🔁 CHANGE
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // 🔁 CHANGE
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

    for (int i = 1; i < pos - 1 && temp->next != head; i++) // 🔁 CHANGE
    {
        temp = temp->next;
    }

    if (temp->next == head && pos != 2)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) // 🔁 CHANGE
    {
        tail = newNode;
    }

    tail->next = head; // 🔁 CHANGE
}

void display()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;

    printf("List is : ");
    do // 🔁 CHANGE (do-while for circular)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void search(int key)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;

    do // 🔁 CHANGE
    {
        if (temp->data == key)
        {
            printf("Key Found at pos %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Key not found\n");
}

void count()
{
    if (head == NULL)
    {
        printf("Count is : 0\n");
        return;
    }

    struct Node *temp = head;
    int count = 0;

    do // 🔁 CHANGE
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    printf("Count is : %d\n", count);
}

void deleteAtFirst()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head == tail)
    {
        free(head);
        head = tail = NULL;
        return;
    }

    struct Node *temp = head;
    head = head->next;
    tail->next = head; // 🔁 CHANGE

    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head == tail)
    {
        free(head);
        head = tail = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next != tail) // 🔁 CHANGE
    {
        temp = temp->next;
    }

    free(tail);
    tail = temp;
    tail->next = head; // 🔁 CHANGE
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

    while (temp->next != head && temp->next->data != value) // 🔁 CHANGE
    {
        temp = temp->next;
    }

    if (temp->next == head)
    {
        printf("Value not found\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == tail)
    {
        tail = temp;
    }

    tail->next = head; // 🔁 CHANGE

    free(delNode);
}

int main()
{
    insertAtFirst(10);
    insertAtEnd(120);
    insertAtEnd(50);
    insertAtFirst(30);
    insertAtFirst(50);
    insertAtEnd(111);

    display();

    printf("\n");

    search(30);
    search(111);
    search(1111);

    count();

    deleteAtFirst();
    deleteAtEnd();

    display();

    printf("\n");

    deleteByValue(10);

    display();

    return 0;
}