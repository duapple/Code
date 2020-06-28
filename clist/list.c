#include "list.h"
#include <stdlib.h>

int InitList(List *plist)
{
    plist = (List *)malloc(sizeof(List));
    if (NULL == plist)
    {
        return -1;
    }
    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;

    return 0;
}

