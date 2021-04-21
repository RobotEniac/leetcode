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

void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
    if (i < 0 || i >= grid.size()) {
        return;
    }
    if (j < 0 || j >= grid[i].size()) {
        return;
    }
    if (grid[i][j] == -1 || grid[i][j] == 3 || grid[i][j] == 1) {
        return;
    }
    if (grid[i][j] == 2) {
        ++count;
    }
    grid[i][j] = 3;
    for (int k = 0; k < dir.size(); ++k) {
        dfs(grid, i+dir[k][0], j+dir[k][1], count);
    }
    grid[i][j] = 0;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int si = 0;
    int sj = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j])
        }
    }
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
