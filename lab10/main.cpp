#include <bits/stdc++.h>
using namespace std;

int main() {
    int [] mc = new int[cost.length + 1];
    mc[0] = cost[0];
    mc[1] = cost[1];

    for(int i = 2; i <= cost.length; i++){
        int costV = (i==cost.length)?0:cost[i];
        mc[i] = Math.min(mc[i-1] + costV, mc[i-2] + costV);
    }
    cout << ans[n-1] << endl;
    return 0;
}
