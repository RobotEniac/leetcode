// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/21 16:59:47
// Description: https://leetcode-cn.com/problems/unique-paths-iii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<vector<int>> dir = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};

bool is_first = true;

void show(vector<vector<int>> &g) {
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            printf("%4d", g[i][j]);
        }
        printf("\n");
    }
}

bool is_all_accessed(vector<vector<int>> &g) {
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
    if (i < 0 || i >= grid.size()) {
        return;
    }
    if (j < 0 || j >= grid[i].size()) {
        return;
    }
    show(grid);
    cout << "==========\n";
    if (grid[i][j] == 2) {
        if (is_all_accessed(grid)) {
            ++count;
        }
    }
    if (grid[i][j] != 0) {
        return;
    }
    grid[i][j] = 3;
    for (int k = 0; k < dir.size(); ++k) {
        dfs(grid, i+dir[k][0], j+dir[k][1], count);
    }
    grid[i][j] = 0;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int si = -1;
    int sj = -1;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1) {
                si = i;
                sj = j;
                break;
            }
        }
        if (si > 0) {
            break;
        }
    }
    int count = 0;
    grid[si][sj] = 0;
    dfs(grid, si, sj, count);
    grid[si][sj] = 1;
    return count;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> grid = {
        {1,0,0,0},{0,0,0,0},{0,0,2,-1}
    };
    cout << uniquePathsIII(grid) << endl;
}
