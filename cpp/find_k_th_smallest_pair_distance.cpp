// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2021/01/15 16:42:19
// Description: https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

void show(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << "(" << v[i][0] << ", " << v[i][1] << ")";
    }
    cout << endl;
}

int smallestDistancePair(vector<int>& nums, int k) {
    vector<vector<int>> pairs;
    int sz = nums.size();
    int len = 0;
    int n = 0;
    sort(nums.begin(), nums.end());
    while (len < sz && n < k) {
        ++len;
        n = n + sz - len;
    }
    for (int i = 0; i < nums.size() - len; ++i) {
        vector<int> p(2, 0);
        p[0] = nums[i];
        p[1] = nums[i+len];
        pairs.push_back(p);
    }
    show(pairs);
    return 0;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(rand() % 10);
    }
    cout << v << endl;
    smallestDistancePair(v, 1);
}
