#include <stdio.h>

int command(void *arg)
{
    (void) arg;
    printf("Command \"Test\" called\n");
    return (0);
}