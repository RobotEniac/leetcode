// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/06 15:37:26
// Description: https://leetcode-cn.com/problems/count-nice-pairs-in-an-array/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int rev(int x) {
    int t = 0;
    while (x > 0) {
        t = t * 10 + (x % 10);
        x = x / 10;
    }
    return t;
}

int countNicePairs(vector<int>& nums) {
    map<int64_t, int> m;
    const int prime = 1e9 + 7;
    cout << prime << endl;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int64_t sub = nums[i] - rev(nums[i]);
        auto it = m.find(sub);
        if (it == m.end()) {
            m[sub] = 1;
        } else {
            count = (count + it->second) % prime;
            ++it->second;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    // vector<int> a = {13,10,35,24,76};
    vector<int> a = {42,11,1,97};
    cout << countNicePairs(a) << endl;
}
