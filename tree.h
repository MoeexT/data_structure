/*
 * Created by yuwancumian666 on 2018/10/26.
*/

#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H

#define DATA_TYPE int

// 二叉树 binary_tree.cpp
typedef struct NodeBT {
    DATA_TYPE data;
    struct NodeBT *LChild;
    struct NodeBT *RChild;
}BTNode, *BTree;

void PreOrder(BTree root);

void InOrder(BTree root);

void PostOrder(BTree root);

#endif //DATA_STRUCTURE_TREE_H
