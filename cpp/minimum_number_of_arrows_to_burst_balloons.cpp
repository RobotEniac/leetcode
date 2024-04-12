// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/02/26 15:34:04
// Description: https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool comp(const vector<int>& lhs, const vector<int>& rhs) {
    return lhs[1] < rhs[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }
    sort(points.begin(), points.end(), comp);
    int cnt = 1;
    int cur = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0] > cur) {
            ++cnt;
            cur = points[i][1];
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << findMinArrowShots(points) << endl;
}
