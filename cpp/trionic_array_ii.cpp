// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/09/12 14:24:08
// Description: https://leetcode.cn/problems/trionic-array-ii/description/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

long long maxSumTrionic(vector<int>& nums) {
    int l = 0, r = 0;
    int p = 0, q = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        l = i;
        p = l+1;
        while (p < nums.size() && nums[p-1] < nums[p]) {
            ++p;
        }
        q = p+1;
        while (q < nums.size() && nums[q-1] > nums[q]) {
            ++q;
        }
        r = q+1;
        while (r < nums.size() && nums[r-1] < nums[r]) {
            ++r;
        }
        if (l < p && p < q && q < r) {
            long long sum = 0;
            for (int j = l; j <= r; ++j) {
                sum += nums[j];
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
