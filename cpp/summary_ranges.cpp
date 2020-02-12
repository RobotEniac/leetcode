// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2019/11/12 16:49:43
// Description: https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#include "util.h"

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) {
        return vector<string>();
    }
    if (nums.size() == 1) {
        stringstream ss;
        ss << nums[0];
        vector<string> ret;
        ret.push_back(ss.str());
        return ret;
    }
    vector<string> ret;
    int start = nums[0];
    int last = nums[0];
    nums.push_back(INT_MAX);
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - last <= 1) {
            if (i == nums.size() - 1) {
                stringstream ss;
                if (start == last) {
                    ss << start;
                } else {
                    ss << start << "->" << last;
                }
                ret.push_back(ss.str());
            }
            last = nums[i];
        } else {
            stringstream ss;
            if (start == last) {
                ss << start;
            } else {
                ss << start << "->" << last;
            }
            ret.push_back(ss.str());
            start = nums[i];
            last = nums[i];
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {0,2,3,4,6,8,9};
    nums.push_back(INT_MAX-2);
    nums.push_back(INT_MAX-1);
    nums.push_back(INT_MAX);
    cout << nums << endl;
    cout << summaryRanges(nums) << endl;
}
