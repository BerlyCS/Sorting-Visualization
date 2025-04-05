#include "sort_array.hpp"
#include "renderer.hpp"
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::vector<int> gen_random_vect(int size) {
  std::vector<int> tmp(size);
  for (int i=0; i<size; i++) {
    tmp[i] = i;
  }

  srand(time(nullptr));
  for (int i=0; i<size-1; i++) {
    std::swap(tmp[i], tmp[(rand()%(size-1-i)) + i+1]);
  }
  return tmp;
}

sort_array::sort_array(size_t size) {
  acc = 0, swp = 0, comp = 0, recur = 0;
  arr = gen_random_vect(size);
  render.cli_init_screen(arr);
}

void sort_array::swap(int pos1, int pos2) {
  render.swap_cols(pos1, pos2, arr);
  std::swap(arr[pos1], arr[pos2]);

  count_swap();
  render.update_count(acc, swp, comp, recur);
  render.cli_refresh_screen();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void sort_array::ignore(int pos1, int pos2) {
  render.reset_color();
  render.color_col(pos1, this->arr[pos1], YELLOW);
  render.color_col(pos2, this->arr[pos2], YELLOW);
  count_comparison();

  render.cli_refresh_screen();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int& sort_array::operator[](size_t index) {
  count_access();
  render.reset_color();
  render.color_col(index, arr[index], CYAN);
  render.update_count(acc, swp, comp, recur);
  render.cli_refresh_screen();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  return arr[index];
}


void sort_array::set_title(std::string algo_name) {
  render.set_name(algo_name);
}

int sort_array::size() const {
  return arr.size();
}

void sort_array::count_access() {
  this->acc++;
}
void sort_array::count_swap() {
  this->swp++;
}
void sort_array::count_comparison() {
  this->comp++;
}
void sort_array::count_recursion() {
  this->recur++;
}
