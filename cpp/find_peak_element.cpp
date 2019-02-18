// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/02/18
// Description: 

#include <vector>
#include <iostream>
#include "util.h"

using namespace std;

vector<int> findPeakElement(vector<int>& nums) {
    vector<int> ret;
    if (nums.size() == 0) {
        return ret;
    }
    if (nums.size() == 1) {
        ret.push_back(0);
        return ret;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            if (nums[i] > nums[i+1]) {
                ret.push_back(i);
            }
            continue;
        }
        if (i == nums.size() - 1) {
            if (nums[i] > nums[i - 1]) {
                ret.push_back(i);
            }
            continue;
        }
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            ret.push_back(i);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,2,1,3,5,6,4};
    vector<int> peak = findPeakElement(a);
    cout << a << endl;
    cout << peak << endl;
}
