/*
    cite:https://www.cnblogs.com/this-543273659/archive/2011/07/31/2122639.html
    modified:
        fix priority_queue_tail();
*/
#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUQ_H_
#define PRIORITY_MAX 1
#define PRIORITY_MIN 2
#define MAX_QUEUE_SIZE 10000
typedef int key_type;
typedef int size_type;
typedef int pri_type;

typedef struct key_value_struct
{
    int _key;
    void *_value;
}KeyValue;

KeyValue *key_value_new(key_type k, void *value);
void key_value_free(KeyValue *kv, void (*freevalue)(void *));

typedef struct priority_queue_s
{
    KeyValue **_nodes;
    size_type _size;
    size_type _capacity;
    pri_type _priority;
}PriorityQueue;

PriorityQueue *priority_queue_new(pri_type priority);
void priority_queue_free(PriorityQueue *pq, void (*freevalue)(void *));
const KeyValue *priority_queue_top(PriorityQueue *pq);
KeyValue *priority_queue_dequeue(PriorityQueue *pq);
void priority_queue_enqueue(PriorityQueue *pq, KeyValue *kv);
size_type priority_queue_size(PriorityQueue *pq);
int priority_queue_empty(PriorityQueue *pq);
void priority_queue_print(PriorityQueue *pq);

#endif
