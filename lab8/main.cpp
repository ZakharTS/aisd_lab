#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fill(vector<vector<char>>& grid, int x, int y) {
        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[x].size() && grid[x][y] == '1') {
            grid[x][y] = '0';
            fill(grid, x, y + 1);
            fill(grid, x + 1, y);
            fill(grid, x, y - 1);
            fill(grid, x - 1, y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    fill(grid, i, j);
                }
            }
        }
        return count;
    }
};