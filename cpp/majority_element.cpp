// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/22
// Description: Amazing!!!

#include <vector>
#include <iostream>

#include "util.h"

using namespace std;

int majorityElement(vector<int>& nums) {
    int maj = 0;
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[maj]) {
            ++count;
        } else {
            --count;
        }
        if (count == 0) {
            maj = i;
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == nums[maj]) {
            ++count;
        }
    }
    if (count >= nums.size() / 2) {
        return nums[maj];
    }
    return 0;
}

