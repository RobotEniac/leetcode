// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/03/12 14:23:23
// Description: https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/?envType=daily-question&envId=2024-03-12

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int ms(int64_t x, int64_t y) {
    const int64_t m = (1e9)+7;
    return ((x % m) + (y % m)) % m;
}

int numRollsToTarget(int n, int k, int t) {
    vector<int> v(n*k+1, 0);
    vector<int> tv(n*k+1, 0);
    for (int i = 1; i <= k; ++i) {
        v[i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        cout << v << endl;
        for (int j = i; j <= i*k; ++j) {
            tv[j] = 0;
            for (int s = 1; s < j && s <= k; ++s) {
                tv[j] = ms(tv[j], v[j-s]);
            }
        }
        for (int j = 0; j <= i*k; ++j) {
            if (j < i) {
                v[j] = 0;
            } else {
                v[j] = tv[j];
            }
        }
    }
    cout << v << endl;
    return v[t];
}

int main(int argc, char *argv[]) {
    cout << numRollsToTarget(30, 30, 500) << endl;
    int t = 1e9 + 7;
}
