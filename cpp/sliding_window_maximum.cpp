// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/14 09:40:51
// Description: https://leetcode.com/problems/sliding-window-maximum

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "util.h"

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> sk;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        if (i < k - 1) {
            sk.insert(nums[i]);
        } else if (i == k-1) {
            sk.insert(nums[i]);
            res.push_back(*sk.rbegin());
        } else {
            auto it = sk.find(nums[i-k]);
            if (it != sk.end()) {
                sk.erase(it);
            }
            sk.insert(nums[i]);
            res.push_back(*sk.rbegin());
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    // [-7,-8,7,5,7,1,6,0]
    // [1,3,-1,-3,5,3,6,7]
    vector<int> a = {1, -1};
    cout << a << endl;
    cout << maxSlidingWindow(a, 1) << endl;
}
