// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/06/29 11:46:56
// Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int dfs(vector<int>& p, int s, int k, int buy, int profit) {
    if (k == 0) {
        return profit;
    }
    if (s >= p.size()) {
        return profit;
    }
    if (buy < 0) {
        if (p.size() - s < 2) {
            return profit;
        }
        int mmax = INT_MIN;
        for (int i = s; i < p.size(); ++i) {
            int t = dfs(p, i+1, k, p[i], profit);
            if (t > mmax) {
                mmax = t;
            }
        }
        return mmax;
    }
    int mmax = 0;
    for (int i = s; i < p.size(); ++i) {
        if (p[i] < buy) {
            continue;
        }
        int t = dfs(p, i, k-1, -1, profit + p[i] - buy);
        if (t > mmax) {
            mmax = t;
        }
    }
    return mmax;
}

int maxProfit(int k, vector<int>& prices) {
    return dfs(prices, 0, k, -1, 0);
}

int main(int argc, char *argv[]) {
    vector<int> a = {2,1,4};
    cout << maxProfit(2, a) << endl;
}
