#ifndef SORT_ARRAY_H
#define SORT_ARRAY_H  
#include <string>
#include "beep.h"
#pragma once

/* Base class that will work as an array */
class SortArray {
    private:
        int *vector, select;
        char **grid;
        int size, delay;
        bool ncurses_scr,SWP_C,IGN_C,ACC_C;
        int comp, acc, swp;
        Beeper sound;
        
    public:
        SortArray(int*, std::string,bool=true); 
        ~SortArray();

        //debug
        void print_grid() const;
        void print_vect() const;
        void print_all() const;

        //Used by algorithms
        void swapv(int, int, bool=true);
        void set(int, int);
        void ignore(int ,int);

        int& operator[](int);

        //ncurses screen updaters (?)
        void update(int, int, int, int, bool=false);
        void update(int, int);
        void write(std::string);
        void update_access();
        void update_comparison();
        void update_swap();
};

#endif
