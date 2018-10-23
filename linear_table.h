/*
 * Created by yuwancumian666 on 2018/10/23.
*/

#ifndef DATA_STRUCTURE_LINEAR_TABLE_H
#define DATA_STRUCTURE_LINEAR_TABLE_H

#endif //DATA_STRUCTURE_LINEAR_TABLE_H

// 线性表
#define ElemType char  // 设定表中元素的类型


// 顺序表 sequence_table.cpp
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef struct {
    int elem[MAXSIZE];
    int last;
} SeqList;

int locate(SeqList L, ElemType e);
int ins_list(SeqList *L, int i, ElemType e);
int del_list(SeqList *L, int i, ElemType *e);
void merge_list(SeqList *LA, SeqList *LB, SeqList *LC);


// 单链表 link_list.cpp
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *LinkList;

void init_list(LinkList *L);
void create_from_head(LinkList L);
void create_from_tail(LinkList L);
Node *get(LinkList L, int i);
Node *locate(LinkList L, ElemType key);
int list_length(LinkList L);
void ins_list(LinkList L, int i, ElemType e);
void del_list(LinkList L, int i, ElemType e);
LinkList merge_link_list(LinkList LA, LinkList LB);



