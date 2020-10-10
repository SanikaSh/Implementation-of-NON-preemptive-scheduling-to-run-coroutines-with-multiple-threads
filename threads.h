#include "q.h"

TCB_t** ReadyQ; 
TCB_t* Curr_Thread;
int cntr_thread=0;

void start_thread(void (*function)(void))
{
    stack_t* stack = (stack_t*)malloc(8192*sizeof(stack_t));
    TCB_t * tcb = (TCB_t*)malloc(sizeof(TCB_t));
    init_TCB(tcb, function, stack, 8192);
    tcb->thread_id=++cntr_thread;
    AddQueue(ReadyQ,tcb);
}

void run()
{
    Curr_Thread = DelQueue(ReadyQ);
    ucontext_t parent;     // get a place to store the main context, for faking
    getcontext(&parent);   // magic sauce
    swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
}

void yield() // similar to run
{  
    TCB_t* Prev_Thread;
    AddQueue(ReadyQ, Curr_Thread);
    Prev_Thread = Curr_Thread;
    Curr_Thread = DelQueue(ReadyQ);
    swapcontext(&(Prev_Thread->context), &(Curr_Thread->context));
    //swap the context, from Prev_Thread to the thread pointed to Curr_Thread
}