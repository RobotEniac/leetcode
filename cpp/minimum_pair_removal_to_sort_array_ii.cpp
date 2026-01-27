// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/23 15:48:35
// Description: https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-ii/description/?envType=daily-question&envId=2026-01-23

#include <iostream>
#include <vector>
#include <string>

#include "prettyprint.hpp"

using namespace std;

bool non_descend(vector<int>& v, int len) {
    for (int i = 0; i < len-1; ++i) {
        if (v[i] > v[i+1]) {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    int len = nums.size();
    while (!non_descend(nums, len)) {
        int mm = INT_MAX;
        int mi = -1;
        for (int i = 0; i < len - 1; ++i) {
            int t = nums[i]+nums[i+1];
            if (t < mm) {
                mm = t;
                mi = i;
            }
        }
        nums[mi] = nums[mi] + nums[mi+1];
        for (int i = mi+1; i < len - 1; ++i) {
            nums[i] = nums[i+1];
        }
        --len;
        cout << nums << endl;
    }
    return nums.size() - len;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,2,2};
    cout << minimumPairRemoval(v) << endl;
}
