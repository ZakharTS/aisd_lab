    #include "prime.h"

void prime(std::vector <std::pair<int, int>> graph[], int size) {
    bool used[size];
    int pr[size];
    for (int i = 0; i < size; i++) {
        pr[i] = -1;
        used[i] = 0;
    }
    int mst_weight = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.push({0, 0});
    int last;
    while (!q.empty()) {
        std::pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {
            continue;
        }
        last = v;
        used[v] = true;
        mst_weight += dst;

        for (auto e: graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) {
                pr[u] = v;
                q.push({len_vu, u});
            }
        }
    }

    std::cout << "Minimum spanning tree weight is " << mst_weight << ":" << std::endl;
    std::vector<int> path;

    path.push_back(last);

    while (pr[last] != -1) {
        last = pr[last];
        path.push_back(last);
    }
    reverse(path.begin(), path.end());
    for (auto v: path) {
        std::cout << v + 1 << " ";
    }
    std::cout << std::endl;
}