// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/06/30 15:48:58
// Description: https://leetcode-cn.com/problems/house-robber-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() <= 3) {
        int mmax = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mmax) {
                mmax = nums[i];
            }
        }
        return mmax;
    }
    vector<int> dp(nums.size(), 0);
    int n = nums.size() - 1;
    dp[n] = nums[n];
    dp[n-1] = std::max(nums[n-1], nums[n]);
    for (int i = n-2; i >= 1; --i) {
        dp[i] = std::max(nums[i] + dp[i+2], dp[i+1]);
    }

    vector<int> dp2(nums.size(), 0);
    dp2[n-1] = nums[n-1];
    dp2[n-2] = nums[n-2];
    for (int i = n-3; i >= 2; --i) {
        dp2[i] = std::max(nums[i] + dp2[i+2], dp2[i+1]);
    }
    return std::max(dp[1], dp2[2] + nums[0]);
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,3,1};
    cout << rob(a) << endl;
}
