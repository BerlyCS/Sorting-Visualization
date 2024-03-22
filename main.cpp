#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

float sleep;

void create_grid(string **&grid, int num, vector<int> array){
    grid = new string*[num];
    for (int i=0;i<num;i++){
        grid[i] = new string[num]();
    }

    for (int i =0;i<num;i++){
        int count=array[i];
        for (int j=num-1;j>=0;j--) {
            if (count-- >= 0) {
                grid[j][i]="█";
            }
            else{
                grid[j][i]=" ";
            }
        }
    }
}

void swap_grid(string**& grid, int num, int lt, int gt) {
    for (int i=0;i<num;i++) {
        swap(grid[i][lt],grid[i][gt]);
    }
}

void print_grid(string**& grid, int num, int curr, int mv) {
    system("clear");

    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++){
            if (j==curr)
                cout<<RED<<grid[i][j]<<RESET<<flush;
            else if (j==mv)
                cout<<GREEN<<grid[i][j]<<RESET<<flush;
            else
                cout<<grid[i][j]<<flush;
        }
        cout<<'\n';
    }
    cout<<'\n';
    system("sleep 0.2");
}


void shuffle_vector(vector<int> &array){
    int size=array.size();
    for (int i = 0; i < size; i++) array[i]=i;
    srand(time(nullptr));
    int rnd;
    for (int i = size - 1 ; i > 0; i--){
        rnd=rand()%i;
        swap(array[rnd],array[i]);
    }
}

void bubble_sort(vector<int> &array, int num, string **&grid) {
    for (int i=num-1;i>=0;i--) {
        for (int j=0;j<i;j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                swap_grid(grid, num, j, j+1);
            }
            print_grid(grid, num,j,j+1);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout<<"Uso: "<<argv[0]<<" [Cantidad] [sleep]\n";
        return 1;
    }
    int num=stoi(argv[1]);
    if (argc==3)
        sleep=stof(argv[2]);
    else
        sleep=0.5;

    vector<int> array(num);
    shuffle_vector(array);
    
    bool sorted=false;
    string **grid;
    create_grid(grid, num, array);
    /* print_grid(grid, num); */
    bubble_sort(array, num, grid);
    
    for (int i=0;i<num;i++)
        cout<<array[i]<<' ';
}
