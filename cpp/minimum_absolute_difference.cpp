// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2026/01/26 12:01:41
// Description: https://leetcode.cn/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26

#include <iostream>
#include <vector>
#include <string>

#include "prettyprint.hpp"

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int64_t mm = INT_MAX;
    for (int i = 0; i < arr.size() - 1; ++i) {
        int64_t t = (int64_t)arr[i+1] - arr[i];
        if (t < mm) {
            mm = t;
        }
    }
    vector<vector<int>> ret;
    for (int i = 0; i < arr.size() - 1; ++i) {
        int64_t t = (int64_t)arr[i+1] - arr[i];
        if (t == mm) {
            vector<int> vt(2, 0);
            vt[0] = arr[i];
            vt[1] = arr[i+1];
            ret.push_back(vt);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    vector<int> a = {3,8,-10,23,19,-4,-14,27};
    cout << minimumAbsDifference(a) << endl;
}
