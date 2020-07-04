#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list_custom.h"

void *student_malloc(size_t size)
{
    struct student *stu = (struct student *)malloc(size);
    return stu;
}

int student_print(void *nodeData, void *data)
{
    struct Student *stu = (struct Student *)(nodeData);
    printf("%s  %d\r\n", stu->name, stu->id);
}

int stu_name_compare(void *nodeData, void *data) 
{
    char * name1 = (char *)nodeData;
    char * name2 = (char *)data;
    if (0 == strcmp(name1, name2)) {
        return 0;
    }

    return -1;
}

void student_free(void *data)
{
    struct Student *stu = (struct Student *)data;
    free(stu);
}
