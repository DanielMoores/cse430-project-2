
#ifndef CSE430_PROJECT_2_THREADS_H
#define CSE430_PROJECT_2_THREADS_H

#include <stdlib.h>
#include "q.h"

void start_thread(void (*function)(void))
{
    // begin pseudo code
    // allocate a stack (via malloc) of a certain size
    // (choose 8192)
    int stack_size = 8192;
    void * stackP = malloc(stack_size);

    // allocate a TCB (via malloc)
    TCB_t * tcb = ALLOC(TCB_t);     // Uses macro from q.h

    // call init_TCB with appropriate arguments
    init_TCB(tcb, function, stackP, stack_size);

    // call addQ to add this TCB into the “RunQ” which is a
    // global header pointer
    AddQueue(runQ, tcb);

    //end pseudo code */
}

void run()
{
    ucontext_t parent;  // Get a place to store the main context, for faking
    getcontext(&parent);    // Magic sauce
    swapcontext(&parent, &runQ->head->context); // Start the first thread.
}

void yield()
{
    ucontext_t current_context = runQ->head->context;
    getcontext(&current_context); // TODO determine if needed?
    RotateQ(runQ);
    swapcontext(&current_context, &runQ->head->context);
}

#endif //CSE430_PROJECT_2_THREADS_H
