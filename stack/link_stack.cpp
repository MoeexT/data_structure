/*
 * Created by yuwancumian666 on 2018/10/25.
 * 链栈
*/

#include <iostream>
#include <cstdlib>
#include "../stack.h"

using namespace std;

void InitLinkStack(LinkStack * &LS) {
    // 初始化栈
    LS = (LinkStack *) malloc(sizeof(LinkStack));
    LS->next = nullptr;
    cout << "address of head pointer of stack: %p" << LS << endl;
}

int PushLinkStack(LinkStack * &LS, STACK_ELEMENT_TYPE x) {
    // 压栈
    LinkStack *new_node;
    new_node = (LinkStack *) malloc(sizeof(LinkStack));
    cout << "address of new node: %p" << new_node << endl;
    if (new_node == nullptr)  // 申请内存失败
        return FALSE;
    new_node->data = x;
    new_node->next = LS->next;
    LS->next = new_node;
    return TRUE;
}

int PopLinkStack(LinkStack * &LS, STACK_ELEMENT_TYPE *x) {
    // 崩栈
    LinkStack *node;
    node = LS->next;
    if (node == nullptr)
        return FALSE;
    LS->next = node->next;
    *x = node->data;
    free(node);
    return TRUE;
}

int GetTopLinkStack(LinkStack * &LS, STACK_ELEMENT_TYPE *x) {
    // 取栈顶元素
    LinkStack *node;
    node = LS;
    if (node->next == nullptr)
        return FALSE;
    *x = node->next->data;
    return TRUE;
}

int main_() {
    int x = 0, *p = &x;
    LinkStack *LS;
    InitLinkStack(LS);
    for (int i = 0; i < 6; ++i) {
        PushLinkStack(LS, i);
    }

    GetTopLinkStack(LS, p);
    cout << "top value of stack: " << *p << ", address: " << p << endl;

    for (int j = 0; j < 6; ++j) {
        PopLinkStack(LS, p);
        cout << "pop value: " << *p << endl;
    }
    return 0;
}
