// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/07/28 17:41:35
// Description: https://leetcode.cn/problems/next-greater-element-iv/

#include <iostream>
#include <vector>
#include <string>

#include "file_util.hpp"
#include "util.h"

using namespace std;

vector<int> secondGreaterElement(vector<int>& nums) {
    vector<int> ret(nums.size(), -1);
    vector<int> lg(nums.size(), 0);
    lg[nums.size()-1] = nums[nums.size()-1];
    for (int i = nums.size()-2; i >= 0; --i) {
        lg[i] = max(lg[i+1], nums[i]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (lg[i] <= nums[i]) {
            continue;
        }
        int cnt = 0;
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[j] > nums[i]) {
                if (cnt == 0) {
                    ++cnt;
                } else if (cnt == 1) {
                    ret[i] = nums[j];
                    break;
                }
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = vector<int>(100000, 8);
    cout << secondGreaterElement(a) << endl;
}
