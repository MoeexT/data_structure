/*
 * Created by yuwancumian666 on 2018/10/29.
 * 树、森林与二叉树的关系
*/

#include <iostream>
#include "../tree.h"

using namespace std;

void RootFirst1(CSTree root) {
    // 树的遍历——1
    CSNode *p;
    if (root != nullptr) {
        cout << root->data << endl;
        p = root->FirstChild;
        while (p != nullptr) {
            cout << p->data << endl;
            p = p->NextSibling;
        }
    }
}

void RootFirst2(CSTree root) {
    // 树的遍历——2
    if (root != nullptr) {
        cout << root->data << endl;
        RootFirst2(root->FirstChild);
        RootFirst2(root->NextSibling);
    }
}

