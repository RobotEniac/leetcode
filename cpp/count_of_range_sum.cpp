// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/12/13 11:05:30
// Description: https://leetcode-cn.com/problems/count-of-range-sum/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int64_t sum(int l, int h) {
    return (l + h) * (h - l + 1) / 2;
}

int countRangeSum(vector<int> &nums, int lower, int upper)
{
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i) {
        sums[i] = sums[i-1] + nums[i-1];
    }
    int ret = 0;
    for (int len = 1; len <= nums.size(); ++len) {
        for (int i = 0; i <= nums.size() - len; ++i) {
            int t = sums[i+len] - sums[i];
            if (t >= lower && t <= upper) {
                ++ret;
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {-2,5,-1};
    cout << countRangeSum(nums, -2, 2) << endl;
}
