#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void print_vect(vector<int> a) {
    for (int i=0;i<a.size();i++){
        cout << a[i]<< ' ';
    }
    cout<<'\n';
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
void insert_sort(vector<int> &a, int n) {
    for (int i=0;i<n-1;i++){
        for (int j=i;j>=0;j--){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            } else if (a[j]<a[j+1]){
                break;
            }
            print_vect(a);
        }
    }
}

void bubble_sort(vector<int> &array, int num) {
    for (int i=num-1;i>=0;i--) {
        for (int j=0;j<i;j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
            print_vect(array);
        }
        
    }
}

using namespace std;
int main(int argc, char* argv[]) {
    if (argc<2) cout<<"./algo <numero>\n";
    vector<int> a(stoi(argv[1]));
    shuffle_vector(a);

    insert_sort(a, a.size());
    return 0;
}
