#include "dijkstra.h"



void dijkstra(std::vector<std::pair<int, int>> graph[], int n, int start) {
    int ans[n];
    int pr[n];
    for (int i = 0; i < n; i++) {
        ans[i] = INT32_MAX;
        pr[i] = -1;
    }

    ans[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    q.push({0, start});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        int dst = cur.first, v = cur.second;

        if (ans[v] < dst) {
            continue;
        }

        for (auto e : graph[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < ans[u]) {
                ans[u] = n_dst;
                pr[u] = v;
                q.push({n_dst, u});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        std::vector<int> path;

        int cur = i;
        path.push_back(cur);

        while (pr[cur] != -1) {
            cur = pr[cur];
            path.push_back(cur);
        }

        reverse(path.begin(), path.end());

        std::cout << "Shortest path between vertices " << start + 1 << " and " << i + 1 << " is "  << ans[i]  << ":" << std::endl;

        for (auto v: path) {
            std::cout << v + 1 << ", ";
        }
        std::cout << std::endl;
    }
}