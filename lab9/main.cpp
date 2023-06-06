#include <bits/stdc++.h>
using namespace std;

void findItems(int i, int j, vector<int> &result, vector<vector<int>> sum, int *w) {
    if (sum[i][j] == 0) return;
    if (sum[i][j] == sum[i-1][j]) {
        findItems(i - 1, j, result, sum, w);
    } else {
        findItems(i - 1, j - w[i], result, sum, w);
        result.push_back(i);
    }
}

int main() {
    int capacity, n;
    cin >> capacity >> n;
    int weight[n + 1], cost[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> cost[i];
    }
    vector<vector<int>> sum(n + 1, vector<int> (capacity + 1));
    for (int i = 0; i <= capacity; i++) {
        sum[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        sum[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j > weight[i]) {
                sum[i][j] = max(sum[i-1][j], cost[i] + sum[i-1][j - weight[i]]);
            } else {
                sum[i][j] = sum[i-1][j];
            }
        }
    }
    vector<int> result;
    findItems(n, capacity, result, sum, weight);
    cout << "Items:" << endl;
    for (auto cur : result) {
        cout << cur << " ";
    }
    return 0;
}
