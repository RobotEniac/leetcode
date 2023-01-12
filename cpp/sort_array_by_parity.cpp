// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/28 16:21:04
// Description: https://leetcode.cn/problems/sort-array-by-parity/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int l = 0;
    int r = 0;
    while (r < nums.size()) {
        if (nums[r] % 2 == 0) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            ++l;
        }
        ++r;
    }
    return nums;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1, 2, 3,4,5,6};
    cout << sortArrayByParity(a) << endl;
}
