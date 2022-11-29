
#include "prime.h"

int prime(std::vector <std::pair<int, int>> graph[], int size) {
    bool used[size];
    int mst_weight = 0;     //Текущий вес остова.

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.push({0, 0});     //Начнём с вершины 0.

    while (!q.empty()) {
        std::pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {      //вершина уже добавлена в остов
            continue;
        }

        used[v] = true;
        mst_weight += dst;

        for (auto e: graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) {
                q.push({len_vu, u});    //Заметьте: мы учитываем только длину ребра.
            }
        }
    }

    std::cout << "Minimum spanning tree weight: " << mst_weight << std::endl;
}