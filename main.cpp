/*
 * Created by yuwancumian666 on 2018/10/23.
 * 测试用主函数
*/

#include <iostream>
#include "tree.h"

using namespace std;


int main() {
    int arr[10] = {15, 2, 35, 54, 12, 25, 35, 45, 18, 91};
    HuffmanTree tree;
    CreateHuffmanTree(tree, arr, 10);
    return 0;
}