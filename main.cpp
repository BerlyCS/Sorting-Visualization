#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <__errc>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std;

//Colores formato ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

sf::SoundBuffer buffer[10];
sf::Sound sound[10];
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

void delete_grid(string**& grid, int num){
    for (int i=0;i<num;i++){
        delete[] grid[i];
    }
    delete[] grid;
}


void swap_grid(string**& grid, int num, int lt, int gt) {
    for (int i=0;i<num;i++) {
        swap(grid[i][lt],grid[i][gt]);
    }
    
    sound[int(lt/(num/10))%10].play();

}

void print_grid(string**& grid, int num, int curr, int mv) {
    system("clear");

    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++){
            if (j==curr)
                cout<<RED<<grid[i][j]<<RESET;
            else if (j==mv)
                cout<<GREEN<<grid[i][j]<<RESET;
            else
                cout<<grid[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
    system(("sleep "+to_string(sleep)).c_str());
}

void verify_sort(string **&grid, int num, vector<int> array) {
    sleep=0.01;
    for (int i=0;i<array.size()-1;i++){
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

void insert_sort(vector<int> &a, int num, string**& grid) {
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

int main(int argc, char* argv[]) {
    for (int i=0; i<10; i++){
        buffer[i].loadFromFile("sounds/beep"+to_string(i)+".wav");
        sound[i].setBuffer(buffer[i]);
    }


    if (argc < 2) {
        cout<<"Uso: "<<argv[0]<<" [Cantidad] {sleep}\n";
        return 1;
    }
    int num=stoi(argv[1]);
    if (argc==3)
        sleep=stof(argv[2]);
    else
        sleep=0.5;

    vector<int> array(num);
    shuffle_vector(array);
    
    /* bool sorted=false; */
    string **grid;
    create_grid(grid, num, array);
    /* print_grid(grid, num); */
    /* bubble_sort(array, num, grid); */
    insert_sort(array, num, grid);
    
    verify_sort(grid, num, array);
    for (int i=0;i<num;i++)
        cout<<array[i]<<' ';
}
