#ifndef SORT_ARRAY_HPP
#define SORT_ARRAY_HPP
#include "renderer.hpp"
#include <cstddef>
#include <string>
#include <vector>
class sort_array {
  private:
    std::vector<int> arr;
    renderer render;
    size_t acc, swp, comp, recur;
  public:
    sort_array(size_t size);
    ~sort_array() = default;

    int& operator[](size_t index);
    void swap(int pos1, int pos2);
    void ignore(int pos1, int pos2);

    void count_comparison();
    void count_swap();
    void count_access();
    void count_recursion();

    int size() const;
    void set_title(std::string algo_name);
};
#endif
