#include <stdlib.h>
#include <stdio.h>
#include "common.h"

list *list_create(int32_t size)
{
    list_t *new_list = NULL;

    new_list = (list_t *)malloc(sizeof(list_t));
    if(NULL == new_list)
    {
        return NULL;
    }

    new_list->head.data = NULL;
    new_list->head.next = &(new_list->head);
    new_list->head.prev = &(new_list->head);
    new_list->cont = 0;

    return new_list;
}

void list_destroy(list_t *list)
{
    list_t *curr_list = NULL;
    node_t *curr_node = NULL;
    node_t *temp_node = NULL;

    curr_list = list;
    if(NULL == curr_list)
    {
        return;
    }

    curr_node = curr_list->head;
    for( ; curr_node; curr_node = temp_node)
    {
        temp_node = curr_node->next;
        free(curr_node);

        curr_list->cont--;
    }

    free(curr_list);
    return;
}

int32_t list_node_append(list_t *list, const void *data)
{
    list_t *curr_list = NULL;
    node_t *curr_node = NULL;
    node_t *temp_node = NULL;
    
    curr_list = list;
    if(NULL == curr_list)
    {
        return -1;
    }

    curr_node = (node_t *)malloc(sizeof(node_t));
    if(NULL == curr_node)
    {
        printf("list_node_apend create node failed when malloced. \n");
        return -1;
    }
    curr_node->next = NULL;
    curr_node->prev = NULL;
    curr_node->data = data;

    temp_node = curr_list->head;
    if(NULL == temp_node)
    {
        temp_node = curr_node;
    }
    else
    {
        while(temp_node->next)
        {
            temp_node = temp_node->next;
        }
        temp_node->next = curr_node;
        curr_node->prev = temp_node;
    }

    return 0;
}

int32_t list_node_remove(list *list, void *value)
{
    int32_t rslt = -1;
    list_t *curr_list = NULL;
    node_t *curr_node = NULL;

    curr_list = list;
    if(NULL == curr_list)
    {
        return -1;
    }

    curr_node = curr_list->head;
    while(curr_node)
    { 
       if(curr_node->data == value)
       {
           node_t *temp_node = curr_node->next;
           temp_node->prev = curr_node->prev;
           temp_node->prev->next = temp_node;
           free(curr_node);
           curr_list->cont--;
           rslt = 0;
           break;
       }
        
       curr_node = curr_node->next;
    }

    return rslt;
}

void* list_node_obtain(list_t *list, int32_t position)
{
    list_t *curr_list = NULL;
    node_t *curr_node = NULL;

    curr_list = list;
    if(NULL == curr_list)
    {
        return NULL;
    }

    curr_node = curr_list->head;
    while(position)
    {
        curr_node = curr_node->next;
    }

    return curr_node;
}

int32_t list_node_find(list *list, void *value)
{
    int32_t indx  = 0;
    int32_t rslt  = -1;
    list_t *curr_list = NULL;
    node_t *curr_node = NULL;

    curr_list = list;
    if(NULL == curr_list)
    {
        return rslt;
    }

    curr_node = curr_list->head;
    while(curr_node)
    {
        if(curr_node->data == value)
        {
            break;
        }
        indx++;
    }

    return indx;
}
