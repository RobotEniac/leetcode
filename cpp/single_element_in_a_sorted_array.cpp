// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/04/13 13:48:49
// Description: https://leetcode-cn.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int val = 0;
    for (int i = 0; i < nums.size(); ++i) {
        val = val ^ nums[i];
    }
    return val;
}

int singleNonDuplicate2(vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    while (l < r-1) {
        int m = (l + r)/2;
        bool ev = ((r - m) % 2) == 0;
        if (nums[m] == nums[m+1]) {
            if (ev) {
                r = m;
            } else {
                l = m+2;
            }
        } else if (nums[m] == nums[m-1]) {
            if (ev) {
                l = m+1;
            } else {
                r = m-1;
            }
        } else {
            return nums[m];
        }
    }
    return nums[l];
}


int main(int argc, char *argv[]) {
    vector<int> a = {1,1,2,3,3,4,4,8,8};
    cout << a << "\n";
    cout << singleNonDuplicate(a) << endl;
    cout << singleNonDuplicate2(a) << endl;
    vector<int> b = {1};
    cout << singleNonDuplicate2(b) << endl;
}
