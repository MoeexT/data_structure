/*
 * Created by yuwancumian666 on 2018/10/25.
 * 双端栈
*/

#include "../stack.h"

void InitDStack(DqStack *S) {
    // 初始化双端栈
    S->top[0] = -1;
    S->top[1] = DSTACK_SIZE;
}

int PushDStack(DqStack *S, STACK_ELEMENT_TYPE x, int i) {
    // 把元素压入i号栈
    if (S->top[0] + 1 == S->top[1])
        return FALSE;
    switch (i) {
        case 0:
            S->top[0]++;
            S->stack[S->top[0]] = x;
            break;
        case 1:
            S->top[1]--;
            S->stack[S->top[1]] = x;
            break;
        default:
            return FALSE;
    }
    return TRUE;
}

int PopDStack(DqStack *S, STACK_ELEMENT_TYPE *x, int i) {
    // 从i号栈崩元素
    switch (i) {
        case 0:
            if(S->top[0] == -1)
                return FALSE;
            *x = S->stack[S->top[0]--];
            break;
        case 1:
            if(S->top[1] == DSTACK_SIZE)
                return FALSE;
            *x = S->stack[S->top[1]++];
            break;
        default:
            return FALSE;
    }
    return TRUE;
}
