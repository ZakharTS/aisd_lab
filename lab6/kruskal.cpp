#include "kruskal.h"

int get_root(int *p, int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = get_root(p, p[v]);
    }
}

bool merge(int *p, int *rk, int a, int b) {
    int ra = get_root(p, a), rb = get_root(p, b);

    if (ra == rb) {
        return false;
    } else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        } else {
            p[ra] = rb;
            rk[rb]++;
        }

        return true;
    }
}

void kruskal(std::vector<edge> edges, int size) {
    int p[size];
    int rk[size];
    for (int i = 0; i < size; i++) {
        p[i] = i;
        rk[i] = 1;
    }
    std::sort(edges.begin(), edges.end());

    int mst_weight = 0;
    std::vector<edge> res;
    for (edge e: edges) {
        if (merge(p, rk, e.a, e.b)) {
            mst_weight += e.len;
            res.push_back(e);
        }
    }
    std::cout << "Minimum spanning tree weight is " << mst_weight << ":" << std::endl;
    for (auto e : res) {
        std::cout << e.a << " - " << e.b << std::endl;
    }
}