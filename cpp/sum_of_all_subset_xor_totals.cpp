// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/05/19 20:02:53
// Description: https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-05-19

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void dfs(vector<int>& nums, int i, int xsum, int &total) {
    if (i == nums.size()) {
        total += xsum;
        return;
    }
    dfs(nums, i+1, xsum, total);
    dfs(nums, i+1, xsum ^ nums[i], total);
}

int subsetXORSum(vector<int>& nums) {
    int ret = 0;
    dfs(nums, 0, 0, ret);
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v = {5,1,6};
    cout << subsetXORSum(v) << endl;
}
