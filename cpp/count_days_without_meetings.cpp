// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/11 10:29:19
// Description: https://leetcode.cn/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-11-10

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(const vector<vector<int>> &vv) {
    for (auto v : vv) {
        cout << "(" << v[0] << ", " << v[1] << "), ";
    }
    cout << endl;
}

int countDays(int days, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end(),
         [](const vector<int> &lhs, const vector<int> &rhs)
         { return lhs[0] < rhs[0]; });
    int l = 0;
    int r = 1;
    while (r < meetings.size()) {
        if (meetings[l][1] < meetings[r][0]) {
            ++l;
            if (l != r) {
                meetings[l] = meetings[r];
            }
            ++r;
        } else if (meetings[l][1] >= meetings[r][1]) {
            ++r;
        } else {
            meetings[l][1] = meetings[r][1];
            ++r;
        }
    }
    show(meetings);
    int ret = days;
    for (int i = 0; i <= l; ++i) {
        if (meetings[i][0] > days) {
            break;
        }
        if (meetings[i][1] > days) {
            ret -= days - meetings[i][0] + 1;
        } else {
            ret -= meetings[i][1] - meetings[i][0] + 1;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int days = 10;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    cout << countDays(days, meetings) << endl;
    meetings = {{5,7},{1,5},{9,10}};
    cout << countDays(days, meetings) << endl;
    meetings = {{2,3},{3,5},{8,8}};
    cout << countDays(8, meetings) << endl;
}
