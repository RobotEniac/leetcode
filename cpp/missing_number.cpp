// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/18 23:55:38
// Description: https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "util.h"

using namespace std;

int missingNumber(vector<int>& nums) {
    vector<int> t(nums.size()+1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        t[nums[i]]++;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == 0) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int missing = atoi(argv[2]);
    vector<int> v;
    for (int i = 0; i <=n; ++i) {
        if (i != missing) {
            v.push_back(i);
        }
    }
    random_shuffle(v.begin(), v.end());
    cout << missingNumber(v) << endl;
}
