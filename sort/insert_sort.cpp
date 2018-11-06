/*
 * Created by yuwancumian666 on 2018/11/5.
 * 直接插入排序
*/

#include "../sort.h"

void InsSort(RecordType r[], int length) {
    // 直接插入排序
    int j = 0;
    for (int i = 2; i <= length; ++i) {
        r[0] = r[i];
        j = i - 1;
        while (r[0].key < r[j].key) {
            r[j + 1] = r[j];
            j = j - 1;
        }
        r[j + 1] = r[0];
    }
}

void BinSort(RecordType r[], int length) {
    // 折半插入排序
    RecordType x;
    int low, mid, high;
    for (int i = 2; i <= length; ++i) {
        x = r[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (x.key < r[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j >= low; --j)
            r[j + 1] = r[j];
        r[low] = x;
    }
}
