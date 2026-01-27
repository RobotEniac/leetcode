// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/26 16:15:36
// Description: https://leetcode.cn/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-26

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int cm = 0;
    int mm = INT_MAX;
    int sum = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] >= 0) {
                if (mm > matrix[i][j]) {
                    mm = matrix[i][j];
                }
                sum += matrix[i][j];
            } else {
                if (mm > -matrix[i][j]) {
                    mm = -matrix[i][j];
                }
                sum -= matrix[i][j];
                ++cm;
            }
        }
    }
    cout << cm << ", " << mm << ", " << sum << endl;
    if (cm & 0x1) {
        return sum - mm - mm;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> m = lc::ReadMatrix("[[1,2,3],[-1,-2,-3],[1,2,3]]");
    cout << m << endl;
    cout << maxMatrixSum(m) << endl;
}
