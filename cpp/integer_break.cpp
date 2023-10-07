// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/06/30 19:10:50
// Description: https://leetcode.cn/problems/integer-break/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void dfs(int n, int k, int mul, int &mmax) {
    if (k == 1) {
        int t = mul * n;
        if (t > mmax) {
            mmax = t;
        }
        return;
    }
    for (int i = 1; i < n; ++i) {
        int t = mul * i;
        if (t > mmax) {
            mmax = t;
        }
        dfs(n-i, k-1, t, mmax);
    }
}

int fast_pow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    if ((n & 1) == 1) {
        int t = fast_pow(a, n / 2);
        return t * t * a;
    }
    int t = fast_pow(a, n/2);
    return t * t;
}

int integerBreak(int n) {
    int r = n % 3;
    if (r == 0) {
        return fast_pow(3, n / 3);
    }
    if ( r == 1) {
        return fast_pow(3, (n-4)/3) * 4;
    }
    if (r == 2) {
        return fast_pow(3, n/3) * 2;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    cout << integerBreak(10) << endl;
}
