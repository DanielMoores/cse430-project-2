#include <stdio.h>
#include "q.h"
int main()
{
    TCB_t * e1 = NewItem();
    TCB_t * e2 = NewItem();
    TCB_t * e3 = NewItem();
    TCB_t * e4 = NewItem();
    TCB_t * e5 = NewItem();
    TCB_t * e6 = NewItem();
    TCB_t * e7 = NewItem();

    Queue * queue = InitQueue();
    AddQueue(queue, e1);
    AddQueue(queue, e2);
    AddQueue(queue, e3);
    AddQueue(queue, e4);
    AddQueue(queue, e5);
    AddQueue(queue, e6);
    AddQueue(queue, e7);

    PrintQueue(queue);

    RotateQ(queue);
    RotateQ(queue);
    RotateQ(queue);

    printf("\n\n\n");

    PrintQueue(queue);

    printf("\n\n\n");


    printf("\n%d", DelQueue(queue)->id);
    printf("\n%d", DelQueue(queue)->id);
    printf("\n%d", DelQueue(queue)->id);
    printf("\n%d", DelQueue(queue)->id);
    printf("\n%d", DelQueue(queue)->id);
    printf("\n%d", DelQueue(queue)->id);
    printf("\n%d", DelQueue(queue)->id);

    printf("\n\n\n");

    PrintQueue(queue);

    return 0;
}