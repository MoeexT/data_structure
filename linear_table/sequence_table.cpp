/*
 * Created by yuwancumian666 on 2018/10/23.
 * 顺序表
*/

#include <iostream>
#include "../linear_table.h"

int Locate(SeqList L, ELEMENT_TYPE e)
// 顺序表的查找
{
    int i = 0;
    while ((i < L.last) && (L.elem[i] != e))
        i++;
    if (i <= L.last)
        return (i + 1);
    else
        return -1;
}

int InsList(SeqList *L, int i, ELEMENT_TYPE e)
// 顺序表的插入
{
    int k;
    if ((i < 1) || (i > L->last + 2)) {
        printf("插入位置i值不合法");
        return (ERROR);
    }
    if (L->last >= MAXSIZE - 1) {
        printf("表已满，无法插入");
        return (ERROR);
    }
    for (k = L->last; k >= i - 1; k--)
        L->elem[k + 1] = L->elem[k];
    L->elem[i - 1] = e;
    L->last++;
    return OK;
}

int DelList(SeqList *L, int i, ELEMENT_TYPE *e)
// 删除元素
{
    int k;
    if ((i < 1) || (i > L->last + 1))
    {
        printf("删除位置不合法");
        return (ERROR);
    }
    *e = L->elem[i - 1];
    for (k = i; k < L->last; k++)
        L->elem[k - 1] = L->elem[k];
    L->last--;
    return OK;
}

void MergeList(SeqList *LA, SeqList *LB, SeqList *LC)
// 合并线性表
{
    int i, j, k, l;
    i = 0;
    j = 0;
    k = 0;
    while (i <= LA->last && j <= LB->last)
        if (LA->elem[i] <= LB->elem[j]) {
            LC->elem[k] = LA->elem[i];
            i++;
            k++;
        }
        else
            {
            LC->elem[k] = LB->elem[j];
            j++;
            k++;
        }
    while (i <= LA->last)
    {
        LC->elem[k] = LA->elem[i];
        i++;
        k++;
    }
    while (j <= LB->last)
    {
        LC->elem[k] = LB->elem[j];
        j++;
        k++;
    }
    LC->last = LA->last + LB->last + 1;
}

