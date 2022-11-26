#include <iostream>
#include "dijkstra.h"


int main() {
    int n;
    std::cout << "Node amount: ";
    std::cin >> n;
    std::vector<std::pair<int, int>> graph[n];
    int m;
    std::cout << "Edge amount: ";
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w; //a node, b node, weight
        std::cin >> a >> b >> w;
        graph[a - 1].push_back(std::make_pair(b - 1, w));
    }
    dijkstra(graph, n, 0);

    return 0;
}
