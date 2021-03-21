#include <stdio.h>
#include "onvif.h"

int main(int argv, char ** argc)
{
    if (onvif_main(argv, argc) != 0)
    {
        printf("error: onvif main failed\r\n");
    }

    while(1)
    {
        ;
    }

    return 0;
}