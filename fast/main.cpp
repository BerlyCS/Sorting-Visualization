#include "algoritms.hpp"
#include "sort_array.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
int main(int argc, char* argv[]) {
  sort_array v(10);
  BubbleSort(v);
  Selection_Sort(v);
}
