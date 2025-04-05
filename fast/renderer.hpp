#ifndef COMPOSITOR_HPP
#define COMPOSITOR_HPP
#include <cstddef>
#include <ncurses.h>
#include <stack>
#include <utility>
#include <vector>
#include <string>

class renderer {
  private:
    size_t _mat_size;
    std::stack<std::pair<int, int>> _colored_cols;
    std::string _algorithm_name;
    
  public:
    renderer();
    ~renderer();

    void cli_init_screen(std::vector<int>&);
    void cli_refresh_screen();

    void gui_init_screen();
    void gui_refresh_screen();

    void color_col(int pos, int value, short color);
    void swap_cols(int pos1, int pos2, std::vector<int>& v);
    void reset_color();
    void exit_screen();
    void update_count(int acc, int swp, int comp, int recur);
    void set_name(std::string algo_name);

};
#endif
