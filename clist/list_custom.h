#ifndef __LIST_CUSTOM_H__
#define __LIST_CUSTOM_H__

#include <stdio.h>

/* 在这里定义自己的链表Data内容 */
struct Student {
    char name[20];
    int id;
};

/* eg: 员工薪酬Data */
struct Worker {
    char name[20];       //姓名
    long payment;        //薪酬
    char tele[12];       //电话
};

/* 学生信息表自定义处理HANDLE */
void *student_malloc(size_t size);

int student_print(void *nodeData, void *data);

int stu_name_compare(void *nodeData, void *data);

void student_free(void *data);

/* 在这里定义Data处理Handle，eg： Worker*/

#endif /* __LIST_CUSTOM_H__ */