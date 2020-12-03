// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/20 11:21:46
// Description: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"
#include "stop_watch.hpp"

using namespace std;

int findDuplicate(vector<int>& nums) {
    for (int i = 1; i <= nums.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == i) {
                ++cnt;
            }
        }
        if (cnt > 1) {
            return i;
        }
    }
    return 0;
}

int findDuplicate2(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while (slow != fast) {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

int main(int argc, char *argv[]) {
    StopWatch w;
    vector<int> v = {1,3,4,2,2};
    cout << findDuplicate(v) << endl;
    w.Pause();
    cout << findDuplicate(v) << endl;
}
