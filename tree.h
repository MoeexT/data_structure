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
    int Ltag;
    int Rtag;
}BTNode, *BTree;

void PreOrder(BTree root);

void InOrder(BTree root);

void PostOrder(BTree root);

#endif //DATA_STRUCTURE_TREE_H


// 树、森林与二叉树 tree.cpp
#define MAX 100
typedef struct TNode {
    DATA_TYPE data;
    int parent;
}TNode;

typedef struct {
    TNode tree[MAX];
    int nodenum;
}ParentTree;

typedef struct ChildNode {
    int Child;
    struct ChildNode *next;
}ChildNode;

typedef struct {
    DATA_TYPE data;
    ChildNode *FirstChild;
}DataNode;

typedef struct {
    DataNode nodes[MAX];
    int root;
    int num;
}ChildTree;

typedef struct CSNode {
    DATA_TYPE data;
    struct CSNode *FirstChild;
    struct CSNode *NextSibling;
}CSNode, *CSTree;

void RootFirst1(CSTree root);

void RootFirst2(CSTree root);


// 哈夫曼树 huffman_tree.cpp
#define N 20
#define M 2*N-1

typedef struct {
    int weight, parent, LChild, RChild;
}HTNode, HuffmanTree[M+1];

void CreateHuffmanTree(HuffmanTree ht, int w[], int n);

void select(HuffmanTree tree, int length, int *p1, int *p2);

typedef char *HuffmanEncode[N+1];

void CreHuffmanEncode(HuffmanTree ht, HuffmanEncode he, int n);
