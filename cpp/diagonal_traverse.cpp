// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/08/25 20:50:51
// Description: https://leetcode.cn/problems/diagonal-traverse/description/?envType=daily-question&envId=2025-08-25

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> ret;
    int m = mat.size();
    int n = mat[0].size();
    int i = 0, j = 0;
    int d = 0;
    vector<vector<int>> dirs = {{-1, 1}, {1, -1}};
    while (i != m || j != n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            ret.push_back(mat[i][j]);
        }
        i += dirs[d][0];
        j += dirs[d][1];
        if (i < 0 && j < n) {
            ++i;
            d = (d + 1) % 2;
        } else if (j < 0 && i < m) {
            ++j;
            d = (d + 1) % 2;
        } else if (i == m) {
            ++j;
            d = (d + 1) % 2;
        } else if (j == n) {
            ++i;
            d = (d + 1) % 2;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ret = findDiagonalOrder(mat);
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
