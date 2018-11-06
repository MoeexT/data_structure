/*
 * Created by yuwancumian666 on 2018/11/6.
 * 归并排序
*/

#include <cstdlib>
#include "../sort.h"

void MergeSort(RecordType r[], int n) {
    MSort(r, 1, n, r);
}

void MSort(RecordType r1[], int low, int high, RecordType r3[]) {
    // 2-路归并排序递归算法
    RecordType *r2;
    r2 = (RecordType *) malloc(sizeof(RecordType) * (high - low + 1));
    if (low == high)
        r3[low] = r1[low];
    else {
        int mid = (low + high) / 2;
        MSort(r1, low, mid, r2);
        MSort(r1, mid + 1, high, r2);
        Merge(r2, low, mid, high, r3);
    }
    free(r2);
}

void Merge(RecordType r1[], int low, int mid, int high, RecordType r2[]) {
    // 相邻两个有序子序列的合并算法
    int i = low, j = mid + 1, k = low;
    while ((i <= mid) && (j <= high)) {
        if (r1[i].key <= r1[j].key) {
            r2[k] = r1[i];
            ++i;
        } else {
            r2[k] = r1[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid) {
        r2[k] = r1[i];
        k++;
        i++;
    }
    while (j <= high) {
        r2[k] = r1[j];
        k++;
        j++;
    }
}
