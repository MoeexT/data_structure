/*
 * Created by yuwancumian666 on 2018/10/25.
*/

#include "SequenceStack.h"


SequenceStack::SequenceStack() {
    this->top = -1;
}

bool SequenceStack::push(STACK_TYPE x) {
    // 进栈
    if (this->top == SIZE - 1)
        return false;
    this->top++;
    this->values[this->top] = x;
    return true;
}

int SequenceStack::pop() {
    // 出栈
    if (this->top == -1)
        return 0;
    else {
        return this->values[this->top--];
    }
}

int SequenceStack::getTop() {
    // 读栈顶元素
    if (this->top == -1)
        return 0;
    else {
        return this->values[this->top];
    }
}
