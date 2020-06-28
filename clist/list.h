#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef void (* p_free)(void *data);
typedef void *(* p_malloc)(size_t size);
typedef void (* p_traverse)(void *data);

typedef struct {
    void *data;
    Node *next;
} Node;

typedef struct {
    Node * head;
    Node * tail;
    int size;
} List;

int init_list(List *plist);

int create_node(Node *pnode, p_malloc *pfun, void *data);

int delete_node(Node *pnode, p_free *p_fun);

int add_node(List *plist, Node *pnode);

int remove_node(List *plist, Node *pnode);

int remove_node_by_data(List *list, void  *data);

void traverse_list(List *list, p_traverse *p_fun, void *data)




#endif /* __LIST_H__ */