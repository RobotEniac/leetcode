// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/08/26 14:23:00
// Description: https://leetcode.cn/problems/range-product-queries-of-powers/description/?envType=daily-question&envId=2025-08-25

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> get_bits(int n) {
    vector<int> bits;
    int c = 0;
    while (n > 0) {
        if (n & 1) {
            bits.push_back(c);
        }
        n >>= 1;
        ++c;
    }
    return bits;
}

int pow2(int n) {
    static const int MOD = 1e9 + 7;
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        ret = (ret << 1) % MOD;
    }
    return ret;
}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> bits = get_bits(n);
    vector<int> ret;
    vector<int> prefix_sum(bits.size()+1, 0);
    for (int i = 1; i < bits.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + bits[i - 1];
    }
    for (auto &query : queries) {
        int l = query[0], r = query[1];
        int sum = prefix_sum[r+1] - prefix_sum[l];
        ret.push_back(pow2(sum));
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> queries = {{0, 1}, {1, 2}};
    vector<int> ret = productQueries(15, queries);
    cout << ret << endl;
}
