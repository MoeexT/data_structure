/*
 * Created by yuwancumian666 on 2018/10/23.
 * 双向链表
*/

#include <iostream>
#include "../linear_table.h"

using namespace std;


int DLinkIns(DoubleList L, int i, ELEMENT_TYPE e){
    // 双向链表的插入操作
    DNode *s, *p;
    int k = 0;
    if (i <= 0)
        return ERROR;
    p = L;
    while ((p = p->next) != nullptr && k < i - 1)
        k++;
    if (p == nullptr){
        cout << "插入位置不合理" << endl;
        return ERROR;
    }


    s = (DNode *) malloc(sizeof(DNode));
    if (s) {
        s->data = e;
        s->prior = p->prior;
        p->prior->next = s;
        s->next = p;
        p->prior = s;
        return TRUE;
    } else
        return FALSE;
}

int DLinkDel(DoubleList L, int i, ELEMENT_TYPE *e){
    // 双向链表的删除操作
    DNode *p;
    int k = 0;
    p = L;
    while ((p = p->next) != nullptr && k < i - 1)
        k++;
    if (p == nullptr) {
        cout << "删除位置不合法" << endl;
        return FALSE;
    }
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return TRUE;
}

