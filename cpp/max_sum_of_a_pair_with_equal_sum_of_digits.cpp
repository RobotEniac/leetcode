// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/16 16:57:34
// Description: https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int digitSum(int a) {
    int ret = 0;
    while (a != 0) {
        ret += a % 10;
        a = a / 10;
    }
    return ret;
}

int maximumSum(vector<int>& nums) {
    map<int, vector<int> > m;
    int ret = -1;
    for (int i = 0; i < nums.size(); ++i) {
        int t = digitSum(nums[i]);
        auto it = m.find(t);
        if (it == m.end()) {
            m[t] = vector<int>(1, nums[i]);
        } else {
            vector<int> &a = it->second;
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] + nums[i] > ret) {
                    ret = a[j] + nums[i];
                }
            }
            a.push_back(nums[i]);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {10, 12, 19, 14};
    cout << maximumSum(a) << endl;
}
