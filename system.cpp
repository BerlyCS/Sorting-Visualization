#include <cstdlib>
#include <exception>
#include <iostream>
#include <utility>

using namespace std;

class SortView {
    private:
        int *vector;
        char **grid;
        int size;
    public:
        SortView(int); 
        void print_grid() const;
        void print_vect() const;
        void swap_grid(int a, int b);
        void set(int a, int);
};

SortView::SortView(int size) : size(size) {
    srand(time(nullptr));
    vector = new int[size];
    for (int i=0; i<size; i++) {
        vector[i] = i+1;
    }
    //Shuffling the vector
    for (int i=size-1; i>0; i--) {
        swap(vector[i], vector[rand()%(i)]);
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
            ((size-j) <= vector[i]) ? grid[j][i] = '$' : grid[j][i] = ' ';
        }
    }
}
void SortView::print_vect() const {
    for (int i=0; i<size; i++) {
        cout<<vector[i]<<' ';
    }
    cout<<endl;

}

void SortView::print_grid() const {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void SortView::swap_grid(int a, int b) {
    if (b>= size) {
        cout<<"Limite excedido.";
        return;
    }
    swap(vector[a], vector[b]);
    for (int i=0; i<size; i++) {
        swap(grid[i][a], grid[i][b]);
    }
}
void SortView::set(int a, int val) {
    return;
}

int main() {
    SortView sys(5);
    sys.print_grid();
    sys.print_vect();
    sys.swap_grid(1, 2);
    sys.print_grid();
}

