// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/11 19:54:08
// Description: https://leetcode.cn/problems/number-of-closed-islands/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void showGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, bool& edge) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return;
    }
    if (visited[i][j]) {
        return;
    }
    if (grid[i][j] == 1) {
        return;
    }
    visited[i][j] = true;
    if (i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) {
        edge = true;
    }
    dfs(grid, i+1, j, visited, edge);
    dfs(grid, i-1, j, visited, edge);
    dfs(grid, i, j+1, visited, edge);
    dfs(grid, i, j-1, visited, edge);
}

int closedIsland(vector<vector<int>>& grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                bool edge = false;
                dfs(grid, i, j, visited, edge);
                if (!edge) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    showGrid(grid);
    cout << "==========\n";
    cout << closedIsland(grid) << endl;
}
