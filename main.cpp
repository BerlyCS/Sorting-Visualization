#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <chrono>
#include <clocale>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <SFML/Audio.hpp>
#include <ncurses.h>
#include <ncursesw/ncurses.h>
#include <ncurses/menu.h>

using namespace std;

//Colores formato ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

sf::SoundBuffer *buffer;
sf::Sound *sound;
int sleep;

void create_grid(char **&grid, int num, vector<int> array){
    grid = new char*[num];
    for (int i=0;i<num;i++){
        grid[i] = new char[num]();
    }

    for (int i =0;i<num;i++){
        int count=array[i];
        for (int j=num-1;j>=0;j--) {
            if (count-- >= 0) {
                grid[j][i]='$';
            }
            else{
                grid[j][i]=' ';
            }
        }
    }
}

void delete_grid(char**& grid, int num){
    for (int i=0;i<num;i++){
        delete[] grid[i];
    }
    delete[] grid;
}


void swap_grid(char**& grid, int num, int lt, int gt) {
    for (int i=0;i<num;i++) {
        swap(grid[i][lt],grid[i][gt]);
    }
}

void print_grid(char**& grid, int num, int curr, int mv) {

    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++){
            if (j==curr){
                attron(COLOR_PAIR(1));
                mvaddch(i,j,grid[i][j]);
                attroff(1);
            }
            else if (j==mv){
                attron(COLOR_PAIR(2));
                mvaddch(i,j,grid[i][j]);
                attroff(2);
            } else {
                
                attron(COLOR_PAIR(3));
                mvaddch(i,j, grid[i][j]);
                attroff(3);
            }
            
        }
    }
    refresh();
    
    sound[curr].play();
    
    this_thread::sleep_for(chrono::milliseconds(sleep));
    /* system(("sleep "+to_string(sleep)).c_str()); */
}

void verify_sort(char **&grid, int num, vector<int> array) {
    sleep=20;
    for (size_t i=0;i<array.size()-1;i++){
        if (array[i]>array[i+1]){
            cout<<"Hubo un error en el programa\n";
        }
        sound[(i/(num/10))%10].play();
        print_grid(grid, num, i, i+1);
    }
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

void bubble_sort(vector<int> &array, int num, char **&grid) {
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

void insert_sort(vector<int> &a, int num, char**& grid) {
    for (int i=0;i<num-1;i++){
        for (int j=i;j>=0;j--){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swap_grid(grid,num,j,j+1);
            } else if (a[j]<a[j+1]){
                break;
            }
            print_grid(grid,num, j, j+1);
        }
    }
}

void selection_sort(vector<int>& array, int num, char**& grid){
    int max;
    for (int i=num;i>0;i--) {
        max=0;
        for (int j=0;j<i;j++) {
            if (array[max]<array[j]) {
                max=j;
            }
            print_grid(grid, num, j, max);
        }
        swap_grid(grid,num,max,i-1);
        swap(array[i-1],array[max]);
    }
}

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "");
    if (argc < 2) {
        cout<<"Uso: "<<argv[0]<<" [Cantidad] {sleep}\n";
        return 1;
    }
    int num=stoi(argv[1]);

    if (argc==3)
        sleep=stoi(argv[2]);
    else
        sleep=100;

    system(("./sounds/gen_samples.sh "+ to_string(num)).c_str());

    buffer=new sf::SoundBuffer[num];
    sound=new sf::Sound[num];

    for (int i=0; i<num; i++){
        buffer[i].loadFromFile(to_string(i)+".wav");
        sound[i].setBuffer(buffer[i]);
    }

    vector<int> array(num);
    shuffle_vector(array);
    
    int opt;
    cout<<"Selecciona algoritmo:\n"
        <<"1.Bubble Sort \n"
        <<"2.Insert Sort \n"
        <<"3.Selection Sort \n";
    cin>>opt;
    
    initscr();
    cbreak();
    noecho();
    start_color();
    if (!has_colors()) {
        endwin();
        printf("El terminal no soporta colores.\n");
        return 1;
    }

    curs_set(0);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);

    char **grid;
    create_grid(grid, num, array);

    switch (opt) {
        case 1:
            bubble_sort(array, num, grid);
            break;
        case 2:
            insert_sort(array, num, grid);
            break;
        case 3:
            selection_sort(array, num, grid);
            break;
        default:
            delete_grid(grid, num);
            endwin();
            
            delete[] sound;
            delete[] buffer;

            system("rm *.wav");
            cout<<"Opcion invalida";
            return 1;
    }
 
    verify_sort(grid, num, array);
    delete_grid(grid, num);
    
    getch();

    endwin();
    delete[] sound;
    delete[] buffer;
    for (int i=0;i<num;i++)
        cout<<array[i]<<' ';
    this_thread::sleep_for(chrono::milliseconds(100));
    system("rm *.wav");
}
