/*
 * Created by yuwancumian666 on 2018/10/25.
 * 链队列
*/

#include <iostream>
#include "../queue.h"

int InitLinkQueue(LinkQueue *Q) {
    // 初始化
    Q->front = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if (Q->front != nullptr) {
        Q->rear = Q->front;
        Q->front->next = nullptr;
        return TRUE;
    } else
        return FALSE;
}

int EnterLinkQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE x) {
    // 进队列
    LinkQueueNode * NewNode;
    NewNode = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if (NewNode != nullptr) {
        NewNode->data = x;
        NewNode->next = nullptr;
        Q->rear->next = NewNode;
        Q->rear = NewNode;
        return TRUE;
    } else
        return FALSE;
}

int DeleteLinkQueue(LinkQueue *Q, QUEUE_ELEMENT_TYPE *x) {
    // 出队列
    LinkQueueNode *p;
    if (Q->front == Q->rear)
        return FALSE;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    *x = p->data;
    free(p);
    return TRUE;
}

