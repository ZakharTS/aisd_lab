#include <iostream>
#include "prime.h"
#include "kruskal.h"

int main() {
    int n;
    std::cout << "Node amount: ";
    std::cin >> n;
    std::vector<std::pair<int, int>> graph[n];
    int m;
    std::cout << "Edge amount: ";
    std::cin >> m;
    std::vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, w; //a node, b node, weight
        std::cin >> a >> b >> w;
        graph[a].push_back(std::make_pair(b, w));
        edge curEdge;
        curEdge.a = a;
        curEdge.b = b;
        curEdge.len = w;
        edges.push_back(curEdge);
    }
    std::cout << "Prime:" << std::endl;
    prime(graph, n);
    std::cout << std::endl << "Kruskal:" << std::endl;
    kruskal(edges, n);
    return 0;
}
