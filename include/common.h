#ifndef __COMMON_H_
#define __COMMON_H_

/* 常用数据类型定义 */

typedef signed char        int8_t;
typedef unsigned char      uint8_t;
typedef short              int16_t;
typedef unsigned short     uint16_t;
typedef int                int32_t;
typedef unsigned int       uint32_t;


/* 常用数据结构定义及接口 */

typedef struct node_t
{
    void    *data;

    struct node_t *next;
    struct node_t *prev;
}node_t;

typedef struct list_t
{
    node_t   *head;

    int32_t  cont;
}list_t;

list_t *list_create();

int32_t list_destroy(list_t *list);

int32_t list_node_append(list_t *list, const void *data);

int32_t list_node_remove(list_t *list, void *value); 

void* list_node_obtain(list_t *list, int32_t positon);

int32_t list_node_find(list_t *list, void *value);

#endif
