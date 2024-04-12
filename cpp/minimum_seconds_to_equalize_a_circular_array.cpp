// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2024/03/21 11:13:08
// Description: https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/?envType=daily-question&envId=2024-03-21

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

int minimumSeconds(vector<int>& nums) {
    map<int, vector<int> > c;
    for (int i = 0; i < nums.size(); ++i) {
        c[nums[i]].push_back(i);
    }
    int ret = (nums.size()-1);
    for (auto it = c.begin(); it != c.end(); ++it) {
        vector<int> &v = it->second;
        if (v.size() > 1) {
            int max_dist = (nums.size()+v[0]-v[v.size()-1])/2;
            for (int i = 1; i < v.size(); ++i) {
                max_dist = std::max(max_dist, (v[i]-v[i-1])/2);
            }
            ret = std::min(ret, max_dist);
        }
    }
    return ret;
}

// 1 -> 0
// 2 -> 1
// 3 -> 1
// 4 -> 2
// 5 -> 2
// 6 -> 3

int main(int argc, char *argv[]) {
    vector<int> a = {5,5,5,5};
    cout << minimumSeconds(a) << endl;
}
