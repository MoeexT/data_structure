/*
 * Created by yuwancumian666 on 2018/10/23.
 * 单链表
*/

#include <iostream>
#include "../linear_table.h"

#define STOP_CHAR '$'


void InitList(LinkList *L) {
// 初始化单链表
    *L = (LinkList) malloc(sizeof(Node));
    (*L)->next = nullptr;
}

void CreateFromHead(LinkList L) {
/* 头插法建立单链表
 * L是带头节点的空链表头指针，通过键盘输入表中元素值建立单链表 L
 * */
    Node *s;
    char c;
    while (true) {
        c = static_cast<char>(getchar());
        if (c != STOP_CHAR) {
            s = (Node *) malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        } else break;
    }
}

void CreateFromTail(LinkList L) {
// 尾插法
    Node *r, *s;
    int flag = 1;
    char c;
    r = L;
    while (flag) {
        c = static_cast<char>(getchar());
        if (c != STOP_CHAR) {
            s = (Node *) malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        } else {
            flag = 0;
            r->next = nullptr;
        }
    }
}

Node *Get(LinkList L, int i) {
// 查找第i个节点，若找到则返回该节点的存储位置，否则返回null
    int j;
    Node *p;
    if (i <= 0) return nullptr;
    p = L;
    j = 0;
    while ((p->next != nullptr) && (j < i)) {
        p = p->next;
        j++;
    }
    if (i == j) return p;
    else return nullptr;
}

Node *Locate(LinkList L, ELEMENT_TYPE key) {
// 在单链表L中查找第一个值为key的节点并返回该节点的位置p，反之返回null
    Node *p;
    p = L->next;
    while (p != nullptr)
        if (p->data != key)
            p = p->next;
        else break;
    return p;
}

int ListLength(LinkList L) {
// 单链表长度
    Node *p = L->next;
    int j = 0;
    while ((p = p->next) != nullptr)
        j++;
    return j;
}

int InsList(LinkList L, int i, ELEMENT_TYPE e) {
// 插入结点
    Node *pre, *s;
    int k;
    if (i <= 0)
        return ERROR;
    pre = L;
    k = 0;
    while (pre != nullptr && k < i - 1) {
        pre = pre->next;
        k++;
    }
    if (pre == nullptr) {
        printf("插入位置不合理");
        return ERROR;
    }
    s = (Node *) malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
    return OK;
}

int DelList(LinkList L, int i, ELEMENT_TYPE *e) {
// 删除节点
    Node *pre, *r;
    int k;
    pre = L;
    k = 0;
    while ((pre = pre->next) != nullptr && k < i - 1)
        k++;
    if (pre->next == nullptr) {
        printf("删除位置不合理");
        return ERROR;
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);
    return OK;
}

LinkList MergeLinkList(LinkList LA, LinkList LB) {
// 合并有序单链表
    Node *pa, *pb, *r;
    LinkList LC;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next = nullptr;
    r = LC;
    while (pa != nullptr && pb != nullptr) {
        if (pa->data <= pb->data) {
            r->next = pa;
            r = pa;
            pa = pa->next;
        } else {
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    if (pa)
        r->next = pa;
    else
        r->next = pb;
    free(LB);
    return LC;
}












