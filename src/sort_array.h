#ifndef SORT_ARRAY_H
#define SORT_ARRAY_H  
#pragma once

/* Base class that will work as an array */
class SortArray {
    private:
        int *vector, select;
        char **grid;
        int size, delay;
        bool ncurses_scr;
        
    public:
        SortArray(int, int, bool=true); 
        ~SortArray();

        //debug
        void print_grid() const;
        void print_vect() const;
        void print_all() const;

        //Used by algorithms
        void swapv(int, int);
        void set(int, int);
        void ignore(int ,int);

        int& operator[](int);

        //ncurses screen updaters (?)
        void update(int a, int b, int,int);
        void update(int a, int);
};

#endif
