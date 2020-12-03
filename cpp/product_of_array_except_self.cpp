// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/14 00:50:48
// Description: https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    // already done
    int zeros = 0;
    int p = 1;
    int zero_pos = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            zero_pos = i;
            zeros++;
        } else {
            p = p * nums[i];
        }
    }
    vector<int> res(nums.size(), 0);
    if (zeros >= 2) {
        return res;
    }
    if (zeros == 1) {
        res[zero_pos] = p;
        return res;
    }
    for (int i = 0; i < nums.size(); ++i) {
        res[i] = p / nums[i];
    }
    return res;
}

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
}
