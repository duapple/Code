#include <stdio.h>
#include "util.h"
#include "cJSON.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    cJSON * test = NULL;
    char * str = util_load_file("test.json");
    if (str) {
        test = cJSON_Parse(str);
    }

    if (!str) {
        test = cJSON_CreateObject();
    }

    cJSON * nameJSON = cJSON_GetObjectItem(test, "name");
    if (nameJSON) {
        printf("name: %s\r\n", nameJSON->valuestring);
    }

    cJSON * IDJSON = cJSON_GetObjectItem(test, "id");
    if (IDJSON) {
        printf("ID: %d\r\n", atoi(IDJSON->valuestring));
    }

    cJSON * gradeJSON = cJSON_GetObjectItem(test, "grade");
    if (gradeJSON) {
        cJSON *ch = cJSON_GetObjectItem(gradeJSON, "Chinese");
        if (ch) {
            printf("Chinese: %d\r\n", atoi(ch->valuestring));
        }
        cJSON *ma = cJSON_GetObjectItem(gradeJSON, "Math");
        if (ma){
            printf("Math: %d\r\n", atoi(ma->valuestring));
        }
        cJSON *en = cJSON_GetObjectItem(gradeJSON, "English");
        if (en) {
            printf("English: %d\r\n", atoi(en->valuestring));
        }

        cJSON *mu = cJSON_GetObjectItem(gradeJSON, "Music");
        if (mu) {
            cJSON *p_key = cJSON_GetObjectItem(mu, "one");
            if (p_key) {
                printf("one: %s\r\n", p_key->valuestring);
            }
            // cJSON_DeleteItemFromObject(mu, "one");
            // cJSON_free(p_key);
            // printf("one: %s\r\n", p_key->valuestring);
            p_key = cJSON_GetObjectItem(mu, "two");
            if (p_key) {
                printf("two: %s\r\n", p_key->valuestring);
            }
        }

        // cJSON_DetachItemViaPointer(gradeJSON, mu);
        // cJSON_DeleteItemFromObject(test, "id");
        cJSON * newItem = cJSON_CreateArray();
        cJSON_AddItemToObject(test, "test", newItem);
        cJSON * value_string = cJSON_CreateString("98");
        // cJSON *new = cJSON_CreateStringReference("id");
        if (cJSON_GetObjectItem(newItem, "id")) {
            cJSON_ReplaceItemInObject(newItem, "id", value_string);
        }
        else {
            cJSON_AddItemToObject(newItem, "id", value_string);
        }

        strcpy(value_string->valuestring, "66");
        
        // cJSON_ReplaceItemInObject(test, "id", newItem);
        // cJSON_AddItemToObject(mu, "three", value_string);

    }
    
    cJSON * protocolsJSON = cJSON_GetObjectItem(test, "protocols");
    int size = cJSON_GetArraySize(protocolsJSON);
    for (int i = 0; i < size; i++) {
        cJSON * protocolArray = cJSON_GetArrayItem(protocolsJSON, i);
        cJSON * enabled = cJSON_GetObjectItem(protocolArray, "enabled");
        if (enabled) {
            printf("enabled: %d, ", atoi(enabled->valuestring));
        }
        cJSON * type = cJSON_GetObjectItem(protocolArray, "type");
        if (type) {
            printf("type: %d, ", atoi(type->valuestring));
        }
        cJSON * port = cJSON_GetObjectItem(protocolArray, "port");
        if (port) {
            printf("port: %d, ", atoi(port->valuestring));
        }
    }

    size = cJSON_GetArraySize(protocolsJSON);
    printf("size : %d\r\n", size);

    // strcpy(IDJSON->valuestring, "100");
    
    // cJSON_DetachItemViaPointer(test, gradeJSON);
    

    putchar('\n');
    char *write_buf = cJSON_Print(test);
    printf("%s", write_buf);
    
    FILE* fp = fopen("test.json", "wb");
    fwrite(write_buf, 1, strlen(write_buf), fp);
    fclose(fp);

    return 0;
}
