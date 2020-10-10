#include "threads.h"
#include<stdio.h>

int global = 0;

void func1(void)
{
    int local = 0;
        
    while (1)
    {
        printf("Printing Function1: Global = %d, Local = %d\n", global, local);
        global++;
        local++;
        sleep(1);
        printf("Function1 yeilding, Global = %d, Local = %d\n", global, local);
        yield();
        printf("Function1 remainder\n");
        yield();
    }
    
}

void func2(void)
{
    int local = 0;
    while (1)
    {
        printf("Printing Function2: Global = %d, Local = %d\n", global, local);
        global++;
        local++;
        sleep(1);
        printf("Function2 yeilding, Global = %d, Local = %d\n", global, local);
        yield();
        printf("Function2 remainder\n");
        yield();
    }
}

void func3(void)
{
    int local = 0;
    while(1)
    {
        printf("Printing Function3: Global = %d, Local = %d\n", global, local);
        global++;
        local++;
        sleep(1);
        printf("Function3 yeilding, Global = %d, Local = %d\n", global, local);
        yield();
        printf("Function3 remainder\n");
        yield();
    }
    
}

int main()
{
    TCB_t* head = newQueue();
    ReadyQ = &head;
    start_thread(func1);
    start_thread(func2);
    start_thread(func3);

    run();
    return 0;
}