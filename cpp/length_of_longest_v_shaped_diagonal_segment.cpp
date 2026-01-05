// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/08/27 15:30:27
// Description: https://leetcode.cn/problems/length-of-longest-v-shaped-diagonal-segment/description/?envType=daily-question&envId=2025-08-27

#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int>>& grid, vector<vector<int>>& visited) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            printf("%3d", visited[i][j] ? 10+grid[i][j] : grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(vector<vector<int>>& grid, 
    int i, int j, int exp, int dir, bool v,
    vector<vector<int>>& visited, int& path, int& ret) {
    static vector<vector<int>> dirs = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    static bool turn = false;
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] != exp) {
        return;
    }
    visited[i][j] = 1;
    ++path;
    if (path > ret) {
        ret = path;
    }
    if (exp == 0 || exp == 1) {
        exp = 2;
    } else {
        exp = 0;
    }
    if (path == 1) {
        for (int d = 0; d < dirs.size(); ++d) {
            dfs(grid, i + dirs[d][0], j + dirs[d][1], exp, d, v, visited, path, ret);
        }
    } else {
        dfs(grid, i + dirs[dir][0], j + dirs[dir][1], exp, dir, v, visited, path, ret);
        if (!v) {
            dir = (dir + 1) % 4;
            dfs(grid, i + dirs[dir][0], j + dirs[dir][1], exp, dir, true, visited, path, ret);
        }
    }
    visited[i][j] = 0;
    --path;
}

int lenOfVDiagonal(vector<vector<int>>& grid) {
    int ret = 0;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                int path = 0;
                dfs(grid, i, j, 1, 0, false, visited, path, ret);
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> grid = {{2,2,2,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    show(grid, visited);
    cout << lenOfVDiagonal(grid) << endl;
}
