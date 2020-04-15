// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/19 15:44:30
// Description: https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void space(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}

int cal(int sum, vector<int64_t> &l, vector<int> &memo) {
    if (sum == 0) {
        return 0;
    }
    if (memo[sum] != 0) {
        return memo[sum];
    }
    int min_cnt = INT_MAX;
    for (int i = 0; i < l.size(); ++i) {
        if (sum < l[i]) {
            continue;
        }
        if (sum == l[i]) {
            return 1;
            break;
        }
        int n = 1 + cal(sum - l[i], l, memo);
        min_cnt = min(min_cnt, n);
    }
    memo[sum] = min_cnt;
    return min_cnt;
}

int numSquares(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n < 3) {
        return n;
    }
    vector<int64_t> square;
    for (int64_t i = n / 2; i > 0; --i) {
        int64_t s = i * i;
        if (s == n) {
            return 1;
        }
        if (s < n) {
            square.push_back(s);
        }
    }
    vector<int> memo(n+1, 0);
    int res = cal(n, square, memo);
    return res;
}

int numSquares2(int n) {
    if (n <= 0) {
        return 0;
    }
    vector<int> s(n+1, INT_MAX);
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            s[i] = min(s[i], s[i - j*j] + 1);
        }
    }
    return s[n];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << numSquares(n) << endl;
    cout << numSquares2(n) << endl;
}
