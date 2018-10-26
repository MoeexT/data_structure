/*
 * Created by yuwancumian666 on 2018/10/26.
 * 二叉树及其遍历
*/

#include <iostream>
#include "../stack.h"
#include "../tree.h"


using namespace std;

void PreOrder(BTree root) {
    // 前序递归遍历
    if (root != nullptr) {
        cout << root->data << endl;
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void InOrder(BTree root) {
    // 中序递归遍历
    if (root != nullptr) {
        InOrder(root->LChild);
        cout << root->data << endl;
        InOrder(root->RChild);
    }
}

void NonRecursiveInOrder(BTree root) {
    // 非递归中序遍历（直接实现栈操作）
    int top = 0;
    static int M = 50;
    BTree s[M];
    BTree bTree = root;

    do {
        while (bTree != nullptr) {
            if (top > M)
                return;
            top ++;
            s[top] = bTree;
            bTree = bTree->LChild;
        }
        if (top != 0) {
            bTree = s[top];
            top--;
            cout << bTree->data << endl;
            bTree = bTree->RChild;
        }
    } while (bTree != nullptr || top !=0);
}

void PostOrder(BTree root) {
    // 后序递归遍历
    if (root != nullptr) {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        cout << root->data << endl;
    }
}
