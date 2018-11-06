/*
 * Created by yuwancumian666 on 2018/11/6.
 * 交换类排序：冒泡排序，快速排序
*/

#include "../sort.h"

void BubbleSort(RecordType r[], int n) {
    // 冒泡排序
}

void QKSort(RecordType r[], int low, int high) {
    // 快速排序
    if (low < high) {
        int pos = QKPass(r, low, high);
        QKSort(r, low, pos - 1);
        QKSort(r, pos + 1, high);
    }
}

int QKPass(RecordType r[], int low, int high) {
    // 一趟快速排序
    RecordType x = r[low];
    while (low < high) {
        while (low < high && r[high].key >= x.key)
            high --;
        if (low < high) {
            r[low] = r[high];
            low++;
        }
        while (low < high && r[low].key < x.key)
            low++;
        if (low < high) {
            r[high] = r[low];
            high--;
        }
    }
    r[low] = x;
    return low;
}
