#include "kruskal.h"

int get_root(int *p, int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = get_root(p, p[v]);   //На выходе из рекурсии переподвешиваем v
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

//Тип для представления рёбер.
struct edge {
    int a, b, len;

    bool operator<(const edge &other) {
        return len < other.len;
    }
};

int kruskal(std::vector<edge> edges, int size) {
    int p[size];
    int rk[size];
    for (int i = 0; i < size; i++) {
        p[i] = i;
        rk[i] = 1;
    }
    std::sort(edges.begin(), edges.end());

    int mst_weight = 0;


    for (edge e: edges) {
        if (merge(p, rk, e.a, e.b)) {      //Если a и b находятся в разных компонентах,
            mst_weight += e.len;    //Добавить ребро в минимальный остов.
        }
    }

    std::cout << "Minimum spanning tree weight: " << mst_weight << std::endl;
}