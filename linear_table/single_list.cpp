/*
 * Created by yuwancumian666 on 2018/10/23.
 * 单链表
*/

#include <iostream>
#include "../linear_table.h"

#define STOP_CHAR '$'

void init_list(LinkList *L)
// 初始化单链表
{
    *L = (LinkList) malloc(sizeof(Node));
    (*L)->next = nullptr;
}

void create_from_head(LinkList L)
/* 头插法建立单链表
 * L是带头节点的空链表头指针，通过键盘输入表中元素值建立单链表 L
 * */
{
    Node *s;
    char c;
    while (true)
    {
        c = getchar();
        if (c != STOP_CHAR)
        {
            s = (Node *) malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        } else break;
    }
}

void create_from_tail(LinkList L)
// 尾插法
{
    Node *r, *s;
    int flag = 1;
    char c;
    r = L;
    while (flag)
    {
        c = getchar();
        if (c != STOP_CHAR)
        {
            s = (Node *) malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else
        {
            flag = 0;
            r->next = nullptr;
        }
    }
}

Node *get(LinkList L, int i)
// 查找第i个节点，若找到则返回该节点的存储位置，否则返回null
{
    int j;
    Node *p;
    if (i <= 0) return nullptr;
    p = L;
    j = 0;
    while ((p->next != nullptr) && (j < i))
    {
        p = p->next;
        j++;
    }
    if (i == j) return p;
    else return nullptr;
}

Node *locate(LinkList L, ElemType key)
// 在单链表L中查找第一个值为key的节点并返回该节点的位置p，反之返回null
{
    Node *p;
    p = L->next;
    while (p != nullptr)
        if (p->data != key)
            p = p->next;
        else break;
    return p;
}

