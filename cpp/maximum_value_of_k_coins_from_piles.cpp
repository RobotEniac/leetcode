// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/19 11:48:52
// Description: https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/?envType=daily-question&envId=2025-05-19

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &vv, vector<int>& idx) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = idx[i]; j < vv[i].size(); ++j) {
            if (j != idx[i]) {
                cout << " | " << vv[i][j];
            } else {
                cout << vv[i][j];
            }
        }
        cout << endl;
    }
    cout << "=====\n";
}

void dfs(vector<vector<int>> &piles, vector<int>& idx, int k, int sum, int &max_sum) {
    show(piles, idx);
    if (k == 0) {
        if (max_sum < sum) {
            max_sum = sum;
        }
        return;
    }
    for (int i = 0; i < piles.size(); ++i) {
        if (idx[i] < piles[i].size()) {
            sum += piles[i][idx[i]];
            ++idx[i];
            dfs(piles, idx, k-1, sum, max_sum);
            --idx[i];
            sum -= piles[i][idx[i]];
        }
    }
}

int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    vector<int> idx(piles.size(), 0);
    int max_sum = 0;
    dfs(piles, idx, k, 0, max_sum);
    return max_sum;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> p = {{1,100,3},{7,8,9}};
    cout << maxValueOfCoins(p, 2) << endl;
}
