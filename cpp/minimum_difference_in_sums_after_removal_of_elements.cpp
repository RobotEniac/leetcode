// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2025/11/05 18:01:07
// Description: https://leetcode.cn/problems/minimum-difference-in-sums-after-removal-of-elements/solutions/1247074/qian-zhui-zui-xiao-he-hou-zhui-zui-da-he-yz3d/?envType=daily-question&envId=2025-10-29

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "util.h"

using namespace std;

long long minimumDifference(vector<int> &nums) {
    if (nums.size() % 3 != 0) {
        return 0;
    }
    priority_queue<int, vector<int>, less<int>> btq;
    priority_queue<int, vector<int>, greater<int> > ltq;

    int n = nums.size() / 3;
    int64_t lsum = 0;
    int64_t rsum = 0;
    for (int i = 0; i < n; ++i) {
        btq.push(nums[i]);
        lsum += nums[i];
    }
    for (int i = 2 * n; i < nums.size(); ++i) {
        ltq.push(nums[i]);
        rsum += nums[i];
    }
    vector<int64_t> vl_min(3 *n, 0);
    vector<int64_t> vr_max(3 *n, 0);
    vl_min[n-1] = lsum;
    vr_max[2*n] = rsum;
    for (int i = n; i < n * 2; ++i)
    {
        if (nums[i] < btq.top())
        {
            lsum = lsum - btq.top() + nums[i];
            btq.pop();
            btq.push(nums[i]);
        }
        vl_min[i] = lsum;
    }
    for (int i = 2*n-1; i >= n; --i) {
        if (nums[i] > ltq.top()) {
            rsum = rsum - ltq.top() + nums[i];
            ltq.pop();
            ltq.push(nums[i]);
        }
        vr_max[i] = rsum;
    }
    cout << vl_min << endl;
    cout << vr_max << endl;
    int64_t ret = INT64_MAX;
    for (int i = n-1; i < 2 * n; ++i) {
        if (ret > vl_min[i] - vr_max[i+1]) {
            ret = vl_min[i] - vr_max[i+1];
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> v = {1,1,1,1,1,5};
    cout << minimumDifference(v) << endl;
    priority_queue<int> q;
    for (int i = 0; i < v.size(); ++i) {
        q.push(v[i]);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << q.top() << ", ";
        q.pop();
    }
}
