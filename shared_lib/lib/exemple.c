#include <stdio.h>

int command(void *arg)
{
    (void) arg;
    printf("Command \"Exemple\" called\n");
    return (0);
}