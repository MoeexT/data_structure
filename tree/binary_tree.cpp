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
    static int L = 50;
    BTree s[L];
    BTree bTree = root;

    do {
        while (bTree != nullptr) {
            if (top > L)
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

BTNode *pre;

void Inthread(BTree root) {
    // 建立中序线索树
    if (root != nullptr) {
        Inthread(root->LChild);
        if (root->LChild == nullptr) {
            root->Ltag = 1;
            root->LChild = pre;
        }
        if (pre != nullptr && pre->RChild == nullptr) {
            pre->RChild = root;
            pre->Rtag = 1;
        }
        pre = root;
        Inthread(root->RChild);
    }
}

BTNode *InPre(BTNode *p) {
    // 在中序线索树中找结点前驱
    BTNode *q;
    if (p->Ltag == 1)
        pre = pre->LChild;
    else {
        for (q = p->LChild; q->Rtag == 0; q = q->RChild) {
            pre = q;
        }
        return pre;
    }
}

BTNode *InNext(BTNode *p) {
    // 在中序线索树中找节点后继
    BTNode *Next, *q;
    if (p->Rtag == 1)
        Next = p->RChild;
    else {
        for (q = p->RChild; q->Ltag == 0; q = q->LChild);
        Next = q;
    }
    return Next;
}

BTNode *InFirst(BTree bt) {
    // 在中序线索树上找中序遍历的第一个节点
    BTNode *p = bt;
    if (!p)
        return nullptr;
    while (p->Ltag == 0)
        p = p->LChild;
    return p;
}

void TInOrder(BTree bt) {
    // 遍历中序二叉线索树
    BTNode *p;
    p = InFirst(bt);
    while (p) {
        cout << p->data << endl;
        p = InNext(p);
    }
}













