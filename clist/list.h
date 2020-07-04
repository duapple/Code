#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>

typedef void (* p_free)(void *data);
typedef void *(* p_malloc)(size_t size);
typedef int (* p_traverse)(void *nodeData, void *data);

typedef struct note_t Node;
struct note_t{
    void *data;
    Node *next;
};

typedef struct {
    Node * head;
    Node * tail;
    int size;
} List;

List * init_list(void);

int delete_list(List *plist, p_free pfun_free);

Node * create_node(void *data, p_malloc pfun_malloc, size_t size);

int delete_node(Node *pnode, p_free pfun_free);

int add_node(List *plist, Node *pnode);

int remove_node(List *plist, p_free pfun_free);

int remove_node_by_data(List *plist, void  *data, p_traverse pfun_compare, p_free pfun_free);

int traverse_list(List *plist, void *data, p_traverse p_fun);

Node * get_node_by_index(List *plist, int index);

Node * find_node_by_data(List *plist, void *data, p_traverse pfun_compare);

int get_index_by_data(List *plist, void *data, p_traverse pfun_compare);

void sort_list(List *plist);


#endif /* __LIST_H__ */
