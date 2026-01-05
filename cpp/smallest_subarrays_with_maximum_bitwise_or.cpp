// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/10/22 10:10:31
// Description: https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/?envType=daily-question&envId=2025-10-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> smallestSubarrays(vector<int> &nums) {
    vector<int> ret(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
        int max_len = 0;
        int max_or = 0;
        int res = 0;
        for (int j = i; j < nums.size(); ++j) {
            res = res | nums[j];
            if (res > max_or) {
                max_or = res;
                max_len = j-i+1;
            }
        }
        ret[i] = max_len;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,0,2,1,3};
    cout << smallestSubarrays(a) << endl;
}
