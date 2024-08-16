#include "sort_array.h"

void BubbleSort(int n, int d) {
    SortArray array(n,d);

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

void Insertion_Sort(int n, int d) {
    SortArray array(n,d);

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

//Incomplete
void Selection_Sort(int n, int d) {
    SortArray array(n,d,false);

    int max;
    for (int i=n;i>=0;i--) {
        max=0;
        for (int j=0;j<i;j++) {
            if (array[max]<array[j]) {
                max=j;
            } else {
                array.ignore(max, j);
            }
        }
        array.swapv(array[i-1],array[max]);
    }
}

