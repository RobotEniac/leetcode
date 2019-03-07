// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/06 20:13:43
// Description: https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<char>> &grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
}

void dfs(vector<vector<char> > &grid, int i, int j, int color) {
    if (i < 0 || i >= grid.size()) {
        return;
    }
    if (j < 0 || j >= grid[0].size()) {
        return;
    }
    if (grid[i][j] == 0) {
        return;
    }
    if (grid[i][j] > 1) {
        return;
    }
    grid[i][j] = 10 + color;
    dfs(grid, i+1, j, color);
    dfs(grid, i, j+1, color);
    dfs(grid, i-1, j, color);
    dfs(grid, i, j-1, color);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    int color = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = grid[i][j] - '0';
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                continue;
            }
            if (grid[i][j] == 1) {
                dfs(grid, i, j, color++);
            }
        }
    }
    return color;
}

int main(int argc, char *argv[]) {
    vector<vector<char>> grid;
    int N = 10;
    int M = 10;
    for (int i = 0; i < N; ++i) {
        grid.push_back(vector<char>());
        for (int j = 0; j < M; ++j) {
            grid[i].push_back((rand() % 100) % 2);
        }
    }
    show(grid);
    cout << "==========\n";
    cout << numIslands(grid) << endl;
}
