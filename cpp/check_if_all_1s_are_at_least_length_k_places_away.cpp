// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/17 20:38:26
// Description: https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

bool kLengthApart(vector<int> &nums, int k) {
    int last = -1;
    for(int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            if (last >= 0 && i - last - 1 < k) {
                return false;
            }
            last = i;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,0,0,0,1,0,0,1};
    cout << kLengthApart(v, 2) << endl;
    v = {1,0,1};
    cout << kLengthApart(v, 2) << endl;
}
