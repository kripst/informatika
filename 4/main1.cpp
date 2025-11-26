#include <iostream>
using namespace std;

void findMax(double *arr, int size, double *maxVal) {
    *maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *maxVal) {
            *maxVal = arr[i];
        }
    }
}

void divideByMax(double *arr, int size, double *maxVal) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] / *maxVal;
    }
}

int main() {
    double A[5], B[5];
    double maxA, maxB;

    for (int i = 0; i < 5; i++) cin >> A[i];
    for (int i = 0; i < 5; i++) cin >> B[i];

    findMax(A, 5, &maxA);
    findMax(B, 5, &maxB);

    divideByMax(A, 5, &maxA);
    divideByMax(B, 5, &maxB);

    for (int i = 0; i < 5; i++) cout << A[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++) cout << B[i] << " ";

    return 0;
}
