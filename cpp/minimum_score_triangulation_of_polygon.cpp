// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/29 15:30:54
// Description: https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-29

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int minScoreTriangulation(vector<int>& values) {
    size_t n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i <= n-3; ++i) {
        dp[i][i+2] = values[i] * values[i+1] * values[i+2];
    }
    for (int len = 4; len <= n; ++len) {
        for (int i = 0; i <= n-len; ++i) {
            for (int k = i+1; k < i+len-1; ++k) {
                int t = dp[i][k] + dp[k][i+len-1] + values[i] * values[k] * values[i+len-1];
                if (dp[i][i+len-1] == 0 || dp[i][i+len-1] > t) {
                    dp[i][i+len-1] = t;
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,3,1,4,1,5};
    cout << minScoreTriangulation(v) << endl;
}
