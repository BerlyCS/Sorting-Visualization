#include <ncurses.h>
#include <iostream>
#include <thread>
#include "sort_array.h"


SortArray::SortArray(int size, int delay, bool scr) : size(size), delay(delay), ncurses_scr(scr) {

    if (scr) {
        initscr();
        cbreak();
        noecho();
        start_color();

        if (!has_colors()) {
            printf("El terminal no soporta colores.\n");
        }

        curs_set(0);
        init_pair(0, COLOR_WHITE, COLOR_BLACK);
        init_pair(1, COLOR_WHITE, COLOR_WHITE);
        init_pair(2, COLOR_RED, COLOR_RED);
        init_pair(3, COLOR_GREEN, COLOR_GREEN);
        init_pair(4, COLOR_BLUE, COLOR_BLUE);
        init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(6, COLOR_CYAN, COLOR_CYAN);
        init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(8, COLOR_BLACK, COLOR_BLACK);
    }

    srand(time(nullptr));
    vector = new int[size];
    for (int i=0; i<size; i++) {
        vector[i] = i+1;
    }
    //Shuffling the vector
    for (int i=size-1; i>0; i--) {
        std::swap(vector[i], vector[rand()%(i)]);
    }

    //Grid allocation
    grid = new char*[size];
    for (int i=0;i<size; i++) {
        grid[i] = new char[size];
    }

    //fills the grid according to the vector
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            //Fills a line
            ((size-j) <= vector[i]) ? grid[j][i] = 'O' : grid[j][i] = ' ';
        }
    }

    select=-1 ;

    //Help menu about color
    attron(COLOR_PAIR(0));
    mvaddstr(1, size+4, ": Swap.");
    mvaddstr(3, size+2, ": Swap ignored, omitted.");
    mvaddstr(5, size+4, ": Acess to the array for comparison");
    mvaddstr(7, size+2, ": Array value modified, setted");
    /* attroff(COLOR_PAIR(1)); */
}

SortArray::~SortArray() {
    endwin();
    print_all();
    for (int i=0; i<size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

void SortArray::print_vect() const {
    for (int i=0; i<size; i++) {
        std::cout<<vector[i]<<' ';
    }
    std::cout<<std::endl;

}

void SortArray::print_grid() const {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            std::cout<<grid[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}

void SortArray::print_all() const {
    this->print_grid();
    this->print_vect();
}

void SortArray::swapv(int a, int b) {
    if (b>= size || a>= size) {
        std::cout<<"\nSwap Limit Exceeded. Aborting"<<std::endl;
        return;
    }
    std::swap(vector[a], vector[b]);
    for (int i=0; i<size; i++) {
        std::swap(grid[i][a], grid[i][b]);
    }

    update(a,b,2,3);
    return;
}

void SortArray::set(int pos, int val) {
    if (pos >= size) {
        std::cout<<"Set Limit Exceeded. Aborting"<<std::endl;
        return;
    }

    vector[pos] = val;

   for (int i=0; i<size; i++) {
        grid[i][pos] = val;
    }

   update(pos, 4);

    return;
}

//Not really necesary for the sorting but can give 
//a better idea when a swap is omitted
void SortArray::ignore(int a, int b) {
    if (a>=size || b>= size) {
        std::cout<<"Ignore Limit Exceeded. Aborting\n";
    }

    update(a,b,5,5);
}

int& SortArray::operator[](int n) {
    if (select == -1) {
        update(n, 4);
        select = n;
    } else {
        update(select, n, 4,6);
        select=-1;
    }

    return vector[n];
}

// for swap and ignore update
void SortArray::update(int a, int b, int color_a, int color_b) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++){
            if (grid[i][j] == ' ') {

                attron(COLOR_PAIR(8));
                mvaddch(i, j, ' ');
                attroff(0);
                continue;
            }
            if (j == a){
                attron(COLOR_PAIR(color_a));
                mvaddch(i, j, ' ');
                attroff(0);
            } 
            else if ( j==b ) {
                attron(COLOR_PAIR(color_b));
                mvaddch(i, j, ' ');
                attroff(0);
            }
            else {
                attron(COLOR_PAIR(1));
                mvaddch(i, j, ' ');
                attroff(0);
            }
        }
    }
    refresh();
    
    
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

// for set update
void SortArray::update(int a, int color) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++){
            if (grid[i][j] == ' ') {

                attron(COLOR_PAIR(8));
                mvaddch(i, j, ' ');
                attroff(0);
                continue;
            }
            if (j == a){
                attron(COLOR_PAIR(color));
                mvaddch(i, j, ' ');
                attroff(0);
            } else {
                attron(COLOR_PAIR(1));
                mvaddch(i, j, ' ');
                attroff(0);
            }
        }
    }
    refresh();
    
    
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}
