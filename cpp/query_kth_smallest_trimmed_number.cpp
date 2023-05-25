// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/16 17:34:58
// Description: https://leetcode.cn/problems/query-kth-smallest-trimmed-number/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int query(vector<int>& a, int s, int e, int k) {
    if (k <= 0) {
        return -1;
    }
    if (e - s < k) {
        return -1;
    }
    int l = s;
    int p = a[e-1];
    for (int i = s; i < e - 1; ++i) {
        if (a[i] <= p) {
            if (l != i) {
                int t = a[l];
                a[l] = a[i];
                a[i] = t;
            }
            ++l;
        }
    }
    a[e-1] = a[l];
    a[l] = p;
    if (l - s +1 == k) {
        return p;
    }
    if (l - s + 1 > k) {
        return query(a, s, l, k);
    }
    return query(a, l+1, e, k - (l+1-s));
}

vector<int> trim(vector<string>& nums, int b) {
    vector<int> ret(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < b; ++i) {
            int t = 0;
            if
            t = nums[i][nums.size() - b+j] - '0';
        }
    }
}

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    vector<int> ret;
    return ret;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < 10; ++i) {
        int r = rand() % 100;
        a.push_back(r);
        b.push_back(r);
    }
    cout << query(a, 0, a.size(), n) << endl;
    sort(b.begin(), b.end());
    cout << b << endl;
}

