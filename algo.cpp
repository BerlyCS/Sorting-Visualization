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

void selection_sort(vector<int>& array, int num){
    int pointer,max;
    for (int i=num;i>=0;i--) {
        max=0;
        for (int j=0;j<i;j++) {
            if (array[max]<array[j]) {
                max=j;
            }
            print_vect(array);
        }
        swap(array[i-1],array[max]);
    }
}

vector<int> merge(vector<int> first_half, vector<int> sec_half) {
    vector<int> merged(first_half.size()+sec_half.size());

    while (true) {
        h;
    }
    return merged;

}
void merge_sort(vector<int>& array, int num){
    //Compute the max index of the halves
    int fhli,lhfi;
    if (num<=1){
        return;
    }
    fhli=num/2;
    lhfi=fhli+1;
    vector<int> fh(array.begin(),array.begin()+fhli);
    vector<int> lh(array.begin()+lhfi,array.end());


    while (middle!=0) {

    }
}

void quick_sort(vector<int> &array, int num) {
    int pivot=array.size()/2;

}

void binary_sort(vector<int> &array, int num) {

}

int main(int argc, char* argv[]) {
    if (argc<2) cout<<"./algo <numero>\n";
    vector<int> a(stoi(argv[1]));
    shuffle_vector(a);
    selection_sort(a, a.size());

   // insert_sort(a, a.size());
    return 0;
}
