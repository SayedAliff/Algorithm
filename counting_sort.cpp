#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* countingSort(int arr[], int n, int maxValue) {
    int* sortedArray = new int[n];
    int* countArray = new int[maxValue + 1];

  
    fill(countArray, countArray + maxValue + 1, 0);

   
    for (int i = 0; i < n; i++) {
        countArray[arr[i]]++;
    }

    for (int i = 1; i <= maxValue; i++) {
        countArray[i] += countArray[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        sortedArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }

    delete[] countArray;

    return sortedArray;
}

int main() {
    int A[] = {4, 3, 2, 5, 4, 3, 5, 1, 0, 2, 5};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Input array: ";
    printArray(A, n);

    int max = *max_element(A, A + n);

    int* sortedArray = countingSort(A, n, max);
    cout << "Sorted array: ";
    printArray(sortedArray, n);

    delete[] sortedArray;

    return 0;
}

