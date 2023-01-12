// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2022/11/03 12:17:53
// Description: https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "util.h"

using namespace std;

void show(vector<int> n, vector<bool> b) {
    for (int i = 0; i < n.size(); ++i) {
        if (b[i]) {
            cout << n[i] << ", ";
        }
    }
    cout << endl;
}

bool dfs(vector<int>& a, int idx, int target, vector<bool>& chosen, vector<int>& bkt) {
    if (idx == bkt.size()) {
        return true;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (chosen[i]) {
            continue;
        }
        if (bkt[idx] + a[i] > target) {
            continue;
        }
        bool ret = false;
        chosen[i] = true;
        bkt[idx] += a[i];
        if (bkt[idx] == target) {
            ret = dfs(a, idx+1, target, chosen, bkt);
        } else {
            ret = dfs(a, idx, target, chosen, bkt);
        }
        if (ret) {
            return true;
        }
        bkt[idx] -= a[i];
        chosen[i] = false;
    }
    return false;
}

bool dfs(vector<int>& a, int idx, int sum, vector<int>& bkt, vector<vector<int> >& memo) {
    if (idx == a.size()) {
        for (int i = 0; i < bkt.size(); ++i) {
            if (bkt[i] != sum) {
                return false;
            }
        }
        return true;
    }
    for (int i = 0; i < bkt.size(); ++i) {
        if (bkt[i] + a[idx] > sum) {
            continue;
        }
        bkt[i] += a[idx];
        memo[i].push_back(a[idx]);
        bool ret = dfs(a, idx+1, sum, bkt, memo);
        if (ret) {
            return true;
        }
        bkt[i] -= a[idx];
        memo[i].pop_back();
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum % k != 0) {
        return false;
    }
    int avg = sum / 4;
    vector<int> bkt(k, 0);
    /*
    vector<vector<int> > memo(k, vector<int>());
    bool ret = dfs(nums, 0, avg, bkt, memo);
    for (int i = 0; i < k; ++i) {
        cout << memo[i] << endl;
    }
    */
    vector<bool> chosen(nums.size(), false);
    bool ret = dfs(nums, 0, avg, chosen, bkt);
    return ret;
}

int main(int argc, char *argv[]) {
    // vector<int> a = {4, 3, 2, 3, 5, 2, 1};
    vector<int> a = {4,4,6,2,3,8,10,2,10,7};
    cout << boolalpha << canPartitionKSubsets(a, 4) << endl;
}
