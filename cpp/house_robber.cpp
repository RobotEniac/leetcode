// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/06
// Description: https://leetcode.com/problems/house-robber/

#include <vector>
#include <iostream>

#include "util.h"

using namespace std;

int MaxSum(vector<int> &num, int s, int e) {
    if (e - s <= 0) {
        return 0;
    }
    if (e - s == 1) {
        return num[s];
    }
    if (e - s == 2) {
        return std::max(num[s], num[s+1]);
    }
    return std::max(num[s] + MaxSum(num, s+2, e), MaxSum(num, s+1, e));
}

int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    int n = nums.size() - 1;
    dp[n] = nums[n];
    dp[n-1] = std::max(nums[n-1], nums[n]);
    for (int i = n-2; i >= 0; --i) {
        dp[i] = std::max(nums[i] + dp[i+2], dp[i+1]);
    }
    return dp[0];
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,3,1};
    cout << a << endl;
    cout << rob(a) << endl;
}

