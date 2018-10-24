/*
 * Created by yuwancumian666 on 2018/10/23.
 * 循环链表
*/

#include<iostream>
#include "../linear_table.h"

#define STOP_CHAR '$'


void InitCLinkList(LinkList *CL) {
    // CL用来接收待初始化循环链表的头指针变量地址
    *CL = (LinkList) malloc(sizeof(Node));
    (*CL)->next = nullptr;
}

void CreateClinkList(LinkList CL) {
    // CL是初始化好的、带头节点的空循环链表的头指针，通过键盘输入元素值
    Node *rear, *s;
    char c;
    rear = CL;
    c = static_cast<char>(getchar());
    while (c != STOP_CHAR) {
        s = (Node *) malloc(sizeof(Node));
        s->data = c;
        rear->next = s;
        rear = s;
        c = static_cast<char>(getchar());
    }
    rear->next = CL;
}

LinkList merge_1(LinkList LA, LinkList LB) {
    // 将两个采用头指针的循环单链表首尾相连
    Node *p, *q;
    p = LA;
    q = LB;
    while (p->next != LA) p = p->next;
    while (q->next != LB) q = q->next;
    q->next = LA;
    p->next = LB->next;
    free(LB);
    return LA;
}

LinkList merge_2(LinkList RA, LinkList RB) {
    // 将两个采用尾指针的循环单链表首尾相连
    Node *p;
    p = RA->next;
    RA->next = RB->next->next;
    free(RB->next);
    RB->next = p;
    return RB;
}
