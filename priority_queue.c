#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

// private func
static void priority_queue_realloc(PriorityQueue *pq);
static void priority_queue_adjust_head(PriorityQueue *pq);
static void priority_queue_adjust_tail(PriorityQueue *pq);
static int priority_queue_compare(PriorityQueue *pq, int pos1, int pos2);
static void priority_queue_swap(KeyValue **nodes, int pos1, int pos2);

KeyValue *key_value_new(key_type key, void *value)
{
    KeyValue *pkv = (KeyValue *)malloc(sizeof(KeyValue));
    pkv->_key = key;
    pkv->_value = value;
    return pkv;
}

void key_value_free(KeyValue *kv, void (*freevalue)(void *))
{
    if (kv) {
        if (freevalue) {
            freevalue(kv->_value);
        }
        free(kv);
    }
}

PriorityQueue *priority_queue_new(pri_type priority) 
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->_capacity = MAX_QUEUE_SIZE;
    pq->_size = 0;
    pq->_priority = priority;
    pq->_nodes = (KeyValue **)malloc(sizeof(KeyValue *) * pq->_capacity);
    return pq;
}

void priority_queue_free(PriorityQueue *pq, void (*freevalue)(void *))
{
    if (pq) {
        for (int i = 0; i < pq->_size; i++) {
            key_value_free(pq->_nodes[i], freevalue);
        }
        free(pq->_nodes);
        free(pq);
    }
}

const KeyValue *priority_queue_top(PriorityQueue *pq) 
{
    if (pq->_size > 0) {
        return pq->_nodes[0];
    }
    return NULL;
}

KeyValue *priority_queue_dequeue(PriorityQueue *pq)
{
    KeyValue *pkv = NULL;
    if (pq->_size > 0) {
        pkv = pq->_nodes[0];
        priority_queue_adjust_head(pq);
    }
    return pkv;
}

void priority_queue_enqueue(PriorityQueue *pq, KeyValue *kv)
{
    pq->_nodes[pq->_size] = kv;
    priority_queue_adjust_tail(pq);
    if (pq->_size == pq->_capacity)
        priority_queue_realloc(pq);
}

size_type priority_queue_size(PriorityQueue *pq)
{
    return pq->_size;
}

int priority_queue_empty(PriorityQueue *pq)
{
    return pq->_size <= 0;
}

void priority_queue_print(PriorityQueue *pq)
{
    KeyValue *kv;
    printf("data in the pq->_nodes\n");
    for (int i = 0; i < pq->_size; i++) {
        printf("%d ", pq->_nodes[i]->_key);
    }
    printf("\n");
    printf("dequeue all data\n");
    while (!priority_queue_empty(pq))
    {
        kv = priority_queue_dequeue(pq);
        printf("%d ", kv->_key);
    }
    printf("\n");   
}

static void priority_queue_realloc(PriorityQueue *pq)
{
    pq->_capacity = pq->_capacity * 2;
    pq->_nodes = realloc(pq->_nodes, sizeof(KeyValue *)*pq->_capacity);
}

static void priority_queue_adjust_head(PriorityQueue *pq)
{
    int i, j, parent, left, right;
    i = 0; j = 0;
    parent = left = right = 0;
    priority_queue_swap(pq->_nodes, 0, pq->_size - 1);
    pq->_size--;
    while (i < (pq->_size - 1) / 2)     
    {
        parent = i;
        left = i * 2 + 1;
        right = left + 1;
        j = left;
        if (priority_queue_compare(pq, left, right) > 0) {
            j++;
        }
        if (priority_queue_compare(pq, parent, j) > 0) {
            priority_queue_swap(pq->_nodes, i, j);
            i = j;
        } else {
            break;
        }
    }
    
}

static void priority_queue_adjust_tail(PriorityQueue *pq)
{
    int i, parent, child;

    i = pq->_size;
    pq->_size++;
    while (i > 0)
    {
        child = i;
        parent = (child - 1) / 2;

        if(priority_queue_compare(pq, parent, child) > 0) {
            priority_queue_swap(pq->_nodes, child, parent);
            i = parent;
        } else {
            break;
        }
    }
}

static int priority_queue_compare(PriorityQueue *pq, int pos1, int pos2) 
{
    int adjust = -1;
    int r = pq->_nodes[pos1]->_key - pq->_nodes[pos2]->_key;
    if (pq->_priority == PRIORITY_MAX) {
        r *= adjust;
    }
    return r;
}

static void priority_queue_swap(KeyValue **nodes, int pos1, int pos2)
{
    KeyValue *temp = nodes[pos1];
    nodes[pos1] = nodes[pos2];
    nodes[pos2] = temp;
}
