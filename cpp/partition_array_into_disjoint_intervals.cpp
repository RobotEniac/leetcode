// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/10/24 16:26:27
// Description: https://leetcode.cn/problems/partition-array-into-disjoint-intervals/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int partitionDisjoint(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    vector<int> pmin(nums.size(), 0);
    vector<int> pmax(nums.size(), 0);
    pmax[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > pmax[i-1]) {
            pmax[i] = nums[i];
        } else {
            pmax[i] = pmax[i-1];
        }
    }
    pmin[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] < pmin[i+1]) {
            pmin[i] = nums[i];
        } else {
            pmin[i] = pmin[i+1];
        }
    }
    cout << pmax << endl;
    cout << pmin << endl;
    for (int i = 0; i < nums.size()-1; ++i) {
        if (pmax[i] <= pmin[i+1]) {
            return i+1;
        }
    }
    return nums.size();
}

int main(int argc, char *argv[]) {
    vector<int> n = {1,1,1,0,6,12};
    cout << partitionDisjoint(n) << endl;
}
