#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(int argv, char ** argc)
{
    cJSON * data = cJSON_CreateObject();
    cJSON * name = cJSON_CreateString("duapple");

    cJSON_AddItemToObject(data, "name", name);

    char *out = cJSON_Print(data);
    printf("%s", out);
    cJSON_Delete(data);
    free(out);

    return 0;
}