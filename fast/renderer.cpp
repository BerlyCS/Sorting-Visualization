#include "renderer.hpp"
#include <cstdio>
#include <ncurses.h>
#include <string>
#include <utility>
#include <vector>



renderer::renderer() {
}

void renderer::cli_init_screen(std::vector<int>& arr) {
  _mat_size = arr.size();
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  start_color();

  if (!has_colors())
    printf("Terminal doesn't support colors\n");

  // FULL WHITE
  init_pair(9, COLOR_WHITE, COLOR_BLACK);
  // COLORS
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_RED);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(6, COLOR_CYAN, COLOR_CYAN);
  init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(8, COLOR_BLACK, COLOR_BLACK);
  
  attron(COLOR_PAIR(NORMAL));
  mvprintw(3, _mat_size + 1, "Accesses: 0");
  mvprintw(7, _mat_size + 1, "Swap: 0");
  mvprintw(5, _mat_size + 1, "Comparisons: 0");
  mvprintw(9, _mat_size + 1, "Recursive: 0");
  attroff(0);

  for (int i = 0; i < _mat_size; i++) {
    for (int j = 0; j < _mat_size; j++) {
      if (arr[j] + 1 < (_mat_size - i)) {
        attron(COLOR_PAIR(8));
      } else {
        attron(COLOR_PAIR(1));
      }
      mvaddch(i, j, ' ');
      attroff(0);
    }
  }
  cli_refresh_screen();
}
void renderer::swap_cols(int pos1, int pos2, std::vector<int> &v) {

  this->reset_color();
  _colored_cols.push({pos1, v[pos2]});
  _colored_cols.push({pos2, v[pos1]});

  for (int i = 0; i < _mat_size; i++) {
    if (v[pos1] + 1 < (_mat_size - i))
      attron(COLOR_PAIR(BLACK));
    else
      attron(COLOR_PAIR(RED));

    mvaddch(i, pos2, ' ');
    attroff(COLOR_PAIR(NORMAL));

    if (v[pos2]+1 < (_mat_size - i))
      attron(COLOR_PAIR(BLACK));
    else
      attron(COLOR_PAIR(GREEN));

    mvaddch(i, pos1, ' ');
    attroff(COLOR_PAIR(NORMAL));
  }
}


renderer::~renderer() {
  getch();
  endwin();
}


void renderer::color_col(int pos, int value, short color) {
  _colored_cols.push({pos, value});
  for (size_t i=0;i<_mat_size; i++) {
    if (value +1< _mat_size-i) {
      attron(COLOR_PAIR(BLACK));
    }
    else {
      attron(COLOR_PAIR(color));
    }
    mvaddch(i, pos, ' ');
    attroff(COLOR_PAIR(NORMAL));
  }
}

void renderer::reset_color() {
  std::pair<int, int> col_pos;
  while (!_colored_cols.empty()) {
    col_pos = _colored_cols.top();
    _colored_cols.pop();
    for (int i=0; i<_mat_size; i++) {
      if (col_pos.second +1< _mat_size-i) {
        attron(COLOR_PAIR(BLACK));
      }
      else {
        attron(COLOR_PAIR(WHITE));
      }
      mvaddch(i, col_pos.first, ' ');
      attroff(COLOR_PAIR(NORMAL));
    }
  }
}

void renderer::exit_screen() { endwin(); }

void renderer::update_count(int acc, int swp, int comp, int recur) {
  /* mvprintw(3, _mat_size + 1, "Accesses: %d", acc); */
  mvprintw(3, _mat_size + 11, "%d", acc);
  /* mvprintw(7, _mat_size + 1, "Swap: %d", swp); */
  mvprintw(7, _mat_size + 7, "%d", swp);
  /* mvprintw(5, _mat_size + 1, "Comparisons: %d", comp); */
  mvprintw(5, _mat_size + 14, "%d", comp);
  /* mvprintw(9, _mat_size + 1, "Recursive: %d", recur); */
  mvprintw(9, _mat_size + 12, "%d", recur);
}

void renderer::set_name(std::string algo_name) {
  attron(COLOR_PAIR(NORMAL));
  mvaddstr(1, _mat_size +1, algo_name.c_str());
  attroff(COLOR_PAIR(NORMAL));
  
  _algorithm_name = algo_name;
}

void renderer::cli_refresh_screen() {
  refresh();
}
