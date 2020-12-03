// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/20 23:16:24
// Description: https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void moveZeroes(vector<int>& nums) {
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] == 0) {
            for (int j = i; j < nums.size() - 1; ++j) {
                if (nums[j+1] == 0) {
                    break;
                }
                int t = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = t;
            }
        }
    }
}

void moveZeroes2(vector<int>& nums) {
    if (nums.size() < 2) {
        return;
    }
    int insert = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[insert++] = nums[i];
        }
    }
    for (; insert < nums.size(); ++insert) {
        nums[insert] = 0;
    }
}

int main(int argc, char *argv[]) {
    vector<int> v = {0,1,0,3,12};
    cout << v << endl;
    moveZeroes2(v);
    cout << v << endl;
}
