#include "floydwarshall.h"

void floydwarshall(std::vector<std::pair<int, int>> graph[], int n) {
    int matr[n][n];
    int prev[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prev[i][j] = 0;
            matr[i][j] = INT_MAX / 2;
            if (i == j) matr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) matr[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (auto itr: graph[i]) {
            int j = itr.first;
            matr[i][j] = matr[j][i] = itr.second;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matr[i][k] + matr[k][j] < matr[i][j]) {
                    matr[i][j] = matr[i][k] + matr[k][j];
                    prev[i][j] = k;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) std::cout << matr[i][j] << " ";
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }
            }
        }
    }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matr[i][j] == 0 || matr[i][j] == INT_MAX / 2) continue;
                std::cout << "Shortest path between vertices " << i + 1 << " and " << j + 1 << " is " << matr[i][j]
                          << ":" << std::endl;
                std::cout << i + 1 << " ";
                int tmp = j;
                while (prev[i][tmp] != 0){
                    std::cout << prev[i][tmp] + 1 << " ";
                    tmp = prev[i][tmp];
                }
                if (i != j) std::cout << j + 1;
                std::cout << "\n";
            }
        }
    }