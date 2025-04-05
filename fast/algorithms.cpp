#include "algoritms.hpp"
#include "sort_array.hpp"

void BubbleSort(sort_array &array) {
  int size = array.size();
  for (int i = size - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      array.count_comparison();
      if (array[j] > array[j + 1]) {
        array.swap(j, j + 1);
      } else {
        /* array.ignore(j, j + 1); */
      }
    }
  }
}

void Insertion_Sort(sort_array &array) {

  int n =array.size();
    for (int i=0; i<n-1; i++) {
        for (int j=i; j>=0; j--) {
            if ( array[j+1] < array[j] ) {
                array.swap(j, j+1);
            } else {
                /* array.ignore(j, j+1); */
                break;
            }
        }
    }
}

void Selection_Sort(sort_array &array) {
    int n = array.size();

    int max;
    for (int i=n;i>0;i--) {
        max=0;
        for (int j=1;j<i;j++) {
            if (array[max]<array[j]) {
                array.count_comparison();
                max=j;
            } else {
                /* array.ignore(max, j); */
            }
        }
        array.swap(max,i-1);
    }
}

void BogoSort(sort_array &a) {
    int n=a.size();

    auto sorted = [&](sort_array& a, int n) {
        for (int i=0; i<n-1; i++) {
            a.count_comparison();
            if (a[i] > a[i+1]) {
                return false;
            }
        }
        return true;
    };

    while (true) {
        a.swap(rand()%n, rand()%n);
        if (sorted(a,n)) break;
    }
}
