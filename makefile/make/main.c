/*
 * @Author: duapple
 * @Date: 2021-11-07 16:00:49
 * @LastEditTime: 2021-11-07 18:29:10
 * @LastEditors: duapple
 * @Description: Add description
 * @FilePath: \make\main.c
 * Copyright (c) 2011 duapple - All rights reserved.
 */
#include <stdio.h>
#include "cJSON.h"
#include "test.h"
#include "app.h"
#include <stdlib.h>

int main() {
    printf("makefile test\n");

    char *test = "[[3,15],\"1234\"]";

    cJSON * test_obj = cJSON_Parse(test);

    char * test_str = cJSON_PrintUnformatted(test_obj);
    printf("test_str: %s\r\n", test_str);
    free(test_str);
    cJSON_Delete(test_obj);

    test_func();

    return 0;
}