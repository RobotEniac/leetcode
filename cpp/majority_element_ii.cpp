// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/12 22:36:08
// Description: https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    if (nums.size() < 3) {
        return nums;
    }
    vector<int> ret;
    int c1 = 0;
    int c2 = 0;
    int maj1 = INT_MAX;
    int maj2 = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == maj1) {
            ++c1;
        } else if (nums[i] == maj2) {
            ++c2;
        } else if (c1 == 0) {
            ++c1;
            maj1 = nums[i];
        } else if (c2 == 0) {
            ++c2;
            maj2 = nums[i];
        } else {
            --c1;
            --c2;
        }
    }

    c1 = 0;
    c2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == maj1) {
            ++c1;
        } else if (nums[i] == maj2) {
            ++c2;
        }
    }
    if (c1 > nums.size() / 3) {
        ret.push_back(maj1);
    }
    if (c2 > nums.size() / 3 && maj1 != maj2) {
        ret.push_back(maj2);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {1,1,1,3,3,2,2,2};
    cout << nums << endl;
    cout << majorityElement(nums) << endl;
}
