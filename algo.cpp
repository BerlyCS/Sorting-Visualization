#include <iostream>
#include <string>
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

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void merge_sort(vector<int>& array, int izq, int der){

    if ( izq < der ) {
        int mid = (izq + ( der - izq ))/2;
        merge_sort(array, izq, mid);
        merge_sort(array, mid+1, der);
        print_vect(array);

        merge(array, izq, mid, der);
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
    /* selection_sort(a, a.size()); */
    merge_sort(a, 0, a.size()-1);

   // insert_sort(a, a.size());
    return 0;
}
