// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/16 16:48:04
// Description: https://leetcode.cn/problems/maximum-number-of-pairs-in-array/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

vector<int> numberOfPairs(vector<int>& nums) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i]) == m.end()) {
            m[nums[i]] = 1;
        } else {
            ++m[nums[i]];
        }
    }
    vector<int> ret(2, 0);
    for (auto it = m.begin(); it != m.end(); ++it) {
        ret[0] += it->second / 2;
        ret[1] += it->second % 2;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,3,2,1,3,2,2};
    cout << a << endl;
    cout << numberOfPairs(a) << endl;
}
