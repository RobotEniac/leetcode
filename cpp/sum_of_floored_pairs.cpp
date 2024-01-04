// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/10/08 20:52:07
// Description: https://leetcode.cn/problems/sum-of-floored-pairs/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int sumOfFlooredPairs(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int64_t sum = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            sum += int64_t(nums[i]/nums[j]);
        }
    }
    return sum;
}

int main(int argc, char *argv[]) {
    vector<int> a = {2,5,9};
    cout << sumOfFlooredPairs(a) << endl;
}
