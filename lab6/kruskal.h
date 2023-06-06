#ifndef LAB6_KRUSKAL_H
#define LAB6_KRUSKAL_H

#include <bits/stdc++.h>
struct edge {
    int a, b, len;

    bool operator<(const edge &other) {
        return len < other.len;
    }
};

void kruskal(std::vector<edge> edges, int size);
#endif //LAB6_KRUSKAL_H
