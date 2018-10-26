/*
 * Created by yuwancumian666 on 2018/10/25.
 * 循环队列
*/

#include "../queue.h"

void InitCircularQueue(SeqQueue *Q) {
    // 初始化
    Q->front = Q->rear = 0;
}

int EnterCircularQueue(SeqQueue *Q, QUEUE_ELEMENT_TYPE x) {
    // 进队列
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return FALSE;
    Q->elements[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return TRUE;
}

int DeleteCircularQueue(SeqQueue *Q, QUEUE_ELEMENT_TYPE *x) {
    // 出队列
    if(Q->front == Q->rear)
        return FALSE;
    *x = Q->elements[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return TRUE;
}

