// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/11 21:28:52
// Description: https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (nums.size() < 2) {
        return false;
    }
    map<int, int> index;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = index.find(nums[i]);
        if (it == index.end()) {
            index[nums[i]] = i;
        } else if (i - it->second <= k) {
            return true;
        } else {
            it->second = i;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {1,0,1,1};
    cout << nums << endl;
    cout << boolalpha << containsNearbyDuplicate(nums, 3) << endl;
}
