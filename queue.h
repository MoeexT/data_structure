/*
 * Created by yuwancumian666 on 2018/10/25.
*/

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#define QUEUE_ELEMENT_TYPE int
#define TRUE 1
#define FALSE 0


// 链队列 link_queue.cpp
typedef struct Node {
    QUEUE_ELEMENT_TYPE data;
    struct Node * next;
}LinkQueueNode;

typedef struct {
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;

int InitLinkQueue(LinkQueue *Q);

int EnterLinkQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE x);

int DeleteLinkQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE *x);


// 循环队列
#define MAXSIZE 50

typedef struct {
    QUEUE_ELEMENT_TYPE elements[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

void InitCircularQueue(SeqQueue *Q);

int EnterCircularQueue(SeqQueue *Q, QUEUE_ELEMENT_TYPE x);

int DeleteCircularQueue(SeqQueue *Q, QUEUE_ELEMENT_TYPE *x);

#endif //DATA_STRUCTURE_QUEUE_H

