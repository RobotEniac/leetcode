// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2020/10/28 20:31:27
// Description: https://leetcode-cn.com/problems/sliding-window-median/

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int find(vector<int> &a, int len, int n) {
    int l = 0;
    int r = len;
    while (r - l > 1) {
        int m = (l + r ) / 2;
        if (a[m] <= n) {
            l = m+1;
        } else {
            r = m;
        }
    }
    if (a[l] <= n) {
        while (l < len & a[l] <= n) ++l;
        return l;
    }
    while (l >= 0 && a[l] > n) --l;
    return l+1;
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ret;
    if (nums.empty() && k == 0) {
        return ret;
    }
    vector<int> slice(k, 0);
    for (int i = 0; i < k; ++i) {
        slice[i] = nums[i];
    }
    sort(slice.begin(), slice.end());
    int m = k / 2;
    if (k % 2 != 0) {
        ret.push_back(slice[m]);
    } else {
        ret.push_back(((double)slice[m-1] + slice[m]) / 2.0);
    }
    for (int i = k; i < nums.size(); ++i) {
        int j = 0;
        while (j < k && slice[j] != nums[i-k]) ++j;
        for (; j < k-1; ++j) {
            slice[j] = slice[j+1];
        }
        for (j = k-2; j >= 0 && slice[j] > nums[i]; --j) {
            slice[j+1] = slice[j];
        }
        slice[j+1] = nums[i];
        if (k % 2 != 0) {
            ret.push_back(slice[m]);
        } else {
            ret.push_back(((double)slice[m-1] + slice[m]) / 2.0);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    // vector<int> a = {1,2};
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    cout << a << endl;
    cout << medianSlidingWindow(a, 3) << endl;
}
