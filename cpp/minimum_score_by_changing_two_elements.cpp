// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/10/18 16:13:16
// Description: https://leetcode.cn/problems/minimum-score-by-changing-two-elements/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int minimizeSum(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int mmax = nums[nums.size() - 1] - nums[0];
    int mmin = mmax;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - nums[i-1] < mmin) {
            mmin = nums[i] - nums[i-1];
        }
    }
    return mmax + mmin;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,4,7,8,5};
    cout << minimizeSum(a) << endl;
}
