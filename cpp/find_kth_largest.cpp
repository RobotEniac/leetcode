// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/03/09 20:36:34
// Description: https://leetcode.cn/problems/xx4gT2/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int find(vector<int>& a, int s, int e, int k) {
    int p = a[e-1];
    e = e- 1;
    int l = s;
    for (int r = s; r < e; ++r) {
        if (a[r] < p) {
            if (l != r) {
                int t = a[l];
                a[l] = a[r];
                a[r] = t;
            }
            ++l;
        }
    }
    a[e-1] = a[l];
    a[l] = p;
    if (l - s == k) {
        return a[l];
    }
    if (l - s < k) {
        return find(a, l+1, e, k - (l+1-s));
    }
    return find(a, s, l, k);
}

int findKthLargest(vector<int>& nums, int k) {
    return find(nums, 0, nums.size(), k-1);
}

int main(int argc, char *argv[]) {
    vector<int> a;
    int k = atoi(argv[1]);
    const int N = 10;
    for (int i = 0; i < N; ++i) {
        a.push_back(rand()%100);
    }
    cout << a << endl;
    cout << findKthLargest(a, k) << endl;
    sort(a.begin(), a.end());
    cout << a << endl;
}
