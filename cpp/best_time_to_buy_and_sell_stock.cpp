// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/12/17 10:50:52
// Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<int>& p, int s) {
    cout << "{";
    for (int i = s; i < p.size(); ++i) {
        if (i != s) {
            cout << ", ";
        }
        cout << p[i];
    }
    cout << "}" << std::endl;
}

int dfs(vector<int> &p, int s) {
    show(p, s);
    if (p.size() - s < 2) {
        return 0;
    }
    int t1 = 0;
    for (int i = s+1; i < p.size(); ++i) {
        if (p[i] > p[s]) {
            int x = dfs(p, i+1) + p[i] - p[s];
            if (x > t1) {
                t1 = x;
            }
        }
    }
    int t2 = dfs(p, s+1);
    cout << "(" << t1 << ", " << t2 << ")\n";
    return std::max(t1, t2);
}

int maxProfit(vector<int> &prices)
{
    vector<int> mmax = prices;
    for (int i = prices.size() - 2; i >= 0; --i) {
        mmax[i] = std::max(prices[i], mmax[i+1]);
    }
    int ret = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (mmax[i+1] - prices[i] > ret) {
            ret = mmax[i+1] - prices[i];
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}
