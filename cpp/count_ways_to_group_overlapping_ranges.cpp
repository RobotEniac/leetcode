// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/04/09 15:36:38
// Description: https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/?envType=daily-question&envId=2024-04-09

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"
#include "file_util.hpp"

using namespace std;

void show(vector<vector<int> > &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin()) {
            cout << ", ";
        }
        cout << "{" << (*it)[0] << "," << (*it)[1] << "}";
    }
    cout << endl;
}

int pow2(int i) {
    const int D = 1e9+7;
    if (i == 0) {
        return 1;
    }
    if (i & 0x1) {
        return (2 * pow2(i-1) % D) % D;
    } else {
        int64_t r = pow2(i/2) % D;
        return r*r % D;
    }
}

int countWays(vector<vector<int>>& ranges) {
    sort(ranges.begin(), ranges.end(),
         [&](vector<int>& lhs, vector<int>& rhs) { return lhs[0] < rhs[0]; });
    show(ranges);
    int k = 1;
    int s = ranges[0][0];
    int e = ranges[0][1];
    for (int i = 1; i < ranges.size(); ++i) {
        if (ranges[i][0] <= e) {
            e = max(ranges[i][1], e);
        } else {
            ++k;
            s = ranges[i][0];
            e = ranges[i][1];
        }
    }
    return pow2(k);
}

int main(int argc, char *argv[]) {
    vector<vector<int> > r = lc::ReadRange("t");
    cout << countWays(r) << endl;
}
