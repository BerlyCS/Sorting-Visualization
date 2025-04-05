#include "algoritms.hpp"
#include "sort_array.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
int main(int argc, char* argv[]) {
  sort_array v(20);
  /* BubbleSort(v); */
  Insertion_Sort(v);
  /* CocktailSort(v); */
  /* QuickSort(v, 0, 9); */
  /* MergeSort(v, 0, 19); */
}
