// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/07/13 15:53:05
// Description: https://leetcode.cn/problems/xiao-zhang-shua-ti-ji-hua/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool check(vector<int>& time, int limit, int day_limit) {
    int day = 0;
    int max_time = 0;
    int total = 0;
    for (int i = 0; i < time.size(); ++i) {
        max_time = max(max_time, time[i]);
        if (total + time[i] - max_time <= limit) {
            total = total + time[i];
        } else {
            total = time[i];
            max_time = time[i];
            ++day;
        }
    }
    day++;
    return day <= day_limit;
}

int minTime(vector<int>& time, int m) {
    int sum = 0;
    for (int i = 0; i < time.size(); ++i) {
        sum += time[i];
    }
    int l = 0;
    int r = sum;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(time, mid, m)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return r;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,3,3};
    cout << minTime(a, 2) << endl;
}
