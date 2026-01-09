// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/09 11:32:49
// Description: https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2026-01-07

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "file_util.hpp"

using namespace std;

void dfs(vector<vector<int>> &g, int x, int y, int64_t sum, int k, int64_t *cnt) {
    if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) {
        return;
    }
    if (x == g.size() - 1 && y == g[0].size() - 1) {
        sum += g[x][y];
        if (sum % k == 0) {
            ++(*cnt);
        }
    }
    dfs(g, x+1, y, sum + g[x][y], k, cnt);
    dfs(g, x, y+1, sum + g[x][y], k, cnt);
}

int numberOfPaths(vector<vector<int>> &grid, int k) {
    int64_t cnt = 0;
    dfs(grid, 0, 0, 0, k, &cnt);
    return cnt;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> g = lc::ReadMatrix("[[7,3,4,9],[2,3,6,2],[2,3,7,0]]");;
    cout << numberOfPaths(g, 1) << endl;
}
