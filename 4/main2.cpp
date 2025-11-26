#include <iostream>
#include <set>
using namespace std;

void fillSet(set<int> &s, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        s.insert(arr[i]);
    }
}

void calc(set<int> &A, set<int> &B, set<int> &res) {
    for (int v : B) {
        if (A.count(v) == 0 && v < 0) {
            res.insert(v);
        }
    }
}

int main() {
    set<int> A;
    set<int> B;
    set<int> result;

    int arrA[10] = {1, -3, 5, 7, 2, 9, -1, 4, 6, 8};
    int arrB[10] = {-5, 3, -3, -7, 10, 2, -9, 4, 11, -1};

    fillSet(A, arrA, 10);
    fillSet(B, arrB, 10);

    calc(A, B, result);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}
