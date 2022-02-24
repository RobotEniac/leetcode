// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/12/17 15:03:08
// Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int dfs(vector<int> &p, int s) {
    if (p.size() - s < 2) {
        return 0;
    }
    int t1 = 0;
    for (int i = s+1; i < p.size(); ++i) {
        if (p[i] > p[s]) {
            int x = dfs(p, i+2) + p[i] - p[s];
            if (x > t1) {
                t1 = x;
            }
        }
    }
    int t2 = dfs(p, s+1);
    return std::max(t1, t2);
}

int maxProfit(vector<int> &prices)
{
    vector<int> profit(prices.size()+5, 0);
    for (int i = prices.size() - 2; i >= 0; --i) {
        int t1 = 0;
        for (int j = i+1; j < prices.size(); ++j) {
            if (prices[j] > prices[i]) {
                int x = profit[j+1] + prices[j] - prices[i];
                if (x > t1) {
                    t1 = x;
                }
            }
        }
        int t2 = profit[i+1];
        profit[i] = std::max(t1, t2);
    }
    cout << prices << endl;
    cout << profit << endl;
    return profit[0];
}

int main(int argc, char *argv[]) {
    vector<int> p = {7,1,5,3,6,4};
    cout << maxProfit(p) << endl;
}
