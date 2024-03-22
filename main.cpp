#include <ctime>
#include <iostream>
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

void print_grid(string**& grid, int num) {
    system("clear");
    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++){
            cout<<grid[i][j];
        }
        cout<<'\n';
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout<<"Uso: "<<argv[0]<<" [Cantidad]\n";
        return 1;
    }
    int num=stoi(argv[1]);

    vector<int> array(num);
    shuffle_vector(array);
    
    bool sorted=false;
    string **grid;
    create_grid(grid, num, array);
    print_grid(grid, num);

}
