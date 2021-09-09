// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/07/01 10:16:36
// Description: https://leetcode-cn.com/problems/paint-house/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int dfs(vector<vector<int>> &costs, int idx, int last_color, int total) {
    if (idx >= costs.size()) {
        return total;
    }
    int mmin = INT_MAX;
    for (int i = 0; i < costs[idx].size(); ++i) {
        if (i == last_color) {
            continue;
        }
        int t = dfs(costs, idx+1, i, total + costs[idx][i]);
        if (t < mmin) {
            mmin = t;
        }
    }
    return mmin;
}

int minCost(vector<vector<int>>& costs) {
    return dfs(costs, 0, -1, 0);
}

int main(int argc, char *argv[]) {
    vector<vector<int>> costs =
    {
        {{12,1,19},{15,1,10},{3,11,10},{9,3,10},{4,8,7},{4,18,2},{16,6,6},{3,3,6},{10,18,16},{5,4,8},{5,3,16},{11,8,19},{18,15,18},{16,4,15},{10,7,13},{11,10,14},{3,9,8},{5,2,2},{3,2,5},{2,19,14},{17,3,6},{6,4,17},{5,15,19},{2,14,14},{19,4,16}}
    };
    cout << minCost(costs) << endl;
}
