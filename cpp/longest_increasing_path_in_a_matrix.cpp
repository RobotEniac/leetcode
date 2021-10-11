// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/09/14 12:04:09
// Description: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<vector<int>> dir = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

void dfs(vector<vector<int>> &matrix,
         vector<vector<int>> &board,
         int sx,
         int sy,
         int depth,
         int &longest,
         vector<int> path)
{
    for (int i = 0; i < dir.size(); ++i) {
        int x = sx + dir[i][0];
        int y = sy + dir[i][1];
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) {
            continue;
        }
        if (board[x][y] > 0) {
            continue;
        }
        if (matrix[x][y] <= matrix[sx][sy]) {
            continue;
        }
        board[x][y] = 1;
        if (depth + 1 > longest) {
            longest = depth + 1;
        }
        dfs(matrix, board, x, y, depth + 1, longest);
        board[x][y] = 0;
    }
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    vector<vector<int>> board(matrix.size(), vector<int>(matrix[0].size(), 0));
    int longest = 0;
    vector<int> path;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            board[i][j] = 1;
            path.push_back(matrix[i][j]);
            dfs(matrix, board, i, j, 1, longest);
            path.pop_back();
            board[i][j] = 0;
        }
    }
    return longest;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> m = {{9,9,4},{6,6,8},{2,1,1}};
    cout << longestIncreasingPath(m) << endl;
}
