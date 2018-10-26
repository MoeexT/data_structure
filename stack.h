/*
 * Created by yuwancumian666 on 2018/10/24.
*/

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

// 栈
#define STACK_SIZE 50
#define DSTACK_SIZE 100
#define STACK_ELEMENT_TYPE int
#define TRUE 1
#define FALSE 0


// 顺序栈 sequence_stack.cpp
typedef struct {
    STACK_ELEMENT_TYPE elem[STACK_SIZE];
    int top;
}SeqStack;

void InitStack(SeqStack *S);

int Push(SeqStack *S, STACK_ELEMENT_TYPE x);

int Pop(SeqStack *S, STACK_ELEMENT_TYPE *x);

int GetTop(SeqStack *S, STACK_ELEMENT_TYPE *x);

int IsEmpty(SeqStack *S);


// 双端栈 double_end_stack.cpp
typedef struct {
    STACK_ELEMENT_TYPE stack[DSTACK_SIZE];
    STACK_ELEMENT_TYPE top[2];
}DqStack;

void InitDStack(DqStack *S);

int PushDStack(DqStack *S, STACK_ELEMENT_TYPE x, int i);

int PopDStack(DqStack *S, STACK_ELEMENT_TYPE *x, int i);


// 链栈 link_stack.cpp
typedef struct node{
    STACK_ELEMENT_TYPE data;
    struct node *next;
}LinkStack;

//typedef LinkStackNode * LinkStack;

void InitLinkStack(LinkStack * &LS);

int PushLinkStack(LinkStack * &LS, STACK_ELEMENT_TYPE x);

int PopLinkStack(LinkStack * &LS, STACK_ELEMENT_TYPE *x);

int GetTopLinkStack(LinkStack * &LS, STACK_ELEMENT_TYPE *x);

#endif //DATA_STRUCTURE_STACK_H


