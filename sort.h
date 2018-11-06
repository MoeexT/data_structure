/*
 * Created by yuwancumian666 on 2018/11/5.
*/

#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H

// 直接插入排序 ins_sort.cpp
typedef int KeyType;
typedef int OtherType;
typedef struct {
    KeyType key;
    OtherType other_data;
} RecordType;

void InsSort(RecordType r[], int length);

void BinSort(RecordType r[], int length);


// 希尔排序 shell_sort.cpp
void ShellSort(RecordType r[], int length, int delta[], int n);

void ShellInsert(RecordType r[], int length, int delta);  // 一趟希尔排序


// 交换类排序 exchange_sort.cpp
void BubbleSort(RecordType r[], int n);

void QKSort(RecordType r[], int low, int high);

int QKPass(RecordType r[], int low, int high);  // 一趟快速排序


// 选择类排序 select_sort.cpp
#define TRUE 1
#define FALSE 0

void SelectSort(RecordType r[], int n);

void HeapSort(RecordType r[], int n);  // 堆排序

void crt_heap(RecordType r[], int n);  // 重建堆过程

void sift(RecordType r[], int k, int m);  // 建初堆


// 归并类排序 merge_sort.cpp
void MergeSort(RecordType r[], int n);

void MSort(RecordType r1[], int low, int high, RecordType r3[]);

void Merge(RecordType r1[], int low, int mid, int high, RecordType r2[]);

#endif //DATA_STRUCTURE_SORT_H
