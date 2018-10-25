/*
 * Created by yuwancumian666 on 2018/10/23.
 * 测试用主函数
*/

#include <iostream>
#include "linear_table.h"
#include "stack.h"

using namespace std;


int main() {
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