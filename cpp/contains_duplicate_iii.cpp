// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/02/12 23:26:24
// Description: https://leetcode.com/problems/contains-duplicate-iii/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

#include "util.h"

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.empty() || k < 0) {
        return false;
    }
    map<int64_t, int64_t> bucket;
    ++k;
    int64_t v = (int64_t)t+1;
    for (int i = 0; i < nums.size(); ++i) {
        if (i >= k) {
            bucket.erase(((int64_t)nums[i-k] - INT_MIN) / v);
        }
        int s = ((int64_t)nums[i] - INT_MIN) / v;
        if (bucket.find(s) != bucket.end()
                || (bucket.find(s-1) != bucket.end() && nums[i] - bucket[s-1] < v)
                || (bucket.find(s+1) != bucket.end() && bucket[s+1] - nums[i] < v)) {
            return true;
        }
        bucket[s] = (int64_t)nums[i];
    }
    return false;
}

int main(int argc, char *argv[]) {
    // vector<int> v = {0,10,22,15,0,5,22,12,1,5};
    vector<int> v = {1, 2147483647};
    cout << boolalpha << containsNearbyAlmostDuplicate(v, 1, 2147483647) << endl;
}
