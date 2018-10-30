/*
 * Created by yuwancumian666 on 2018/10/29.
 * 哈夫曼树
*/

#include <iostream>
#include <string.h>
#include "../tree.h"

using namespace std;

void CreateHuffmanTree(HuffmanTree ht, int w[], int n) {
    int i, m;

    for (i = 1; i <= n; ++i)
        ht[i] = {w[i], 0, 0, 0};
    m = 2 * n - 1;
    for (i = n + 1; i <= m; ++i)
        ht[i] = {0, 0, 0, 0};
    int s1, s2;
    for (i = n + 1; i <= m; i ++) {
        select(ht, i-1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].LChild = s1;
        ht[i].RChild = s2;
        // printf("%d,%d,%d,%d\n", ht[i].weight,ht[i].parent, ht[i].RChild, ht[i].LChild);
    }
}

void select(HuffmanTree tree, int length, int *p1, int *p2) {
    HTNode node;
    *p1 = tree[1].weight;
    *p2 = *p1;
    for (int i = 1; i <= length; i++) {
        node = tree[i];
        if (node.parent == 0) {
            *p1 = node.weight < *p1 ? node.weight : *p1;
            *p2 = node.weight > *p2 ? node.weight : *p2;
        }
    }
    for (int i = 1; i <= length; i++) {
        node = tree[i];
        if (node.parent == 0 && node.weight < *p2 && node.weight > *p1)
            *p2 = node.weight;
    }
    // cout << "p1: " << *p1 << ", p2: " << *p2 << endl;
}

void CreHuffmanEncode(HuffmanTree ht, HuffmanEncode he, int n) {
    // 哈夫曼编码
    int start, c, p;
    char *cd;
    cd = (char *) malloc(sizeof(char));
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; ++i) {
        start = n - 1;
        c = i;
        p = ht[i].parent;
        while (p != 0) {
            --start;
            if (ht[p].LChild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = p;
            p = ht[p].parent;
        }
        he[i] = (char *) malloc((n - start) * sizeof(char));
        strcpy(he[i], &cd[start]);
    }
    free(cd);
}
