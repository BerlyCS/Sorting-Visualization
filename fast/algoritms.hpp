#ifndef ALGORITMS_HPP
#define ALGORITMS_HPP

#include "sort_array.hpp"
void BubbleSort(sort_array& arr);
void Selection_Sort(sort_array& arr);
void Insertion_Sort(sort_array& arr);
void MergeSort(sort_array &array, int left, int right);
void QuickSort(sort_array &array, int low, int high);

void GnomeSort(sort_array &array);
void CocktailSort(sort_array &array);
#endif
