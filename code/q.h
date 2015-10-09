#ifndef CSE430_PROJECT_2_Q_H
#define CSE430_PROJECT_2_Q_H

// Define an easy to use memory allocation method.
#include <stdlib.h>

#define ALLOC(t) (t*) calloc(1, sizeof(t))

struct QElement
{
    struct QElement * previous;
    struct QElement * next;
    int payload;
} QElement;

struct QElement * NewItem()
{
    struct QElement * element = ALLOC(struct QElement);
    element->previous = NULL;
    element->next = NULL;
    element->payload = -1;
    return element;
}

struct QElement * InitQueue()
{
    struct QElement * head = ALLOC(struct QElement);
    printf("\nNew Queue\n");
    return head;
}

void AddToQueue(struct QElement * head, struct QElement * element)
{
    printf("\n1 Added Successfully");
    if(head == NULL)
    {
        printf("\n1 Head Null");
        head = element;
        head->previous = head;
        head->next = head;
        printf("\n2 Head Null");
    }
    else
    {
        printf("\n1 Head Not Null");
        struct QElement * tail = head->previous;
        printf("\ntail = head->previous;");
        tail->next = element;
        printf("\ntail->next = element;");
        element->previous = tail;
        printf("\nelement->previous = tail;");
        tail = tail->next;
        printf("\ntail = tail->next;");

        // To make queue circular
        tail->next = head;
        printf("\ntail->next = head;");
        head->previous = tail;
        printf("\nhead->previous = tail;");

        printf("\n2 Head Not Null");
    }
    printf("\n2 Added Successfully");
}

struct QElement * DelQueue(struct QElement * head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        struct QElement * temp = head;
        struct QElement * tail = head->previous;

        // Only 1 element
        if(head->next == head)
        {
            head = NULL;
        }
        // Multiple elements
        else
        {
            head = head->next;
            // To make queue circular
            head->previous = tail;
            tail->next = head;
        }
        return temp;
    }
}

void Rotate(struct QElement * head)
{
    head = head->next;
}

void PrintQueue(struct QElement * head)
{
    struct QElement * temp = head;

    // No elements
    if(head == NULL)
    {
        printf("\nEmpty Queue");
        return;
    }
    // Only 1 element
    else if(temp->next == head)
    {
        printf("\n%d", temp->payload);
        return;
    }
    // Multiple elements
    else
    {
        printf("\n%d", temp->payload);
        temp = temp->next;
        while(temp != head)
        {
            printf("\n%d", temp->payload);
            temp = temp->next;
        }
    }

}

void FreeQueue(struct QElement * head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        struct QElement * next = head->next;
        free(head);
        head = NULL;
        FreeQueue(next);
    }
}

#endif //CSE430_PROJECT_2_Q_H
