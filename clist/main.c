#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list_custom.h"


int main()
{
    List *students;
    /* 初始化一个空链表 */
    students = init_list();
    struct Student std[5] = {
        {"李明", 2001},
        {"王强", 2002},
        {"徐晓丽", 2003},
        {"张强", 2004}, 
        {"李伟", 2005}
    };
    /* 将结构体数据装载到链表中 */
    for (int i = 0; i < 5; i++) {
        Node *student = create_node(std + i, student_malloc, sizeof(struct Student));
        add_node(students, student);
    }

    /* 遍历链表，打印学生信息 */
    printf("\r\n------学生排名成绩表-------\r\n");
    traverse_list(students, NULL, student_print);
    printf("-------------------------\r\n\r\n");

    /* 假设链表的顺序是按照成绩排名的，取得第3名的学生信息 */
    Node *pnode = get_node_by_index(students, 3);
    struct Student * stu3 = (struct Student *)(pnode->data);
    printf("第三名同学信息 name : %s,  id : %d\r\n", stu3->name, stu3->id);

    /* 找到名字叫张强的学生信息 */
    pnode = find_node_by_data(students, "张强", stu_name_compare);
    if (NULL == pnode) {
        printf("查无此人（张强）\r\n");
    }
    else {
        struct Student * stu = (struct Student *)(pnode->data);
        printf("张强 name : %s,  id : %d\r\n", stu->name, stu->id);
    }

    /* 假设链表的顺序是按照成绩排名的，取得李明同学的名次 */
    int rank = get_index_by_data(students, "李明", stu_name_compare);
    if (rank < 1) {
        printf("李明未上榜\r\n");
    }
    else {
        printf("李明的排名： %d\r\n", rank);
    }

    /* 王强同学考试作弊，踢出成绩排名表单 */
    remove_node_by_data(students, "王强", stu_name_compare, student_free);
    printf("\r\n------学生排名成绩表-------\r\n");
    traverse_list(students, NULL, student_print);
    printf("-------------------------\r\n\r\n");

    delete_list(students, student_free);

    /* 初始化工人信息链表 */
    List *worker = init_list();

    return 0;
}