// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/10 15:42:39
// Description: https://leetcode.cn/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int minOperations(vector<int> &nums) {
    stack<int> s;
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (s.empty()) {
            s.push(nums[i]);
            continue;
        }
        if (nums[i] > s.top()) {
            s.push(nums[i]);
        } else if (nums[i] < s.top()) {
            while (!s.empty() && nums[i] < s.top()) {
                ++ret;
                s.pop();
            }
            if (s.empty() || s.top() != nums[i]) {
                s.push(nums[i]);
            }
        } else { // nums[i] == s.top()
            ;
        }
    }
    while (!s.empty() && s.top() != 0) {
        ++ret;
        s.pop();
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v = {7,2,0,4,2};
    cout << minOperations(v) << endl;
}
