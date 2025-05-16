// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/06/14 11:00:41
// Description: https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    vector<int64_t> sums(nums.size()+1, 0);
    for (int i = 1; i < nums.size()+1; ++i) {
        sums[i] = sums[i-1]+nums[i-1];
    }
    int ret = 0;
    for (int i = 0; i < sums.size(); ++i) {
        for (int j = i+1; j < sums.size(); ++j) {
            if (sums[j] - sums[i] == k) {
                ++ret;
            }
        }
    }
    cout << sums << endl;
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1};
    cout << subarraySum(a, 0) << endl;
}
