#include <stdio.h>
#include "q.h"
int main()
{
    printf("Hello world!");

    struct QElement *head1 = InitQueue();
    head1->payload = 1;
    struct QElement * e1 = NewItem();
    e1->payload = 5;
    AddToQueue(head1, e1);

    PrintQueue(head1);

    return 0;
}