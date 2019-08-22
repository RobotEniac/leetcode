// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/08/08 10:40:59
// Description: https://leetcode.com/problems/maximal-square/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void dfs(vector<vector<char> >& matrix, int i, int j) {
}

int maximalSquare(vector<vector<char> >& matrix) {
    int m = matrix.size();
    if (m == 0) {
        return 0;
    }
    int n = matrix[0].size();
    vector<vector<int> > dp(m, vector<int>(n, 0));
    int max_len = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0 || matrix[i][j] == '0') {
                dp[i][j] = matrix[i][j] - '0';
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                }
            }
        }
    }
    return max_len * max_len;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
    vector<vector<char> > v = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0},
    };
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            v[i][j] = v[i][j] + '0';
        }
    }
    cout << maximalSquare(v) << endl;
}
