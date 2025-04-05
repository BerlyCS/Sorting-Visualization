#include "algoritms.hpp"
#include "sort_array.hpp"

void BubbleSort(sort_array &array) {
  array.set_title("Bubble Sort");
  int size = array.size();
  for (int i = size - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      array.count_comparison();
      if (array[j] > array[j + 1]) {
        array.swap(j, j + 1);
      } else {
        array.ignore(j, j + 1);
      }
    }
  }
}

void Insertion_Sort(sort_array &array) {
  array.set_title("Insertion Sort");
  int n = array.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j >= 0; j--) {
      array.count_comparison();
      if (array[j + 1] < array[j]) {
        array.swap(j, j + 1);
      } else {
        array.ignore(j, j + 1);
        break;
      }
    }
  }
}

void Selection_Sort(sort_array &array) {
  array.set_title("Selection Sort");
  int n = array.size();

  int max;
  for (int i = n; i > 0; i--) {
    max = 0;
    for (int j = 1; j < i; j++) {
      if (array[max] < array[j]) {
        array.count_comparison();
        max = j;
      } else {
        array.ignore(max, j);
      }
    }
    array.swap(max, i - 1);
  }
}

void BogoSort(sort_array &a) {
  int n = a.size();

  auto sorted = [&](sort_array &a, int n) {
    for (int i = 0; i < n - 1; i++) {
      a.count_comparison();
      if (a[i] > a[i + 1]) {
        return false;
      }
    }
    return true;
  };

  while (true) {
    a.swap(rand() % n, rand() % n);
    if (sorted(a, n))
      break;
  }
}
void Merge(sort_array &array, int left, int mid, int right) {
  array.count_recursion();
  int i = left;
  int j = mid + 1;

  while (i <= mid && j <= right) {
    array.count_comparison();
    if (array[i] <= array[j]) {
      array.ignore(i, j);
      i++;
    } else {
      for (int k = j; k > i; k--) {
        array.swap(k, k - 1);
      }
      i++;
      mid++;
      j++;
    }
  }
}
void MergeSort(sort_array &array, int left, int right) {
  array.count_recursion();
  array.set_title("Merge Sort");
  if (left >= right) return;

  int mid = (left + right) / 2;
  MergeSort(array, left, mid);
  MergeSort(array, mid + 1, right);
  Merge(array, left, mid, right);
}

int Partition(sort_array &array, int low, int high) {
  array.count_recursion();
  int pivot = high;
  int i = low - 1;

  for (int j = low; j < high; j++) {
    array.count_comparison();
    if (array[j] < array[pivot]) {
      i++;
      array.swap(i, j);
    } else {
      array.ignore(j, pivot);
    }
  }
  array.swap(i + 1, pivot);
  return i + 1;
}

void QuickSort(sort_array &array, int low, int high) {
  array.count_recursion();
  if (low < high) {
    int pivot_index = Partition(array, low, high);
    QuickSort(array, low, pivot_index - 1);
    QuickSort(array, pivot_index + 1, high);
  }
}

void GnomeSort(sort_array &array) {
  array.set_title("Gnome Sort");
  int i = 0, n = array.size();

  while (i < n) {
    if (i == 0) {
      i++;
    }
    array.count_comparison();
    if (array[i] >= array[i - 1]) {
      array.ignore(i, i - 1);
      i++;
    } else {
      array.swap(i, i - 1);
      i--;
    }
  }
}

void CocktailSort(sort_array &array) {
  array.set_title("Cocktail Shaker Sort");
  int left = 0, right = array.size() - 1;

  while (left < right) {
    for (int i = left; i < right; ++i) {
      array.count_comparison();
      if (array[i] > array[i + 1]) {
        array.swap(i, i + 1);
      } else {
        array.ignore(i, i + 1);
      }
    }
    right--;

    for (int i = right; i > left; --i) {
      array.count_comparison();
      if (array[i] < array[i - 1]) {
        array.swap(i, i - 1);
      } else {
        array.ignore(i, i - 1);
      }
    }
    left++;
  }
}
