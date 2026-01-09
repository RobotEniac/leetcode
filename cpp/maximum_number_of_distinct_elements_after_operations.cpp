// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/08 12:05:00
// Description: https://leetcode.cn/problems/maximum-number-of-distinct-elements-after-operations/description/?envType=daily-question&envId=2026-01-07

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"
#include "file_util.hpp"

using namespace std;

inline void put(map<int, int>& m, int a) {
    if (m.find(a) != m.end()) {
        ++m[a];
    } else {
        m[a] = 1;
    }
}

inline void rm(map<int, int>& m, int a) {
    if (m.find(a) == m.end()) {
        return;
    }
    --m[a];
    if (m[a] <= 0) {
        m.erase(a);
    }
}

int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int last = INT_MIN;
    int c = 0;
    for (int i = 0; i < nums.size(); ++i) {
       int j = std::max(nums[i] - k, last+1);
        if (j <= nums[i] +k) {
            last = j;
            ++c;
        }
   }
    return c;
}

int main(int argc, char *argv[]) {
    // vector<int> a = lc::ReadArrayInt("in.txt");
    vector<int> a = {4,4,4,4};
    cout << maxDistinctElements(a, 1) << endl;
}
