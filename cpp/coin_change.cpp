// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/11/30 12:07:39
// Description: https://leetcode-cn.com/problems/coin-change/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

int dfs(vector<int> &coins, int e, int amount) {
    cout << coins << ", " << e << ", " << amount << "\n";
    if (coins.empty()) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }
    if (coins[0] > amount) {
        return -1;
    }
    for (int i = e - 1; i >= 0; --i) {
        if (coins[i] > amount) {
            continue;
        }
        if (coins[i] == amount) {
            return 1;
        }
        int d = amount / coins[i];
        while (d > 0)
        {
            int t = dfs(coins, i, amount - coins[i] * d);
            if (t > 0)
            {
                return t + d;
            }
            else
            {
                --d;
            }
        }
    }
    return -1;
}

int coinChange(vector<int> &coins, int amount) {
    sort(coins.begin(), coins.end());
    vector<int> res(amount+1, 0);
    for (int i = coins[0]; i <= amount; ++i) {
        int mmin = INT32_MAX;
        for (int j = 0; j < coins.size(); ++j) {
            int t = i - coins[j];
            if (res[t] < mmin) {
                mmin = res[t];
            }
        }
        res[i] = mmin + 1;
    }
    return res[amount];
}

int main(int argc, char *argv[]) {
    vector<int> c = {411,412,413,414,415,416,417,418,419,420,421,422};
    int t = coinChange(c, 9864);
    // vector<int> c = {1,2,5};
    // int t = coinChange(c, 11);
    cout << c << endl;
    cout << t << endl;
}
