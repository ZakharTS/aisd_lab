#include "floydwarshell.h"

void floydwarshell(std::vector<std::pair<int, int>> graph[], int n) {
    int matr[n][n];
    std::vector<int> path[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matr[i][j] = INT32_MAX;
        }
    }
    for (int i = 0; i < n; i++) matr[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (auto itr: graph[i]) {
            int j = itr.first;
            matr[i][j] = matr[j][i] = itr.second;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matr[j][k] = std::min(matr[j][k], matr[j][i] + matr[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] == 0 || matr [i][j] == INT32_MAX) continue;
            std::cout << "Shortest path between vertices " << i + 1 << " and " << j + 1 << " is "  << matr[i][j] << ":" << std::endl;
        }
    }
}