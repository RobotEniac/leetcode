// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/03/18 16:01:50
// Description: https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    vector<int> memo;
    int sum = 0;
    memo.push_back(0);
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        memo.push_back(sum);
    }
    for (int len = 1; len <= nums.size(); ++len) {
        for (int i = 0; i <= nums.size() - len; ++i) {
            if (memo[i+len] - memo[i] >= s) {
                return len;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,3,4,5};
    cout << a << endl;
    cout << "mininum sum = " << minSubArrayLen(15, a) << endl;
}
