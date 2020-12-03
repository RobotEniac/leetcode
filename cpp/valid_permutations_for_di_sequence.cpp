// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/22 11:09:21
// Description: https://leetcode.com/problems/valid-permutations-for-di-sequence/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;


// dp[i][j] 表示在 0..i 数字的permutation中以数字j结尾的，满足S表示的type的序列数
// e.g. S = DID
// dp[2][0] = 0
// dp[2][1] 表示 201
// dp[3][2] 表示 3012 dp[3][2] = dp[2][0] + dp[2][1];

int numPermsDISequence(string S) {
    int n = S.size();
    int m = 1e9 + 7;
    cout << m << "\n";
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <=i; ++j) {
            if (S[j] == 'D') {
                for (int k = j; k <= i-1; ++k) {
                    dp[i][j] = dp[i][j] % m + dp[i-1][k] % m;
                }
            } else if (S[j] == 'I') {
                for (int k = 0; k <= j-1; ++k) {
                    dp[i][j] = dp[i][j] % m + dp[i-1][k] % m;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        res = res % m + dp[n][i] % m;
    }
    return res;
}

int main(int argc, char *argv[]) {
    string S(argv[1]);
    cout << S << ": " << numPermsDISequence(S) << endl;
}
