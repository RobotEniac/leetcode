// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/13 15:41:52
// Description: https://leetcode-cn.com/problems/01-matrix/

#include <iostream>
#include <vector>
#include <string>
#include <deque>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            printf("%-4d", m[i][j]);
        }
        printf("\n");
    }
}

void bfs(vector<vector<int>>& matrix, vector<vector<int>>& res, int i, int j) {
    vector<vector<int>> height(matrix.size(), vector<int>(matrix[0].size(), -1));
    deque<vector<int>> q;
    vector<int> t(2, 0);
    vector<vector<int>> dir = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    t[0] = i;
    t[1] = j;
    height[i][j] = 0;
    q.push_back(t);
    while (!q.empty()) {
        vector<int> tp = q.front();
        q.pop_front();
        for (int k = 0; k < dir.size(); ++k) {
            i = tp[0] + dir[k][0];
            j = tp[1] + dir[k][1];
            if (i >= 0 && i < matrix.size() &&
                j >= 0 && j < matrix[0].size() && height[i][j] < 0) {
                height[i][j] = height[tp[0]][tp[1]] + 1;
                if (height[i][j] < res[i][j]) {
                    res[i][j] = height[i][j];
                }
                t[0] = i;
                t[1] = j;
                q.push_back(t);
            }
        }
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    vector<int> t(2, 0);
    deque<vector<int>> q;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                res[i][j] = 0;
                t[0] = i;
                t[1] = j;
                q.push_back(t);
            }
        }
    }

    vector<vector<int>> dir = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    while (!q.empty()) {
        vector<int> tp = q.front();
        q.pop_front();
        for (int k = 0; k < dir.size(); ++k) {
            int i = tp[0] + dir[k][0];
            int j = tp[1] + dir[k][1];
            if (i >= 0 && i < matrix.size() &&
                j >= 0 && j < matrix[0].size() && res[i][j] == INT_MAX) {
                res[i][j] = res[tp[0]][tp[1]] + 1;
                t[0] = i;
                t[1] = j;
                q.push_back(t);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    show(matrix);
    vector<vector<int>> res = updateMatrix(matrix);
    show(res);
}
