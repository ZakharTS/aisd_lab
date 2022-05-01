#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int findMax(int *, size_t);
void sortCount(int *, size_t, int);
void sortInsert(int *, size_t);
void sortPyramid(int *, size_t);
void to_heap(int *, size_t, size_t);
void display(int *, size_t);

int main() {
    for (size_t n = 50000; n <= 1000000; n += 50000) {
        int * arr1 = new int[n], * arr2 = new int[n], * arr3 = new int[n];
        for (size_t i = 0; i < n; i++) {
            int temp = 3 * rand();
            arr1[i] = temp;
            arr2[i] = temp;
            arr3[i] = temp;
        }
        cout << "n = " << n << endl;
        int k = findMax(arr1, n);
        clock_t time = clock();
        sortCount(arr1, n, k);
        time = clock() - time;
        cout << "sortCount() run time is " << time << " ms" << endl;

        time = clock();
        sortInsert(arr2, n);
        time = clock() - time;
        cout << "sortInsert() run time is " << time << " ms" << endl;

        time = clock();
        sortPyramid(arr3, n);
        time = clock() - time;
        cout << "sortPyramid() run time is " << time << " ms" << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<" << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    return 0;
}

void display(int * arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int * arr, size_t n) {
    int maximum = 0;
    for (size_t i = 0; i < n; i++) {
        maximum = max(maximum, arr[i]);
    }
    return maximum;
}

void sortCount(int * arr, size_t n, int maximum) {
    int * count = new int[maximum + 1];
    for(size_t i = 0; i < maximum; i++) {
        count[i] = 0;
    }

    for (size_t i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int b = 0;
    for (size_t i = 0; i <= maximum; i++) {
        for(size_t j = 0; j < count[i]; j++) {
            arr[b++] = i;
        }
    }
}

void sortInsert(int * arr, size_t n) {
    for (int step = 1; step < n; step++) {
        int key = arr[step];
        int j;
        for (j = step - 1; key < arr[j] && j >= 0; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void sortPyramid(int * arr, size_t n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        to_heap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        to_heap(arr, i, 0);
    }
}

void to_heap(int * arr, size_t n, size_t root) {
    size_t largest = root;
    size_t left = root * 2 + 1;
    size_t right = root * 2 + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        swap(arr[root], arr[largest]);
        to_heap(arr, n, largest);
    }
}