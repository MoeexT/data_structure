/*
 * Created by yuwancumian666 on 2018/11/6.
 * 希尔排序
*/

#include "../sort.h"

void ShellSort(RecordType r[], int length, int delta[], int n) {
    // 对数组r做希尔排序，delta为增量数组， n为delta的长度
    for (int i = 0; i < n; ++i) {
        ShellInsert(r, length, delta[i]);
    }
}

void ShellInsert(RecordType r[], int length, int delta) {
    // 对记录数组做一趟希尔插入排序
    int i = 0, j = 0;
    for (i = 1 + delta; i <= length ; ++i) {
        if (r[i].key < r[i - delta].key) {
            r[0] = r[i];
            for (j = i - delta; j > 0 && r[0].key < r[j].key; j -= delta)
                r[j + delta] = r[j];
            r[j + delta] = r[0];
        }
    }
}
