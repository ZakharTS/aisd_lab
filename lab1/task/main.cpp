#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n = rand()%5001 + 5000;
    cout << "n = " << n << endl;
    int ** matrix = new int * [n];
    for(int i = 0; i < n; i++) matrix[i] = new int[n];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] = rand()%1000 - 500;
        }
    }
    clock_t time = clock();
    long long sumP = 0, sumN = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (matrix[i][j] >= 0) {
                sumP += matrix[i][j];
            } else {
                sumN += matrix[i][j];
            }
        }
    }
    time = clock() - time;
    cout << "Time is " << time << " ms" << endl;
    return 0;
}
