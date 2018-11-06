/*
 * Created by yuwancumian666 on 2018/11/6.
 * 选择类排序
*/

#include "../sort.h"

void SelectSort(RecordType r[], int n) {
    // 简单选择排序
    int k;
    RecordType x;
    for (int i = 0; i < n; ++i) {
        k = 1;
        for (int j = i + 1; j <= n; ++j)
            if (r[j].key < r[k].key)
                k = j;
        if (k != i) {
            x = r[i];
            r[i] = r[k];
            r[k] = x;
        }
    }
}

void HeapSort(RecordType r[], int n) {
    // 堆排序
    RecordType b;
    crt_heap(r, n);
    for (int i = n; i >= 2; --i) {
        b = r[1];
        r[1] = r[i];
        r[i] = b;
        sift(r, 1, i - 1);
    }
}

void crt_heap(RecordType r[], int n) {
    for (int i = n / 2; i >= 1; --i) {
        sift(r, i, n);
    }
}

void sift(RecordType r[], int k, int m) {
    int x, i, j, finished;
    RecordType t;
    t = r[k];
    x = r[k].key;
    i = k;
    j = 2 * i;
    finished = FALSE;
    while (j <= m && !finished) {
        if (j + 1 <= m && r[j].key < r[j + 1].key)
            j ++;
        if (x >= r[j].key)
            finished = TRUE;
        else {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
    }
    r[i] = t;
}
