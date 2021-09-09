// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/06/28 10:49:23
// Description: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int find(vector<int>& nums, int s, int e) {
    if (e - 1 == s) {
        return nums[s];
    }
    if (nums[s] < nums[e-1]) {
        return nums[s];
    }
    int m = (s + e) / 2;
    int m1 = find(nums, s, m);
    int m2 = find(nums, m, e);
    return std::min(m1, m2);
}

int findMin(vector<int>& nums) {
    return find(nums, 0, nums.size());
}

int main(int argc, char *argv[]) {
    vector<int> a = {2,2,2,0,1};
    cout << findMin(a) << endl;
}
