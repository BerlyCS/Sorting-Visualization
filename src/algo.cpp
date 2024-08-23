#include "sort_array.h"

void BubbleSort(int* args) {
    int n = args[1];
    SortArray array(args,"Bubble Sort");

    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<i; j++) {
            if (array[j] > array[j+1]){
                array.swapv(j, j+1);
            } else {
                array.ignore(j, j+1);
            }
        }
    }
} 

void Insertion_Sort(int* args) {
    int n = args[1];
    SortArray array(args,"Insertion Sort");

    for (int i=0; i<n-1; i++) {
        for (int j=i; j>=0; j--) {
            if ( array[j+1] < array[j] ) {
                array.swapv(j, j+1);
            } else {
                array.ignore(j, j+1);
                break;
            }
        }
    }
}

void Selection_Sort(int* args) {
    int n = args[1];
    SortArray array(args,"Selection Sort");

    int max;
    for (int i=n;i>0;i--) {
        max=0;
        for (int j=1;j<i;j++) {
            if (array[max]<array[j]) {
                array.update_comparison();
                max=j;
            } else {
                array.ignore(max, j);
            }
        }
        array.swapv(max,i-1);
    }
}

//to work on
void Quick_Sort();

void Merge_sort();

