#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct node
{
    int32_t val;
    struct node *next;
};

int32_t list_init(struct node **node_list)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));

    if (node_list == NULL)
    {
        printf("LINE: [%d] FUNC: [%s] pointer is null\r\n", __LINE__, __func__);
        return 1;
    }
    cur->next = NULL;
    cur->val = 0;
    *node_list = cur;

    // *node_list = (struct node *)malloc(sizeof(struct node));
    // (*node_list)->val = 0;
    // (*node_list)->next = NULL;
    
    return 0;
}

int32_t list_size_get(struct node *node_list, int32_t *size)
{
    int16_t index = 0;
    struct node *cur = node_list;

    while(NULL != cur->next)
    {
        cur = cur->next;
        index++;
    }
    *size = index;

    return 0;
}

int32_t node_get(struct node *node_list, int32_t index, int32_t *val)
{
    struct node *cur;
    struct node *insert_node = NULL;
    int32_t size = 0;
    int32_t count = index;

    cur = node_list;
    list_size_get(node_list, &size);

    if (0 == index || size < index)
    {
        printf("function:[%s], line:[%d], index is wrong!\r\n", __func__, __LINE__);
        return 1;
    }

    while(0 != count)
    {
        cur = cur->next;
        count--;
    }

    *val = cur->val;

    printf("function:[%s], line:[%d], node index %d, value: %d\r\n", __func__, __LINE__, index, cur->val);

    return 0;
}

int32_t add_tail(struct node *node_list, int32_t val)
{
    struct node *cur = node_list;
    struct node *pnode = NULL;

    while(NULL != cur->next)
    {
        cur = cur->next;
    }
    pnode = (struct node*)malloc(sizeof(struct node));
    pnode->val = val;

    cur->next = pnode;

    return 0;
}

int32_t print_list(struct node *node_list)
{
    struct node *cur = node_list;

    while (NULL != cur->next)
    {
        cur = cur->next;
        printf("function:[%s], line:[%d], value: %d\r\n", __func__, __LINE__, cur->val);
    }

    return 0;
}
int32_t add_head(struct node *node_list, int32_t val)
{
    struct node *pnode = (struct node *)malloc(sizeof(struct node));

    pnode->val = val;
    pnode->next = node_list->next;
    node_list->next = pnode;

    return 0;
}
int32_t add_at_index_before(struct node *node_list, int32_t index, int32_t val)
{
    struct node *cur;
    struct node *prev_cur = NULL;
    struct node *insert_node = NULL;
    int32_t size = 0;

    cur = node_list;
    list_size_get(node_list, &size);

    if (0 == index || size < index)
    {
        printf("function:[%s], line:[%d], index is wrong!\r\n", __func__, __LINE__);
        return 1;
    }

    while(0 != index)
    {
        prev_cur = cur;
        cur = cur->next;
        index--;
    }

    insert_node = (struct node *)malloc(sizeof(struct node));
    insert_node->val = val;
    insert_node->next = prev_cur->next;
    prev_cur->next = insert_node;

    return 0;
}

int32_t add_at_index_after(struct node *node_list, int32_t index, int32_t val)
{
    struct node *cur;
    struct node *insert_node = NULL;
    int32_t size = 0;

    cur = node_list;
    list_size_get(node_list, &size);

    if (0 == index || size < index)
    {
        printf("function:[%s], line:[%d], index is wrong!\r\n", __func__, __LINE__);
        return 1;
    }

    while(0 != index)
    {
        cur = cur->next;
        index--;
    }

    insert_node = (struct node *)malloc(sizeof(struct node));
    insert_node->val = val;
    insert_node->next = cur->next;
    cur->next = insert_node;

    return 0;
}

int32_t remove_elements(struct node *node_list, int32_t val)
{
    struct node *cur;
    struct node *remove_node = NULL;

    cur = node_list;

    while(NULL != cur->next)
    {
        if (cur->next->val == val)
        {
            remove_node = cur->next;
            cur->next = cur->next->next;
            free(remove_node);
        }
        // 这里不加else会出现段错误，因为cur指针往下多移来一位
        // cur = cur->next;
        // printf("function:[%s], line:[%d]\r\n", __func__, __LINE__);
        else
        {
            cur = cur->next;
            printf("function:[%s], line:[%d]\r\n", __func__, __LINE__);
        }
        
    }

    return 0;
}

int32_t remove_node_index(struct node *node_list, int32_t index)
{
    struct node *cur;
    struct node *remove_node = NULL;
    struct node *prev = NULL;
    int32_t size = 0;

    cur = node_list;
    list_size_get(node_list, &size);

    if (0 == index || size < index)
    {
        printf("function:[%s], line:[%d], index is wrong!\r\n", __func__, __LINE__);
        return 1;
    }

    // while(0 != index)
    // {
    //     prev = cur;
    //     cur = cur->next;
    //     index--;
    // }

    // remove_node = cur;
    // prev->next = prev->next->next;
    // free(remove_node);

    while(--index)
    {
        cur = cur->next;
        // index--;
    }

    remove_node = cur->next;
    cur->next = cur->next->next;
    free(remove_node);

    return 0;
}


int32_t main()
{
    struct node *mylist;
    int32_t size = 0;
    int32_t node_value = 0;

    // mylist = (struct node*)malloc(sizeof(struct node));
    list_init(&mylist);

    add_tail(mylist, 1);
    add_tail(mylist, 1000);
    add_head(mylist, 300);

    // add_at_index_before(mylist, 3, 435);
    add_at_index_after(mylist, 1, 900);
    add_head(mylist, 1000);

    print_list(mylist);

    list_size_get(mylist, &size);
    printf("function:[%s], line:[%d], list size: %d\r\n", __func__, __LINE__, size);

    // node_get(mylist, 4, &node_value);
    // remove_elements(mylist, 1000);
    remove_node_index(mylist, 2);

    print_list(mylist);
    
    return 0;
}