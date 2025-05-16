// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/03/19 17:01:43
// Description: https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2025-03-19

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int> > ret;
    sort(nums.begin(), nums.end());
    int s = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != nums[s]) {
            s = i;
        }
        if (i - s + 1 > ret.size()) {
            ret.push_back(vector<int>());
        }
        ret[i-s].push_back(nums[i]);
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {1,3,4,1,2,3,1};
    vector<vector<int> > r = findMatrix(a);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
}
