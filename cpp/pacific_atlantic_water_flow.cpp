// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/10 16:28:27
// Description: https://leetcode.cn/problems/pacific-atlantic-water-flow/?envType=daily-question&envId=2025-09-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<vector<int>> dir = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) {
        return;
    }
    if (visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    for (int k = 0; k < dir.size(); ++k) {
        int ni = i + dir[k][0];
        int nj = j + dir[k][1];
        if (ni < 0 || ni >= heights.size() || nj < 0 || nj >= heights[0].size()) {
            continue;
        }
        if (heights[ni][nj] < heights[i][j]) {
            continue;
        }
        dfs(heights, ni, nj, visited);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
    for (int i = 0; i < heights.size(); ++i) {
        dfs(heights, i, 0, pacific);
        dfs(heights, i, heights[0].size()-1, atlantic);
    }
    for (int j = 0; j < heights[0].size(); ++j) {
        dfs(heights, 0, j, pacific);
        dfs(heights, heights.size()-1, j, atlantic);
    }
    vector<vector<int>> result;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights[0].size(); ++j) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> result = pacificAtlantic(heights);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
}
