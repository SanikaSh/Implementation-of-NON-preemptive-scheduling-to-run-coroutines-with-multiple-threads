#include <ucontext.h>
#include <string.h>

typedef struct TCB_t
{
    struct TCB_t * prev;
    struct TCB_t * next;
    int thread_id;
    ucontext_t context;
}TCB_t;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));
    getcontext(&tcb->context);
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);
}