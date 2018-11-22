// Copyright (c) 2015,
// All rights reserved.
//
// Author: wuhaibo <gethaibo@gmail.com>
// Created: 12/08/15
// Description:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> TwoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> ret;
    for (int i = 0; i < (int)nums.size(); ++i) {
        map[nums[i]] = i;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
        unordered_map<int, int>::iterator it
            = map.find(target - nums[i]);
        if (it != map.end() && i != it->second) {
            int tmp_ary[2] = {0};
            tmp_ary[0] = i < it->second ? i : it->second;
            tmp_ary[1] = i < it->second ? it->second : i;
            ret.push_back(tmp_ary[0] + 1);
            ret.push_back(tmp_ary[1] + 1);
            return ret;
        }
    }
    return ret;
}
