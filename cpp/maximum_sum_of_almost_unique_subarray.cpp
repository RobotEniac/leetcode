// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/10/07 17:38:11
// Description: https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "util.h"

using namespace std;

void insert(map<int, int> &m, int x) {
    auto it = m.find(x);
    if (it == m.end()) {
        m[x] = 1;
    } else {
        it->second += 1;
    }
}

void del(map<int, int> &m, int x) {
    auto it = m.find(x);
    if (it == m.end()) {
        return;
    }
    if (it->second == 1) {
        m.erase(it);
    } else {
        it->second -= 1;
    }
}

long long maxSum(vector<int>& nums, int m, int k) {
    int64_t sum = 0;
    int64_t mm = INT_MIN;
    map<int, int> p;
    for (int i = 0; i < nums.size(); ++i) {
        cout << mm << ", " << sum << endl;
        if (i < k) {
            sum += nums[i];
            insert(p, nums[i]);
            if (i == k-1 && p.size() >= m) {
                mm = sum;
            }
        } else {
            sum = sum - nums[i-k] + nums[i];
            del(p, nums[i-k]);
            insert(p, nums[i]);
            if (p.size() >= m && sum > mm) {
                mm = sum;
            }
        }
    }
    return mm;
}

int main(int argc, char *argv[]) {
    vector<int> a = {5,9,9,2,4,5,4};
    cout << maxSum(a, 1, 3) << endl;
}
