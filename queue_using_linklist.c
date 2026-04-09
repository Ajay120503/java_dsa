#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    return (front == NULL);
}

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Queue is Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Underflow\n");
        return;
    }

    struct Node *temp = front;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Underflow\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue is :\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}