
#ifndef CSE430_PROJECT_2_THREADS_H
#define CSE430_PROJECT_2_THREADS_H

#include <stdlib.h>
#include "tcb.h"
#include "q.h"

// NOT supposed to have Queue parameter. Necessary for our implementation.
void start_thread(void (*function)(void), Queue * queue)
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
    AddQueue(queue, tcb);

    //end pseudo code */
}

#endif //CSE430_PROJECT_2_THREADS_H
