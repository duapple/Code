#include "list.h"
#include <stdlib.h>
#include <string.h>
#include "sal.h"

List * init_list(void)
{
    List *plist = NULL;
    plist = (List *)malloc(sizeof(List));
    if (NULL == plist) {
        return NULL;
    }
    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;

    return plist;
}

Node * create_node(void *data, p_malloc pfun_malloc, size_t size)
{
    if (NULL == data) {
        return NULL;
    }

    Node *pnode = NULL;
    pnode = (Node *)malloc(sizeof(Node));
    if (NULL == pnode) {
        return NULL;
    }
    pnode->data = pfun_malloc(size);
    if (pnode->data == NULL) {
        free(pnode);
        return NULL;
    }
    memcpy(pnode->data, data, size);
    pnode->next = NULL;

    return pnode;
}

int delete_node(Node *pnode, p_free pfun_free)
{
    SAL_CHECK_P_NULL(pnode);

    pfun_free(pnode->data);
    free(pnode);

    return SAL_OK;
}

int delete_list(List *plist, p_free pfun_free)
{
    SAL_CHECK_P_NULL(plist);

    Node *pnode = plist->head;
    for (; pnode != NULL; pnode = plist->head) {
        plist->head = plist->head->next;
        delete_node(pnode, pfun_free);
    }
    free(plist);

    return SAL_OK;
}

int add_node(List *plist, Node *pnode)
{
    SAL_CHECK_P_NULL(pnode);
    SAL_CHECK_P_NULL(plist);
    
    if (NULL == plist->head) {
        plist->head = pnode;
        plist->tail = pnode;
    }
    else {
        plist->tail->next = pnode;
        plist->tail = pnode;
    }
    plist->size++;

    return SAL_OK;
}

Node * get_node_by_index(List *plist, int index)
{
    if (NULL == plist 
     || NULL == plist->head
     || index < 1 
     || index > plist->size) {
        return NULL;
    }

    Node *pnode = plist->head;
    for (int i = 1; i < index; i++) {
        pnode = pnode->next;
    }

    return pnode;
}

int remove_node(List *plist, p_free pfun_free)
{
    SAL_CHECK_P_NULL(plist);

    if (plist->size == 1) {
        delete_node(plist->tail, pfun_free);
        plist->head = NULL;
        plist->tail = NULL;
    }
    else {
        Node *pnode = get_node_by_index(plist, plist->size - 1);
        if (NULL == pnode) {
            return SAL_ERR;
        }
        delete_node(plist->tail, pfun_free);
        plist->tail = pnode;
        plist->tail->next = NULL;
    }
    plist->size--;
    
    return SAL_OK;
}

int remove_node_by_data(List *plist, void *data, p_traverse pfun_compare, p_free pfun_free)
{
    SAL_CHECK_P_NULL(plist);
    SAL_CHECK_P_NULL(data);

    if (plist->size == 1 && 0 == pfun_compare(plist->head->data, data)) {
        remove_node(plist, pfun_free);
    }
    else {
        Node *pnode = plist->head;
        for (Node *pprior = NULL; pnode != NULL; pprior = pnode, pnode = pnode->next) {
            if (0 == pfun_compare(pnode->data, data)) {
                pprior->next = pnode->next;
                if (pnode == plist->tail) {
                    plist->tail = pprior;
                }
                delete_node(pnode, pfun_free);
                plist->size--;
            }
        }
    }
    
    return SAL_OK;
}

int get_index_by_data(List *plist, void *data, p_traverse pfun_compare)
{
    SAL_CHECK_P_NULL(plist);
    SAL_CHECK_P_NULL(data);

    Node *pnode = plist->head;
    for (int index = 1; pnode != NULL; index++, pnode = pnode->next) {
        if (0 == pfun_compare(pnode->data, data)) {
            return index;
        }
    }

    return 0;
}

Node * find_node_by_data(List *plist, void *data, p_traverse pfun_compare)
{
    if (NULL == plist || NULL == data) {
        return NULL;
    }
#if 0
    int index = get_index_by_data(plist, data);
    if (index > 0) {
        Node *pnode = NULL;
        pnode = get_node_by_index(plist, index);
        if (pnode != NULL) {
            return pnode;
        }
    }
#else
    Node *pnode = plist->head;
    for (; pnode != NULL; pnode = pnode->next) {
        if (0 == pfun_compare(pnode->data, data)) {
            return pnode;
        }
    }
#endif

    return NULL;
}

int traverse_list(List *plist, void *data, p_traverse pfun_traverse)
{
    SAL_CHECK_P_NULL(plist);

    Node *pnode = plist->head;
    for (; pnode != NULL; pnode = pnode->next) {
        pfun_traverse(pnode->data, data);
    }

    return SAL_OK;
}
