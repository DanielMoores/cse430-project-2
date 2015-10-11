#ifndef CSE430_PROJECT_2_Q_H
#define CSE430_PROJECT_2_Q_H

// Define an easy to use memory allocation method.
#include <stdlib.h>
#include <stdio.h>
#include "tcb.h"

#define ALLOC(t) (t*) calloc(1, sizeof(t))

int element_counter = 0;

typedef struct Queue
{
    struct TCB_t * head;
} Queue;

Queue * runQ;

TCB_t * NewItem();
Queue * InitQueue();
void AddQueue(struct Queue * queue, struct TCB_t * tcb);
TCB_t * DelQueue(struct Queue * queue);
void RotateQ(struct Queue * queue);

struct TCB_t * NewItem()
{
    TCB_t * element = ALLOC(struct TCB_t);
    element->prev = NULL;
    element->next = NULL;
    element->id = ++element_counter;
    return element;
}

struct Queue * InitQueue()
{
    return ALLOC(struct Queue);
}

void AddQueue(struct Queue * queue, struct TCB_t * element)
{
    if(queue->head == NULL)
    {
        queue->head = element;
        queue->head->prev = queue->head;
        queue->head->next = queue->head;
    }
    else
    {
        TCB_t * tail = queue->head->prev;
        tail->next = element;
        element->prev = tail;
        tail = tail->next;

        // To make queue circular
        tail->next = queue->head;
        queue->head->prev = tail;
    }
}

struct TCB_t * DelQueue(struct Queue * queue)
{
    // No elements
    if(queue->head == NULL)
    {
        return NULL;
    }
    // One element
    else if (queue->head->next == queue->head)
    {
        TCB_t * temp = queue->head;
        queue->head = NULL;
        return temp;
    }
    // Multiple elements
    else
    {
        TCB_t * temp = queue->head;
        TCB_t * tail = queue->head->prev;

        // Only 1 element
        if(queue->head->next == queue->head)
        {
            queue->head = NULL;
        }
            // Multiple elements
        else
        {
            queue->head = queue->head->next;
            // To make queue circular
            queue->head->prev = tail;
            tail->next = queue->head;
        }
        return temp;
    }
}

void RotateQ(struct Queue * queue)
{
    queue->head = queue->head->next;
}

void PrintQueue(struct Queue * queue)
{
    TCB_t * temp = queue->head;

    // No elements
    if(queue->head == NULL)
    {
        printf("\nEmpty Queue");
        return;
    }

    // Only 1 element
    else if(temp->next == queue->head)
    {
        printf("\nElement %d", queue->head->id);
        return;
    }

    // Multiple elements
    else
    {
        // If this wasn't here it wouldn't pass initial check.
        printf("\nElement %d", temp->id);
        temp = temp->next;
        while(temp != queue->head)
        {
            printf("\nElement %d", temp->id);
            temp = temp->next;
        }
    }
}

void FreeQueue(struct Queue * queue)
{
    TCB_t * head;
    while(head != NULL)
    {
        TCB_t * temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

#endif //CSE430_PROJECT_2_Q_H
