/*
 * Created by yuwancumian666 on 2018/10/23.
*/

#ifndef DATA_STRUCTURE_LINEAR_TABLE_H
#define DATA_STRUCTURE_LINEAR_TABLE_H

// 线性表
#define ELEMENT_TYPE char  // 设定表中元素的类型
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


// 顺序表 sequence_table.cpp
typedef struct {
    ELEMENT_TYPE elem[MAXSIZE];
    int last;
} SeqList;

int Locate(SeqList L, ELEMENT_TYPE e);

int InsList(SeqList *L, int i, ELEMENT_TYPE e);

int DelList(SeqList *L, int i, ELEMENT_TYPE *e);

void MergeList(SeqList *LA, SeqList *LB, SeqList *LC);


// 单链表 link_list.cpp
typedef struct Node {
    ELEMENT_TYPE data;
    struct Node *next;
} Node, *LinkList;

void InitList(LinkList *L);

void CreateFromHead(LinkList L);

void CreateFromTail(LinkList L);

Node *Get(LinkList L, int i);

Node *Locate(LinkList L, ELEMENT_TYPE key);

int ListLength(LinkList L);

int InsList(LinkList L, int i, ELEMENT_TYPE e);

int DelList(LinkList L, int i, ELEMENT_TYPE *e);

LinkList MergeLinkList(LinkList LA, LinkList LB);


// 循环链表 circular_linked_list.cpp
void InitCLinkList(LinkList *CL);

void CreateClinkList(LinkList CL);

LinkList merge_1(LinkList LA, LinkList LB);

LinkList merge_2(LinkList RA, LinkList RB);


// 双向链表 doubly_linked_list.cpp
typedef struct DNode {
    ELEMENT_TYPE data;
    struct DNode *prior, *next;
}DNode, *DoubleList;

int DLinkIns(DoubleList L, int i, ELEMENT_TYPE e);

int DLinkDel(DoubleList L, int i, ELEMENT_TYPE *e);

#endif //DATA_STRUCTURE_LINEAR_TABLE_H


