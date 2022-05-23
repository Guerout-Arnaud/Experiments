#include <stdio.h>

int command(void *arg)
{
    (void) arg;
    printf("Command \"Template\" called\n");
    return (0);
}