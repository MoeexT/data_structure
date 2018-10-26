/*
 * Created by yuwancumian666 on 2018/10/24.
 * 顺序栈
*/

#include <iostream>
#include "../stack.h"


void InitStack(SeqStack *S) {
    // 初始化顺序栈
    S->top = -1;
}

int Push(SeqStack *S, STACK_ELEMENT_TYPE x) {
    // 进栈
    if (S->top == STACK_SIZE - 1)
        return FALSE;
    S->top++;
    S->elem[S->top] = x;
    return TRUE;
}

int Pop(SeqStack *S, STACK_ELEMENT_TYPE *x) {
    // 出栈
    if (S->top == -1)
        return FALSE;
    else {
        *x = S->elem[S->top--];
        return TRUE;
    }
}

int GetTop(SeqStack *S, STACK_ELEMENT_TYPE *x) {
    // 读栈顶元素
    if (S->top == -1)
        return FALSE;
    else {
        *x = S->elem[S->top];
        return TRUE;
    }
}

int IsEmpty(SeqStack *S) {
    return S->top == -1;
}
